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

struct edge{
	int nod, nwn;
	int64 cost;
	
	bool operator < (const edge &p)const{
		return cost < p.cost;	
	}
};

int cn, M; 
int X[MX], Y[MX], SET[MX];
vector<edge> G;

inline int64 dist(int i, int j){
	return (int64)(X[i] - X[j])*(X[i] - X[j]) + (int64)(Y[i] - Y[j])*(Y[i] - Y[j]);	
}

int find_set(int nod){
	if( nod != SET[nod] )
	    return SET[nod] = find_set(SET[nod]);
	return nod;    	
}

bool join(int nod, int nwn){
	nod = find_set(nod), nwn = find_set(nwn);
	
	if( nod == nwn ) return false;
	if( nod > nwn ) swap(nod, nwn);
	
	SET[nwn] = nod;
	return true;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &M);
    for(int i=1; i<=cn; i++)
		scanf("%d%d", &X[i], &Y[i]);
		
	for(int i=1; i<=cn; i++) for(int j=i+1; j<=cn; j++)
		G.pb({i, j, dist(i, j)});
        
	sort(all(G));
	
	for(int i=1; i<=cn; i++)
		SET[i] = i;
	
	int a, b;
	while( M-- ){
		scanf("%d%d", &a, &b);
		join(a, b);	
	}
	
	double sol = 0.0;
	for(auto i: G)
		if( join(i.nod, i.nwn) )
			sol += sqrt(i.cost);
	
	printf("%.2lf\n", sol);
	
   return 0;
}
