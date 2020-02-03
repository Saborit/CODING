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
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

#define POSSIBLE X > 0 && X<=7 && Y > 0 && Y<=7

const int dx[] = {0, 1, -1, 0}; 
const int dy[] = {1, 0, 0, -1}; 
const int ddx[] = {0, 2, -2, 0}; 
const int ddy[] = {2, 0, 0, -2}; 

int sol;
char S[10][10];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf(" %s", S[1]+3); 
    scanf(" %s", S[2]+3);
    scanf(" %s", S[3]+1); 
    scanf(" %s", S[4]+1); 
    scanf(" %s", S[5]+1); 
    scanf(" %s", S[6]+3); 
    scanf(" %s", S[7]+3);
    
    for(int i=1; i<=7; i++)	for(int j=1; j<=7; j++){
		for(int k=0; k < 4; k++){
			int x = i + dx[k];
			int y = j + dy[k];
			int X = i + ddx[k];	
			int Y = j + ddy[k];
			
			if( S[i][j] == 'o' && POSSIBLE && S[X][Y] == '.' && S[x][y] == 'o')
				sol++;		
		}
	}
	
	printf("%d\n", sol);

   return 0;
}
