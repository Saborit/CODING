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

struct suffix{
	int a, b, p;
	
	bool operator < (const suffix &p)const{
		return a==p.a ? b < p.b : a < p.a;
	}
	bool operator == (const suffix &p)const{
		return a==p.a && b==p.b;
	}
};

struct suffix_array{
	int k, del, ls;
	vector<vector<int>> P;
	suffix L[MX];
	
	suffix_array(char *S) : P(MX, vector<int>(20, 0)){
		ls = strlen(S);
		
		for(int i=0; i < ls; i++)
			P[i][0] = S[i] - 'A';
			
		for(k=del=1; (del>>1) < ls; k++, del<<=1){
			for(int i=0; i < ls; i++){
				L[i] = {
					P[i][k-1],
					i + del < ls ? P[i+del][k-1] : -1,
					i
				};
			}
			sort(L, L+ls);
			
			for(int i=0; i < ls; i++)
				P[ L[i].p ][k] = (i && L[i]==L[i-1]) ? P[ L[i-1].p ][k] : i;
		}
	}
	
	int order(int x){ return P[x][k-1]; }
};

int N;
char S[MX];
string sol;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d\n", &N);
    for(int i=0; i < N; i++) 
        scanf("%c\n", &S[i]);
    S[N] = '$';
    for(int i=N+1, j=N-1; i<=2*N; i++, j--)
		S[i] = S[j];
    S[2*N+1] = '\0';
    
    suffix_array SA(S);
    
    for(int i=0, j=N-1; i<=j; ){
		if( SA.order(i) < SA.order(2*N-j) ){
			sol.pb(S[i]);
			i++;	
		}	
		else{
			sol.pb(S[j]);
			j--;	
		}
	}
	
	for(int i=0; i < (int)sol.size(); i++){
		if( i && i % 80 == 0 ) printf("\n");
		printf("%c", sol[i]);	
	}
	printf("\n");
	
   return 0;
}
