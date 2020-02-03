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

int t;
char c;

void solve(){
	int sol = 0;
	string S;
	
	while( true ){
		scanf("%c", &c);
		
		if( c == ' ' || c == '.' || c == '?' || c == '!'){
			bool ok = true;
			
			for(int i=1; i < (int)S.size(); i++)
				if( !islower(S[i]) )
					ok = false;
			if( isupper(S[0]) && ok ) sol++;
			//~ db() << imie(S);	
			S = "";	
		}
		else
			S += c;
			
		if( c == '.' || c == '?' || c == '!' )
			break;	
	}	
	
	printf("%d\n", sol);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d\n", &t);
    while( t-- )
		solve(); 

   return 0;
}
