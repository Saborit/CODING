/* Code by Saborit 
 * 
 * dp
 * */
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

int N;
int A[MX];
int64 dp[MX][MX];

int rest(int a, int b){ return N - b + a; }

int64 f(int a, int b){
	if( a > b ) return 0;
	if( dp[a][b] != -1 ) return dp[a][b];
	
	dp[a][b] = f(a+1, b) + (int64)A[a] * rest(a, b);
	dp[a][b] = max(dp[a][b], f(a, b-1) + (int64)A[b] * rest(a, b));
	
	return dp[a][b];	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    
    for(int i=0; i<=N+1; i++) for(int j=0; j<=N+1; j++)
		dp[i][j] = -1;
        
    printf("%lld\n", f(1, N)); 

   return 0;
}
