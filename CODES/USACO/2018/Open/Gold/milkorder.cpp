/* Code by wizard98 
 * 
 * kahn top_sort
 * */
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
 
 struct edge{
     int nwn, id;
 };
 
 int cn, M;
 bool off[MX];
 vector<int> order, delta(MX), sol;
 vector<edge> G[MX];
 priority_queue<int, vector<int>, greater<int> > Q;
 
 vector<int> kahn(vector<int> delta, int max_id){
     vector<int> ans;
     while(!Q.empty()) Q.pop();
     
     for(int i=1; i<=cn; i++){
        if( !delta[i] )
           Q.push(i);

        off[i] = false;
     }

     for(; !Q.empty(); ){
        int nod = Q.top();
        Q.pop(); 
        ans.push_back(nod);
        
        off[nod] = true;
        for(auto i: G[nod]){
            if( i.id <= max_id ){
			    delta[i.nwn]--;

				if( !delta[i.nwn] && !off[i.nwn] )
					Q.push(i.nwn);	
			}
        }
    }

    return ans;
 }
 
 vector<int> calc_incomming_degree(int max_id){
     vector<int> ans(MX);
     
     for(int nod=1; nod<=cn; nod++)
         for(auto i: G[nod])
             if( i.id <= max_id )
                 ans[i.nwn]++;
             
     return ans;        	 
 }
 
 int main(void){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
    
     scanf("%d%d", &cn, &M);
     for(int i=1, a, cant, last; i<=M; i++){
	     scanf("%d", &cant);
	     
	     for(int j=1; j<=cant; j++){
		     if( j==1 )
		         scanf("%d", &last);
		     else{
			     scanf("%d", &a);
			     G[last].push_back({a, i});
			     last = a;
			 }    
		 }	 
	 }
	 
	 int p = 0; 
	 for(int i=log2(M)+1; i>=0; i--){
	     if( p + (1<<i) <= M ){
		     delta = calc_incomming_degree( p + (1<<i) );
		     
		     order = kahn(delta, p + (1<<i) );
		     
		     if( order.size() == cn ){
		         p += (1<<i);
		         sol = order;  
		     }	 
		 }
	 }
	 
	 for(int i=0; i < sol.size(); i++)
	     printf(i==sol.size()-1 ? "%d\n" : "%d ", sol[i]);

    return 0;
}
