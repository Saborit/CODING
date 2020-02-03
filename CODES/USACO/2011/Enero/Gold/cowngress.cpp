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

vector<vector<int>> kosaraju(int, vector<int>*);

struct two_sat{
	int N, M;
	bool mk[MX];
	char sol[MX];
	vector<int> G[2*MX];
	
	void add(bool b1, int a1, bool b2, int a2){
		G[2 * a1 - (!b1)].pb(2 * a2 - b2);	
		G[2 * a2 - (!b2)].pb(2 * a1 - b1);	
	}
	
	bool solve(){
		vector<vector<int>> scc = kosaraju(2*N, G);
		
		function<void(int)> dfs = [&](int nod){
			mk[nod] = true;
			
			for(auto nwn: G[nod]) if( !mk[nwn] )
				dfs(nwn);
		};
		
		for(auto& vec: scc){
			sort(all(vec));	
			
			for(int i=1; i < (int)vec.size(); i++)
				if( (vec[i-1] & 1) && vec[i] == vec[i-1] + 1 )
					return false;		
		}
		
		for(int i=1; i<=N; i++)
			sol[i] = '?';
		
		for(int i=1; i<=2*N; i++){
			for(int j=1; j<=2*N; j++) 
				mk[j] = false;
				
			dfs(i);
	
			if( (i&1) && mk[i+1] ) sol[(i+1)/2] = 'N';
			if( !(i&1) && mk[i-1] ) sol[i/2] = 'Y';
		}
		return true;
	}
};

vector<vector<int>> kosaraju(int cn, vector<int> G[]){
	bool mk[MX];
	stack<int> K;
	vector<int> T[MX];
	vector<vector<int>> scc;
		
	function<void(int, int)> dfs = [&](int nod, int pass){
		mk[nod] = !pass;
		
		if( pass ) scc.back().pb(nod);
		
		vector<int> adj = !pass ? G[nod] : T[nod];
		
		for(auto nwn: adj) if( (!mk[nwn]) ^ pass )
			dfs(nwn, pass);
		
		if( !pass ) K.push(nod);		
	};
		
	for(int i=1; i<=cn; i++){
		mk[i] = 0;
		for(auto j: G[i]) T[j].pb(i);
	}
	
	for(int i=1; i<=cn; i++) if( !mk[i] )
		dfs(i, 0);
		
	for(; !K.empty(); K.pop()) if( mk[K.top()] ){
		scc.pb({});
		dfs(K.top(), 1);		
	}
	
	return scc;	
}		

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int a, c;
    char b, d;
    
    two_sat G;
    
    scanf("%d%d\n", &G.N, &G.M);
    for(int i=1; i<=G.M; i++){
		scanf("%d %c %d %c\n", &a, &b, &c, &d);
		
		G.add(b&1, a, d&1, c);
	} 
    
    if( !G.solve() )
		printf("IMPOSSIBLE\n");
	else{
		for(int i=1; i<=G.N; i++)
			printf("%c", G.sol[i]);
		printf("\n");
	}

   return 0;
}
