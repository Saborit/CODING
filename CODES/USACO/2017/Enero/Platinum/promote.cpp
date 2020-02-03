/* Code by Saborit 
 * 
 * trees wavelet_tree euler_tour
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

struct wavelet_tree{
    int lo, hi;
    vector<int> v;
    wavelet_tree *L, *R;
    
    wavelet_tree(){}
    wavelet_tree(int *x, int *xend, int a, int b){
        lo = a, hi = b;
        
        if( lo==hi || x>=xend ) return;
        
        int m = (lo+hi)/2;
        auto f = [m](int p){ return p < m; };
        v.reserve(xend - x + 1); v.pb(0);
        
        for(auto it=x; it!=xend; it++)
            v.pb(v.back() + f(*it));
            
        auto pivot = stable_partition(x, xend, f);
        L = new wavelet_tree(x, pivot, a, m);    
        R = new wavelet_tree(pivot, xend, m+1, b);    
    }  
    
    int lte(int a, int b, int k){
        if( a > b || k < lo ) return 0;
        if( hi<=k ) return b - a + 1;
        
        return L->lte(v[a-1]+1, v[b], k) + R->lte(a - v[a-1], b - v[b], k);    
    }
    
    int great(int a, int b, int k){
        return b - a + 1 - lte(a, b, k);    
    }
};

struct graph{
    int cn, N;
    int A[MX], T[2*MX], L[MX], R[MX];
    vector<int> G[MX];
    wavelet_tree WT;
    
    graph(): WT(){}
    
    void add_edge(int a, int b){
        G[a].pb(b);
        G[b].pb(a);
    }   
    
    void dfs(int nod, int p){
        T[++N] = A[nod];
        L[nod] = N;
        
        for(auto nwn: G[nod]) if( nwn != p )
            dfs(nwn, nod);    
        
        T[++N] = A[nod];
        R[nod] = N;
    }
    
    void build(){
        dfs(1, -1);
        
        WT = wavelet_tree(T+1, T+N+1, 1, 1e9);    
    }
    
    int query(int nod){
        return WT.great(L[nod]+1, R[nod]-1, A[nod]) / 2;
    }
};

graph G;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &G.cn);
    for(int i=1; i<=G.cn; i++)
        scanf("%d", &G.A[i]);
    for(int i=2, a; i<=G.cn; i++){
        scanf("%d", &a);
        
        G.add_edge(i, a);    
    } 
    
    G.build();
    
    for(int i=1; i<=G.cn; i++)
        printf("%d\n", G.query(i));
    
    return 0;
}


