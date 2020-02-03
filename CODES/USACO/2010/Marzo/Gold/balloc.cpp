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

struct interval{
    int a, b;
    
    bool operator < (const interval& p)const{
	    if( b != p.b ) return b < p.b;
	    return a > p.a;	
	}	
};

int N, M, sol;
int A[MX];
interval R[MX];

struct segment_tree{
	vector<int> T, mk;
	
	segment_tree(): T(4*MX), mk(4*MX){}
	
	int build(int x=1, int xend=N, int nod=1){
	    if( x==xend ) return T[nod] = A[x];	
	    
	    return T[nod] = min(build(x, mid, izq), build(mid+1, xend, der));
	} 
	
	void lazy(int x, int xend, int nod){
		T[izq] = T[izq] - mk[nod];	
		T[der] = T[der] - mk[nod];
		
		mk[izq] += mk[nod];	
		mk[der] += mk[nod];
		
		mk[nod] = 0;	
	}
	
	int update(int a, int b, int x=1, int xend=N, int nod=1){
	    if( x < xend && mk[nod] )
			lazy(x, xend, nod);
			
	    if( a<=x && xend<=b ){
	        mk[nod]++;
	        return --T[nod];	
	    }
	    
	    if( b < x || xend < a )
	       return T[nod];
	       
	    return T[nod] = min(update(a, b, x, mid, izq), update(a, b, mid+1, xend, der));   
 	}
 	
 	int query(int a, int b, int x=1, int xend=N, int nod=1){
	    if( x < xend && mk[nod] )
			lazy(x, xend, nod);
	    
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
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    for(int i=1; i<=M; i++)
        scanf("%d%d", &R[i].a, &R[i].b);    
             
    sort(R+1, R+M+1);
    
    ST.build();
    
    for(int i=1; i<=M; i++){
	    if( ST.query(R[i].a, R[i].b) ){
			sol++;
			
			ST.update(R[i].a, R[i].b);	
		}	
	}    

    printf("%d\n", sol);
    
   return 0;
}
