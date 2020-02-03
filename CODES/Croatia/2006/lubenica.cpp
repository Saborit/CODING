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

struct edge{
    int nwn, cost;  
};

struct graph{
    int cn;
    int L[MX], P[MX][20], may[MX][20], men[MX][20];
    bool mk[MX];
    vector<edge> G[MX];
    
    void add_edge(int a, int b, int c){
        G[a].pb({b, c});    
        G[b].pb({a, c});    
    }
    
    void build(){
        dfs(1);
        
        for(int j=1, l=log2(cn); j<=l; j++)
            for(int i=1; i<=cn; i++)
                P[i][j] = P[ P[i][j-1] ][j-1],
                men[i][j] = min(men[i][j-1], men[ P[i][j-1] ][j-1]),
                may[i][j] = max(may[i][j-1], may[ P[i][j-1] ][j-1]); 
    }
    
    void dfs(int nod){
        mk[nod] = true;
        
        for(auto i: G[nod]) if( !mk[i.nwn] ){
            P[i.nwn][0] = nod;
            L[i.nwn] = L[nod] + 1;
            men[i.nwn][0] = may[i.nwn][0] = i.cost;
            
            dfs(i.nwn); 
        }    
    }
    
    pair<int, int> query(int a, int b){
       int ans_min = INF, ans_max = -INF;
       
       if( L[a] < L[b] ) swap(a, b);
       
       for(int i=log2(L[a]); i>=0; i--)
           if( P[a][i] && L[ P[a][i] ] >= L[b] ){
               ans_min = min(ans_min, men[a][i]);      
               ans_max = max(ans_max, may[a][i]);
               a = P[a][i];
           }
           
        if( a==b ) return {ans_min, ans_max};
           
        for(int i=log2(L[a]); i>=0; i--)
            if( P[a][i] && P[a][i] != P[b][i] ){
                ans_min = min(ans_min, men[a][i]);    
                ans_min = min(ans_min, men[b][i]);    
                ans_max = max(ans_max, may[a][i]);    
                ans_max = max(ans_max, may[b][i]);
                a = P[a][i], b = P[b][i];    
            } 
        ans_min = min(ans_min, men[a][0]);    
        ans_min = min(ans_min, men[b][0]);    
        ans_max = max(ans_max, may[a][0]);    
        ans_max = max(ans_max, may[b][0]);    
            
        return {ans_min, ans_max};        
    }
}G;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &G.cn);
    for(int i=1, a, b, c; i < G.cn; i++){
        scanf("%d%d%d", &a, &b, &c);
        
        G.add_edge(a, b, c);
    }
    
    G.build();
    
    int Q, a, b; scanf("%d", &Q);
    
    while( Q-- ){
        scanf("%d%d", &a, &b);
        
        auto sol = G.query(a, b);
        
        printf("%d %d\n", sol.fr, sol.sc);    
    }  
        
   return 0;
}
