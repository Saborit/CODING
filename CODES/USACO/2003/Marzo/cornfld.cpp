/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
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

#define midx ((c+d) >> 1)
#define midy ((a+b) >> 1)
#define NTR -INF

struct qtree{
	int a, b, c, d, val;
	qtree* P[4]; 
	
	qtree(){}
	qtree(int a, int b, int c, int d): a(a), b(b), c(c), d(d){
		P[0] = P[1] = P[2] = P[3] = NULL;
		val = NTR;
	}
	
	void split(){
		P[0] = new qtree(a, midy, c, midx);
		if( a < b ) P[1] = new qtree(midy+1, b, c, midx);
		if( c < d ) P[2] = new qtree(a, midy, midx+1, d);
		if( a< b && c < d )
			P[3] = new qtree(midy+1, b, midx+1, d);
	}
	
	void update(int aa, int bb, int cc, int dd, int x){
		if( aa<=a && b<=bb && cc<=c && d<=dd ){
			val = x;
			return; 
		}
		if( bb < a || b < aa || dd < c || d < cc )
			return;
		
		if( !P[0] ) split();
		
		for(int i=0; i < 4; i++) if( P[i] ){
			P[i]->update(aa, bb, cc, dd, x);
			val = max(val, P[i]->val);
		}
	}
	
	int query(int aa, int bb, int cc, int dd){
		if( aa<=a && b<=bb && cc<=c && d<=dd )
			return val; 	
		if( bb < a || b < aa || dd < c || d < cc )
			return NTR;
	    
	    int ans = NTR;
	    for(int i=0; i < 4; i++) if( P[i] )
	        ans = max(ans, P[i]->query(aa, bb, cc, dd));
	    
	    return ans;
	}
};

#define NTR2 INF

struct qtree2{
	int a, b, c, d, val;
	qtree2* P[4]; 
	
	qtree2(){}
	qtree2(int a, int b, int c, int d): a(a), b(b), c(c), d(d){
		P[0] = P[1] = P[2] = P[3] = NULL;
		val = NTR2;
	}
	
	void split(){
		P[0] = new qtree2(a, midy, c, midx);
		if( a < b ) P[1] = new qtree2(midy+1, b, c, midx);
		if( c < d ) P[2] = new qtree2(a, midy, midx+1, d);
		if( a< b && c < d )
			P[3] = new qtree2(midy+1, b, midx+1, d);
	}
	
	void update(int aa, int bb, int cc, int dd, int x){
		if( aa<=a && b<=bb && cc<=c && d<=dd ){
			val = x;
			return; 
		}
		if( bb < a || b < aa || dd < c || d < cc )
			return;
		
		if( !P[0] ) split();
		
		for(int i=0; i < 4; i++) if( P[i] ){
			P[i]->update(aa, bb, cc, dd, x);
			val = min(val, P[i]->val);
		}
	}
	
	int query(int aa, int bb, int cc, int dd){
		if( aa<=a && b<=bb && cc<=c && d<=dd )
			return val; 	
		if( bb < a || b < aa || dd < c || d < cc )
			return NTR2;
	    
	    int ans = NTR2;
	    for(int i=0; i < 4; i++) if( P[i] )
	        ans = min(ans, P[i]->query(aa, bb, cc, dd));
	    
	    return ans;
	}
};

int N, B, Q;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &N, &B, &Q);
    
    qtree QT(1, N, 1, N);
    qtree2 QT2(1, N, 1, N);
    for(int i=1, a; i<=N; i++) for(int j=1; j<=N; j++){
		scanf("%d", &a);
		QT.update(j, j, i, i, a);		
		QT2.update(j, j, i, i, a);		
	}
	
    int a, b; while( Q-- ){
		scanf("%d%d", &a, &b);
		
		printf("%d\n", QT.query(b, b+B-1, a, a+B-1) - QT2.query(b, b+B-1, a, a+B-1));	
	}    

   return 0;
}


