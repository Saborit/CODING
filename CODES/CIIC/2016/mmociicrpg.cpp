/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct qry{
	int x, id;
};

struct par{
	int64 first;
	int second;
	
	par operator + (const par& p)const{ return (par){fr + p.fr, sc + p.sc}; }
};

int cn, M, Q;
int A[MX], V[MX];
int64 sol[MX];
bool mk[MX];
vector<int> G[MX];
vector<qry> q[MX];

const int N = 1e6;

struct segment_tree{
	vector<par> T;
	
	segment_tree(): T(4*N+5, {0ll, 0}){}
	
	par update(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = {T[nod].fr + b, T[nod].sc + (b < 0 ? -1 : 1)};
		if( a < x || xend < a )
			return T[nod];
			
		return T[nod] = update(a, b, x, mid, izq) + update(a, b, mid+1, xend, der);
	}
	
	par query(int a,int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return {0ll, 0};
		
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);	
	} 
}ST;

void dfs0(int nod, int p){
	bool here = false;
	
	if( !mk[ A[nod] ] ){
		mk[ A[nod] ] = true;
		here = true;
	}
	else
		A[nod] = 0;
	
	for(auto nwn: G[nod]) if( nwn != p ){
		dfs0(nwn, nod);
	}
	
	if( here )
		mk[ A[nod] ] = false;
}

void dfs(int nod, int p){
	if( A[nod] > 0 )
		ST.update(V[ A[nod] ], V[ A[nod] ]);
	
	for(auto i: q[nod]){
		auto ans = ST.query(i.x, N);
		sol[i.id] = ans.fr - (int64)ans.sc * i.x;	
	}
	
	for(auto nwn: G[nod]) if( nwn != p ){	
		dfs(nwn, nod);
	}
	
	if( A[nod] > 0 )
		ST.update(V[ A[nod] ], -V[ A[nod] ]);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &cn, &M, &Q);
    for(int i=1; i<=M; i++)
		scanf("%d", &V[i]);
		
    for(int i=2, a, b; i<=cn; i++){
		scanf("%d%d", &a, &b);
		
		G[i].pb(a);
		G[a].pb(i);
		A[i] = b;	
	}
	
	for(int i=1, a, b; i<=Q; i++){
		scanf("%d%d", &a, &b);
		q[a].pb({b, i}); 
	}
	
	dfs0(1, -1);
    
    dfs(1, -1);
    
	for(int i=1; i<=Q; i++)
		printf("%lld\n", sol[i]);
	
   return 0;
}
