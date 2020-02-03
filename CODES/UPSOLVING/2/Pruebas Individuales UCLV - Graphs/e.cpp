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
    int nwn;
    int64 cost;
    
    bool operator < (const par &p)const{
        return p.cost < cost;
    }    
};

int ca, cn, X, K, ni;
int64 dist[MX];
bool clique;
vector<par> G[MX];
priority_queue<par> Q;


void clear(){
    for(int i=1; i<=cn; i++){
        dist[i] = INF;
        G[i].clear();
    }
    while( !Q.empty() ) Q.pop(); 
    clique = false;  
}

void solve(){
    scanf("%d%d%d%d%d", &cn, &K, &X, &ca, &ni);
    
    clear();
    for(int i=1, a, b, c; i<=ca; i++){
        scanf("%d%d%d", &a, &b, &c);
        G[a].pb({b, c});
        G[b].pb({a, c});
    }    
    dist[ni] = 0ll;
    
    for(Q.push({ni, 0ll}); !Q.empty(); Q.pop()){
        int nod = Q.top().nwn;

        if( Q.top().cost > dist[nod] )
            continue;
        
        if( nod<=K && !clique ){
            for(int i=1; i<=K; i++){
                if( dist[i] > dist[nod] + X ){
                    dist[i] = dist[nod] + X;
                    Q.push({i, dist[i]});
                }
            }
            clique = true;        
        }   
        
        for(auto i: G[nod]){
            if( dist[i.nwn] > dist[nod] + i.cost ){
                dist[i.nwn] = dist[nod] + i.cost;
                Q.push({i.nwn, dist[i.nwn]});
            }    
        }
    }
    
    for(int i=1; i<=cn; i++)
       printf(i==cn ? "%lld\n" : "%lld ", dist[i]);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int T; scanf("%d", &T);
    while( T-- ){
        solve();    
    }
     
   return 0;
}


