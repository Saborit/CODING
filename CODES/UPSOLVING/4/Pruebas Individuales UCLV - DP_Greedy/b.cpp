/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 205
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

int K, a, b; 
char A[MX];
bool dp[MX][MX];
pair<int, int> P[MX][MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &K, &a, &b);
    scanf(" %s", A+1);
    
    int N = strlen(A+1);
    
    dp[0][0] = true;
    
    for(int n=1; n<=N; n++){
        for(int k=1; k<=K; k++){
            for(int i=n-b; i<=n-a; i++){
                if( i>=0 && dp[i][k-1] ){
                    dp[n][k] = true;
                    P[n][k] = {i, k-1};    
                }    
            }    
        }    
    }
    
    if( !dp[N][K] )
        return !printf("No solution\n");
        
    vector<int> sol;
    
    int i=N, j=K;
    while( i || j ){
        sol.pb(i);
        
        auto now = P[i][j];
        i = now.fr, j = now.sc;            
    } 
    
    sort(all(sol));
    
    for(int i=1, st=0; i<=N; i++){
        printf("%c", A[i]);
        
        if( i == sol[st] ){ 
            printf("\n");    
            st++;
        }
    }  
    
   return 0;
}
