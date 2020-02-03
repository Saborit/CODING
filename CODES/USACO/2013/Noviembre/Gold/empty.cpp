/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 3000005
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

int N, Q, a, b, x, y;
int A[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &Q);
    while( Q-- ){
		scanf("%d%d%d%d", &x, &y, &a, &b);
		
		for(int i=1; i<=y; i++)
			A[ ((int64)a * i + b) % N ] += x;	
	} 
    
    int v = 0;
    for(int i=0; i < N; i++){
		A[i] += v;
		
		v = max(0, A[i] - 1);
		A[i] -= v;	
	}
			
	A[0] += v, v = 0;
	for(int i=0; i < N; i++){
		A[i] += v;
		
		v = max(0, A[i] - 1);
		A[i] -= v;	
	}
	
	for(int i=0; i < N; i++) if( !A[i] )
		return !printf("%d\n", i);
	
   return 0;
}
