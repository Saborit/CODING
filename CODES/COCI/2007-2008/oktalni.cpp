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

string S;

int val(int x){
	int ans = 0;
	ans += (S[x] - '0') * 4;	
	ans += (S[x+1] - '0') * 2;	
	ans += (S[x+2] - '0') * 1;
	
	return ans;	
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    cin >> S;
    while( S.size() % 3 != 0 )
		S = "0" + S;
		
	for(int i=0; i < (int)S.size(); i+=3)
		printf("%d", val(i));
	printf("\n");
    
   return 0;
}
