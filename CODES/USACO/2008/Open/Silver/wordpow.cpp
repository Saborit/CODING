/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1005
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

int N, M, sol;
char S[MX][MX], A[MX][MX];

bool is_subsequence(char* S, char* C){
	int p = 0;
	for(int i=0; S[i] != '\0'; i++)
		if( C[p] != '\0' && S[i] == C[p] ) p++;
	return C[p] == '\0'; 
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)	{
		scanf(" %s", S[i]);
		for(int j=0; S[i][j] != '\0'; j++)
		    S[i][j] = tolower(S[i][j]);
	}
    for(int i=1; i<=M; i++)	{
		scanf(" %s", A[i]);
		for(int j=0; A[i][j] != '\0'; j++)
		    A[i][j] = tolower(A[i][j]);
	}
	
	for(int i=1; i<=N; i++){
		sol = 0;
		for(int j=1; j<=M; j++)
			sol += is_subsequence(S[i], A[j]);	
		printf("%d\n", sol);
	}	
	
   return 0;
}


