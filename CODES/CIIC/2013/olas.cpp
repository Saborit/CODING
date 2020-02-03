/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 500005
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

int N, M;
int A[MX][20];

int query(int a, int b){
	int lg = log2(b - a + 1);
	
	return __gcd(A[a][lg], A[b-(1<<lg)+1][lg]);	
}

int bsearch(int x){
	int p = x;
	
	for(int i=log2(N); ~i; i--)
		if( p+(1<<i)<=N && query(x, p+(1<<i)) >= M )
			p += (1<<i);
	return p;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i][0]);
	}
	
	for(int j=1; j<=log2(N); j++)
		for(int i=1; i+(1<<(j-1))<=N; i++)
			A[i][j] = __gcd(A[i][j-1], A[i+(1<<(j-1))][j-1]);
	
	int sol = 0;
    for(int i=1; i<=N; i++){
		if( A[i][0] >= M ){
			sol = max(sol, bsearch(i) - i + 1);
		}
	}
	printf("%d\n", sol);
        
   return 0;
}
