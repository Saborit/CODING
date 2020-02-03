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

struct tile{
	int a, b;
	
	bool operator < (const tile& p)const{
	    return a + b < p.a + p.b; 	
	}
};

int N;
tile A[MX];
stack<int> sol;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d%d", &A[i].a, &A[i].b);
    
    sort(A+1, A+N+1);
    
    int acum = 0;
    for(int i=1; i<=N; i++){
		sol.push((A[i].a + A[i].b + acum) % 10);
		acum = (A[i].a + A[i].b + acum) / 10;
	}    
	if( acum ) sol.push(acum);
	
	while( !sol.top() ) sol.pop();
	
	while( !sol.empty() ){
		printf("%d", sol.top());
		sol.pop();
	}	
	printf("\n");	

   return 0;
}


