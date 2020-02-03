/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 55
#define INF (1ll<<62)
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

typedef tree<
	pair<int64, int64>,
	null_type,
	less<pair<int64, int64>>,
	rb_tree_tag,
	tree_order_statistics_node_update
> ordered_set;

int64 t = 0;
ordered_set S;

int64 N, M;
int64 G[MX], H[MX];
vector<pair<int64, int64>> L, R;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld%lld", &N, &M); 
    for(int i=0; i < N; i++)
		scanf("%lld%lld", &H[i], &G[i]);
	
	int K = N/2;
	
	for(int mask=1; mask < (1<<K); mask++){
		pair<int64, int64> tmp = {0, 0};
		bool ok = true;
		
		for(int i=0; i < K; i++) if( mask & (1<<i) ){
			if( tmp.sc <= H[i] ){
				tmp.fr += G[i];
				tmp.sc = H[i];	
			}
			else{
				ok = false;
				break;	
			}	
		}
		
		if( ok )
			L.pb(tmp);
	}
	
	int T = N - K;
	
	for(int mask=1; mask < (1<<T); mask++){
		pair<int64, int64> tmp = {0, INF};
		bool ok = true;
		
		for(int i=T-1; ~i; i--) if( mask & (1<<i) ){
			if( tmp.sc >= H[i+K] ){
				tmp.fr += G[i+K];
				tmp.sc = H[i+K];	
			}
			else{
				ok = false;
				break;
			}
		}
		
		if( ok )
			R.pb(tmp);
	}
	
	auto cmp = [](pair<int64, int64>& a, pair<int64, int64>& b){
		return a.sc > b.sc;	
	};
	
	int64 sol = 0;
	for(auto i: L) if( i.fr >= M )
		sol++;	
	for(auto i: R) if( i.fr >= M )
		sol++;	
	
	sort(all(L), cmp);
	sort(all(R), cmp);
	
	int64 r = 0;
	for(auto l: L){
		while( r < (int)R.size() && R[r].sc >= l.sc ){
			S.insert({R[r].fr, ++t});
			r++;	
		}
		
		sol += S.size() - S.order_of_key({M - l.fr, 0});
	}
	
	printf("%lld\n", sol);
	
   return 0;
}
