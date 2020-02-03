/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 5005
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
char S[MX], acum[MX];
bool A[MX];

int solve(int K){
	for(int i=1; i<=N; i++)
	    acum[i] = 0, A[i] = (S[i] == 'B'); 
	
	int ans = 0;    
	for(int i=1, c=0; i<=N; i++){
		c += acum[i];
		A[i] ^= (c & 1);
				
		if( A[i] ){
			if( i<=N-K+1 ){
				ans++;
				acum[i]++, acum[i+K]--;
				c++;
				A[i] ^= 1;
			}
			else{
				return INF;	
			}	
		}			
	}    
	
	return ans;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d\n", &N);
	for(int i=1; i<=N; i++) 
        scanf("%c\n", &S[i]);
	
	pair<int, int> best = {INF, -1};
	for(int i=1; i<=N; i++)
	    best = min(best, {solve(i), i});
	
	printf("%d %d\n", best.sc, best.fr);
	
   return 0;
}
