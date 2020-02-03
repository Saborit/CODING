/* Code by Saborit 
 * 
 * rmq binary_search
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
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

template<class any>
struct rmq{
     int N;
     function<any(any, any)> f;
     vector< vector<any> > T;
     
     rmq(any *A, int sz, any (*fun)(any, any)){
         N = sz;
         f = *fun;
         T.resize(sz + 5, vector<any>(20, 0) );
         
         for(int i=1; i<=N; i++)
             T[i][0] = A[i];
             
         for(int j=1, l=log2(N); j<=l; j++){
             N -= 1<<(j-1); 
             for(int i=1; i<=N; i++)
                 T[i][j] = f(T[i][j-1], T[i + (1<<(j-1))][j-1]);
         }    
         N = sz;    
     }
     
     any query(int a, int b){
         int l = log2(b-a+1);
         return f(T[a][l], T[b-(1<<l)+1][l]);
     }  
};

inline int gcd(int a, int b){ return __gcd(a, b); }

int N;
int A[2*MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);    
    
    for(int i=1; i<=N; i++)
        A[N+i] = A[i];
        
    rmq<int> RMQ(A, 2*N, gcd);
    
    int sol = -1;
    for(int i=1; i<=N; i++){
        int pos = i;
        for(int j=log2(2*N); j>=0; j--){
            if( pos + (1<<j) <= 2 * N && RMQ.query(i, pos+(1<<j)) > 1 )
                pos += (1<<j);    
        }
        
        if( pos < i + N )
            sol = max(sol, pos - i + 1);    
    }    
    
    printf("%d\n", sol);    

   return 0;
}
