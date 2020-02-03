/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 2005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N, sigma;
int val[27];
int dp[MX][MX];
char S[MX], c;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &sigma, &N);
    scanf(" %s\n", S+1);
    for(int i=1, a, b; i<=sigma; i++){
		scanf(" %c%d%d\n", &c, &a, &b);
		val[c - 'a' + 1] = min(a, b);	
	} 
	
	for(int l=1; l<=N; l++){
		for(int i=1; i<=N; i++){
			int j = i + l - 1;
			
			if( j<=N ){
				if( l < 2 ){
					dp[i][j] = 0;	
				}
				else{
					if( S[i] == S[j] )
						dp[i][j] = dp[i+1][j-1];
					else
					    dp[i][j] = min(dp[i+1][j] + val[ S[i] - 'a' + 1 ], 
					                   dp[i][j-1] + val[ S[j] - 'a' + 1]);	
				}	
			}	
		}	
	}

    printf("%d\n", dp[1][N]);    

   return 0;
}
