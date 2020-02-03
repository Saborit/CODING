/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1000005
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

int N;
int A[MX]; 

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	
	int sol = 0;
	for(int i=1, j=N, sumi=A[1], sumj=A[N]; i<=j; ){
		if( i > j ){
			break;	
		}
		if( i == j ){
			sol++;
			break;	
		}
		
		if( sumi == sumj ){
			sumi = A[++i];
			sumj = A[--j];
			sol += 2;	
		}
		else if( sumi > sumj ){
			sumj += A[--j];	
		}
		else{
			sumi += A[++i];	
		}
	}
	
	printf("%d\n", N - sol);
	
   return 0;
}
