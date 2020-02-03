/* Code by wizard98
 * 
 * dp trees graphs  
 * */
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
 
 int cn, K;
 int A[MX], P[MX], dph[MX][25], dp[MX];
 bool mk[MX];
 vector<int> G[MX];
 
 void dfsh(int nod){
     mk[nod] = true;
     dph[nod][0] = A[nod];
     
     for(auto nwn: G[nod]){
	     if( !mk[nwn] ){
		     dfsh(nwn);
		     P[nwn] = nod;
		     
		     for(int k=1; k<=K; k++)
				 dph[nod][k] += dph[nwn][k-1];
		 }	 
	 }	 
 }
 
 void dfs(int nod){
     mk[nod] = true;
     
     for(int i=0, nwn=nod, last; i<=K; i++){
		 dp[nod] += dph[nwn][K-i];
		 if( i )  dp[nod] -= dph[last][K-i-1];
		 
		 if( nwn == 1 ) break;
		 
		 last = nwn;
		 nwn = P[nwn];
	 }
     
     for(auto nwn: G[nod]){
	     if( !mk[nwn] ) dfs(nwn);	 
	 }
 }

 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d", &cn, &K);
     for(int i=1, a, b; i < cn; i++){
         scanf("%d%d", &a, &b);
         
         G[a].push_back(b);
         G[b].push_back(a);
     }
     
     for(int i=1; i<=cn; i++)
         scanf("%d", &A[i]);
         
     dfsh(1);
     
     for(int i=1; i<=cn; i++) mk[i] = false;
     
     for(int i=1; i<=cn; i++){
	     for(int j=1; j<=K; j++)
	         dph[i][j] += dph[i][j-1]; 	 
	 }
	 
	 //~ for(int i=1; i<=cn; i++){
	     //~ for(int j=0; j<=K; j++){
	         //~ printf("%d ", dph[i][j]);		 
		//~ }printf("\n");
	 //~ }
	 
	 dfs(1);
	 
	 for(int i=1; i<=cn; i++)
	     printf("%d\n", dp[i]);
	     

    return 0;
}


