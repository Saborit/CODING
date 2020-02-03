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

int N, M, x;
int A[MX], acum[MX];
int diff_pos[MX], diff_neg[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		
		if( A[i] == M )
			x = i; 
	} 
	
	diff_pos[0]++;
	
	int bal = 0;
	for(int i=x+1; i<=N; i++){
		bal += (A[i] > M) ? 1 : -1;
		
		if( bal >= 0 ) diff_pos[bal]++;
		else diff_neg[-bal]++;
	}
	
	for(int i=1; i<=x; i++){
		acum[i] = acum[i-1] + ((A[i] < M) ? 1 : (A[i] == M) ? 0 : -1);
	}
	
	int sol = 0;
	for(int i=1; i<=x; i++){
		int d = acum[x] - acum[i-1];
		
		if( d >= 0 )  
			sol += diff_pos[d];
		else 
			sol += diff_neg[-d];
	}
     
    printf("%d\n", sol);    

   return 0;
}
