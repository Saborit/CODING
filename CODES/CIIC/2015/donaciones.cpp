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

const int M = 1e6;

struct tri{
	int a, b, c;
};

int N, Q;
int64 sum;
tri A[MX];

struct segment_tree{
	vector<int64> T;
	
	segment_tree(): T(4*M+5){}
	
	int64 update(int a, int b, int x=1, int xend=M, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = T[nod] + b;
		if( a < x || xend < a )
			return T[nod];
			
		return T[nod] = update(a, b, x, mid, izq) + update(a, b, mid+1, xend, der);	
	} 
	
	int64 query(int a, int b, int x=1, int xend=M, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return 0ll;
		
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);	
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    
    segment_tree F, S;
    
    for(int i=1, a, b, c; i<=N; i++){
		scanf("%d%d%d", &a, &b, &c);
		
		A[i] = {a, b, c};
		F.update(b, c);
		S.update(a, c);
		sum += c;
	}
	
	int ty, id, a, b, c; 
	
	scanf("%d", &Q);
	while( Q-- ){
		scanf("%d", &ty);
		
		if( ty == 1 ){
			scanf("%d%d", &a, &b);
			
			int64 f = (1 <= a-1 ? F.query(1, a-1) : 0);
			int64 s = (b+1 <= M ? S.query(b+1, M) : 0);
			
			printf("%lld\n", sum - f - s);	
		}
		else{
			scanf("%d%d%d%d", &id, &a, &b, &c);
			
			F.update(A[id].b, -A[id].c);	
			S.update(A[id].a, -A[id].c);	
			sum -= A[id].c; 
			
			F.update(b, c);
			S.update(a, c);
			sum += c;
			
			A[id] = {a, b, c};
		}		
	}
	 
   return 0;
}
