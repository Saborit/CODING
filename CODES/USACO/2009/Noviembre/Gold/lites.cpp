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

struct range{
    int on;
};

inline int swap(int a, int b, int on){ return b - a + 1 - on; }    

int N, Q;

struct segment_tree{
    vector<range> T;
    bool mk[4*MX];
    
    segment_tree():
        T(4*MX) {}
    
    void lazy(int x, int xend, int nod){
        mk[nod] = 0;
        mk[izq] ^= true;
        mk[der] ^= true;
        
        T[izq].on = swap(x, mid, T[izq].on); //exec_lazy
        T[der].on = swap(mid+1, xend, T[der].on); //exec_lazy
        
    }
    
    range update(int a, int b, int x=1, int xend=N, int nod=1){
        if( x < xend && mk[nod] )
            lazy(x, xend, nod);
        
        if( a<=x && xend<=b ){
            mk[nod] = 1;
            return T[nod] = {swap(x, xend, T[nod].on)};    
        }
        if( b < x||xend < a )
            return T[nod];
            
        return T[nod] = {update(a, b, x, mid, izq).on + update(a, b, mid+1, xend, der).on};        
    }
    
    int query(int a, int b, int x=1, int xend=N, int nod=1){
        if( x < xend && mk[nod] )
            lazy(x, xend, nod);
        
        if( a<=x && xend<=b )
            return T[nod].on;    
        if( b < x || xend < a )
            return 0;
            
        return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);    
    }
}ST;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    
    int ty, a, b;
    while( Q-- ){
        scanf("%d%d%d", &ty, &a, &b);
        
        if( !ty ){
            ST.update(a, b); 
        } 
        else
            printf("%d\n", ST.query(a, b));   
    }  
        
   return 0;
}
