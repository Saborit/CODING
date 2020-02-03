/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 250005
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

struct node{
	int A[10];
	
	node(){
		for(int i=0; i < 10; i++)
			A[i] = 0;
	}
	node(int d, int cant=1){
		for(int i=0; i < 10; i++)
			A[i] = 0;
		A[d] += cant;
	}
	
	void flip(int x){
		int tmp[10];
		
		for(int i=0; i < 10; i++)
			tmp[i] = A[(i + 10 - x % 10) % 10];
		for(int i=0; i < 10; i++)
			A[i] = tmp[i];	
	}
	
	int sum(){
		int ans = 0;
		for(int i=0; i < 10; i++)
			ans += i * A[i];
		return ans;
	}
	
	node merge(node p){
		node ans;	
		
		for(int i=0; i < 10; i++)
			ans.A[i] = A[i];
		for(int i=0; i < 10; i++)
			ans.A[i] += p.A[i];
		return ans;
	}
};

int N, Q;
char A[MX];

struct segment_tree{
	vector<node> T;
	vector<int> mk;
	
	segment_tree(): T(4*MX), mk(4*MX, 0){}
	
	node build(int x=1, int xend=N, int nod=1){
		if( x==xend )
			return T[nod] = node(A[x] - '0');	
		return T[nod] = build(x, mid, izq).merge(build(mid+1, xend, der));
	}
	
	void lazy(int x, int xend, int nod){
		T[izq].flip(mk[nod]);
		T[der].flip(mk[nod]);
		
		mk[izq] += mk[nod];
		mk[der] += mk[nod];
		mk[nod] = 0;
	}
	
	node update(int a, int b, int x=1, int xend=N, int nod=1){
		if( x < xend && mk[nod] )
			lazy(x, xend, nod);
			
		if( a<=x && xend<=b ){
			T[nod].flip(1);
			mk[nod] = 1;
			return T[nod];	
		}
		if( b < x || xend < a )
			return T[nod];
			
		return T[nod] = update(a, b, x, mid, izq).merge(update(a, b, mid+1, xend,der));
	}
	
	int query(int a, int b, int x=1, int xend=N, int nod=1){
		if( x < xend && mk[nod] )
			lazy(x, xend, nod);
		
		if( a<=x && xend<=b )
			return T[nod].sum();
		if( b < x || xend < a )
			return 0;
			
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    scanf(" %s", A+1);
    
    segment_tree ST;
    ST.build();
    
    int a, b;
    while( Q-- ){
		scanf("%d%d", &a, &b);
		
		printf("%d\n", ST.query(a, b));
		
		ST.update(a, b);
	}
    
   return 0;
}
