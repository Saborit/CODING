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

int cn, ca;
bool mk[MX][MX];
vector<int> G[MX];

void dfs(int ni, int nod){
	mk[ni][nod] = true;
	
	for(auto nwn: G[nod]) if( !mk[ni][nwn] )
	    dfs(ni, nwn);	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d", &a, &b);
		G[a].pb(b);
	}
	
	for(int i=1; i<=cn; i++)
	    dfs(i, i); 
    
    int sol = 0;
    for(int i=1; i<=cn; i++) for(int j=i+1; j<=cn; j++)
		sol += !(mk[i][j] || mk[j][i]);
	
	printf("%d\n", sol);		

   return 0;
}
