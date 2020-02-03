/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 5005
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

int N;
int A[MX], acum[MX];
int dp[MX][MX];

int sum(int i, int j){
    return acum[j] - acum[i-1];
}

int f(int n, int m){
    if( n > m ) return 0;
    if( dp[n][m] != -1) return dp[n][m];
    
    dp[n][m] = max(dp[n][m], sum(n, m) - f(n+1, m));
    dp[n][m] = max(dp[n][m], sum(n, m) - f(n, m-1));
    
    return dp[n][m];
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
        
    for(int i=1; i<=N; i++)
        acum[i] = acum[i-1] + A[i];    
    
    for(int i=0; i<=N+1; i++) for(int j=0; j<=N+1; j++)
        dp[i][j] = -1;
        
    printf("%d\n", f(1, N));    
        
   return 0;
}


