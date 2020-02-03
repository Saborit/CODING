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

int A[3];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &A[0], &A[1], &A[2]);
    sort(A, A+3);
    
    int m = min(A[1] - A[0], A[2] - A[1]);
    
    if( A[0] + m != A[1] ){
		printf("%d\n", A[0] + m);
		return 0;	
	}
	if( A[1] + m != A[2] ){
		printf("%d\n", A[1] + m);
		return 0;		
	}
	printf("%d\n", A[2] + m);
     
        

   return 0;
}
