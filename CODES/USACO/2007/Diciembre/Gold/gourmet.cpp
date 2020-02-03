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

int N, M;
pair<int, int> cows[MX];
pair<int, int> graces[MX]; 
multiset<pair<int, int>> byprice;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
		scanf("%d%d", &cows[i].sc, &cows[i].fr);	
	for(int i=1; i<=M; i++)
		scanf("%d%d", &graces[i].sc, &graces[i].fr);
	
	sort(cows+1, cows+N+1);	
	sort(graces+1, graces+M+1);	
	
	int64 sol = 0;
	for(int i=N, j=M; i > 0; i--){
		while( j > 0 && graces[j].fr >= cows[i].fr ){
			byprice.insert({graces[j].sc, graces[j].fr});
			j--;
		}
			
		auto it = byprice.upper_bound({cows[i].sc, cows[i].fr});
		
		if( it == byprice.end() )
			return !printf("-1\n"); 	
		
		sol += it->fr;
		byprice.erase(it);
	}
        
	printf("%lld\n", sol);
	
   return 0;
}
