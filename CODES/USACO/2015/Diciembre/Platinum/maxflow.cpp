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

int cn, Q, sol;
int C[MX], dp[MX];
vector<int> G[MX]; 

struct lca{
	int cn;
	vector<int>L;
	vector<vector<int>> P;
	
	lca(int cn): 
		cn(cn), L(cn+1), P(cn+1, vector<int>(20, 0))
	{
		L[1] = 1;
		dfs(1, -1);
		
		for(int j=1; j<=log2(cn); j++)
			for(int i=1; i<=cn; i++)
				P[i][j] = P[ P[i][j-1] ][j-1];
	}
	
	void dfs(int nod, int p){
		for(auto nwn: G[nod]) if( nwn != p ){
			P[nwn][0] = nod;
			L[nwn] = L[nod] + 1;	
			dfs(nwn, nod);
		}	
	}
	
	int query(int a, int b){
		if( L[a] < L[b] ) swap(a, b);
		
		for(int i=log2(L[a]); ~i; i--)
			if( P[a][i] && L[ P[a][i] ] >= L[b] )
				a = P[a][i];
		if( a==b ) return a;
		
		for(int i=log2(L[a]); ~i; i--)
			if( P[a][i] && P[a][i] != P[b][i] )
				a = P[a][i], b = P[b][i];		
		return P[a][0];	
	}
};

void dfs(int nod, int p){
	dp[nod] = C[nod];
	
	for(auto nwn: G[nod]) if( nwn != p ){
		dfs(nwn, nod);
		dp[nod] += dp[nwn];
	}
	
	sol = max(sol, dp[nod]); 	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &Q);
    for(int i=1, a, b; i < cn; i++){
		scanf("%d%d", &a, &b);
		
		G[a].pb(b);
		G[b].pb(a);
	}
	
	lca LCA(cn); 
	
	int a, b;
	while( Q-- ){
		scanf("%d%d", &a, &b);
		
		C[a]++, C[b]++;
		
		int l = LCA.query(a, b);
		
		C[l]--, C[ LCA.P[l][0] ]--;	
	}
	
	dfs(1, -1);	
    
    printf("%d\n", sol);    

   return 0;
}
