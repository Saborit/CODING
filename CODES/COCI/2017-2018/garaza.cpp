/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
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

bool pr = false;

struct node{
	int64 val;
	bool neutro;
	vector<pair<int, int>> P, S;
	
	node(bool neutro): val(0), neutro(neutro){}
	node(int x): neutro(false){
		P.pb({x, 1}), S.pb({x, 1});
		val = (x > 1);
	}
	
	node operator + (node p){
		if( neutro )
			return p;
		if( p.neutro )
			return *this;
		
		node ans(false);
		
		ans.P = P;
		for(int i=0, tmp; i < (int)p.P.size(); i++){
			tmp = __gcd(P.back().fr, p.P[i].fr);
			
			if( tmp == ans.P.back().fr )
				ans.P.back().sc += p.P[i].sc;
			else
				ans.P.pb({tmp, p.P[i].sc});
		}
		
		ans.S = p.S;
		reverse(all(ans.S));
		
		for(int i=S.size()-1, tmp; ~i; i--){
			tmp = __gcd(p.S[0].fr, S[i].fr);
			
			if( tmp == ans.S.back().fr )
				ans.S.back().sc += S[i].sc;
			else
				ans.S.pb({tmp, S[i].sc});
		}
		reverse(all(ans.S));
		
		int64 sum = 0;
		for(int i=0, j=0; i < (int)S.size(); i++){
			while( j < (int)p.P.size() && __gcd(S[i].fr, p.P[j].fr) > 1 ){
				sum += (int64)p.P[j].sc;
				j++;
			}	
			ans.val += sum * S[i].sc;
		}
		
		ans.val += val + p.val;
		
		return ans;
	}
};

int N, Q;
int A[MX];

struct segment_tree{
	vector<node> T;
	
	segment_tree(): T(4*MX, node(false)){}
	
	node build(int x=1, int xend=N, int nod=1){
		if( x == xend )
			return T[nod] = node(A[x]);
		return T[nod] = build(x, mid, izq) + build(mid+1, xend, der);
	}
	
	node update(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = node(b);
		if( a < x || xend < a ) 
			return T[nod];
		return T[nod] = update(a, b, x, mid, izq) + update(a, b, mid+1, xend, der);
	}
	
	node query(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return node(true);
			
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der); 
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);	
	}     
	
	segment_tree ST;
	ST.build();
	
	int ty, a, b;
	while( Q-- ){
		scanf("%d%d%d", &ty, &a, &b);
		
		if( ty == 1 ){
			ST.update(a, b);	
		}
		else
			printf("%lld\n", ST.query(a, b).val);
	}

   return 0;
}
