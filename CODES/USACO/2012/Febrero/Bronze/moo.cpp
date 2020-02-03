/* Code by wizard98 
 * 
 * recursion implementation
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
 #define pb push_back
 #define all(X) (X).begin(), (X).end()
 #define unique(X) (X).resize(unique(all(X)) - (X).begin())
 using namespace std;
 using namespace __gnu_pbds;
 typedef long long int64;
 typedef unsigned long long unt64;
 
 int64 N;
 int64 L[45];
 
 bool f(int64 p, int64 k){
     if( !k )
	     return p==1;	 
     
     int64 piv1 = L[k-1];
     int64 piv2 = L[k-1] + k + 3ll;     
     
     if( 1ll <= p && p <= piv1 )
         return f(p, k-1);
	 
     else if( piv1 < p && p <= piv2 )
         return p == piv1 + 1;
     else
		 return f(p - piv2, k-1);        	 
 }
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%lld", &N);
     
     L[0] = 3ll; 
     for(int i=1; i<=40; i++)
         L[i] = 2ll * L[i-1] + (int64)i + 3ll;
     
     printf(f(N, 40) ? "m\n" : "o\n");    

    return 0;
}


