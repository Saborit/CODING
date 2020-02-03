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
	int nod, nwn, cost, id;
	
	bool operator < (const edge &p)const{
		return cost < p.cost;	
	} 	
}; 

int cn, ca, cc;
int SET[MX];
vector<edge> G;

int fset(int nod){
	if( nod != SET[nod] )
		return SET[nod] = fset(SET[nod]);
	return nod;	
}

bool join(int nod, int nwn){
	nod = fset(nod), nwn = fset(nwn);
	
	if( nod == nwn ) return false;
	if( nod < nwn ) swap(nod, nwn);
	
	SET[nod] = nwn;	
	return true;
}

int kruskal(int k){
	for(int i=1; i<=cn; i++)
		SET[i] = i;
    
    int cc = cn, ans = 0;
    for(auto e: G) if( e.id<=k ){
		if( join(e.nod, e.nwn) ){
			ans += e.cost;
			cc--;	
		}	
	}
    return cc == 1 ? ans : -1; 
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca); 
    
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);
		G.pb({a, b, c, i});	
	}   
	
	sort(all(G));
	
	for(int i=1; i<=ca; i++)
		printf("%d\n", kruskal(i)); 

   return 0;
}
