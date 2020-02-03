/* Code by Saborit 
 * 
 * convex_hull_trick
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF 1e18
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

struct rect{
	int w, h;
	
	bool operator < (const rect &p)const{
		return h < p.h; 
	}
};

struct line{ 
	int64 m, b; 
	double limit; 
};

int inter(line l1, line l2){
	assert(abs(l1.m - l2.m) > EPS);
	return (l2.b - l1.b)/(l1.m - l2.m);	
	
}

struct cht{
	vector<line> hull;
	
	void add(int64 m, int64 b){
		line l = {m, b, INF};
		
		while( hull.size() > 1 && inter(l, hull.back()) < inter(l, hull[hull.size()-2]))
			hull.pop_back();
		
		if(hull.size())
			hull.back().limit = inter(l, hull.back());
		hull.pb(l);
	}
	
	int64 query(int64 x){
		int p = hull.size()-1;
		
		for(int i=log2(hull.size()); ~i; i--){
			if( hull[p-(1<<i)].limit > x )
			    p -= (1<<i);	
		}
		
		return hull[p].m * x + hull[p].b;	
	}	
};

int N;
int64 dp[MX];
bool mk[MX];
rect A[MX];
vector<rect> V;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d%d", &A[i].w, &A[i].h);
    
    sort(A+1, A+N+1);
     
    for(int i=N, j; i > 1; ){
		j = i-1;
		
		while( j > 0 && A[j].w <= A[i].w && A[j].h <= A[i].h ){
			mk[j] = true;
			j--;
		}	
		
		i = j;
	}  
	
	V.pb({0, 0});
	for(int i=1; i<=N; i++) if( !mk[i] )
	    V.pb(A[i]);
	N = V.size() - 1;    
	  
	cht C;
	C.add(V[1].w, 0);
	
	for(int i=1; i<=N; i++){
		dp[i] = C.query(V[i].h);
		
		if( i < N ) C.add(V[i+1].w, dp[i]);	
	}
	
	printf("%lld\n", dp[N]);
	
   return 0;
}
