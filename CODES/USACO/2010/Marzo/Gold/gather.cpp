/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
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

struct par{
	int nwn, cost;
};

int cn;
int64 sol = INF, sum;
int A[MX], sz[MX], dist[MX];
vector<par> G[MX];

int dfs1(int nod, int p){
	sz[nod] = A[nod];
	
	for(auto i: G[nod]) if( i.nwn != p ){
	    dist[i.nwn] = dist[nod] + i.cost;
	    sz[nod] += dfs1(i.nwn, nod);
	}	
	
	return sz[nod];
}

void dfs(int nod, int p, int64 sum){
	sol = min(sol, sum);
	
	for(auto i: G[nod]) if( i.nwn != p ){
	    dfs(i.nwn, nod, sum + (int64)i.cost * (sz[1] - 2 * sz[i.nwn]));	
	}
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &cn);
    for(int i=1; i<=cn; i++)
		scanf("%d", &A[i]);
	for(int i=1, a, b, c; i < cn; i++){
		scanf("%d%d%d", &a, &b, &c);
		
		G[a].pb({b, c});	
		G[b].pb({a, c});	
	}	
	
	dfs1(1, -1);
		
    for(int i=1; i<=cn; i++){
		sum += (int64) dist[i] * A[i];
	}
	
	dfs(1, -1, sum);
	
	printf("%lld\n", sol);			

   return 0;
}
