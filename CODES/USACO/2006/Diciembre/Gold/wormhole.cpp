/* Code by wizard98
 * 
 * bellman_ford graphs shortest_paths
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
 #define pb push_back
 #define all(X) (X).begin(), (X).end()
 #define unique(X) (X).resize(unique(all(X)) - (X).begin())
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 struct edge{
	 int nod, nwn, cost; 
 };
 
 int T, cn, ca, cw;
 int dist[MX];
 vector<edge> G;
 
 bool solve(){
	 G.clear();
	 
     scanf("%d%d%d", &cn, &ca, &cw);
     for(int i=1, a, b, c; i<=ca; i++){
		 scanf("%d%d%d", &a, &b, &c);
		 G.pb({a, b, c});
		 G.pb({b, a, c});
	 }
	 for(int i=1, a, b, c; i<=cw; i++){
		 scanf("%d%d%d", &a, &b, &c);
		 G.pb({a, b, -c});
	 }
	 
	 for(int i=1; i<=cn; i++) 
		 dist[i] = INF;	 
     dist[1] = 0;
	 
	 for(int i=1; i < cn; i++)
	     for(auto arc: G)
	         if( dist[arc.nwn] > dist[arc.nod] + arc.cost )
	             dist[arc.nwn] = dist[arc.nod] + arc.cost;
	 
	 for(auto arc: G)
	     if( dist[arc.nwn] > dist[arc.nod] + arc.cost )
	 	     return true;
	 	     
	 return false;	     
 }

 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d", &T);
     while( T-- )
         printf(solve() ? "YES\n" : "NO\n");
        
    return 0;
}
