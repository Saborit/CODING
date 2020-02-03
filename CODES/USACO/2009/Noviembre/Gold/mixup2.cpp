/* Code by Saborit 
 * 
 * dp bitmasks
 * */
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
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N, K;
int A[25];
int64 dp[MX][25];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for(int i=0; i < N; i++)
        scanf("%d", &A[i]);
    
    for(int i=0; i < N; i++)
        dp[(1<<i)][i] = 1ll;    
             
    for(int mask=1; mask < (1<<N); mask++){
        for(int n=0; n < N; n++) if( mask & (1<<n) ){
            for(int i=0; i < N; i++) if( (mask & (1<<i)) && i!=n ){
                if( abs(A[n] - A[i]) > K )
                    dp[mask][n] += dp[mask - (1<<n)][i];    
            }    
        }    
    }
    
    int64 sol = 0ll;
    for(int i=0; i < N; i++)     
        sol += dp[(1<<N)-1][i];
        
    printf("%lld\n", sol);
        
   return 0;
}
