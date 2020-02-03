/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 405
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

int cn, ca;
int dist[MX][MX], T[MX][MX];
bool mk[MX];
vector<par> G[MX];
priority_queue<par> Q;

void dijkstra(int ni){
    for(Q.push({ni, 0}); !Q.empty(); Q.pop()){
	    int nod = Q.top().nwn;
	    
	    for(auto i: G[nod]){
		    if( dist[ni][i.nwn] > dist[ni][nod] + i.cost ){
				dist[ni][i.nwn] = dist[ni][nod] + i.cost;
				Q.push({i.nwn, dist[ni][i.nwn]});
			}	
		}	
	}	
}


int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);
		T[a][b] = c;
	}
	
	for(int i=1; i<=cn; i++){
	    for(int j=1; j<=cn; j++){
		    if( T[i][j] > 0 )
		        G[i].pb({j, T[i][j]});
    
		    dist[i][j] = INF;	
		}
		dist[i][i] = 0;	
	}
	
	for(int ni=1; ni<=cn; ni++)
	    dijkstra(ni);
    
	int Q, a, b;
	scanf("%d", &Q);
	while( Q-- ){
	    scanf("%d%d", &a, &b);
	    
	    printf(dist[a][b] < INF ? "%d\n" : "-1\n", dist[a][b]);	
	}
	
    return 0;
}


