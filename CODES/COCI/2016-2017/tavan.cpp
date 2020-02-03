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

int N, M, K, X;
char S[MX];
char A[MX][26]; 
int64 pot[MX];

inline int64 ceil(int64 a, int64 b){ return a / b + (a % b != 0); }

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d%d", &N, &M, &K, &X);
    scanf(" %s", S+1);
   
    for(int i=1; i<=M; i++){
		scanf(" %s", A[i] + 1);
		sort(A[i]+1, A[i]+K+1);
	}  
	
	int pm = 0;
	pot[0] = 1ll;
	for(pm=1; ; pm++){
		pot[pm] = pot[pm-1] * K;
		
		if( pot[pm] > X ) break;
	}
	
	vector<char> sol;
	for(int i=1, x; i<=M; i++){
		x = ceil(X, pot[min(M-i, pm)]);
		X -= (x-1) * pot[min(M-i, pm)];
		
		sol.pb(A[i][x]);
	}
	
	for(int i=1, j=0; i<=N; i++)
        if( S[i] == '#' )
			printf("%c", sol[j++]);
		else 
			printf("%c", S[i]);
	printf("\n");

   return 0;
}
