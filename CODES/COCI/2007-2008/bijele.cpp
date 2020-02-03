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

int B[] = {1, 1, 2, 2, 2, 8};

int A[6];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d%d%d%d%d", &A[0], &A[1], &A[2], &A[3], &A[4], &A[5]);
     
     printf("%d %d %d %d %d %d\n", 
		B[0] - A[0], 
		B[1] - A[1], 
		B[2] - A[2], 
		B[3] - A[3], 
		B[4] - A[4], 
		B[5] - A[5]
	);
        

   return 0;
}
