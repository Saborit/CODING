/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 1000005
#define INF (1ll<<62)
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

int N;
int64 sol;
int64 A[MX];
int64 sum;
int64 acum[2][MX];

inline int64 query(int a, int b){
    if( a > b ) return 0;
    return acum[a % 2][b] - acum[a % 2][a - 1];	
} 

int64 f(int a, int b){
	if( a > b ) return 0;
    if( (b - a + 1) & 1 ) return query(a, b);  
    
    int64 ans = A[a] - query(a + 1, b); 
    ans = max(ans, A[b] - query(a, b - 1)); 
    if( a < b ) ans = max(ans, A[a] + A[b] - f(a + 1, b - 1)); 
    
    return ans;
}

void solve(){
    sol = f(1, N);	
}

static void run_with_stack_size(void (*func)(), size_t stsize) {
	char *stack, *send;
	stack = (char *)malloc(stsize);
	send = stack + stsize - 16;
	send = (char *)((uintptr_t)send/16 * 16);
	
	asm volatile(
		"mov %%rsp, (%0)\n"
		"mov %0, %%rsp\n"
		:
		: "r" (send));
	func();
	
	asm volatile(
		"mov (%0), %%rsp\n"
		:
		: "r" (send));
	free(stack);
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf("%lld", &A[i]);
		sum += A[i];
    }
    
    for(int i=1; i<=N; i++)
        acum[1][i] = acum[1][i-1] + A[i] * ((i & 1) ? 1ll: -1ll), 
        acum[0][i] = acum[0][i-1] + A[i] * ((i & 1) ? -1ll: 1ll); 
    
    run_with_stack_size(solve, 100 * (1<<20));
	
	printf("%lld %lld\n", sum - (sum - sol)/2, (sum - sol)/2);
        
   return 0;
}


