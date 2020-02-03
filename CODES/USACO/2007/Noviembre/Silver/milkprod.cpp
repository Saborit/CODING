/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1005
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

struct interval{
	int l, r, val;
	
	bool operator < (const interval &p)const{
		return r < p.r;
	}
};

int N, M, R;
int dp[MX];
interval A[MX];

int bound(int x){
	int p = 0;
	for(int i=log2(N); ~i; i--)
		if( p + (1<<i)<=N && A[p + (1<<i)].r <= x )
		    p += (1<<i);
	return p;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d%d", &M, &N, &R);
    for(int i=1; i<=N; i++)
		scanf("%d%d%d", &A[i].l, &A[i].r, &A[i].val);
		
	sort(A+1, A+N+1);
     
    dp[0] = 0;
    A[0] = {-INF, -INF, 0};
    
    for(int n=1; n<=N; n++)
		dp[n] = max(dp[n-1], dp[bound(A[n].l - R)] + A[n].val);
	
	printf("%d\n", dp[N]);
	
   return 0;
}


