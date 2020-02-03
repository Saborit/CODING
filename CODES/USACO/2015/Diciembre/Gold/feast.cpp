/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 5000005
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

int N, A, B;
bool dp[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &A, &B); 
    
    dp[0] = true;
    for(int i=A; i<=N; i++)
		dp[i] |= dp[i-A];	
	for(int i=B; i<=N; i++)
		dp[i] |= dp[i-B];
	
	for(int i=1; i<=N; i++)
		dp[i/2] |= dp[i];
	
	for(int i=A; i<=N; i++)
		dp[i] |= dp[i-A];	
	for(int i=B; i<=N; i++)
		dp[i] |= dp[i-B];
	
	for(int i=N; i>=0; i--)
		if( dp[i] )
			return !printf("%d\n", i);
	
   return 0;
}
