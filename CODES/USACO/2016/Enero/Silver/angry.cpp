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

int N, K;
int A[MX];


int check(int R){
	int ans = 0;
	for(int i=1, tmp; i<=N; ){
		tmp = i;
		ans++;
		
		while( i<=N && A[i] - A[tmp] <= 2*R )
			i++;	
	}
	
	return ans;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	
	sort(A+1, A+N+1);
	
	int p = 1e9+5;
	for(int i=log2(p); ~i; i--)
		if( p-(1<<i)>=0 && check(p-(1<<i)) <= K )
			p -= (1<<i);
	
	printf("%d\n", p);

   return 0;
}
