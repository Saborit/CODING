/* Code by wizard98
 * 
 * greedy
 *  */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct route{
    int a, b;
    
    bool operator < (const route &p)const{
		return a != p.a ? a < p.a : b < p.b;
	}	
};

int N, M;
int64 sol;
route A[MX];
multiset<int> back;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++){
	    scanf("%d%d", &A[i].a, &A[i].b);
	    back.insert(A[i].b);	
	} 
	
	sort(A+1, A+N+1);
	
	int pos = 0, _min = INF;
	
	for(int i=1; i<=N; i++){
	    sol += A[i].a - pos;
	    
	    back.erase(back.lower_bound(A[i].b));
	    _min = min(_min, A[i].b);
		
	    if( back.empty() || *back.begin() > A[i].a ){
		    sol += 2 * (A[i].a - _min > 0 ? (A[i].a - _min) : 0);
		    _min = INF;	
		}
		
		pos = A[i].a;    	
	}
	
	printf("%lld\r\n", sol + M - pos);
        

   return 0;
}


