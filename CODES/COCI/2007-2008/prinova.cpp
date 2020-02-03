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

int N, a, b;
int A[MX];

int dist(int son, int p){
	if( a<=p && p<=b ){
		return abs(p - son);
	}	
	return INF;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);	
	}
	scanf("%d%d", &a, &b);
	
	sort(A+1, A+N+1);
	
	pair<int, int> sol = {-1, -1},  m = {INF, -1};
	
	for(int i=1; i<=N; i++){
		if( a & 1 )
			m = min(m, {dist(A[i], a), a});
		else{
			m = min(m, {dist(A[i], a+1), a+1});
		}
	}
	if( m.fr < INF ) sol = max(sol, m);
	
	m = {INF, -1};
	for(int i=1; i<=N; i++){
		if( b & 1 )
			m = min(m, {dist(A[i], b), b});
		else{
			m = min(m, {dist(A[i], b-1), b-1});
		}
	}
	if( m.fr < INF ) sol = max(sol, m);
	
	for(int i=2; i<=N; i++){
		int p = (A[i-1] + A[i]) / 2;
	
		m = {INF, -1};
		
		if( p & 1 )
			m = min(m, {dist(A[i-1], p), p});	
		else{
			m = min(m, {dist(A[i-1], p-1), p-1});
			m = min(m, {dist(A[i], p+1), p+1});
		}
		
		if( m.fr < INF ) sol = max(sol, m);
	}
    
    printf("%d\n",sol.sc);    

   return 0;
}
