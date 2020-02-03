/* Code by wizard98
 * 
 * greedy
 * */
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #define MX 10005
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
	int val, t;
	
	bool operator < (const cow &p)const{
	    return t > p.t;	
	} 
 }A[MX];
 
 int N, ti, sol;
 priority_queue<int> Q;
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%d", &N);
     for(int i=1; i<=N; i++)
         scanf("%d%d", &A[i].val, &A[i].t);
     
     sort(A+1, A+N+1);
     
     for(int i=1; i<=N; ){
	     ti = A[i].t;
	     
	     while( i<=N && A[i].t == ti )
	         Q.push(A[i++].val); 
	     
	     while( !Q.empty() && ((i==N+1 && ti > 0) || ti > A[i].t) ){
	         sol += Q.top();
	         Q.pop();
	         ti--;
	     }
	 }   
	 
	 printf("%d\n", sol);
	 
    return 0;
}


