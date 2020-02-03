/* Code by wizard98
 * 
 * graphs connectivity
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
 
 int K, cn, ca, sol;
 int A[MX], can[MX];
 bool mk[MX];
 vector<int> G[MX];
 
 void dfs(int nod){
    mk[nod] = true;
    can[nod]++;
    
    for(auto nwn: G[nod]){
	    if( !mk[nwn] )
	        dfs(nwn);	
	} 	 
 }
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d%d", &K, &cn, &ca);
     for(int i=1; i<=K; i++)
         scanf("%d", &A[i]);
     for(int i=1, a, b; i<=ca; i++){
	     scanf("%d%d", &a, &b);
	     G[a].pb(b);	 
	 }    
        
     for(int i=1; i<=K; i++){
         for(int i=1; i<=cn; i++) 
             mk[i] = false;
         
         dfs(A[i]);
	 }
     for(int i=1; i<=cn; i++)
         sol += can[i] == K;
         
      printf("%d\n", sol);          

    return 0;
}

