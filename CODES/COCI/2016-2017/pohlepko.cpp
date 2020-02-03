/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 2005
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

#define POSSIBLE(X, Y) (X) > 0 && (X)<=N && (Y) > 0 && (Y)<=M
typedef pair<int, int> cell;

int N, M;
char A[MX][MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M); 
    for(int i=1; i<=N; i++)
		scanf(" %s", A[i]+1);	
	
	string sol;
	vector<cell> Q, tmp;
	
	Q.pb({1, 1});
	for(int i=1; i < N+M; i++){
		tmp.clear();
		sol += A[Q.back().fr][Q.back().sc];
		
		char c = 'z' + 1;
		for(auto p: Q){
			if( POSSIBLE(p.fr + 1, p.sc) )
				c = min(c, A[p.fr + 1][p.sc]);
					
			if( POSSIBLE(p.fr, p.sc + 1) )
				c = min(c, A[p.fr][p.sc + 1]);
		}
					
		for(auto p: Q){
			if( POSSIBLE(p.fr + 1, p.sc) && c == A[p.fr+1][p.sc] && 
				(tmp.empty() || tmp.back() != (cell){p.fr + 1, p.sc} ) ){
				tmp.pb({p.fr + 1, p.sc});
			}
			if( POSSIBLE(p.fr, p.sc + 1) && c == A[p.fr][p.sc+1] ){
				tmp.pb({p.fr, p.sc + 1});
			}
		}
		Q = tmp;	
	}
	
	cout << sol << endl;
	
   return 0;
}
