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

int N, M, Q;
int A[MX], acum[MX];
vector<int> T[105];

int64 query(int m, int a, int b){
	int x = upper_bound(all(T[m]), b) - T[m].begin() - 1;	
	
	a--;
	if( a )	
		x -= upper_bound(all(T[m]), a-1) - T[m].begin() - 1;
		
	return (int64) x *(x-1)/2;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);	
	} 
	
	for(int i=0; i < M; i++)
		T[i].pb(-1);
	
	T[0].pb(0);
	for(int i=1; i<=N; i++){
		acum[i] = (acum[i-1] + A[i]) % M;
		
		T[ acum[i] ].pb(i);
	}
	
	while( Q-- ){
		int a, b; scanf("%d%d", &a, &b);
		
		int64 sol = 0;
		for(int i=0; i < M; i++)
			sol += query(i, a, b); 
		
		printf("%lld\n", sol);
	}
        

   return 0;
}
