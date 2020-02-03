/* , by wizard98 */
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
 
 int64 a, b;
 
 int main(void){
     //~ freopen("a.in", "r", stdin);
     //~ freopen("a.out", "w", stdout);
    
     scanf("%lld.%lld", &a, &b);
     int64 N = a*100ll + b;
     
     printf("%lld\n", 36000ll/__gcd(36000ll, N)); 
        
    return 0;
}


