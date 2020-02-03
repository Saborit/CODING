/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1005
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
char S[MX], A[MX][MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%s", S+1); 
    N = strlen(S+1);
    
    int n = 0, m = 0;
    for(int i=1; i*i<=N; i++) if( N % i == 0 ){
		n = i, m = N/i;		
	}
	
	int ii=1, jj=1;
	for(int i=1; i<=N; i++){
		A[jj][ii] = S[i];
		jj++;
		
		if( jj > n ){
			ii++, jj=1;	
		}	
	}
	
	for(int j=1; j<=n; j++) for(int i=1; i<=m; i++)
		printf("%c", A[j][i]);
	printf("\n");	

   return 0;
}
