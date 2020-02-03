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

struct par{
	int nwn, c, id;
};

int cn, ca;
int mk[MX];
vector<par> G[MX];

bool dfs(int nod, int idm, int c){
	mk[nod] = c;
	
	bool ans = true;
	for(auto i: G[nod]) if( i.id <= idm ){
		if( mk[i.nwn] && mk[i.nwn] != i.c * mk[nod] )
			return false;
		if( !mk[i.nwn] )
			ans &= dfs(i.nwn, idm, mk[nod] * i.c);
	}  
	return ans;
}

bool check(int m){
	for(int i=1; i<=cn; i++)
		mk[i] = false;
	
	for(int i=1; i<=cn; i++)
		if( !mk[i] ){
			mk[i] = 1;
			if( !dfs(i, m, 1) ) return false;	
		}
	return true;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &cn, &ca);
    
    char c;
    for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d %c", &a, &b, &c);
		
		G[a].pb({b, c == 'T' ? 1 : -1, i});	
		G[b].pb({a, c == 'T' ? 1 : -1, i});	
	}
	
	int p = 1;
	for(int i=log2(ca); ~i; i--){
		if( p + (1<<i) <= ca && check(p + (1<<i)) )
			p += (1<<i);	
	}
		
    printf("%d\n", p);    

   return 0;
}
