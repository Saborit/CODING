/* Code by wizard98
 * 
 * dp
 **/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 100005
#define INF (1ll<<62)
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

template <class T>
struct ds_queue{
     stack< pair<T, T> > s1, s2;

     int size(){ return s1.size() + s2.size(); }
     int empty(){ return s1.empty() && s2.empty(); }

     T top(){
        T ans = numeric_limits<T>::max();

        if( !s1.empty() && ans > s1.top().second )
            ans = s1.top().second;
        if( !s2.empty() && ans > s2.top().second )
            ans = s2.top().second;

        return ans;
     }

     void push(T val){
         if( s2.empty() )
             s2.push({val, val});
         else
             s2.push({val, min(val, s2.top().second)});
     }

     void pop(){
         if( s1.empty() ){
              while( !s2.empty() ){
                  if( s1.empty() )
                      s1.push({s2.top().first, s2.top().first});
                  else
                      s1.push({s2.top().first, min(s2.top().first, s1.top().second)});
                  s2.pop();
              }
         }
         assert( !s1.empty() );
         s1.pop();
     }
};

int N, K;
int A[MX];
int64 sum, sol;
int64 dp[MX];
ds_queue<int64> Q;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        sum += A[i];
    }
    dp[0] = 0ll;
    for(int i=1; i<=N; i++)
        dp[i] = INF;
    
    Q.push(0ll);    
    for(int i=1; i<=N; i++){
	    dp[i] = Q.top() + A[i];
	    Q.push(dp[i]);
	    
	    if( i-K-1 >= 0 ) Q.pop();	
	}
	
	sol = INF;
	for(int i=N-K; i<=N; i++)
	     sol = min(sol, dp[i]);      
    
    printf("%lld\n", sum - sol);
 
   return 0;
}
