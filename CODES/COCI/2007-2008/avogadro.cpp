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

int N;
int A[MX][3], cant[MX][3];
bool mk[MX];
vector<int> col[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i][0]);
		col[ A[i][0] ].pb(i);
		cant[ A[i][0] ][0]++;
	}
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i][1]);
		col[ A[i][1] ].pb(i);
		cant[ A[i][1] ][1]++;
	}
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i][2]);
		col[ A[i][2] ].pb(i);
		cant[ A[i][2] ][2]++;
	}
	
	queue<int> Q;
	for(int i=1; i<=N; i++)
		if( !cant[i][0] || !cant[i][1] || !cant[i][2] ){
			mk[i] = true;
			Q.push(i);
		}
	
	while( !Q.empty() ){
		int x = Q.front();
		
		for(auto c: col[x]){
			for(int i=0; i < 3; i++){
				cant[ A[c][i] ][i]--;
				
				if( !mk[ A[c][i] ] && !cant[ A[c][i] ][i] ){
					mk[ A[c][i] ] = true;
					Q.push(A[c][i]);	
				}
				A[c][i] = 0;
			}	
		}
		Q.pop();
	}
	
	int sol = 0;
	
	for(int i=1; i<=N; i++)
		sol += !A[i][0] && !A[i][1] && !A[i][2];	
		
	printf("%d\n", sol);
    
   return 0;
}
