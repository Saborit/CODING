/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 205
#define INF (1<<30)
#define EPS 1e-9
#define MOD 100000
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N;
bool big = false;
int64 dp[MX][MX];
char S[MX];

int cost(int a, int b){
	if( S[a] == '?' && S[b] == '?') return 3;	
	if( S[a] == '(' && S[b] == '?') return 1;	
	if( S[a] == '[' && S[b] == '?') return 1;	
	if( S[a] == '{' && S[b] == '?') return 1;	
	
	if( S[a] == '?' && S[b] == ')') return 1;	
	if( S[a] == '?' && S[b] == ']') return 1;	
	if( S[a] == '?' && S[b] == '}') return 1;	
	
	if( S[a] == '(' && S[b] == ')') return 1;	
	if( S[a] == '[' && S[b] == ']') return 1;	
	if( S[a] == '{' && S[b] == '}') return 1;
	else return 0;	
}

int64 f(int a, int b){
	if( a > b ) return 1ll;
	
	if( dp[a][b] >= 0 ) return dp[a][b];
	
	dp[a][b] = 0ll;
	for(int i=a+1; i<=b; i+=2){
		dp[a][b] += f(a+1, i-1) * cost(a, i) * f(i+1, b);
		
		if( dp[a][b] >= MOD )
			big = true;
			
		dp[a][b] %= MOD;
	}
	
	return dp[a][b];
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d %s", &N, S+1);  
    
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++){
		dp[i][j] = -1;
	}
	
	string sol = to_string(f(1, N));
	
	while( big && (int)sol.size() < 5 )
		sol = "0" + sol;
	
	printf("%s\n", sol.c_str()); 
	 
   return 0;
}
