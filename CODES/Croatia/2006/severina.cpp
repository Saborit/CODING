/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 300005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1337377
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

int dp[MX], L[MX];

#define SIGMA 26

struct aho_corasick{
     int cn, sz;
     int F[MX];
     vector<int> T[MX], ac[MX];
     
     aho_corasick(){
        cn = 1, sz = 0;
        T[0] = vector<int>(SIGMA, -1);
     }
     
     void add(char S[]){
         int nod = 0;
         int N = strlen(S);
         sz++;
         
         for(int i=0; i < N; i++){
             int c = S[i] - 'a';
             
             if( T[nod][c] == -1 ){
                 T[++cn] = vector<int>(SIGMA, -1);
                 T[nod][c] = cn; 
             }
             nod = T[nod][c];
         }
         ac[nod].pb(sz);
     }
     
     void build(){
         queue<int> Q;
         for(int c=0; c < SIGMA; c++) if( T[0][c] != -1 )
             Q.push(T[0][c]);
             
         for(; !Q.empty(); Q.pop() ){
             int nod = Q.front();
             
             for(int c=0; c < SIGMA; c++) if( T[nod][c] != -1 ){
                 int st = F[nod];
                 
                 while( st > 0 && T[st][c] == -1 ) st = F[st];
                 
                 if( T[st][c] != -1 ) 
                     st = T[st][c];
                 F[ T[nod][c] ] = st;
                 
                 for(auto i: ac[st]) ac[ T[nod][c] ].pb(i);
                 
                 Q.push(T[nod][c]);        
             }    
         }       
     }
     
     vector< pair<int, int> > match(char A[]){
         int N = strlen(A);
         vector< pair<int, int> > ans;
          
         for(int i=0, st=0; i < N; i++){
             int c = A[i] - 'a';
             
             while( st > 0 && T[st][c] == -1 ) st = F[st];
             
             if( T[st][c] != -1 ){
                 st = T[st][c];
                 
                 for(auto feat: ac[st]){ 
                     ans.pb({feat, i});
                 
                     dp[i+1] = (dp[i+1] + dp[i - L[feat] + 1]) % MOD;
                 }    
             }        
         }
         
         return ans;    
     }
};

int N;
char T[MX], P[MX];
aho_corasick AC;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%s %d ", &T, &N);
    for(int i=1; i<=N; i++){
        scanf("%s ", &P);
        
        AC.add(P);
        L[i] = strlen(P);
    }    
    
    AC.build();
    
    dp[0] = 1;
    
    auto v = AC.match(T);
    
    printf("%d\n", dp[strlen(T)]);
    
   return 0;
}
