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
int A[MX][5], P[MX][5];
vector<int> values, sol;

bool cmp(int a, int b){
	a = lower_bound(all(values), a) - values.begin() + 1;
	b = lower_bound(all(values), b) - values.begin() + 1;
	
	int ans = 0; 
	for(int i=0; i < 5; i++)
		ans += P[a][i] < P[b][i];
	return ans > 2; 	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int j=0; j < 5; j++)
		for(int i=1; i<=N; i++)
			scanf("%d", &A[i][j]);
	
	for(int i=1; i<=N; i++)
		values.pb(A[i][0]);
	
	sort(all(values));
	unique(values);
	
	for(int j=0; j < 5; j++){
		for(int i=1; i<=N; i++){
			assert(lower_bound(all(values), A[i][j]) - values.begin() + 1 <=N);
			P[ lower_bound(all(values), A[i][j]) - values.begin() + 1 ][j] = i;	
		}	
	}
    
    sol = values;
     
    sort(all(sol), cmp);
    
    for(auto i: sol)
		printf("%d\n", i);	

   return 0;
}
