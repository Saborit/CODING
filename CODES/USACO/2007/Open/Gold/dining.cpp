/* Code by Saborit 
 * 
 * flows
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 605
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

struct fordfulk{
    int cn, ca, ni, nf, max_edge, f;
    int P[MX];
    int G[MX][MX];
    bool mk[MX]; 
    
    void add_edge(int a, int b, int c){
        G[a][b] = c;  
        max_edge = max(max_edge, c);   
    }
    
    bool augment(int nod, int th){
        mk[nod] = true;
        
        if( nod==nf )
            return true;
        
        int ans = false;
        for(int nwn=1; nwn<=cn; nwn++){ 
            if( !mk[nwn] && G[nod][nwn] > th ){
                P[nwn] = nod;
                ans |= augment(nwn, th);    
            }    
        }
        
        return ans;
    }
    
    void resolve(int nod, int min_edge){
        if( nod==ni ){ f = min_edge; return; }
        else{
            resolve(P[nod], min(min_edge, G[ P[nod] ][nod]));
            G[ P[nod] ][nod] -= f, G[nod][ P[nod] ] += f;    
        } 
    }
    
    int throw_flow(){
        int mf = 0, th = max_edge;    
        
        while( true ){
            for(int i=0; i<=cn; i++) 
                mk[i] = false;
                
            if( augment(ni, th) ){
                resolve(nf, INF);
                mf += f;
            }
            else if( !th ) 
                break;
            else 
                th/=2;
        }
        return mf;
    } 
}G;

int N, F, D;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &F, &D);
     
    G.ni = 0, G.nf = G.cn = D + 2*N + F;
    
    for(int i=1; i<=D; i++)
        G.add_edge(G.ni, i, 1);
    for(int i=1; i<=F; i++)
        G.add_edge(D + 2*N + i, G.nf, 1);
    for(int i=1; i<=N; i++)
        G.add_edge(D + i, D + N + i, 1);
        
    int f, d;
    for(int i=1; i<=N; i++){
        scanf("%d%d", &f, &d);
        
        for(int j=1, a; j<=f; j++){
            scanf("%d", &a);
            G.add_edge(D + N + i, D + 2*N + a, 1);    
        }
        for(int j=1, a; j<=d; j++){
            scanf("%d", &a);
            G.add_edge(a, D + i, 1);    
        }
    }
    
    printf("%d\n", G.throw_flow());      

   return 0;
}
