/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 50005
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

int N;
int acum[MX], F[2*MX];
pair<int, int> A[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d%d", &A[i].sc, &A[i].fr);
		
	sort(A+1, A+N+1);
	
	for(int i=0; i < 2*MX; i++)
		F[i] = -1;
	F[MX] = 0;
	
	int sol = 0; 
	for(int i=1; i<=N; i++){
		acum[i] = acum[i-1] + (A[i].sc ? 1 : -1);
		
		if( F[ acum[i] + MX ] == -1 )
			F[ acum[i] + MX ] = i;			
		else
			sol = max(sol, A[i].fr - A[ F[ acum[i] + MX ] + 1].fr);	
	}
    
    printf("%d\n", sol);    

   return 0;
}
