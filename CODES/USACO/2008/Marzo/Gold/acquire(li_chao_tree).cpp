/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1000005
#define INF (1ll<<62)
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

const int M = 1e6+1;

int N;
int64 dp[MX];
pair<int, int> A[MX];
vector<pair<int, int>> V;

struct line{
	int64 m, b;
	
	int64 eval(int64 x){
		return m*x + b;	
	}	
};

struct lichao{
	vector<line> T;
	
	lichao(): T(4*MX, {0, INF}){}
	
	void add(line p, int x=1, int xend=M, int nod=1){
		bool l = p.eval(x) < T[nod].eval(x);	
		bool m = p.eval(mid+1) < T[nod].eval(mid+1);	
		
		if( m ) swap(T[nod], p);
		
		if( x==xend )
			return;
		if( l != m )
			add(p, x, mid, izq);
		else 
			add(p, mid+1, xend, der);	
	}
	
	int64 query(int a, int x=1, int xend=M, int nod=1){
		if( x==xend ) 
			return T[nod].eval(a);
		if( a<=mid )
			return min(T[nod].eval(a), query(a, x, mid, izq));
		else 
			return min(T[nod].eval(a), query(a, mid+1, xend, der));		
	}
}; 

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1, a, b; i<=N; i++){
		scanf("%d%d", &a, &b);
		
		V.pb({a, b});
	}
	sort(all(V), greater<pair<int, int>>());
	
	N = 0;
	A[++N] = *V.begin();
	for(int i=1; i < (int)V.size(); i++) 
		if( !(A[N].fr >= V[i].fr && A[N].sc >= V[i].sc) )
			A[++N] = V[i];	
	
	for(int i=1; i<=N; i++)
		dp[i] = INF;

	lichao L;
		
	L.add({A[1].fr, 0});
	for(int n=1; n<=N; n++){
		dp[n] = L.query(A[n].sc);
		
		L.add({A[n+1].fr, dp[n]});	
	}
	
    printf("%lld\n", dp[N]);    

   return 0;
}
