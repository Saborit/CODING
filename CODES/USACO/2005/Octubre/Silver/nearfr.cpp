/* Code by wizard98
 * 
 * math meet_in_the_middle
 *  */
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #define MX 100005
 #define INF (1ll<<62)
 #define EPS 1e-9
 #define mid (x+xend)/2
 #define izq nod*2
 #define der nod*2+1
 #define MOD 1000000007
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 const int64 MAX = 32767ll;
 
 int64 N, D, sol_diff = INF, sol_a, sol_b;
 set<int64> S;
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%lld%lld", &N, &D);
     
     for(int64 a=1ll; a<=MAX; a++) S.insert(a*D);
         
     for(int64 b=1ll; b<=MAX; b++){
	     auto it = S.lower_bound(N * b);
	     
	     if( abs(N*b - *it) > 0 && sol_diff >= abs(N*b - *it) ){
			 sol_diff = abs(N*b - *it);
			 sol_a = *it/D, sol_b = b;		     	 
		 }
		 
		 --it;
		 if( abs(N*b - *it) > 0 && sol_diff >= abs(N*b - *it) ){
			 sol_diff = abs(N*b - *it);
			 sol_a = *it/D, sol_b = b;		     	 
		 }
	 }
	 
	 printf("%lld %lld\n", sol_a, sol_b);     

    return 0;
}


