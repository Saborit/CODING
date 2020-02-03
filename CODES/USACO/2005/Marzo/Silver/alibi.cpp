/* Code by wizard98
 * 
 * dijkstra
 **/
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
 
 struct par{
    int nwn, cost;
    
    bool operator < (const par &p)const{
		return cost > p.cost;
	}	 
 };
 
 int cn, ca, C, T;
 int A[1005], dist[1005];
 vector<int> sol;
 vector<par> G[1005];
 priority_queue<par> Q; 
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d%d%d", &cn, &ca, &C, &T);
     for(int i=1, a, b, c; i<=ca; i++){
	     scanf("%d%d%d", &a, &b, &c);
	     G[a].push_back({b, c});	 
	     G[b].push_back({a, c});	 
	 }
	 for(int i=1; i<=C; i++)
	      scanf("%d", &A[i]);
	 
	 for(int i=1; i<=cn; i++)
	     dist[i] = INF;
	 dist[1] = 0;
	 
	 for(Q.push({1, 0}); !Q.empty(); Q.pop()){
		 int nod = Q.top().nwn;
		 
		 for(auto i: G[nod])
		     if( dist[i.nwn] > dist[nod] + i.cost ){
			     dist[i.nwn] = dist[nod] + i.cost;
				 Q.push({i.nwn, dist[i.nwn]}); 	
             }
	 }
	 
	 for(int i=1; i<=C; i++)
	     if( dist[ A[i] ] <= T )
	         sol.emplace_back(i);    
	 
	 sort(sol.begin(), sol.end());
	 
	 printf("%d\n", sol.size());
	 for(auto i: sol)
	     printf("%d\n", i);    	 
        
    return 0;
}


