/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 105
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

struct edge{ int a, b, c; };

#define LOG 22

int N, cn, ca, ni, nf;
int G[MX][MX];
int64 dist[MX][MX][25], dp[MX][25];
vector<int> values;
vector<edge> g;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d%d", &N, &ca, &ni, &nf);
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);
		
		g.pb({b, c, a});
		values.pb(b);	
		values.pb(c);	
	} 
	
	values.pb(ni);
	values.pb(nf);
    
    sort(all(values));
    unique(values);
    
    cn = values.size();
    ni = lower_bound(all(values), ni) - values.begin() + 1;    
    nf = lower_bound(all(values), nf) - values.begin() + 1;
    
    int nod, nwn;
    for(auto i: g){
		nod = lower_bound(all(values), i.a) - values.begin() + 1;    
		nwn = lower_bound(all(values), i.b) - values.begin() + 1;
		    
		G[nod][nwn] = G[nwn][nod] = i.c;	
	}
	
	for(int p=0; p<=LOG; p++)
		for(int i=1; i<=cn; i++) for(int j=1; j<=cn; j++)
			dist[i][j][p] = (!p && G[i][j]) ? G[i][j] : INF;
        
    for(int p=1; p<=LOG; p++)
		for(int i=1; i<=cn; i++) for(int j=1; j<=cn; j++)
			for(int k=1; k<=cn; k++)
			    dist[i][j][p] = min(dist[i][j][p], dist[i][k][p-1] + dist[k][j][p-1]); 
	
	for(int i=1; i<=cn; i++)
		dp[i][0] = INF;
	dp[ni][0] = 0;	
	
	if( N & 1 )
		for(int i=1; i<=cn; i++)
			dp[i][0] = dist[ni][i][0];
		
	for(int p=1; p<=LOG; p++){
		for(int i=1; i<=cn; i++)
			dp[i][p] = INF;
			
		if( N & (1<<p) ){
			for(int i=1; i<=cn; i++) for(int j=1; j<=cn; j++)
				dp[j][p] = min(dp[j][p], dp[i][p-1] + dist[i][j][p]);
		}
		else{
			for(int i=1; i<=cn; i++)
				dp[i][p] = dp[i][p-1];	
		}	
	}
	
	printf("%lld\n", dp[nf][LOG]);
	
   return 0;
}
