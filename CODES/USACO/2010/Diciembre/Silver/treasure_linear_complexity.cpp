/* Code by Saborit 
 * 
 * Tomasz Idziaszek's method
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
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

int N, sum; 
int A[MX];
vector<int> V;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	    sum += A[i];
 	}
		
	for(int i=1; i < N; i++){
	    V.pb(A[i]);
	    
	    while( V.size() > 1 && V[V.size()-1] >= V[V.size()-2] && 
			V[V.size()-1] >= A[i+1] ){
				A[i+1] = V[V.size()-2] - V[V.size()-1] + A[i+1];
				V.resize(V.size()-2);	
			}	
	}
	V.pb(A[N]);
			
	int sol = 0;			
	for(int i=1, l=0, r=(int)V.size()-1, val; l<=r; i++){
	    if( V[l] > V[r] ) val = V[l++];
	    else val = V[r--];
	    
	    sol += (i & 1) ? val : -val;	
	}
    
    printf("%d\n", (sol + sum) >> 1);    

   return 0;
}
