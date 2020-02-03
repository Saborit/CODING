/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 300005
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
typedef long long int64;
typedef unsigned long long unt64;

#define SIGMA 26

struct trie{
	bool end[MX];
	vector<vector<int>> T;
	
	trie(){
		T.pb(vector<int>(SIGMA, -1));
		
		for(int i=0; i < MX; i++) 
			end[i] = false;	
	}
	
	void add(string& S){
		int nod = 0;
		
		for(int i=0; i < (int)S.size(); i++){
			int c = S[i] - 'a';
			
			if( T[nod][c] == -1 ){
				T[nod][c] = T.size();
				T.pb(vector<int>(SIGMA, -1));
			}	
			nod = T[nod][c];	
		}
		end[nod] = true;	
	}
	
	bool graph(string& S, vector<int>* G){
		int nod = 0;
		
		for(int i=0; i < (int)S.size(); i++){
			int c = S[i] - 'a';
			
			if( end[nod] )
				return false;
			
			for(int cc=0; cc < SIGMA; cc++) if( ~T[nod][cc] && c != cc )
				G[c].pb(cc);
			nod = T[nod][c];		
		}
		return true;	
	}
};

vector<int> kahn(int cn, vector<int>* G){
	vector<int> ans, off(cn+1, 0), delta(cn+1, 0);
	queue<int> Q;
	
	for(int i=0; i < cn; i++)
		for(auto j: G[i]) 
			delta[j]++;
			
	for(int i=0; i < cn; i++)
		if( !delta[i] )
			Q.push(i);
			
	for(; !Q.empty(); Q.pop()){
		int nod = Q.front();
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

int N;
string S[MX];
vector<int> G[SIGMA+5];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
     
    cin >> N;
    
    trie T;
    for(int i=1; i<=N; i++){
		cin >> S[i];	
		
		T.add(S[i]);
	}
		
	vector<string> sol;
	
	for(int i=1; i<=N; i++){	
		for(int j=0; j < SIGMA; j++)
			G[j].clear();
		
		if( T.graph(S[i], G) && kahn(SIGMA, G).size() == SIGMA ) 
			sol.pb(S[i]);
	}
	
	printf("%d\n", (int)sol.size());
	for(auto i: sol)
		printf("%s\n", i.c_str());		
	
   return 0;
}
