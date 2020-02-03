/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 2000005
#define INF (1ll<<62)
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

int N, h;
int W[25], H[25], S[25];
int64 sumH[MX], sumW[MX], dp[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &h);
    for(int i=0; i < N; i++)
		scanf("%d%d%d", &H[i], &W[i], &S[i]);
		
	for(int i=1;i < (1<<N); i++){
		int lsb = i & (-i);
		
		sumW[i] = sumW[i - lsb] + W[31 - __builtin_clz(lsb)];
		sumH[i] = sumH[i - lsb] + H[31 - __builtin_clz(lsb)];
	}
	
	dp[0] = INF;
	for(int i=1; i < (1<<N); i++)
		dp[i] = -INF;
	
	
	for(int mask=1; mask < (1<<N); mask++){
		for(int i=0; i < N; i++){
			if( (mask & (1<<i)) && S[i] - sumW[mask - (1<<i)] >= 0 )
				dp[mask] = max(dp[mask], 
					min(S[i] - sumW[mask - (1<<i)], dp[mask - (1<<i)]));	
		}	
	}
	
	int64 sol = -1;
	for(int i=1; i < (1<<N); i++)
		if( sumH[i] >= h ) 
			sol = max(sol, dp[i]);
	
	printf(~sol ? "%lld\n" : "Mark is too tall\n", sol);
	
   return 0;
}
