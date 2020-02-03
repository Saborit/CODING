/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1000005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int B, E, a;
int b[MX], e[MX]; 
char c;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &B, &E);
    
    int pb = 1;
    b[1] = 0;
    for(int i=1, v=1; i<=B; i++){
		scanf("%d %c", &a, &c);
		
		int inc = c == 'L' ? -1 : 1;
		
		for(int j=0; j < a; j++){
			v += inc;
			b[++pb] = v;	
		}
	}
    
    int pe = 1; 
    e[1] = 0;
    for(int i=1, v=1; i<=E; i++){
		scanf("%d %c", &a, &c);
		
		int inc = c == 'L' ? -1 : 1;
		
		for(int j=0; j < a; j++){
			v += inc;
			e[++pe] = v;	
		}
	}
	
	while( pb < pe )
		b[++pb] = b[pb];
	while( pe < pb )
		e[++pe] = e[pe];
	
	int sol = 0;
	for(int i=2; i<=min(pb, pe); i++)
		sol += (b[i] == e[i] && b[i-1] != e[i-1]);
    
    printf("%d\n", sol);    

   return 0;
}
