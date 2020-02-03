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
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

const unt64 base = 400009ull;

unt64 hashing(vector<int> V){
	unt64 ans = 0, p = 1;
	
	for(int i=0; i < (int)V.size(); i++, p *= base)
	    ans += (V[i] + 200000) * p;
	return ans;	
}

int N, M, sol;
int acum[MX][35];
vector<int> tmp;
map<unt64, int> dic;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	
	for(int i=1; i < M; i++)
	    tmp.pb(0);
	dic[hashing(tmp)] = 0;    
	
	for(int i=1, a; i<=N; i++){
		scanf("%d", &a);
		
		tmp.clear();
		tmp.reserve(30);
		
		for(int j=0; j < M; j++){
		    acum[i][j] = acum[i-1][j] + ((a & (1<<j)) ? 1 : -1);
			
			if( j )
				tmp.pb(acum[i][j] - acum[i][j-1]);
		}
		
		unt64 h = hashing(tmp);
		
		if( dic.find(h) == dic.end() )
			dic[h] = i;	
		else
			sol = max(sol, i - dic[h]);	
	}
	
	printf("%d\n", sol);
		
   return 0;
}
