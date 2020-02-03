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

int N, Q;

struct segment_tree{
	vector<int> T;
	int ans = -1;
	
	segment_tree(): T(4*MX, INF){}
	
	int update(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = b;
		if( a < x || xend < a )
			return T[nod];
		return T[nod] = min(update(a, b, x, mid, izq), update(a, b, mid+1, xend, der));	
	}
	
	int query(int a, int b, int x=1, int xend=N, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return INF;
		return min(query(a, b, x, mid, izq), query(a, b, mid+1, xend, der));
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    
    N++;
    
    segment_tree ST;
    ST.update(N, -1);
    
    char ty;
    int a, b;
    
    while( Q-- ){
		scanf(" %c%d%d", &ty, &a, &b);	
		
		if( ty == 'M' ){
			ST.update(b, a);	
		}
		else{
			int p = b-1;
			
			for(int i=log2(N); ~i; i--){
				if( p + (1<<i) <= N && ST.query(b, p + (1<<i)) > a ){
					p += (1<<i);
				}
			}
			printf("%d\n", p+1 == N ? -1 : p+1);
		}
	} 
      
   return 0;
}
