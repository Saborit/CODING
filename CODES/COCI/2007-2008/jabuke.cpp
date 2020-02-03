/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF (1<<30)
#define EPS 1e-12
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

typedef double type;

struct pt{
	type x, y;
	
	pt operator + (pt p){ return {x + p.x, y + p.y};  } 
	pt operator - (pt p){ return {x - p.x, y - p.y};  } 
	
	type operator * (pt p){ return x * p.x + y * p.y;  } 
	type operator ^ (pt p){ return x * p.y - y * p.x;  } 
};

type orient(pt a, pt b, pt c){
	return (b-a) ^ (c-a);
}

bool in_disk(pt a, pt b, pt p){	
	return (a - p) * (b - p) < EPS;
}

bool on_segment(pt a, pt b, pt p){
	return fabs(orient(a, b, p)) < EPS && in_disk(a, b, p);
}

bool crosses_ray(pt a, pt p, pt q){
	return ( (q.y - a.y > -EPS) - (p.y - a.y > -EPS) ) * orient(a, p, q) > EPS ;
}

bool in_polygon(vector<pt>& P, pt a, bool strict=true){
	int ans = 0;
	
	for(int i=0, n=P.size(); i < n; i++){
		if( on_segment(P[i], P[(i+1)%n], a) ){
			return !strict;
		}
		
		ans += crosses_ray(a, P[i], P[(i+1)%n]);
	}
	return ans & 1;	
}

type area_polygon(vector<pt>& P){
	type ans = 0;
	
	for(int i=0, n=P.size(); i < n; i++)
		ans += P[i] ^ P[(i+1)%n]; 
	return fabs(ans) / 2.0;
}

int N, sol;
vector<pt> T;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    for(int i=0, a, b; i < 3; i++){
		scanf("%d%d", &a, &b);
		
		T.pb({(type)a, (type)b});	
    }
    
    printf("%.1lf\n", area_polygon(T));
    
    scanf("%d", &N);
    for(int i=0, a, b; i < N; i++){
		scanf("%d%d", &a, &b);	
		
		sol += in_polygon(T, {(type)a, (type)b}, false);
	}
	
	printf("%d\n", sol);
    
   return 0;
}
