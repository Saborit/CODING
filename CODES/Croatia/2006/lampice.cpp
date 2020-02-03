/* Code by Saborit 
 * 
 * greedy
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

int N, sol;
char A[2][MX];

bool cmp(int i, int j, string S){
	for(int k=0; k < 3; k++)
	    if( A[i][j+k] != S[k] ) return false;
	return true;    	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d\n", &N);
    for(int i=1; i<=N; i++)
		scanf("%c", &A[0][i]);
	scanf("\n");	
    for(int i=1; i<=N; i++)
		scanf("%c", &A[1][i]);
    A[0][0] = A[1][0] = A[0][N+1] = A[1][N+1] = '0';
    N++;
    
    for(int i=1; i<=N; i++)    
		if( A[0][i] == '1' && A[0][i-1] == '0' )
			sol++;
	for(int i=1; i<=N; i++)    
		if( A[1][i] == '1' && A[1][i-1] == '0' )
			sol++;
	
	for(int i=0; i<=N-2; i++)
		if( cmp(0, i, "010") && cmp(1, i, "010") ){
		    sol--;
		    A[0][i+1] ^= 1, A[1][i+1] ^= 1; 
		}
		else if( cmp(0, i, "101") && cmp(1, i, "101") ){
			sol--;
			A[0][i+1] ^= 1, A[1][i+1] ^= 1;
		}
		else if( cmp(0, i, "101") && cmp(1, i, "010") ){
			sol--;
			A[0][i+1] ^= 1, A[1][i+1] ^= 1;
		}
		else if( cmp(0, i, "010") && cmp(1, i, "101") ){
			sol--;
			A[0][i+1] ^= 1, A[1][i+1] ^= 1;
		}
	
	printf("%d\n", sol);	
	
   return 0;
}
