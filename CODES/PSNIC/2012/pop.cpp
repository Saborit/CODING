/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 300005
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

#define SIGMA 26 

struct aho_corasick{
     int cn, sz;
     int L[MX], mk[MX];
     vector<int> f;
     vector< vector<int> > T, ac; 
     
     aho_corasick(){
        cn = 1, sz = 0;
        T.pb(vector<int>(SIGMA, -1));
        f.pb(0); ac.pb(vector<int>());     
     }
     
     void add(char S[]){
         int nod = 0;
         L[++sz] = strlen(S);
         
         for(int i=0; i < L[sz]; i++){
             int c = S[i] - 'a';
             
             if( T[nod][c] == -1 ){
                 ++cn;
                 T.pb(vector<int>(SIGMA, -1));
                 f.pb(0);
                 ac.pb(vector<int>());
                 T[nod][c] = cn-1;    
             }
             nod = T[nod][c];
         }
         ac[nod].pb(sz);
     }
     
     void build(){
         queue<int> Q;
         
         for(int c=0; c < SIGMA; c++) if( T[0][c] != -1 )
              Q.push(T[0][c]);
             
         for(; !Q.empty(); Q.pop()){
             int nod = Q.front();
             
             for(int c=0; c < SIGMA; c++) if( T[nod][c] != -1 ){
                 int st = f[nod];
                 
                 while( st > 0 && T[st][c] == -1 ) st = f[st];
                 
                 if( T[st][c] != -1 )
                     st = T[st][c];
                 f[ T[nod][c] ] = st;
                 
                 for(auto i: ac[st]) ac[ T[nod][c] ].pb(i);
                 
                 Q.push(T[nod][c]);
             }     
         }      
     }
     
     int match(char A[]){
         int N = strlen(A);
         
         for(int i=0; i < N; i++)
             mk[i] = 0;
         
         for(int i=0, st=0; i < N; i++){
             int c = A[i] - 'a';
               
             while( st > 0 && T[st][c] == -1 ) st = f[st];
             
             if( T[st][c] != -1 ){
                 st = T[st][c];
                 
                 for(auto feat: ac[st]){
                     mk[i+1]--;
                     mk[ i - L[feat] + 1 ]++;     
                 }    
             }      
         }
         
         int ans = 0;
         for(int i=0; i < N; i++){
             if( i ) mk[i] += mk[i-1];
             
             if( !mk[i] ) ans++; 
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
    
    scanf("%d %s ", &N, &T); 
    scanf("%d ", &N); 
    for(int i=1; i<=N; i++){
        scanf(" %s ", &P);
        
        AC.add(P);
    }    
    
    AC.build();
    
    printf("%d\n", AC.match(T));

   return 0;
}


