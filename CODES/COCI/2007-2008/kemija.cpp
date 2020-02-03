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

int N;
int A[MX];
int64 sum;
int64 S[MX];
bool mk[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=0; i < N; i++){
		scanf("%d", &A[i]);
		sum += A[i];
	}
	
	if( N % 3 == 0 ){
		int64 s = 0, m = 1; 
		
		for(int i=3; i < N; i+=3){
			S[i] = S[(i+N-3)%N] + A[(i+N-1)%N] - A[(i+N-2)%N];
			m = max(m, 1 - S[i]);
		}
		
		for(int i=0; i < N; i+=3){
			S[i] += m;
			s += S[i];
		}
		
		m = 1;
		for(int i=4; i < N; i+=3){
			S[i] = S[(i+N-3)%N] + A[(i+N-1)%N] - A[(i+N-2)%N];
			m = max(m, 1 - S[i]);
		}
		
		for(int i=1; i < N; i+=3){
			S[i] += m;
			s += S[i];
		}
		
		sum = sum/3 - s;
		m = 0ll;
		
		for(int i=5; i < N; i+=3){
			S[i] = S[(i+N-3)%N] + A[(i+N-1)%N] - A[(i+N-2)%N];
			m += S[i];
		}
		
		m = (sum - m) / (N/3);
		
		for(int i=2; i < N; i+=3)
			S[i] += m;
			
		for(int i=0; i < N; i++)
			printf("%lld\n", S[i]);
	}
	else{
		int64 r = 0;
		for(int i=0; !mk[i]; i=(i+3)%N){
			r += S[i];
			mk[i] = true;
			
			if( !mk[(i+3) % N] ){
				S[(i+3) % N] = S[i] + A[(i+2) % N] - A[(i+1) % N];
			}
		}
		
		int64 x = (sum/3 - r) / N;
		
		for(int i=0; i < N; i++)
			printf("%lld\n", S[i] + x);
	}
	
   return 0;
}
