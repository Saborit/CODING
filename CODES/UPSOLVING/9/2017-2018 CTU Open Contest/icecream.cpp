/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 1000005
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

struct counter{
    int diff, count;
    int C[MX];  
    
    void clear(){
        diff = count = 0;
        for(int i=0; i<=MX; i++) 
            C[i] = 0;    
    } 
    
    void add(vector<int>& V){
        count += V.size();
            
        for(auto a: V){
            if( C[a]++ == 0 )
                diff++;
        }     
    }
    
    void erase(vector<int>& V){
        count -= V.size();
            
        for(auto a: V){
            if( --C[a] == 0 )
                diff--;
        }     
    }
};

int N, K, M;
vector<int> A[2*MX];
counter C;

void solve(){
    C.clear();
    
    for(int i=1; i<=N; i++){
        A[i].clear();
        A[i+N].clear();
        
        scanf("%d", &M);
        
        for(int j=1, a; j<=M; j++){
            scanf("%d", &a);
            A[i].pb(a);    
            A[i+N].pb(a);
        }
    }
    
    int sol = INF;
    for(int l=1, r=0; l<=N; l++){
        while( r<=l+N && C.diff < K ){
            r++;
            C.add(A[r]);
        }
        
        if( r<=l+N && C.diff >= K )
            sol = min(sol, C.count);
        
        C.erase(A[l]);
    }
    
    
    printf(sol==INF ? "-1\n" : "%d\n", sol);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    while(scanf("%d%d", &N, &K) == 2 )
        solve();    
       
   return 0;
}
