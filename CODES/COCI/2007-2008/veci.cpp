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
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N;

vector<int> cif(int N){
	vector<int> ans;
	
	while( N ){
		ans.pb(N % 10);
		N /= 10;
	}	
	
	sort(all(ans));
	
	return ans;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    int c = log10(N) + 1;
    
    int ma = 1;
    for(int i=0; i < c; i++)	
		ma *= 10;
		
	for(int i=N+1; i<=ma; i++){
		if( cif(N) == cif(i) ){
			printf("%d\n", i);
			return 0;
		}	
	}
	
	puts("0");
     
   return 0;
}
