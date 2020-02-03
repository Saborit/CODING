/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
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

inline int sq(int x){ return x*x; } 

struct stack_min{
	int64 T[105], p;
	
	stack_min(): p(-1ll){}
	
	void add(int64 x){
		if( p < 0 ) T[++p] = x;
		else{ 
			p++;
			T[p] = std::min(x, T[p-1]);
		}	
	}
	int64 min(){ return p < 0 ? INF : T[p]; }
	
	bool empty(){ return p < 0; }
	void pop(){ p--; }
};

int N, C, H;
int A[MX];
int64 dp[MX][105];
stack_min down, up;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &C);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		H = max(H, A[i]);
	}
	
	for(int i=1; i<=N; i++) for(int j=1; j<=H; j++)
		dp[i][j] = INF;
		
	for(int i=A[1]; i<=H; i++)
		dp[1][i] = sq(i - A[1]);
    
    for(int n=2; n<=N; n++){
		while( !up.empty() ) up.pop();
		while( !down.empty() ) down.pop();
		
		for(int i=H; i > A[n]; i--)
			up.add(dp[n-1][i] + (int64)C * i);
		
		for(int i=1; i<=A[n]; i++)
			down.add(dp[n-1][i] - (int64)C * i);
		
		for(int h=A[n]; h<=H; h++){
			dp[n][h] = min(
				sq(h - A[n]) + (int64)C * h + down.min(),
				sq(h - A[n]) - (int64)C * h + up.min()
			);
			
			if( !up.empty() ) up.pop();
			down.add(dp[n-1][h+1] - (int64)C * (h+1));	
		}
	}
		
	int64 sol = INF;
	for(int i=1; i<=H; i++)
		sol = min(sol, dp[N][i]);
	
	printf("%lld\n", sol);
		
   return 0;
}
