/* Code by wizard98
 * 
 * binary_search greedy
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
 
 int L, N, M;
 int A[MX];
 
 bool check(int k){
    int ans = 0;
    
    for(int i=0, j=1; i<=N; ){
	    while( j<=N && A[j] < A[i] + k ){
			ans++, j++;
		}
		
		if( j == N+1 ){
		    if( A[j] - A[i] < k )
		        if( N - ans > 0 ) return ans + 1 <= M;
		        else return 0;
		    else
			    return ans <= M; 	
		}
		 
		i = j;
		j++;    	
	}
	
	assert(0); 	 
 }
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
     
     scanf("%d%d%d", &L, &N, &M);
     for(int i=1; i<=N; i++)
         scanf("%d", &A[i]);
			
     sort(A+1, A+N+1);
     A[N+1] = L;
     
     int sol = 0;
     for(int i=log2(L)+1; i>=0; i--)
	     if( sol + (1<<i) <= L && check(sol + (1<<i)) )
	         sol = sol + (1<<i);	 
	     
     
     printf("%d\n", sol);
        
    return 0;
}


