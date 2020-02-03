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

#define MN 100000

typedef int type;

struct monotonic : deque<pair<type, int>>{
	void add(type val, int x){
		while( !empty() && val <= back().fr )
			pop_back();
		push_back({val, x});
	}

	type top(){ return front().fr; }

	void pop(int x){ if( front().sc == x ) pop_front(); }
};

int N, K;
int A[MX], dp[MX], acum[MX];

int sum(int i, int j){
    if( i > j ) return 0;
    return acum[j] - (i ? acum[i-1] : 0);
}

bool solve(int limit){
	for(int i=1; i<=N; i++)
		dp[i] = INF;
	dp[0] = 0;

	monotonic Q;
	Q.add(0, 0);

	for(int i=1, last=0; i<=N; i++){
		while( sum(last + 1, i) > limit )
		    Q.pop(last++);
		
		if( !Q.empty() )
			dp[i] = Q.top() + 1;
		Q.add(dp[i], i);
	}
	
	return dp[N] <= K;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);

    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		acum[i] = acum[i-1] + A[i];
	}

    int p = MN;
    for(int i=log2(MN); ~i; i--)
        if( p-(1<<i) >= 0 && solve(p-(1<<i)) )
            p -= (1<<i);

    printf("%d\n", p);

   return 0;
}
