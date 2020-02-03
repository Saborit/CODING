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
 
 struct cow{
     int w, s;
     
     bool operator < (const cow &p)const{
	     return w + s < p.w + p.s;	 
	 }	 
 };
 
 int N, sum, sol = -INF;
 cow A[MX]; 
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%d", &N);
     for(int i=1; i<=N; i++)
         scanf("%d%d", &A[i].w, &A[i].s);
         
     sort(A+1, A+N+1);
      
     for(int i=1; i<=N; i++){
	     sol = max(sol, sum - A[i].s);
	     sum += A[i].w;	 
	 }    
       
     printf("%d\n", sol);   

    return 0;
}


