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
typedef long double ld;

vector<ld> distribute(vector<ld>& V, ld M){
	priority_queue<ld, vector<ld>, greater<ld>> Q;
	vector<ld> ans;
	
	for(auto i: V) Q.push(i);
	
	while( M > 0.0 && !Q.empty() ){
		ld x = min((ld)Q.top(), M / Q.size());
		
		ans.pb(x);
		M -= x;
		Q.pop();
	}
	return ans;
}

int N, M, cn;
int A[MX];
ld ma[MX];
char S[MX], op[MX];
vector<int> G[MX];
stack<int> K;

void dfs(int nod){
	for(auto nwn: G[nod])
		dfs(nwn);
	
	ld sum = 0;
	vector<ld> ch;
	for(auto nwn: G[nod]){
		ch.pb(ma[nwn]);
		sum += ma[nwn];
	}
	
	int cant_ch = (int)ch.size() == 0 ? 1 : ch.size();
	
	sum = min(sum, (ld)A[cant_ch]);
	
	if( op[nod] == '+' ){
		ma[nod] = 0;
		
		for(auto i: distribute(ch, sum))
			ma[nod] += i;
	}
	else if( op[nod] == '*' ){
		ma[nod] = 1.0;
		
		for(auto i: distribute(ch, sum))
			ma[nod] *= i;
	}
	else ma[nod] = A[1];
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &M);
    for(int i=1; i<=M; i++)
		scanf("%d", &A[i]);
	
    scanf(" %s", &S);
    N = strlen(S);
    
    K.push(0);
    for(int i=0; i < N; i++){
		if( S[i] == '(' ){
			G[K.top()].pb(++cn);
			K.push(cn);	
		}
		else if( S[i] == ')' )
			K.pop();
		else{
			op[K.top()] = S[i];	
		}
	}
	
	dfs(1);
    printf("%.9LF\n", ma[1]);
    
   return 0;
}
