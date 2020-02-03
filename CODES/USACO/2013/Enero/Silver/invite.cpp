/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 250005
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

int N, K;
int SET[MX];
bool mk[MX];
vector<int> in[MX], S[MX];
queue<int> Q;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for(int i=1; i<=K; i++){
		scanf("%d", &SET[i]);
		
		for(int j=0, a; j < SET[i]; j++){
			scanf("%d", &a);
			S[i].pb(a);	
			
			in[a].pb(i);
		}
	} 
    
    S[0] = {1};
    int sol = 0;
    
    for(Q.push(0); !Q.empty(); Q.pop()){
		for(auto elem: S[Q.front()]) if( !mk[elem] ){
			mk[elem] = true;
			sol++;
			
			for(auto st: in[elem]){
				SET[st]--;
				
				if( SET[st] == 1 )
					Q.push(st);	
			}
		}
	}
    
    printf("%d\n", sol);    

   return 0;
}
