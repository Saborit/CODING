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

int cn, ca;
int dp1[MX], dp2[MX];
bool mk[MX];
vector<int> G[MX], T[MX];

int dfs1(int nod){
	if( mk[nod] ) return dp1[nod];
	
	mk[nod] = true;
	
	if( G[nod].empty() ) dp1[nod] = 1;
	
	for(auto nwn: G[nod]) 
		dp1[nod] += dfs1(nwn);	
	
	return dp1[nod];
}

int dfs2(int nod){
	if( mk[nod] ) return dp2[nod];
	mk[nod] = true;
	
	if( nod == cn ) dp2[nod] = 1;
	
	for(auto nwn: T[nod])
		dp2[nod] += dfs2(nwn);
		
	return dp2[nod];
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d", &a, &b);
		
		T[a].pb(b);
		G[b].pb(a);
	}
	
	dfs1(cn);
	
	for(int i=1; i<=cn; i++)
	    mk[i] = false; 
    
    for(int i=1; i<=cn; i++)
		if( !mk[i] ) dfs2(i);	
	
	int sol = 0;
	for(int i=1; i<=cn; i++) for(auto j: T[i])
		sol = max(sol, dp1[i] * dp2[j]);
	
	printf("%d\n", sol);
	
   return 0;
}
