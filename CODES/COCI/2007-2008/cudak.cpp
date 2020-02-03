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

int N, S;
int64 a;
int64 dp[MX][MX][2];
char A[MX], B[MX];

int64 f(char A[]){
	N = strlen(A+1);
	
	for(int n=0; n<=N; n++)
		for(int s=0; s<=S; s++)
			dp[n][s][0] = dp[n][s][1] = 0;
	
	dp[0][0][0] = 1;		
	for(int n=0; n < N; n++) for(int s=0; s<=S; s++){
		for(int d=0; d<=(A[n+1] - '0'); d++){
			if( s+d <= S ){
				dp[n+1][s+d][ '0' + d < A[n+1] ] += dp[n][s][0];
			}
		}
		for(int d=0; d < 10; d++){
			if( s+d <= S ){
				dp[n+1][s+d][1] += dp[n][s][1];	
			}
		}		
	}
	return dp[N][S][0] + dp[N][S][1];	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld %s %d", &a, B+1, &S); 
    
    int64 solb = f(B); 
    
    a--;
    string s = to_string(a);
    for(int i=0; i < (int)s.size(); i++)
		A[i+1] = s[i];
	A[s.size() + 1] = '\0';
    
    int64 sola = f(A);
    
    printf("%lld\n", solb - sola);   
    
    string aa = to_string(a+1); 
    string bb(B+1);
    
    while( aa.size() < bb.size() ) 
		aa = "0" + aa;
	
	string sol = "";
	bool m = 0;
	
	for(int i=0, d; i < (int)aa.size(); i++){
		d = max(0, S - 9 * (int)(aa.size() - i - 1));
		
		if( !m ) d = max(d, (int)(aa[i] - '0'));
		
		if( !( !sol.size() && !d ) )
			sol += char(d + '0');
		S -= d;
		
		if( d > aa[i] - '0' ) m = true;
	}
		
	printf("%s\n", sol.c_str());

   return 0;
}
