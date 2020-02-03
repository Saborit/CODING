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
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N, a, b;
int A[MX];
double dp[MX], best;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &a, &b); 
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
		
	sort(A+1, A+N+1);
	
	dp[0] = 0.0;
	best = -b*A[1]/2.0;
	
	for(int i=1; i<=N; i++){
		dp[i] = a + b*A[i]/2.0 + best;
		
		best = min(best, dp[i] - b*A[i+1]/2.0); 
	}
	
	//Esto es para revisar con diff
	if( fabs(dp[N] - (int)dp[N]) < EPS )
		printf("%d\n", (int)dp[N]);
	else 
		printf("%.1lf\n", dp[N]);

   return 0;
}
