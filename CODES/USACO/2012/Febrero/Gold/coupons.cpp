/* Code by wizard98
 * 
 * greedy 
 **/
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
 
 struct cow{
	bool is_coupon; 
	int64 p, id;
	
	bool operator < (const cow &c)const{
		return p == c.p ? is_coupon > c.is_coupon : p > c.p;
	} 
 };
 
 int64 N, K, M, sol, a, b;
 bool mk[MX];
 priority_queue<cow> Q; 

 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%lld%lld%lld", &N, &K, &M);
     for(int i=1; i<=N; i++){
	     scanf("%lld%lld", &a, &b);	 
	     Q.push({false, a, i});
	     Q.push({true, b, i});
	 }
	        
	 while( !Q.empty() && M>=0ll ){
	     if( Q.top().is_coupon ){
			 if( M - Q.top().p >= 0ll && K > 0ll && !mk[Q.top().id] ){
			     K--;
			     mk[Q.top().id] = true;
				 sol++;
				 M -= Q.top().p;	 
			 }
			 Q.pop();
		 }
		 else{
			 if( M - Q.top().p >= 0ll &&  !mk[Q.top().id] ){
				 mk[Q.top().id] = true;
			     sol++;
			     M -= Q.top().p;		 
			 }
			 Q.pop();		
		 }
	 }       
	 
	 printf("%lld\n", sol);

    return 0;
}


