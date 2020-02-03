/* Code by wizard98
 * 
 * bitmasks brute_force
 *  */
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #define MX 1005
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
 
 int N, D, K, sol, sum;
 int dis[MX];
 
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%d%d%d", &N, &D, &K);
     for(int i=1, M, a; i<=N; i++){
	    scanf("%d", &M);
	    for(int j=1; j<=M; j++){
			scanf("%d", &a);
	        dis[i] |= (1<<(a-1));
	    }	 
	 }
	 
	 for(int mask=0; mask < (1<<D); mask++) 
	     if(__builtin_popcount(mask) <= K){
			 sum = 0;
			 for(int i=1; i<=N; i++) 
				 sum += (mask | dis[i]) == mask;
			 sol = max(sol, sum);
		 }
	 
	 printf("%d\n", sol);
        

    return 0;
}


