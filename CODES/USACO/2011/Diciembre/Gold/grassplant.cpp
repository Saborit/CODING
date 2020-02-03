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

int N, cn, Q;
int L[MX], R[MX], A[MX];
vector<int> G[MX];

namespace lca{
	int L[MX];
	int P[MX][20];
	
	void dfs(int nod, int p){
		for(auto nwn: G[nod]) if( nwn != p ){
			L[nwn] = L[nod] + 1;
			P[nwn][0] = nod;
			
			dfs(nwn, nod);
		}	
	}
	
	void build(){
		L[1] = 1;
		dfs(1, -1);
		
		for(int j=1; j<=log2(cn); j++)
			for(int i=1; i<=cn; i++)
				P[i][j] = P[ P[i][j-1] ][j-1];
	}
	
	int query(int a, int b){
		if( L[a] < L[b] )
			swap(a, b);
			
		for(int i=log2(L[a]); ~i; i--)
			if( P[a][i] && L[ P[a][i] ] >= L[b] )
				a = P[a][i];
		if( a == b )
			return a;
		for(int i=log2(L[a]); ~i; i--)
			if( P[a][i] && P[a][i] != P[b][i] )
				a = P[a][i], b = P[b][i];
		return P[a][0];
	}
};

struct segment_tree{
	vector<int> T;
	
	segment_tree(): T(4*MX){}
	
	int update(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = T[nod] + b;
		if( a < x || xend < a )
			return T[nod];
		return T[nod] = update(a, b, x, mid, izq) + update(a, b, mid+1, xend, der);	
	}
	
	int query(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return 0;
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);		
	}
}ST;

void dfs(int nod, int p){
	A[++N] = nod;
	L[nod] = N;
	
	for(auto nwn: G[nod]) if( nwn != p )
		dfs(nwn, nod);	
		
	A[++N] = nod;
	R[nod] = N;
}

void update(int nod, int val){
	ST.update(L[nod], val);	
	ST.update(R[nod], val);	
}

int query(int nod){
	return ST.query(L[nod], R[nod])/2;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &cn, &Q);
	for(int i=1, a, b; i < cn; i++){
		scanf("%d%d", &a, &b);
		G[a].pb(b);	
		G[b].pb(a);	
	}	
	
	lca::build();
	
	dfs(1, -1);
	
	int a, b;
	char ty;
	
	for(int i=1; i<=Q; i++){
		scanf(" %c%d%d", &ty, &a, &b);
		
		if( lca::L[a] > lca::L[b] )
			swap(a, b);
		
		if( ty == 'P' ){
			int c = lca::query(a, b);
			
			update(a, -1);
			update(b, -1);
			update(c,  2);
		}	
		else{
			printf("%d\n", -query(b));
		}
	}
       
   return 0;
}
