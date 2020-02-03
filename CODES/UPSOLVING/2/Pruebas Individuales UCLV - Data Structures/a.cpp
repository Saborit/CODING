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

int N;
bool mk[MX];
vector<int> G[MX];

int dfs(int nod){
   mk[nod] = true;
   
   int ans = 1;
   for(auto nwn: G[nod]) if( !mk[nwn] ){
       ans += dfs(nwn);
   }    
   
   return ans; 
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N); 
    for(int i=1, a, b; i<=N; i++){
        scanf("%d%d", &a, &b);
        
        G[a].pb(b);    
        G[b].pb(a);    
    }
    
    int mi = INF, ma=-INF;
    for(int i=1; i<=2*N; i++){
        if( !mk[i] ){
            int cant = dfs(i);
            if( cant > 1 ){
                mi = min(mi, cant);    
                ma = max(ma, cant);
            }    
        }    
    }
    
    printf("%d %d\n", mi, ma);        

   return 0;
}
