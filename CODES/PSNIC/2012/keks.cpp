/* Code by wizard98 
 * 
 * greedy
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 500005
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

struct bundle{
    char dig;
    int id;
    
    bool operator < (const bundle &p)const{
	    return dig != p.dig ? dig > p.dig : id < p.id;	
	} 
};

int N, K;
char A[MX];
string sol;

struct SegmentTree{
	vector<bundle> T;
	
	SegmentTree():
	    T(4*MX){}
	
	bundle build(int x=1, int xend=N, int nod=1){
	    if( x == xend ) 
			return T[nod] = {A[x], x};
			
		return T[nod] = min(build(x, mid, izq), build(mid+1, xend, der));	 	
	}
	
	bundle query(int a, int b, int x=1, int xend=N, int nod=1){
	    if(a<=x && xend<=b )
	        return T[nod];
	    if( x > b || a > xend )
	        return {0, INF};
	        
	    return min(query(a, b, x, mid, izq), query(a, b, mid+1, xend, der));         	
	}
}ST;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    K = N - K;
    
    for(int i=1; i<=N; i++)
	    scanf(" %c", &A[i]);
	    
	ST.build();    
		
	for(int pos = 0, left = K - 1, next; left >=0; ){
	    next = ST.query(pos + 1, N - left).id;
	    
	    sol += A[next];
	    pos = next;
	    left--;	
	}
	
	cout << sol << '\n';
        
   return 0;
}


