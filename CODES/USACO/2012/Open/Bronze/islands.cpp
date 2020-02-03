/* Code by wizard98
 * 
 * ad_hoc implementation
 * */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

struct column{
	int h, id;
	
	bool operator < (const column &p)const{
		return h < p.h;	
	} 
};

struct interval{
	 int a, b;
	 
	 bool operator < (const interval &p)const{
		 return a != p.a ? a < p.a : b < p.b; 
	 }
};

int N, sol;
vector<column> A;
set<interval> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1, a; i<=N; i++){
	    scanf("%d", &a);
        A.pb({a, i});	    
	}
	    
	sort(all(A));
	
	S.insert({1, N});
	sol = 1;
	
	for(int i=0; i < (int)A.size(); ){
		int elem = A[i].h;
	    while( i < (int)A.size() && A[i].h == elem ) {
			auto it = S.lower_bound({A[i].id, A[i].id}); 
			if( it->a != A[i].id ) it--;	
			auto inter = *it;
			
			S.erase(it);
						
			if( inter.a < A[i].id ) S.insert({inter.a, A[i].id - 1});
			if( A[i].id < inter.b ) S.insert({A[i].id + 1, inter.b});
			
		    i++;
		}
		sol = max(sol, (int)S.size());	
	}
    
    printf("%d\n", sol);    

   return 0;
}


