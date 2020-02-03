/* Code by wizard98
 * 
 * dp
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N;
int dp[MX][2];
char A[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf(" %c", &A[i]); 
    
    for(int i=1; i<=N; i++)
        dp[i][0] = dp[i][1] = INF;
        
    for(int i=1; i<=N; i++){
	    dp[i][0] = min(dp[i][0], dp[i-1][0] + (A[i] != 'A'));	
	    dp[i][0] = min(dp[i][0], dp[i-1][1] + (A[i] != 'A') + 1);	
	
	    dp[i][1] = min(dp[i][1], dp[i-1][1] + (A[i] != 'B'));	
	    dp[i][1] = min(dp[i][1], dp[i-1][0] + (A[i] != 'B') + 1);	
	
	    dp[i][0] = min(dp[i][0], dp[i][1] + 1);	
	}  
	 	
	printf("%d\r\n", dp[N][0]);  

   return 0;
}


