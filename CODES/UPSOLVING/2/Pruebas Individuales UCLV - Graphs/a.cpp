/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    int nod, nwn, cost;
    
    bool operator < (const edge &p)const{
	    return cost < p.cost;	
	}	
};

int cn, ca, r, l, cant;
int SET[MX];
int64 sol;
vector<edge> G;

int find_set(int nod){
    if( nod != SET[nod] )
        return SET[nod] = find_set(SET[nod]);
    return SET[nod];    	
}

void join_set(int nod, int nwn){
	if( nod < nwn )
	    SET[nwn] = nod;
	else    
	    SET[nod] = nwn;
}

int64 solve(){
    G.clear();
     
    scanf("%d%d%d%d", &cn, &ca, &l, &r);
    for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d", &a, &b);
		G.push_back({a, b, r});
	}
	
	sol = (int64) l * cn;
	
	sort(all(G));
	for(int i=1; i<=cn; i++)
	    SET[i] = i;
	
	for(auto edg: G){
	    int setnod = find_set(edg.nod);	
	    int setnwn = find_set(edg.nwn);
	    
	    if( setnod != setnwn && sol > sol - l + edg.cost ){
		    sol = sol - l + edg.cost;
		    join_set(setnod, setnwn);	
		}	
	}
	
	return sol; 	
}

int T;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &T);
    while( T-- ){
	   printf("%lld\n", solve());	
	}   

   return 0;
}


