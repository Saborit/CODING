/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int cn, ca, sol;
bool mk[MX];
vector<int> G[MX];

int dfs(int nod){
    mk[nod] = true;
    
    int cant = 1;
    for(auto nwn: G[nod]){
	    if( !mk[nwn] )
	        cant += dfs(nwn);	
	}
	
	if( nod != 1 && cant % 2 == 0 ) sol++;
	
	return cant;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    for(int i=1, a, b; i<=ca; i++){
	    scanf("%d%d", &a, &b);
	    
	    G[a].pb(b);	
	    G[b].pb(a);	
  	}
  	
  	dfs(1); 
    
    printf("%d\n", sol);    

   return 0;
}


