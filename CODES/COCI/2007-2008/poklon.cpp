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

const int M = 1000000;

int N;
int dp[MX], pp[MX];
pair<int, int> A[MX];

struct segment_tree{
	vector<pair<int, int>> T;
	
	segment_tree(): T(4 * M + 5){}
	
	pair<int, int> update(int a, int b, int x=1, int xend=M, int nod=1){
		if( a<=x && xend<=a ){
			return T[nod] = max(T[nod], {dp[b], b});	
		} 	
		if( a < x || xend < a )
			return T[nod];
		return T[nod] = max(update(a, b, x, mid, izq), update(a, b, mid+1, xend, der));
	}
	
	pair<int, int> query(int a, int b, int x=1, int xend=M, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return {0, -1};
		return max(query(a, b, x, mid, izq), query(a, b, mid+1, xend, der));
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d%d", &A[i].fr, &A[i].sc);	
	} 
	
	segment_tree ST;
	
	A[0] = {0, M};
	sort(A+1, A+N+1, [](pair<int, int> a, pair<int, int> b){
		if( a.fr != b.fr ) 
			return a.fr < b.fr;
		return a.sc > b.sc; 
	});
	
	ST.update(M, 0);
	for(int i=1; i<=N; i++){
		auto tmp = ST.query(A[i].sc, M);
		dp[i] = tmp.fr + 1;
		pp[i] = tmp.sc;
		
		ST.update(A[i].sc, i);
	}
	
	pair<int, int> best;
	vector<pair<int, int>> ans;
	for(int i=1; i<=N; i++)
		best = max(best, {dp[i], i});
	 
	for(int i=best.sc; i; i=pp[i])
		ans.pb(A[i]);
		
	sort(all(ans), [](pair<int, int> a, pair<int, int> b){
		if( a.fr != b.fr ) 
			return a.fr < b.fr;
		return a.sc > b.sc; 
	});
	
	printf("%d\n", best.fr);
	for(auto i: ans)
		printf("%d %d\n", i.fr, i.sc);
	
   return 0;
}
