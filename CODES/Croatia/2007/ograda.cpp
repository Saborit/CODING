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

struct tri{
	int h, p, id;
	
	bool operator < (const tri& p)const{
		return this->p > p.p;	
	}
};

int N;
int64 sol;
int SOL[MX];
tri A[MX];
vector<int> pend;
multiset<pair<int, int>> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1, a; i<=N; i++){
		scanf("%d", &a);
		S.insert({a, i});
	}
	
	for(int i=1; i<=N; i++){
		scanf("%d%d", &A[i].h, &A[i].p);
		A[i].id = i;	
	} 
	
	sort(A+1, A+N+1);
	
	for(int i=1; i<=N; i++){
		auto it = S.upper_bound({A[i].h, INF}); 
		
		if( it == S.begin() ){
			pend.pb(A[i].id);
			continue;
		}
		it--;
		
		sol += A[i].p;
		SOL[it->sc] = A[i].id;	
		S.erase(it);
	}
	
	for(int i=1; i<=N; i++)
		if( !SOL[i] ){
			SOL[i] = pend.back();
			pend.pop_back();
		}
	
	printf("%lld\n", sol);
	for(int i=1; i<=N; i++)
		printf(i == N ? "%d\n" : "%d ", SOL[i]);

   return 0;
}
