/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1'500'005
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
int A[MX], id[MX];

struct fenwick_tree{
	fenwick_tree(){
		for(int i=0; i < MX; i++)
			id[i] = 0;	
	}
	
	int acc(int b){
		int ans = 0;
		for(; b; b-=(b&(-b))) ans += id[b];
		return ans;	
	}	
	
	void update(int p, int val){
		for(; p < MX; p+=(p&(-p)))
			id[p] += val;
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    N /= 2;
    
    for(int i=1, a; i<=N; i++){
		scanf("%d", &a);
		
		id[a] = i;
	}
	
	for(int i=1, a; i<=N; i++){
		scanf("%d", &a);
		
		A[i] = id[a];
	}
	
	fenwick_tree F;
	
	int64 sol = 0;
	for(int i=1; i<=N; i++){
		sol += (i - 1) - F.acc(A[i]);
		
		F.update(A[i], 1);
	}
	
	printf("%lld\n", sol); 
        
   return 0;
}
