/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 30005
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

int N;
int A[MX], delta[MX], id[MX];
bool off[MX];
char in[105];
string S[MX], O[MX];
vector<int> G[MX];

vector<int> kahn(){
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> Q;
	
	for(int i=0; i < 26; i++){
		if( !delta[i] )
			Q.push(i);
		off[i] = false;	
	}
	
	for(; !Q.empty(); ){
		int nod = Q.top();
		Q.pop();
		ans.pb(nod);
		
		off[nod] = true;
		for(auto nwn: G[nod]){
			delta[nwn]--;
			
			if( !delta[nwn] && !off[nwn] )
				Q.push(nwn);
		}
	}
	return ans;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf(" %s", in);
		
		O[i] = string(in);
	}
	for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
		
	for(int i=1; i<=N; i++)
		S[i] = O[ A[i] ];
		
	for(int ii=1; ii<=N; ii++){
		for(int jj=ii+1; jj<=N; jj++){
			int i = 0;
			
			while( i < (int)S[ii].size() && i < (int)S[jj].size() 
				&& S[ii][i] == S[jj][i] ) i++;
			
			if( i < (int)S[ii].size() && i < (int)S[jj].size() ){
				G[ S[ii][i] - 'a' ].pb(S[jj][i] - 'a');
				delta[S[jj][i] - 'a']++;
			}
			else{
				if( i < (int)S[ii].size() && i >= (int)S[jj].size()  ){
					printf("NE\n");
					return 0;
				}  
			}
		}
	}
	
	auto order = kahn();
	
	if( (int)order.size() != 26 )
		puts("NE");	
	else{
		puts("DA");
		
		char sol[27], ch='a';		
		
		for(auto c: order)
			sol[c] = ch++;	
			
		sol[26] = '\0';
		printf("%s\n", sol);
	}
	
   return 0;
}
