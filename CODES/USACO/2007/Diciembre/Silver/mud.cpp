/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1005
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

#define POSSIBLE X > 0 && Y > 0 && X<=x_max && Y<=y_max
const int DEL = 501, x_max = 1001, y_max = 1001;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int N, x_b, y_b;
int dp[MX][MX];
char T[MX][MX];
queue<pair<int, int>> Q;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &x_b, &y_b, &N);
    x_b += DEL, y_b += DEL;
    
    for(int i=1, a, b; i<=N; i++){
		scanf("%d%d", &a, &b);
		a += DEL, b += DEL;
		
		T[a][b] = 'M';
	} 
	
	for(int i=1; i<=x_max; i++) for(int j=1; j<=y_max; j++)
        dp[i][j] = INF;
    dp[DEL][DEL] = 0;
	
	for(Q.push({DEL, DEL}); !Q.empty(); Q.pop()){
		int x = Q.front().fr;	
		int y = Q.front().sc;
		
		for(int i=0; i < 4; i++){
			int X = x + dx[i];	
			int Y = y + dy[i];	
			
			if( POSSIBLE && T[X][Y] != 'M' && dp[X][Y] > dp[x][y] + 1 ){
				dp[X][Y] = dp[x][y] + 1;
				Q.push({X, Y});	
			}
		}	
	}
	
	printf("%d\n",dp[x_b][y_b]);
	
   return 0;
}
