/* Code by wizard98
 * 
 * sweep_line
 *  */
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #define MX 50005
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
 
 struct point{
	 int x, y;
	 
	 bool operator < (const point &p)const{
	     return x==p.x ? y < p.y : x < p.x; 	 
     } 
 };
 
 int N, W, sol;
 point P[MX];
 multiset<int> S;
  
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%d%d", &N, &W);
     for(int i=1; i<=N; i++)
         scanf("%d%d", &P[i].x, &P[i].y);
     P[++N] = {W+1, 0};
         
     sort(P+1, P+N+1);
     
     S.insert(0);
     for(int i=1; i<=N; i++){
         
     
	     while( *S.rbegin() > P[i].y ) {
			 auto it = S.end(); it--;
			 S.erase(it);
			 sol++;
		 }	 
		 if( *S.rbegin() != P[i].y )S.insert(P[i].y);		 	 
	 }     
     
     printf("%d\n", sol);   

    return 0;
}


