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
	int x, y;
	
	bool operator < (const pt& p)const{
		return x != p.x ? x < p.x : y < p.y;	
	}
	bool operator == (const pt& p)const{
		return x == p.x && y == p.y;	
	}
};

struct line{
	int64 a, b, c;
	
	line(int64 a, int64 b, int64 c): a(a), b(b), c(c){
		stdize();
	} 
	line(pt p, pt q){
		a = q.y - p.y;
		b = p.x - q.x;
		c = p.x * a + p.y * b;
		stdize();
	}
	
	void stdize(){
		int64 gcd = __gcd(__gcd(abs(a), abs(b)), abs(c));	
		if( a < 0 ) 
			gcd *= -1;
		else if( a == 0 && b < 0 ) 
			gcd *= -1;
		else if( a == 0 && b == 0 && c < 0 ) 
			gcd *= -1;
			
		a /= gcd, b /= gcd, c /= gcd;
	}
	
	bool operator < (const line& p)const{
		if( a != p.a ) return a < p.a;	
		if( b != p.b ) return b < p.b;	
		return c < p.c;
	}	
};

/* Devuelve una recta perpendicular a la recta l y que pase por el punto p */
line perp_line(line l, pt p){
	return line(-l.b, l.a, -l.b * p.x + l.a * p.y);
} 

int N;
pt A[MX];
map<line, vector<pt>> S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d%d", &A[i].x, &A[i].y);
		
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++){
		S[line(A[i], A[j])].pb(A[i]);
		S[line(A[i], A[j])].pb(A[j]);
	}
	
	for(auto &i: S){
		sort(all(i.sc));
		unique(i.sc);
	}
			
	int sol = 0;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++){
		if( S.find(perp_line(line(A[i], A[j]), A[i])) != S.end() ){
			sol += S[perp_line(line(A[i], A[j]), A[i])].size() - 1;
		}
		if( S.find(perp_line(line(A[i], A[j]), A[j])) != S.end() ){
			sol += S[perp_line(line(A[i], A[j]), A[j])].size() - 1;		
		}
	}
	
	printf("%d\n", sol/2);    

   return 0;
}
