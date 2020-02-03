/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 25
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

int N, M;
char A[MX][MX]; 
vector<string> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
		scanf(" %s", A[i]+1);
		
    for(int i=1; i<=N; i++){
		string tmp;
		for(int j=1; j<=M; j++){
			if( A[i][j] != '#' )
				tmp += A[i][j];
			if( j == M || A[i][j+1] == '#' ){
				if( tmp.size() > 1 )
					S.pb(tmp);	
				tmp = "";
			}
		}	
	}
	
    for(int j=1; j<=M; j++){
		string tmp;
		for(int i=1; i<=N; i++){
			if( A[i][j] != '#' )
				tmp += A[i][j];
			if( i == N || A[i+1][j] == '#' ){
				if( tmp.size() > 1 )
					S.pb(tmp);	
				tmp = "";
			}
		}	
	}
	
	sort(all(S));
	
    printf("%s\n", S[0].c_str());    

   return 0;
}
