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

int64 N, S;
int64 A[15];
int64 C[105][105];

int64 sum(){
	int64 ans = 0ll;
	
	for(int i=1; i<=N; i++)
		ans += A[i] * C[N-i][i-1];
		
	return ans;			
}

void print(){
	for(int i=1; i<=N; i++)	
		printf(i==N ? "%lld\n" : "%lld ", A[i]);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld%lld", &N, &S);
    for(int i=1; i<=N; i++){
		A[i] = i;
		C[i][0] = C[0][i] = 1ll;
	}
    C[0][0] = 1ll;
    
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)    
		C[i][j] = C[i-1][j] + C[i][j-1];
		
	do{
		if( sum() == S ){
			print();
			break;
		}	
	}
	while( next_permutation(A+1, A+N+1) );

   return 0;
}


