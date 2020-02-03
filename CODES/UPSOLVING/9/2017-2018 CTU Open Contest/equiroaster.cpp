/* Code by wizard98
 * 
 * geometry ad_hoc
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
 #define pb emplace_back
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 struct point{
	  int x, y;
	  
	  bool operator < (const point &p)const{
		  return x != p.x ? x < p.x : y < p.y;  
	  } 
	  
	  bool operator != (const point &p)const{
		  return x != p.x || y != p.y;  
	  } 
 }A[MX];
 
 int N, x_size, y_size, sol;
 int vx[MX], vy[MX];
 vector<int> cx[MX], cy[MX];
 
 bool dets_an_square(point a, point b){
     bool flag;
     if( a.x == b.x ){
	     if( a.y > b.y ) swap(a, b);
	     
	     flag = (binary_search(A+1, A+N+1, (point){b.x + b.y - a.y, b.y}) &&	 
	             binary_search(A+1, A+N+1, (point){a.x + b.y - a.y, a.y})) || 
	            (binary_search(A+1, A+N+1, (point){b.x - b.y + a.y, b.y}) &&	 
	             binary_search(A+1, A+N+1, (point){a.x - b.y + a.y, a.y}));	 
	 }
	 else if( a.y == b.y ){
		 if( a.x > b.x ) swap(a, b);
		     
		 flag = (binary_search(A+1, A+N+1, (point){a.x, a.y + b.x - a.x}) &&
		         binary_search(A+1, A+N+1, (point){b.x, b.y + b.x - a.x})) ||
		        (binary_search(A+1, A+N+1, (point){a.x, a.y - b.x + a.x}) &&
		         binary_search(A+1, A+N+1, (point){b.x, b.y - b.x + a.x}));
	 }
	 else flag = false;
	 
	 return flag;	 
 }
   
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     while( scanf("%d", &N) == 1 ){
	     for(int i=1; i<=N; i++)
	         scanf("%d%d", &A[i].x, &A[i].y);	  
	     sol = 0;
	     x_size = y_size = 0;
	 
		 sort(A+1, A+N+1, [] (point a, point b){ 
			 return a.y != b.y ? a.y < b.y : a.x < b.x;
		 });
		 
		 cy[0].clear();
		 vy[0] = A[1].y;
		 for(int i=1; i<=N; i++){
			 if( A[i-1].y < A[i].y ){
				 vy[++y_size] = A[i].y; 
				 cy[y_size].clear();
			 }
			 cy[y_size].pb(A[i].x);    	 
		 }
		 
		 sort(A+1, A+N+1, [] (point a, point b){ 
			 return a.x != b.x ? a.x < b.x : a.y < b.y;
		 });
		 
		 cx[0].clear();
		 vx[0] = A[1].x;
		 for(int i=1; i<=N; i++){
			 if( A[i-1].x < A[i].x ){
				 vx[++x_size] = A[i].x; 
				 cx[x_size].clear();
			 }
			 cx[x_size].pb(A[i].y);    	 
		 }
			 
		 for(int i=1; i<=N; i++){
			  int xp = lower_bound(vx, vx + x_size + 1, A[i].x) - vx;
			  int yp = lower_bound(vy, vy + y_size + 1, A[i].y) - vy;
			  
			  if( cx[xp].size() < cy[yp].size() ){
				  for(auto coord_y: cx[xp])
				      if( A[i] != (point){vx[xp], coord_y} && dets_an_square(A[i], {vx[xp], coord_y}) )
				         sol = max(sol, abs(A[i].y - coord_y));   
			  }
			  else{
				  for(auto coord_x: cy[yp])
				      if( A[i] != (point){coord_x, vy[yp]} && dets_an_square(A[i], {coord_x, vy[yp]}) )   
			               sol = max(sol, abs(coord_x - A[i].x));
			  } 	 
		 }
		 
		 printf("%d\n", sol);
     }				 
        
    return 0;
}


