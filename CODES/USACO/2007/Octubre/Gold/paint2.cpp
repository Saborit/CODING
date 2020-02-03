/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 105
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

int N, M, a, b;
int C[MX][MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++){
		scanf("%d%d", &a, &b);
		C[a][b]++;
		
		for(int i=1; i<=N; i++){
			if( i != b ) C[a][i]++;
			if( i != a ) C[i][b]++;
		}
		for(int i=-2*N; i<=2*N; i++){
		    if( 1<=a+i && a+i<=N && 1<=b+i && b+i<=N && i != 0 )
				C[a+i][b+i]++;	
		    if( 1<=a+i && a+i<=N && 1<=b-i && b-i<=N && i != 0 )
				C[a+i][b-i]++;	
		}
	}
	
	int sol = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		sol += (C[i][j] == M);
		
	printf("%d\n", sol);
	
   return 0;
}
