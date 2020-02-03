/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 50005
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

struct row{
	vector<int> A;
	
	bool operator < (const row& p)const{
		return A < p.A;
	}	
	bool operator == (const row& p)const{
		return A == p.A;
	}	
};

int N, M;
int A[15][MX];
char S[MX];
vector<row> values;

struct segment_tree{
	vector<int> T;
	
	segment_tree(): T(8*MX, -1){}
	
	int update(int a, int b, int x=1, int xend=2*N, int nod=1){
		if( a<=x && xend<=a )
			return T[nod] = max(T[nod], b);
		if( a < x || xend < a )
			return T[nod];
		return T[nod] = max(update(a, b, x, mid, izq), update(a, b, mid+1, xend, der));
	}
	
	int query(int a, int b, int x=1, int xend=2*N, int nod=1){
		if( a<=x && xend<=b )
			return T[nod];
		if( b < x || xend < a )
			return -1;
		return max(query(a, b, x, mid, izq), query(a, b, mid+1, xend, der));
	}
};

segment_tree ST[15];

struct acummulative{
	vector<int> T[MX];
	
	acummulative(){
		for(int i=1; i<=N; i++){
			row tmp;
			for(int j=1; j<=M; j++)
				tmp.A.pb(A[j][i]);
				
			int id = lower_bound(all(values), tmp) - values.begin();
			
			T[id].pb(i);
		}	
	}
	
	int query(int id, int a, int b){
		return upper_bound(all(T[id]), b) - lower_bound(all(T[id]), a);	
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &M, &N);	
    for(int i=1; i<=M; i++){
		scanf(" %s", S + 1);
		
		for(int j=1; j<=N; j++)
			A[i][j] = A[i][j-1] + (S[j] == '(' ? 1 : -1);	
	}
	
	for(int i=1; i<=N; i++){
		vector<int> tmp;
		
		for(int j=1; j<=M; j++){
			tmp.pb(A[j][i]);	
		}
		values.pb({tmp});
	}
	
	sort(all(values));
	unique(values);
	
	acummulative acum;
	
	int64 sol = 0;
	for(int i=1; i<=N; i++){
		int p = -1;
		vector<int> tmp;
		
		for(int j=1; j<=M; j++){
			p = max(p, ST[j].query(1, N + A[j][i]-1));
			tmp.pb(A[j][i]);	
		}
		int id = lower_bound(all(values), (row){tmp}) - values.begin();	
		sol += acum.query(id, p+1, i) - 1;
		
		for(int j=1; j<=M; j++){
			ST[j].update(N + A[j][i], i);
		}
	}
	
	printf("%lld\n", sol);
        
   return 0;
}
