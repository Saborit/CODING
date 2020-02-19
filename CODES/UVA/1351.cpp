/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 205
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
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct disp{
	int64 a, b;
	
	disp operator + (disp p)const{
		return {(a + p.a) % MOD, (b + p.b) % MOD};	
	}
	disp operator - (disp p)const{
		return {(a + MOD - p.a) % MOD, (b + MOD - p.b) % MOD};	
	}
	disp operator * (disp p)const{
		return {(a * p.a) % MOD, (b * p.b) % MOD};	
	}
	bool operator == (disp p)const{ return a == p.a && b == p.b;	}
	bool operator < (disp p)const{ return a != p.a ? a < p.a : b < p.b;	}
};

const disp BASE = {29ll, 31ll};
disp P[MX];

void init(){
	P[0] = {1ll, 1ll};
	for(int i=1; i < MX; i++)
		P[i] = P[i-1] * BASE;
}

struct hasher{
	int N;
	disp H[MX];
	
	hasher(){}
	hasher(int N, char* S): N(N){
		for(int i=0; i < N; i++){
			H[i] = P[i] * (disp){S[i] - 'a' + 1, S[i] - 'a' + 1};
			H[i] = H[i] + (i ? H[i-1] : (disp){0, 0});	
		}
	}
	
	disp query(int a, int b){
		if( a > b ) return (disp){0, 0};
		return (H[b] - (a ? H[a-1] : (disp){0, 0})) * P[MX-a-1]; 	
	}
	
	bool is_period(int a, int b, int k){
		return (b-a+1) % k == 0 && query(a, b-k) == query(a+k, b);	
	}
};

int N;
int dp[MX][MX];
char S[MX];
hasher H;

int f(int a, int b){
	if( a > b ) return 0;
	if( dp[a][b] < INF ) return dp[a][b];
	
	dp[a][b] = min(dp[a][b], f(a+1, b) + 1);	
	dp[a][b] = min(dp[a][b], f(a, b-1) + 1);
	
	int n = b - a + 1;
	for(int k=1; k*k<=n; k++) if( n % k ==0 ){
		if( H.is_period(a, b, k) )
			dp[a][b] = min(dp[a][b], f(a, a+k-1) + (int)log10(n/k) + 3);
		
		if( k > 1 && H.is_period(a, b, n/k) )
			dp[a][b] = min(dp[a][b], f(a, a+n/k-1) + (int)log10(k) + 3);	
	}
	
	for(int i=1; a+i<=b; i++)
		dp[a][b] = min(dp[a][b], f(a, a+i-1) + f(a+i, b));	
	
	return dp[a][b];
}

void solve(){
	scanf(" %s", S);
	N = strlen(S);
	
	H = hasher(N, S);
	
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++)
		dp[i][j] = INF;
		
	printf("%d\n", f(0, N-1));	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    init(); 
    
    int t; scanf("%d", &t); 
    while( t-- ) solve();
    
   return 0;
}
