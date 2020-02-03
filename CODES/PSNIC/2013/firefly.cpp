/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MX 500005
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
int A[MX], acum[MX];
multiset<int> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
		
	for(int i=1; i<=N; i+=2)
		S.insert(A[i]);	
		
    for(int i=1; i<=M; i++){
	    acum[i] += S.size();
	    
	    if( S.find(i) != S.end() )
			S.erase(i);	
	}
	
	for(int i=2; i<=N; i+=2)
		S.insert(A[i]);
			
	for(int i=M; i > 0; i--){
	    acum[i] += S.size();
	    
	    if( S.find(M-i+1) != S.end() )
			S.erase(M-i+1);	
	}
	
	int min_elem = INF, cant;
	for(int i=1; i<=M; i++)
	    if( acum[i] < min_elem ) 
			min_elem = acum[i],
			cant = 1;
		else if( min_elem == acum[i] )
		    cant++;	 
		    
	printf("%d %d\n", min_elem, cant);       

   return 0;
}


