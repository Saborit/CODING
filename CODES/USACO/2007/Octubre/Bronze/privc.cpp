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

int N, c1, c2, c3, sol;
int A[MX];
vector<pair<int, int>> V; 

inline bool in1(int x){ return 1<=x && x<=c1; }
inline bool in2(int x){ return c1+1<=x && x<=c1+c2; }
inline bool in3(int x){ return c1+c2+1<=x && x<=N; }

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		
		c1 += A[i] == 1;	
		c2 += A[i] == 2;	
		c3 += A[i] == 3;	
	}
    
    for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		if( in1(i) && in2(j) && A[i] == 2 && A[j] == 1 ){
			swap(A[i], A[j]);
			sol++;
		}
		else if( in1(i) && in3(j) && A[i] == 3 && A[j] == 1 ){
			swap(A[i], A[j]);
			sol++;
		}
		else if( in2(i) && in3(j) && A[i] == 3 && A[j] == 2 ){
			swap(A[i], A[j]);
			sol++;
		}
		
	for(int i=1; i<=c1; i++)
		sol += 2 * (A[i] != 1);
		
	printf("%d\n", sol);

   return 0;
}
