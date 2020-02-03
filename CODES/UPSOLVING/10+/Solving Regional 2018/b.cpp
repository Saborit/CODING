/* , by wizard98 */
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
 #define pb emplace_back
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 int N, sol;
 int A[MX], acum[MX];
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d", &N);
     for(int i=1; i<=N; i++){
	     scanf("%d", &A[i]);
	     acum[i] = acum[i-1] + A[i];	 
	 }
	 
	 if( acum[N] & 1 ) 
	     return !printf("N\n");
	 
	 for(int i=1; i<=N; i++)
	     sol += binary_search(acum+1, acum+N+1, acum[i] + acum[N]/2);	 
	 
	 printf(sol > 1 ? "Y\n" : "N\n");
	
    return 0;
}


