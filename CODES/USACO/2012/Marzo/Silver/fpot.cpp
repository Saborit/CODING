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

struct pt{
	int x, y;
	
	bool operator < (const pt& p)const{
		return x < p.x;	
	}
};

int N, D;
pt A[MX];
multiset<int> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &D);
    for(int i=1; i<=N; i++){
		scanf("%d%d", &A[i].x, &A[i].y);	
	} 
	
	sort(A+1, A+N+1);
    
    int sol = INF;
    S.insert(A[1].y);
    
    for(int i = 1, j=1; i<=N; i++){
		while( j<=N && *S.rbegin() - *S.begin() < D )
			S.insert(A[++j].y);
		
		if( j<=N )
			sol = min(sol, A[j].x - A[i].x);	

		S.erase(S.lower_bound(A[i].y));
	}    
	
	printf("%d\n", sol == INF ? -1 : sol);

   return 0;
}
