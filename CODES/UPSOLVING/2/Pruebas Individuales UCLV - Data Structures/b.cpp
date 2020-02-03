/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 3000005
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

struct trie{
    int C[MX];
    vector< vector<int> > T;
    
    trie(){
         T.pb(vector<int>(26, -1));   
    }
    
    void add(string S){
        int nod = 0;
        C[nod]++;
         
        for(int i=0; i < (int)S.size(); i++){
            int c = S[i] - 'a';
            
            if( T[nod][c] == -1 ){
                T[nod][c] = T.size();
                T.pb(vector<int>(26, -1));    
            }
            nod = T[nod][c];
            C[nod]++;  
        }
    }
    
    int find(string S){
        int nod = 0;
        
        for(int i=0; i < (int)S.size(); i++){
            int c = S[i] - 'a';
            
            if( T[nod][c] == -1 )
                return 0;
            else nod = T[nod][c];         
        }
        return C[nod];    
    }
}T;

int N;
string ord, feat;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    cin >> N; 
    for(int i=1; i<=N; i++){
        cin >> ord >> feat;
        
        if( ord[0] == 'a' )
            T.add(feat);
        else printf("%d\n", T.find(feat));    
    }
        
   return 0;
}
