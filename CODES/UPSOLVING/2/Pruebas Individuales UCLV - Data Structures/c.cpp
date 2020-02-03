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

const int MAX = 100000;

int N; 
int A[MX], L[MX], R[MX];
vector<int> ord;
set<int> S;

struct segment_tree{
    vector<int> T;
    
    segment_tree():
        T(4*MX)
    {}
    
    int build(int x=1, int xend=MAX, int nod=1){
        if( x==xend ) return T[nod] = INF;
        
        return T[nod] = min(build(x, mid, izq), build(mid+1, xend, der));   
    } 
    
    int update(int a, int val, int x=1, int xend=MAX, int nod=1){
        if( a<=x && xend<=a )
            return T[nod] = val;
        if( a < x || xend < a )
            return T[nod];
            
        return T[nod] = min(update(a, val, x, mid, izq), update(a, val, mid+1, xend, der));            
    } 
    
    int query(int a, int b, int x=1, int xend=MAX, int nod=1){
        if( a<=x && xend<=b )
            return T[nod];
        if( b < x || xend < a )
            return INF;
            
        return min(query(a, b, x, mid, izq), query(a, b, mid+1, xend, der));            
    }  
}ST;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        
        S.insert(A[i]);    
    }
    
    for(auto i: S) ord.pb(i);
    
    for(int i=1; i<=N; i++)
        A[i] = lower_bound(all(ord), A[i]) - ord.begin() + 1; 
    
    ST.build();
    for(int i=1; i<=N; i++){
        int x = ST.query(A[i]+1, MAX);
        
        if( x != INF ) L[i] = -x;
        
        ST.update(A[i], -i);    
    }
    
    ST.build();
    for(int i=N; i > 0; i--){
        int x = ST.query(A[i]+1, MAX);
        
        if( x != INF ) R[i] = x;
        
        ST.update(A[i], i);   
    }
    
    int64 sol = 0ll;
    for(int i=1; i<=N; i++)
        sol = max(sol, (int64)L[i] * R[i]);
    
    printf("%lld\n", sol);
    
   return 0;
}
