/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 305
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
	int nwn, cost;
	
	bool operator < (const par &p)const{
		return cost > p.cost;
	}
};

int cn, ca, q;
int dp[MX][MX];
vector<par> G[MX];
priority_queue<par> Q;

void prim(int ni){
	for(int i=1; i<=cn; i++)
		dp[ni][i] = INF;
	dp[ni][ni] = 0;
	
	for(Q.push({ni, 0}); !Q.empty(); ){
		int nod = Q.top().nwn;
		Q.pop();
		
		for(auto i: G[nod]){
			if( dp[ni][i.nwn] > max(dp[ni][nod], i.cost)){
				dp[ni][i.nwn] = max(dp[ni][nod], i.cost);
				Q.push({i.nwn, dp[ni][i.nwn]});
			}
		}
	}	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &cn, &ca, &q);
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);
		G[a].pb({b, c});
	}
	
	for(int i=1; i<=cn; i++)
	    prim(i);
    
	int a, b;
	while( q-- ){
		scanf("%d%d", &a, &b);
		
		printf(dp[a][b] == INF ? "-1\n" : "%d\n", dp[a][b]);	
	}
	 
   return 0;
}
