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

int cn, ca, ni, nf;
int dp[MX];
bool mk[MX];
vector<int> G[MX];
queue<int> Q;
stack<int> order;

void tsort(int nod){
    mk[nod] = true;
    
    for(auto nwn: G[nod])
	    if( !mk[nwn] )
	        tsort(nwn);	
	
	order.push(nod);	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d%d", &cn, &ca, &ni, &nf);
    for(int i=1, a, b; i<=ca; i++){
	    scanf("%d%d", &a, &b);
	    G[a].pb(b);	
	}
	
	dp[ni] = 1;
	
	for(int i=1; i<=cn; i++)
	    if( !mk[i] ) tsort(i);
	
	for(; !order.empty(); order.pop()){
	    int nod = order.top();
	    
	    for(auto nwn: G[nod])
	        dp[nwn] = (dp[nod] + dp[nwn]) % MOD;	
	}    
             
    printf("%d\n", dp[nf]);    

   return 0;
}


