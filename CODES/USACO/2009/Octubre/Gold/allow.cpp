/* Code by Saborit */
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

int N, C;
vector <pair<int, int> >A;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &C);
    for(int i=1, a, b; i<=N; i++){
		scanf("%d%d", &a, &b);
		
		A.pb({a, b});
	}
		
	sort(all(A));
	
	int sol = 0;
	
	while( 1 ){
		int sum = C;
		
		for(int i=A.size()-1; i>=0; i--){
			while( A[i].sc > 0 && sum - A[i].fr >= 0 ){
				A[i].sc--;
				sum -= A[i].fr;	
			}	
		}
		for(int i=0; i < (int)A.size(); i++)
		    if( A[i].sc > 0 && sum > 0 ){
				A[i].sc--;
				sum -= A[i].fr;
				break;	
			}
			
		if( sum > 0 ) break;
		sol++;		
	}
     
    printf("%d\n", sol);
    
   return 0;
}
