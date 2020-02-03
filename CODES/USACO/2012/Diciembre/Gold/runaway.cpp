/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
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

struct par{
	int nwn;
	int64 cost;	
};

int cn, a; 
int dp[MX], P[MX][20];
int64 L, b;
int64 dist[MX][20];
vector<par> G[MX];

void dfs0(int nod, int p){
	for(auto i: G[nod]) if( i.nwn != p ){
		P[i.nwn][0] = nod;
		dist[i.nwn][0] = i.cost;
		
		dfs0(i.nwn, nod);	
	}
}

void dfs(int nod, int p){
	for(auto i: G[nod]) if( i.nwn != p ){
		dfs(i.nwn, nod);
		dp[nod] += dp[i.nwn];	
	}	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%lld", &cn, &L);
    for(int i=2; i<=cn; i++){
		scanf("%d%lld", &a, &b); 
    
		G[a].pb({i, b});
    }
    
    dfs0(1, -1);
    
    for(int j=1; (1<<j)<=cn; j++) for(int i=1; i<=cn; i++){
			P[i][j] = P[ P[i][j-1] ][j-1];
			dist[i][j] = dist[i][j-1] + dist[ P[i][j-1] ][j-1];
	}	
	
	for(int i=1; i<=cn; i++){
		int64 l = 0, nod = i;
		
		for(int j=log2(cn); ~j; j--)
			if( P[nod][j] && l + dist[nod][j] <= L )
				l += dist[nod][j], nod = P[nod][j]; 		
		
		dp[i]++;
		dp[ P[nod][0] ]--;
	}
	
	dfs(1, -1);
	
	for(int i=1; i<=cn; i++)
		printf("%d\n", dp[i]);
	
   return 0;
}
