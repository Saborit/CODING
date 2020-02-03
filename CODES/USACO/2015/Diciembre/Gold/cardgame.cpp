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
int A[MX];
vector<int> V;
set<int> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=2 * N; i++)
        S.insert(i);
        
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        
        S.erase(A[i]);    
    } 
    
    int sol = 0;
    for(int i=1; i<=N/2; i++){
        auto it = S.lower_bound(A[i]);
        
        if( it != S.end() ){
            sol++;
            
            V.pb(*it);
            S.erase(it);    
        }    
    }
    
    sort(all(V));
    
    for(auto i: V){
        S.insert(i);
        
        auto it = S.end(); it--;
        S.erase(it);     
    }
    
    for(int i=N/2+1; i<=N; i++){
        auto it = S.lower_bound(A[i]);
        
        if( it != S.begin() ){
            it--;
            
            sol++;
            S.erase(it);    
        }   
    }
    
    printf("%d\n", sol);
       
   return 0;
}


