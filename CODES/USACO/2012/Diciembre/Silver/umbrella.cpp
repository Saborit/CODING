/* Code by wizard98
 * 
 * dp
 *  */
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
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
 #define all(X) (X).begin(), (X).end()
 #define unique(X) (X).resize(unique(all(X)) - (X).begin())
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 int N, M;
 int A[MX], C[MX], dp[MX];
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d", &N, &M);
     for(int i=1; i<=N; i++){
         scanf("%d", &A[i]);
         dp[i] = INF;
     }
     
     for(int i=1; i<=M; i++)
         scanf("%d", &C[i]);    
     
     sort(A+1, A+N+1);
     
     C[M+1] = INF;
     for(int i=M; i > 0; i--){
	     C[i] = min(C[i], C[i+1]);
	 }
     
     dp[0] = 0;
     for(int n=1; n<=N; n++){
	     for(int i=0; i < n; i++){
		     dp[n] = min(dp[n], dp[i] + C[ A[n] - A[i+1] + 1 ] );	 
		 }	 
     }
     
     printf("%d\n", dp[N]);
    
    return 0;
}


