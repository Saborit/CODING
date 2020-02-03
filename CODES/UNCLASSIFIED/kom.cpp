/* Code by Saborit 
 * 
 * lca trees
 * */
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

struct par{
    int nwn, cost;    
};

struct lca_tree{
    int cn;
    int L[MX], P[MX][20];
    bool mk[MX];
    int64 dist[MX];
    vector<par> G[MX];
    
    void add_edge(int a, int b, int c){
        G[a].pb({b, c});    
        G[b].pb({a, c});    
    }
    
    void dfs(int nod){
        mk[nod] = true;
        
        for(auto i: G[nod]) if( !mk[i.nwn] ){
            P[i.nwn][0] = nod;
            L[i.nwn] = L[nod] + 1;
            dist[i.nwn] = dist[nod] + i.cost;
                
            dfs(i.nwn);    
        }    
            
    }
    
    void build(){
        dist[1] = 0ll, L[1] = 1;
        
        dfs(1);
        
        for(int j=1, l=log2(cn); j<=l; j++)
            for(int i=1; i<=cn; i++)
                P[i][j] = P[ P[i][j-1] ][j-1];        
    }
    
    int query(int a, int b){
        if( L[b] > L[a] )
            swap(a, b);
        for(int i=log2(L[a]); i>=0; i--)
            if( L[ P[a][i] ] >= L[b] ) a = P[a][i];    
        if( a==b )
            return a;
            
        for(int i=log2(L[a]); i>=0; i--)
            if( P[a][i] && P[a][i] != P[b][i] )
                a = P[a][i], b = P[b][i];
        return P[a][0];
    }
    
    int64 shortest_path(int a, int b){
        return dist[a] + dist[b] - 2ll * dist[query(a, b)];
    }        
};

lca_tree G;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &G.cn);
    for(int i=1, a, b; i < G.cn; i++){
        scanf("%d%d", &a, &b);
        
        G.add_edge(a, b, 1);    
    }
    
    G.build();
     
    int cant, last, a, sol = 0; 
    scanf("%d%d", &cant, &last);    
    for(int i=1; i < cant; i++){
        scanf("%d", &a);
        
        sol += G.shortest_path(a, last);
        last = a;    
    }
        
    printf("%d\n", sol);
    
   return 0;
}


