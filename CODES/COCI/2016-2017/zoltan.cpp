/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
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
int A[MX], inc[MX], de[MX];
int64 winc[MX], wde[MX];
vector<int> values;

struct par{
	int val, cant;
	
	par operator + (par p){
		if( val < p.val )
			return {p.val, p.cant};
		else if( val > p.val )
			return {val, cant};
		else return {val, (cant + p.cant) % MOD};	
	}
};

struct segment_tree{
	vector<par> T;
	
	segment_tree(): T(4*MX, {0, 0}){}
	
	par update(int a, int b, int c, int x=0, int xend=M, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = T[nod] + (par){b, c};
		if( a < x || xend < a )
			return T[nod];
		return T[nod] = update(a, b, c, x, mid, izq) + update(a, b, c, mid+1, xend, der);	
	}
	
	par query(int a, int b, int x=0, int xend=M, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return {0, 0};
		return query(a, b, x, mid, izq) + query(a, b, mid+1, xend, der);	
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);	
		values.pb(A[i]);
	}
	
	sort(all(values));
	unique(values);
	
	M = values.size() + 1;
	
	for(int i=1; i<=N; i++)
		A[i] = lower_bound(all(values), A[i]) - values.begin() + 1;
	
	segment_tree ST_INC, ST_DE;
	ST_INC.update(M, 0, 1);
	ST_DE.update(0, 0, 1);
	
	for(int i=N; i > 0; i--){
		auto tmp = ST_INC.query(A[i] + 1, M);
		
		inc[i] = tmp.val + 1;
		winc[i] = tmp.cant;
		
		ST_INC.update(A[i], inc[i], winc[i]);
		
		tmp = ST_DE.query(0, A[i]-1);
		
		de[i] = tmp.val + 1;
		wde[i] = tmp.cant;
		
		ST_DE.update(A[i], de[i], wde[i]);
	}
	
	int64 ma = 0, ways = 0;
	for(int i=1; i<=N; i++){
		if( ma < inc[i] + de[i] - 1 ){
			ma = inc[i] + de[i] - 1;
			ways = winc[i] * wde[i] % MOD;	
		}	
		else if( ma == inc[i] + de[i] - 1 ){
			ways += winc[i] * wde[i] % MOD;	
			ways %= MOD;
		}
	}
	
	for(int i=0; i < N - ma; i++)
		ways = ways * 2 % MOD;
	
	printf("%lld %lld\n", ma, ways);

   return 0;
}
