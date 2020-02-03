/* Code by Saborit 
 * 
 * lca trees geometry
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

int X[MX], Y[MX];

struct edge{
    int id, nwn, cost;
    char dir;    
};

inline char op(char c){
    if( c == 'E' ) return 'W';    
    if( c == 'W' ) return 'E';    
    if( c == 'N' ) return 'S';    
    if( c == 'S' ) return 'N';  
    return ' ';  
}

inline int dist(int i, int j){ return abs(X[i] - X[j]) + abs(Y[i] - Y[j]); }

int cn, ca;

struct graph{
    int cn, ca;
    int M[MX][20], L[MX], P[MX][20];
    bool mk[MX];
    vector<edge> G[MX];

    void add_edge(int a, int b, int c, char d, int t){
        G[a].pb({t, b, c, d});
        G[b].pb({t, a, c, op(d)});   
    }
    
    void build(){
        dfs(1);  
        
        for(int j=1, l=log2(cn); j<=l; j++)
            for(int i=1; i<=cn; i++)    
                P[i][j] = P[ P[i][j-1] ][j-1],
                M[i][j] = max(M[i][j-1], M[ P[i][j-1] ][j-1]);
    }
    
    void dfs(int nod){
        mk[nod] = true;
        
        for(auto i: G[nod]) if( !mk[i.nwn] ){
            P[i.nwn][0] = nod;
            L[i.nwn] = L[nod] + 1;
            M[i.nwn][0] = i.id;
            
            if( i.dir  == 'E' )
                X[i.nwn] = X[nod] + i.cost, Y[i.nwn] = Y[nod];
            else if( i.dir  == 'W' )
                X[i.nwn] = X[nod] - i.cost, Y[i.nwn] = Y[nod];
            else if( i.dir  == 'N' )
                X[i.nwn] = X[nod], Y[i.nwn] = Y[nod] + i.cost;
            else if( i.dir  == 'S' )
                X[i.nwn] = X[nod], Y[i.nwn] = Y[nod] - i.cost;
            
            dfs(i.nwn);    
        }    
    }
    
    int query(int a, int b){
       int ans = -INF;
       
       if( L[a] < L[b] ) swap(a, b);
       
       for(int i=log2(L[a]); i>=0; i--)
           if( L[ P[a][i] ] >= L[b]  ){ 
               ans = max(ans, M[a][i]);
               a = P[a][i];
       }
           
       if( a==b ) return ans;
       
       for(int i=log2(L[a]); i>=0; i--)
           if( P[a][i] && P[a][i] != P[b][i] )
               ans = max(ans, M[a][i]),
               ans = max(ans, M[b][i]),
               a = P[a][i], b = P[b][i];
       
       ans = max(ans, M[a][0]);               
       ans = max(ans, M[b][0]);
                      
       return ans;        
    }
}G;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &G.cn, &G.ca);
    for(int i=1; i<=G.ca; i++){
        int a, b, c;
        char d;
        
        scanf("%d%d%d %c ", &a, &b, &c, &d);
        G.add_edge(a, b, c, d, i);
    }   
    
    G.build();
    
    int Q, a, b, c; scanf("%d", &Q);
    
    while( Q-- ){
        scanf("%d%d%d", &a, &b, &c);
        
        printf("%d\n", G.query(a, b) > c ? -1 : dist(a, b));    
    }  
    
   return 0;
}
