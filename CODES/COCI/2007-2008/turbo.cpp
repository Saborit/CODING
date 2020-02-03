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
int A[MX], id[MX];

struct fenwick_tree{
	int T[MX];
	
	fenwick_tree(){
		for(int i=0; i < MX; i++)
			T[i] = 0;	
	}
	
	int acc(int b){
		int ans = 0;
		for(; b; b-=(b&(-b))) ans += T[b];
		return ans;	
	}
	int query(int a, int b){
		return acc(b) - (a == 1 ? 0 : acc(a-1));	
	}
	
	void update(int p, int val){
		for(; p < MX; p+=(p&-p))
			T[p] += val;
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		id[ A[i] ] = i;
	}
	
	fenwick_tree FT;
	
	for(int i=1; i<=N; i++)
		FT.update(i, 1);
		
	for(int i=1, a=1, b=N; i<=N; i++){
		if( i & 1 ){
			printf("%d\n", FT.query(1, id[a] - 1));
			FT.update(id[a++], -1);	
		}
		else{
			printf("%d\n", FT.query(id[b] + 1, N));
			FT.update(id[b--], -1);	
		}
	}
    
   return 0;
}
