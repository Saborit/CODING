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
 #define mid (x+xend)/2
 #define izq nod*2
 #define der nod*2+1
 #define MOD 1000000007
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;

 int N, P, sol;
 int T[255], W[255];
 bool mk[255][1005];
 pair<int64, int64> dp[255][1005];

 int main(void){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

     scanf("%d%d", &N, &P);
     for(int i=1; i<=N; i++)
         scanf("%d%d", &W[i], &T[i]);

     for(int i=0; i<=N; i++) for(int j=0; j<=P; j++)
         dp[i][j] = {0ll, 1ll};
     mk[0][0] = true;
     dp[0][0] = {0ll, 0ll};

     for(int i=0; i<=N; i++) for(int j=0; j<=P; j++){
	     for(int k=i+1; k<=N; k++){
   		     auto next = dp[k][min((int64)P, dp[i][j].second + W[k])];

   		     if( mk[i][j] && (dp[i][j].first + T[k]) * next.second >
                 (dp[i][j].second + W[k]) * next.first ){

		         dp[k][min((int64)P, dp[i][j].second + W[k])] = {dp[i][j].first + T[k], dp[i][j].second + W[k]};
		         mk[k][min((int64)P, dp[i][j].second + W[k])] = true;
		     }
		 }
	 }

      for(int i=1; i<=N; i++){
          if( sol < (dp[i][P].first * 1000ll)/dp[i][P].second )
              sol = (dp[i][P].first * 1000ll)/dp[i][P].second;
      }

      printf("%d\n", sol);

    return 0;
}


