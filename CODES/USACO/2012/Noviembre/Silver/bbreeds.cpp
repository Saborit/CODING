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

struct state{
	int n, a, b;
	
	bool operator < (const state &p)const{
		if( n != p.n ) return n < p.n;
		if( a != p.a ) return a < p.a;
		return b < p.b;
	}
};

int N;
char S[MX];
set<state> mk;
map<state, int> dp; 
queue<state> Q;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%s", S+1);
    int N = strlen(S+1);
    
    dp[{0, 0, 0}] = 1;
    
    for(Q.push({0, 0, 0}); !Q.empty(); Q.pop()){
		int n = Q.front().n;	
		int a = Q.front().a;	
		int b = Q.front().b;	
		
		if( n == N )
			continue;
		
		int cost = S[n+1] == '(' ? 1 : -1;
		
		if( a + cost >= 0 ){
			dp[{n+1, a + cost, b}] += dp[{n, a, b}];
			dp[{n+1, a + cost, b}] %= 2012;
		
			if( mk.find({n+1, a + cost, b}) == mk.end())
				Q.push({n+1, a + cost, b});
			mk.insert({n+1, a + cost, b});
		}
		
		if( b + cost >= 0 ){
			dp[{n+1, a, b + cost}] += dp[{n, a, b}];
			dp[{n+1, a, b + cost}] %= 2012;
			
			if( mk.find({n+1, a, b + cost}) == mk.end())
				Q.push({n+1, a, b + cost});
			
			mk.insert({n+1, a, b + cost});
		}
	} 
	
	printf("%d\n", dp[{N, 0, 0}]);
	
   return 0;
}
