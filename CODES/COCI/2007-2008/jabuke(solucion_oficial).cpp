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
	
	pt operator - (pt p){ return {x - p.x, y - p.y}; } 
	type operator ^ (pt p){ return x * p.y - y * p.x;  } 
};

type area(pt a, pt b, pt c){
	return fabs((c - a) ^ (b - a)) / 2.0;	
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
    
    printf("%.1lf\n", area(T[0], T[1], T[2]));
    
    scanf("%d", &N);
    for(int i=0, a, b; i < N; i++){
		scanf("%d%d", &a, &b);	
		
		type sum_area = 0;
		for(int i=0; i < 3; i++)
			sum_area += area(T[i], T[(i+1)%3], {(type)a, (type)b});
		
		sol += sum_area == area(T[0], T[1], T[2]);
	}
	
	printf("%d\n", sol);
    
   return 0;
}
