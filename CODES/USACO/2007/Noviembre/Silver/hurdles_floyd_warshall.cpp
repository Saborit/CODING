/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 305
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

int cn, ca, q;
int G[MX][MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &cn, &ca, &q);
    
    for(int i=1; i<=cn; i++) for(int j=1; j<=cn; j++) 
		G[i][j] = INF;
    
    for(int i=1, a, b, c; i<=ca; i++){
		scanf("%d%d%d", &a, &b, &c);
		G[a][b] = c;
	}
    
	for(int k=1; k<=cn; k++)
		for(int i=1; i<=cn; i++) if( G[i][k] < INF )
			for(int j=1; j<=cn; j++)
				G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
	
	int a, b;
	while( q-- ){
		scanf("%d%d", &a, &b);
		
		printf(G[a][b] == INF ? "-1\n" : "%d\n", G[a][b]);	
	}
	 
   return 0;
}
