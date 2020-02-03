/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 500005
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

int N;
int A[MX], acum[MX];
vector<pair<int, int>> par[MX], impar[MX];

auto cmp = [](pair<int, int>& a, pair<int, int>& b){
	return a.sc - a.fr < b.sc - b.fr;
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		acum[i] = acum[i-1] + (A[i] == i);
	}
	
	for(int i=1; i<=N; i++){
		if( (A[i] + i) & 1 )
			par[ (A[i] + i)/2 ].pb({min(i, A[i]), max(i, A[i])});
		else
			impar[ (A[i] + i)/2 ].pb({min(i, A[i]), max(i, A[i])});
	}
	
	for(int i=1; i<=N; i++){
		sort(all(par[i]), cmp);	
		sort(all(impar[i]), cmp);	
	}
	
	int sol = 0;
	pair<int, int> best = {1, 1};
	
	for(int i=1; i<=N; i++){
		int gain = 0;
		for(auto j: par[i]){
			gain++;
			
			if( sol < gain - (acum[j.sc] - acum[j.fr-1]) ){
				sol = gain - (acum[j.sc] - acum[j.fr-1]);
				best = {A[j.fr], A[j.sc]};	
			}
		}	
	}
	
	for(int i=1; i<=N; i++){
		int gain = 0;
		for(auto j: impar[i]){
			gain++;
			
			if( sol < gain - (acum[j.sc] - acum[j.fr-1]) ){
				sol = gain - (acum[j.sc] - acum[j.fr-1]);
				best = {A[j.fr], A[j.sc]};	
			}
		}	
	}
	
	printf("%d %d\n", best.fr, best.sc);
	
   return 0;
}
