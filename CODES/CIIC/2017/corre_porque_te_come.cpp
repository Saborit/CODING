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
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	//~ #include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct edge{
	int nod, nwn, cost;
	
	bool operator < (const edge& p)const{
		return cost > p.cost;
	}	
};

struct par{
	int nwn, cost;	
};

int cn, ca;
int SET[MX];
vector<edge> G;
vector<par> T[MX];

struct lca{
	int cn;
	vector<int> L;
	vector<vector<int>> P;
	vector<vector<int>> M;
	
	lca(int cn): cn(cn), L(cn+5), P(cn+5, vector<int>(20, 0))
	{
		M = P;
		L[1] = 1;
		dfs(1, -1);
	
		for(int j=1; j<=log2(cn); j++)
			for(int i=1; i<=cn; i++){	
				P[i][j] = P[ P[i][j-1] ][j-1];
				M[i][j] = min(M[i][j-1], M[ P[i][j-1] ][j-1]);
			}
	}
	
	void dfs(int nod, int p){
		for(auto i: T[nod]) if( i.nwn != p ){
			P[i.nwn][0] = nod;
			M[i.nwn][0] = i.cost;
			L[i.nwn] = L[nod] + 1;
			
			dfs(i.nwn, nod);	
		}	
	}
	
	int query(int a, int b){
		if( L[a] < L[b] )
			swap(a, b);
		
		int sol = INF;
		for(int i=log2(cn); ~i; i--)
			if( L[ P[a][i] ] >= L[b] ){
				sol = min(sol, M[a][i]);
				a = P[a][i];	
			}
			
		if( a == b ) 
			return sol;
			
		for(int i=log2(cn); ~i; i--){
			if( P[a][i] && P[a][i] != P[b][i] ){
				sol = min(sol, M[a][i]);	
				sol = min(sol, M[b][i]);
				a = P[a][i], b = P[b][i];	
			}
		}	
		return min({sol, M[a][0], M[b][0]});
	}
};

int fset(int nod){
	if( SET[nod] != nod )
		return SET[nod] = fset(SET[nod]);
	return SET[nod];
}

void join(int nod, int nwn){
	if( nod > nwn ) swap(nod, nwn);
	
	SET[nwn] = nod;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);	
		
		G.pb({a, b, c});
	} 
    
    sort(all(G));
    
    for(int i=1; i<=cn; i++){
		SET[i] = i;
	}
	
	for(auto e: G){
		int setnod = fset(e.nod);	
		int setnwn = fset(e.nwn);	
		
		if( setnod != setnwn ){
			T[e.nod].pb((par){e.nwn, e.cost});	
			T[e.nwn].pb((par){e.nod, e.cost});
			
			join(setnod, setnwn);	
		}
	}
	
	lca L(cn);
	
	int Q; scanf("%d", &Q);
	for(int i=1, a ,b; i<=Q; i++){
		scanf("%d%d", &a, &b);
		
		printf("%d\n", L.query(a, b) - 1);
	}
	
   return 0;
}
