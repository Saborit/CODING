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

int N, M;
int X[MX], Y[MX], S1[MX], S2[MX], P1[MX], P2[MX];

int ceil(int a, int b){
	if( (a < 0) ^ (b < 0) ) 
		return a / b - (a % b != 0);
	else 
		return a / b + (a % b != 0);
}

int cost(int j, int tot){
	int ans = INF;

	for(int i=0, x; (int64)(i-1) * S1[j]<=tot; i++){
		x = max(0, ceil(tot - i*S1[j], S2[j]));
		
		if( S1[j] * i + S2[j] * x >= tot )
			ans = min(ans, P1[j] * i + P2[j] * x);
	}
	
	return ans;
}

bool check(int s){
	int tot = M;
	
	for(int i=1; i<=N; i++){
		int tmp = cost(i, X[i] * s - Y[i]);
		
		tot -= tmp;
	}
	
	return tot >= 0;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
		scanf("%d%d%d%d%d%d", &X[i], &Y[i], &S1[i], &P1[i], &S2[i], &P2[i]);
		
	int p = 0;
	for(int i=log2(M); ~i; i--)
		if( check(p+(1<<i)) )
			p += (1<<i);	
	
	printf("%d\n", p);
	
   return 0;
   
}
