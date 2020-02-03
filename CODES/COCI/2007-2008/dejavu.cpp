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

struct pt{
	int x, y;	
};

struct cmp_x{
	bool operator ()(const pt& a, const pt& b)const{
		return a.x < b.x;	
	}
};

struct cmp_y{
	bool operator ()(const pt& a, const pt& b)const{
		return a.y < b.y;	
	}
};

int N;
int cant[MX], L[MX], R[MX];
pt A[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d%d", &A[i].x, &A[i].y);	
	} 
	
	sort(A+1, A+N+1, cmp_x());
	
	vector<int> buffer;
	for(int i=1; i<=N; i++){
		buffer.pb(i);
		
		if( i == N || A[i+1].x > A[i].x ){
			for(auto j: buffer)
				cant[j] = buffer.size() - 1;
				
			buffer.clear();	
		}	
	} 
    
    int64 sol = 0;
    for(int i=1; i<=N; i++){
		sol += L[ A[i].y ];
		
		L[ A[i].y ] += cant[i];
	}
	
	for(int i=N; i > 0; i--){
		sol += R[ A[i].y ];
		
		R[ A[i].y ] += cant[i];
	}
    
    printf("%lld\n", sol);    

   return 0;
}
