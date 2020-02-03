/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
#define INF (1ll<<62)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct node{
	int64 m, c;
	
	node operator & (const node &p){
		return {min(m, p.m), c + p.c};	
	}
};

int N, Q;
int A[MX];

struct segment_tree{
	vector<node> T;
	vector<int64> mk;
	
	segment_tree(): T(4*MX), mk(4*MX, 0ll){}
	
	node build(int x=1, int xend=N, int nod=1){
		if( x==xend )
			return T[nod] = {A[x], A[x]};
		return T[nod] = build(x, mid, izq) & build(mid+1, xend, der);	
	}
	
	void lazy(int x, int xend, int nod){
		T[izq] = {T[izq].m + mk[nod], T[izq].c + (mid-x+1) * mk[nod]};	
		T[der] = {T[der].m + mk[nod], T[der].c + (xend-mid) * mk[nod]};
		
		mk[izq] += mk[nod];	
		mk[der] += mk[nod];	
		mk[nod] = 0ll;
	}
	
	node update(int a, int b, int64 c, int x=1, int xend=N, int nod=1){
		if( x < xend && mk[nod] )	
			lazy(x, xend, nod);
			
		if( a<=x && xend<=b ){
			mk[nod] = c;
			T[nod] = {T[nod].m + c, T[nod].c + (xend-x+1) * c};
			return T[nod];	
		}
		if( b < x || xend < a )
			return T[nod];
			
		return T[nod] = update(a, b, c, x, mid, izq) & update(a, b, c, mid+1, xend, der);			
	}
	
	node query(int a, int b, int x=1, int xend=N, int nod=1){
		if( x < xend && mk[nod] )	
			lazy(x, xend, nod);
			
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return {INF, 0ll};
			
		return query(a, b, x, mid, izq) & query(a, b, mid+1, xend, der);
	}
};	

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
    
    segment_tree ST;
    ST.build();
    
    char ty;
    int a, b, c; 
    
    while( Q-- ){
		scanf(" %c", &ty);
		
		if( ty == 'M' ){
			scanf("%d%d", &a, &b);
			
			printf("%lld\n", ST.query(a, b).m);	
		}
		else if( ty == 'P' ){
			scanf("%d%d%d", &a, &b, &c);
			ST.update(a, b, c);	
		}
		else{
			scanf("%d%d", &a, &b);
			
			printf("%lld\n", ST.query(a, b).c);	
		}
	}    

   return 0;
}
