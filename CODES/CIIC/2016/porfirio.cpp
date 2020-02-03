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
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct edge{
	int nod, nwn, cost;
	
	bool operator < (const edge& p)const{
		return cost < p.cost;	
	}
};

int cn;
int SET[MX], R[MX];
vector<edge> G;

int fset(int nod){
	if( SET[nod] != nod )
		return SET[nod] = fset(SET[nod]);
	return nod;	
}

void join(int nod, int nwn){
	if( R[nod] > R[nwn] ){
		SET[nwn] = nod;
		R[nod] += R[nwn];	
	}	
	else{
		SET[nod] = nwn;
		R[nwn] += R[nod];		
	}
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &cn);
    for(int i=1, a, b, c; i < cn; i++){
		scanf("%d%d%d", &a, &b, &c);
		
		G.pb({a, b, c});
	}
	
	for(int i=1; i<=cn; i++){
		SET[i] = i;
		R[i] = 1;
	}
	
	sort(all(G));
	
	int64 sol = 0;
	for(auto e: G){
		int setnod = fset(e.nod);	
		int setnwn = fset(e.nwn);
		
		int64 paths = R[setnod] * R[setnwn] % MOD;
		sol += e.cost * paths % MOD;
		sol %= MOD;
		
		join(setnod, setnwn);	
	}
	 
    printf("%llu\n", sol);    

   return 0;
}
