/* Code by Saborit
 * 
 * dp
 *  */
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

inline bool beats(int a, int b){ return (a+1)%3==b; }

int N, K;
int A[MX], dp[MX][25][3];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d\n", &N, &K);
    char a;
    for(int i=1; i<=N; i++){
        scanf("%c ", &a);
        
        if( a == 'H' ) A[i] = 0;
        else if( a == 'S' ) A[i] = 1;
        else if( a == 'P' ) A[i] = 2;
    }
    
    dp[1][0][ (A[1]+2)%3 ] = 1;
    
    for(int n=2; n<=N; n++){
        for(int k=0; k<=K; k++){
            for(int t=0; t < 3; t++){
                for(int tt=0; tt < 3; tt++){
                    if( k && tt!=t )
                        dp[n][k][t] = max(dp[n][k][t], dp[n-1][k-1][tt] + beats(t, A[n]));
                    else if( t==tt )    
                        dp[n][k][t] = max(dp[n][k][t], dp[n-1][k][tt] + beats(t, A[n]));
                }    
            }    
        }
    }
    
    int sol = -INF;
    for(int i=0; i<=K; i++)
        for(int j=0; j < 3; j++)
            sol = max(sol, dp[N][i][j]);
    
    printf("%d\n", sol);
     
   return 0;
}
