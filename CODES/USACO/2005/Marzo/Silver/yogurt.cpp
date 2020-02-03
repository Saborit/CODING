/* Code by wizard98
 * 
 * greedy
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
 
 int N, S;
 int C[MX], Y[MX];
 int64 sol; 
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%d%d", &N, &S);
     for(int i=1; i<=N; i++)
         scanf("%d%d", &C[i], &Y[i]);
         
     for(int i=1; i<=N; i++){
	     int cost = C[i];
	     for(int j=1; j < i; j++)
		     cost = min(cost, C[j] + (i-j)*S );
		 sol += (int64)cost * Y[i];    	 
	 }
	 
	 printf("%lld\n", sol);    
        
    return 0;
}


