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

struct fenwick_tree{
    int T[MX];
    
    int acc(int b){
        int ans = 0;
        for(; b; b-=(b&(-b))) ans += T[b];
        return ans;    
    }    
    
    int query(int a, int b){
        return acc(b) - (a!=1 ? acc(a-1) : 0);  
    }
    
    void update(int p, int val){
        for(; p < MX; p+=(p&(-p)))
            T[p] += val; 
    }
}FT;

int N;
int A[MX], L[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=2*N; i++){
        scanf("%d", &A[i]);
    
        if( !L[ A[i] ] ) 
            L[ A[i] ] = i;
    }
    
    int64 sol = 0ll;
    for(int i=1; i<=2*N; i++){
        if( i == L[ A[i] ] )
            FT.update(i, 1);
        else{
            FT.update(L[ A[i] ], -1);
            sol += FT.query(L[ A[i] ], i);    
        }        
    }     
    
    printf("%lld\n", sol);    

   return 0;
}
