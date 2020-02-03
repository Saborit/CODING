/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000
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

int N, max_value;
int A[MX], dp[5 * MX], mk[5 * MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		max_value += A[i];	
	}
	
	dp[0] = mk[0] = 1;
	for(int i=1; i<=N; i++){
		for(int j=max_value; j>=A[i]; j--)
			dp[j] = (dp[j] + dp[j - A[i]]) % MOD,
			mk[j] = mk[j] | mk[j - A[i]];
	}
    	
    pair<int, int> best = {0, -INF};
    for(int i=1; 2*i<=max_value; i++)
		if( mk[i] ) best = max(best, {i, dp[i]});
    
    printf("%d\n%d\n", max_value - 2*best.fr, best.sc);    

   return 0;
}
