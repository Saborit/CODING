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

inline int64 sum(int64 i){ return (i*i + i)/2; }
inline int64 sum(int64 a, int64 b){ 
	if( a > b ) return 0;
	return sum(b) - sum(a-1); 
}

int64 N;
vector<pair<int64, int64>> sol;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld", &N);
    
    for(int i=1; (int64)i*i<=2*N; i++) if( 2*N % (int64)i == 0ll ){
		int64 x = i;
		int64 y = 2*N / (int64)i;
		
		if( (x - y + 1) > 0 && (x - y + 1) % 2ll == 0ll ){
			sol.pb({(x - y + 1) / 2, y + (x - y + 1) / 2ll - 1});	
		}	
		if( (int64)i*i != 2*N ){
			swap(x, y);
			
			if( (x - y + 1) > 0 && (x - y + 1) % 2ll == 0ll ){
				sol.pb({(x - y + 1) / 2, y + (x - y + 1) / 2ll - 1});	
			}		
		}
	}
    
	sort(all(sol));
	reverse(all(sol));
	
	for(auto i: sol) if( i.fr < i.sc )
		printf("%lld %lld\n", i.fr, i.sc);
        
   return 0;
}

