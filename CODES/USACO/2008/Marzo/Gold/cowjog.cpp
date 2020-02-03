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

struct par{
	int nwn;
	int64 cost;	
	
	bool operator < (const par &p)const{
		return cost > p.cost;	
	}
};

int cn, ca, K;
bool mk[MX];
vector<int> S;
vector<par> G[MX];
multiset<int64> dp[MX];

void dfs(int nod){
	mk[nod] = true;
	
	for(auto i: G[nod]) if( !mk[i.nwn] ){
		dfs(i.nwn);	
	}	
	S.pb(nod);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &cn, &ca, &K);
    
    int64 c;
    for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d%lld", &a, &b, &c);	
		G[a].pb({b, c});	
	}
	
	dfs(cn);
	
	reverse(all(S));
	
	dp[cn].insert(0);
	for(auto nod: S){
		for(auto cost: dp[nod]){
			for(auto i: G[nod]){
				dp[i.nwn].insert(cost + i.cost);
				
				if( (int)dp[i.nwn].size() > K ){
					auto it = dp[i.nwn].end(); it--;
					dp[i.nwn].erase(it);
				}	
			} 	
		}	
	}
	
	int k = 1;
	for(auto i: dp[1]){ 
		printf("%lld\n", i);
		k++;
	}
	for(; k<=K; k++) printf("-1\n");
			
   return 0;
}
