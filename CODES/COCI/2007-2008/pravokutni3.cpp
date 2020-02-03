/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1505
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
	int64 x, y;
	
	pt operator - (const pt &p){ return {x - p.x, y - p.y};	}
};

struct ray : pt{
	int quad;
	
	ray(pt p, int q): pt(p), quad(q){}
	
	void rotate90(){
		swap(x, y); x = -x;
		quad = (quad + 1) % 4;	
	}
	
	bool operator < (const ray &p)const{
		return y * p.x < x * p.y;	
	}
	bool operator == (const ray &p)const{
		return y * p.x == x * p.y;	
	}
};

int N;
int cant[4];
pt A[MX];
vector<ray> v;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%lld%lld", &A[i].x, &A[i].y); 
    
    int64 sol = 0;
    
    for(int i=1; i<=N; i++){
		v.clear();
		
		for(int j=1; j<=N; j++){
			if( i == j ) continue;	
			
			ray tmp = {A[j] - A[i], 0};
			
			while( !(tmp.x > 0 && tmp.y >= 0) ) tmp.rotate90();
			
			v.pb(tmp);
		}
		
		sort(all(v));
		
		cant[0] = cant[1] = cant[2] = cant[3] = 0;
		
		for(int j=0; j < (int)v.size(); j++){
			cant[ v[j].quad ]++;
			
			if( j == (int)v.size()-1 || !(v[j] == v[j+1]) ){
				sol += cant[0] * cant[1];
				sol += cant[1] * cant[2];
				sol += cant[2] * cant[3];
				sol += cant[3] * cant[0];
				
				cant[0] = cant[1] = cant[2] = cant[3] = 0;	
			}
		}	
	}  
	
	printf("%lld\n", sol);  

   return 0;
}
