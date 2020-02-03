/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 55
#define INF (1ll<<62)
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

#define POSSIBLE X > 0 && X<=N && Y > 0 && Y<=N

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int N, a, b;
int A[MX][MX];
int64 dp[MX][MX];
queue<pair<int, int>> Q;

int64 bfs(int xi, int yi){
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		dp[i][j] = INF;
	dp[xi][yi] = 0;
	
	for(Q.push({xi, yi}); !Q.empty(); Q.pop()){
		int x = Q.front().fr;	
		int y = Q.front().sc;
		
		for(int i=0; i < 4; i++){
			int X = x + dx[i];	
			int Y = y + dy[i];
			
			int cost = (A[X][Y] == A[x][y]) ? a : b;
			
			if( POSSIBLE && dp[X][Y] > dp[x][y] + cost ){	
				dp[X][Y] = dp[x][y] + cost;
				Q.push({X, Y});
			}
		}	
	}
	
	int64 ans = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		ans = max(ans, dp[i][j]);
	
	return ans;
}  

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &a, &b);
    char c;
    for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			scanf(" %c", &c);
			
			A[i][j] = (c == '(') ? 1 : 0;	
		}
	
	int64 sol = 0;
	
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
        sol = max(sol, bfs(i, j));		
	
	printf("%lld\n", sol);
	
   return 0;
}
