/* Code by Saborit 
 * 
 * convex_hull_trick
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1000005
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

int64 N, a, b, c;
int64 A[MX];
int64 S[MX], dp[MX];

struct line{
	int64 m, b;
	long double limit;
}; 

long double inter(line l1, line l2){
	assert( abs(l1.m - l2.m) > EPS );
	return (long double)(l2.b - l1.b) / (l1.m - l2.m);
} 

struct cht{
	vector<line> hull;
	
	void add(int64 m, int64 b){
		line l = {m, b, INF};
		
		while( hull.size() > 1 
			&& inter(l, hull.back()) < inter(l, hull[hull.size()-2]))	
		
			hull.pop_back();	
		
			if( hull.size() )
			    hull.back().limit = inter(l, hull.back());
			hull.pb(l);    
	}
	
	int64 query(int64 x){
		int p = hull.size() - 1;
		
		for(int i=log2(hull.size()); ~i; i--)
			if( p-(1<<i)>=0 && hull[p-(1<<i)].limit > x )
				p -= (1<<i);
		
		return (int64)hull[p].m * x	+ hull[p].b;
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld%lld%lld%lld", &N, &a, &b, &c);
    for(int i=1; i<=N; i++){
        scanf("%lld", &A[i]); 
		S[i] = S[i-1] + A[i];
	}
    
    cht C;
    C.add(0ll, 0ll);
    
    for(int i=1; i<=N; i++){
		dp[i] = a * S[i] * S[i] + b * S[i] + c + C.query(S[i]);
		
		C.add(-2ll * a * S[i], dp[i] + a * S[i] * S[i] - b * S[i]);
	}
		
    printf("%lld\n", dp[N]);    
	
   return 0;
}
