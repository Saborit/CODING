/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 205
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

int N, M;
char A[MX][MX];

struct accumulative{
	int acum[MX][MX];
	
	void build(){
		for(int i=0; i<=N; i++) for(int j=0; j<=M; j++)
			acum[i][j] = 0;
			
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++){
			acum[i][j] = acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1];
			acum[i][j] += (A[i][j] == 'X');
		}	
	}
	
	int query(int a, int b, int c, int d){
		return acum[b][d] - acum[a-1][d] - acum[b][c-1] + acum[a-1][c-1];	
	}
};

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		scanf(" %c", &A[i][j]);
    
    accumulative AC;
    AC.build();
    
    int sol = 0;
    for(int ii=1, i; ii<=N; ii++){
		for(int jj=ii; jj<=N; jj++){
			int j = 1;
	
			while( j<=M ){
				while( j<=M && AC.query(ii, jj, j, j) > 0 ) j++;
				
				i = j;
				while( j<=M && A[ii][j] == '.' && A[jj][j] == '.' ){
					if( AC.query(ii, jj, j, j) == 0 )
						sol = max(sol, (jj - ii + 1) * (j - i + 1) );
					j++;		
				}
			}	
		}	
	}
	
	printf("%d\n", sol);
	
	return 0;
}
