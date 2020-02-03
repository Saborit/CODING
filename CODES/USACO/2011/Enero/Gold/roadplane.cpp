/* Code by wizard98
 * 
 * spfa graphs
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
 
 struct par{
     int nwn, cost;	 
 };
  
 int cn, cr, cp, ni;
 int dist[MX];
 bool in_queue[MX];
 vector<par> G[MX];
 deque<int> Q;
 
 void add_node(int nod){
     if( !in_queue[nod] ){
		 if( dist[nod] < dist[Q.front()] )
		     Q.push_front(nod);
		 else 
			 Q.push_back(nod);
	     in_queue[nod] = true;
	 } 	 
 }
  
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d%d%d%d", &cn, &cr, &cp, &ni);
     for(int i=1, a, b, c; i<=cr; i++){
	     scanf("%d%d%d", &a, &b, &c);
	     
	     G[a].push_back({b, c});	 
	     G[b].push_back({a, c});	 
	 }
	 for(int i=1, a, b, c; i<=cp; i++){
	     scanf("%d%d%d", &a, &b, &c);
	     
	     G[a].push_back({b, c});	 	 
	 }
	 
	 for(int i=1; i<=cn; i++) dist[i] = INF;
	 dist[ni] = 0;
	 
	 for(Q.push_back(ni); !Q.empty(); ){
		 int nod = Q.front(); 
		 Q.pop_front();
		 
		 in_queue[nod] = false;
		 
		 for(auto i: G[nod]){
		     if( dist[i.nwn] > dist[nod] + i.cost ){
		         dist[i.nwn] = dist[nod] + i.cost;
				 add_node(i.nwn);
			 }	 
		 }
	 }
     
     for(int i=1; i<=cn; i++){
	     printf(dist[i] < INF ? "%d\n" : "NO PATH\n", dist[i]);	 
	 }   

    return 0;
}
