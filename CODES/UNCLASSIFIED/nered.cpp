/* Code by Saborit
 * 
 * dp
 *  */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 105
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

int M, sol;

struct accumulative{
	int N;
	int A[MX][MX], acum[MX][MX];
	
    void build(){
	    for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
			    acum[i][j] = acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1], 
			    acum[i][j] += A[i][j] > 0;
	}
	
	int query(int a, int b, int c, int d){
		return acum[d][b] - acum[c-1][b] - acum[d][a-1] + acum[c-1][a-1];	
	}	
}ACUM;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &ACUM.N, &M);
    for(int i=1, a, b; i<=M; i++)
        scanf("%d%d", &a, &b),
        ACUM.A[a][b]++;
        
    ACUM.build(); 
        
    for(int i=1, N=ACUM.N; i<=N; i++){
	    for(int j=1; j<=N; j++){
			for(int ii=i; ii<=N; ii++) if( M % (ii-i+1) == 0 ){
			    int jj = j + M/(ii-i+1) - 1;
			    
			    if( jj > N ) continue;
			    
			    sol = max(sol, ACUM.query(j, jj, i, ii));	
			}	
		}	
	}
	
	printf("%d\n", M - sol);
        
   return 0;
}
