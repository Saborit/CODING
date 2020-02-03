/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#define MX 100005
#define INF (1ll<<30)
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

typedef int64 type;

struct pt{
	type x, y;

	pt operator + (const pt p){ return {x + p.x, y + p.y}; }
	pt operator - (const pt p){ return {x - p.x, y - p.y}; }
	type operator ^ (const pt p){ return x * p.y - y * p.x; }
};

type orient(pt a, pt b, pt c){ return (b - a) ^ (c - a); }

int N;
int64 A[MX];
int64 L[MX], R[MX];
double sol = 1e18;
vector<pt> hull;

inline double slope(int64 p, int pos){
	return (double)(L[p] + hull[pos].y) / (p + hull[pos].x); 
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%lld", &A[i]);

    for(int i=1; i<=N; i++)
		L[i] = L[i-1] + A[i];
    for(int i=N; i > 0; i--)
		R[i] = R[i+1] + A[i];

	for(int p=N-2, q=1; p > 0; p--, q++){
		while( hull.size() > 1 && orient(hull[hull.size()-2], hull.back(), {q, R[p+2]}) <= 0 )
			hull.pop_back();
		hull.pb({q, R[p+2]});

		int pos = 0;
		for(int n = hull.size(), i=log2(n); ~i; i--)
			if( pos + (1<<i) < n && slope(p, pos + (1<<i)) <= slope(p, pos + (1<<i) - 1) )
				pos += (1<<i);

		sol = min(sol, slope(p, pos));
	}

    printf("%.3f\n", sol);

   return 0;
}
