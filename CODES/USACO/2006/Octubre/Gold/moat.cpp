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

#define pen(X) (X)[(X).size()-2]
typedef int type;

struct pt{
	type x, y;	
	
	pt operator - (pt p){ return {x - p.x, y - p.y}; }
	type operator ^ (pt p){ return x * p.y - y * p.x; }
};

double dist(pt& a, pt& b){ return hypot(a.x - b.x, a.y - b.y); }

type orient(pt a, pt b, pt c){ return (b - a) ^ (c - a); }

vector<pt> convex_hull(vector<pt>& P){
	sort(all(P), [](pt &a, pt &b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;	
	});
	
	vector<pt> 	lh, uh;
	for(int i=0; i < (int)P.size(); i++){
		while( lh.size() > 1 &&  orient(pen(lh), lh.back(), P[i]) < EPS )
			lh.pop_back();
		lh.pb(P[i]);	
	}
	
	int i=0;
	while( i+1 < (int)P.size() && P[i].x == P[i+1].x )
		i++;
	
	for(; i < (int)P.size(); i++){
		while( uh.size() > 1 &&  orient(pen(uh), uh.back(), P[i]) > -EPS )
			uh.pop_back();
		uh.pb(P[i]);
	}
	
	for(int i=uh.size()-1; ~i; i--) 
		lh.pb(uh[i]);
	
	return lh;
}

int N;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    
    vector<pt> A(N);
    for(int i=0; i < N; i++)
		scanf("%d%d", &A[i].x, &A[i].y);	
	
	double sol = 0;
	auto C = convex_hull(A);
	
	for(int i=0, n=C.size(); i < n; i++)
		sol	+= dist(C[i], C[(i+1)%n]);
	
	printf("%.2lf\n", sol);
	
   return 0;
}


