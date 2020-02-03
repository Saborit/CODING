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

int N, M;
int dp[MX], W[MX], D[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
		scanf("%d%d", &W[i], &D[i]);
		
	for(int i=1; i<=N; i++)
		for(int j=M; j>=W[i]; j--)
			dp[j] = max(dp[j], dp[j - W[i]] + D[i]);
		
	int sol = 0;	
	for(int i=1; i<=M; i++)
		sol = max(sol, dp[i]);
			
	printf("%d\n", sol);

   return 0;
}
