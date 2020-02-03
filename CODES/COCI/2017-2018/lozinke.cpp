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

#define SIGMA 26
#define MN 15

struct disp{
	int64 a, b;
	
	disp operator + (disp p)const{
		return {(a + p.a) % MOD, (b + p.b) % MOD};	
	}
	disp operator - (disp p)const{
		return {(a + MOD - p.a) % MOD, (b + MOD - p.b) % MOD};	
	}
	disp operator * (disp p)const{
		return {(a * p.a) % MOD, (b * p.b) % MOD};	
	}
	bool operator == (disp p){ return a == p.a && b == p.b; }
	bool operator < (disp p)const{ return a != p.a ? a < p.a : b < p.b; }
};

const disp BASE = {37ll, 31ll};
disp P[MX];

void init(){
	P[0] = {1ll, 1ll};
	for(int i=1; i < MN; i++)
		P[i] = P[i-1] * BASE;
}

struct hasher{
	int N;
	disp H[MN];
	
	hasher(){}
	hasher(string& S){
		N = S.size();
		
		for(int i=0; i < N; i++){
			H[i] = P[i] * (disp){S[i] - 'a' + 1, S[i] - 'a' + 1};
			H[i] = H[i] + (i ? H[i-1] : (disp){0ll, 0ll}) ;
		}	
	}
	
	disp query(int a, int b){
		if( a > b ) return {0, 0};
		return (H[b] - (a ? H[a-1] : (disp){0, 0})) * P[MN-a-1];	
	}
};

int N, M;
char in[MN];
string A[MX];
set<disp> diff;
map<disp, int> S;
hasher H;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    init();
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
		scanf(" %s", &in);
		A[i] = string(in);
	}

	for(int i=1; i<=N; i++){
		H = hasher(A[i]);
		diff.clear();	
		
		for(int j=0; j < (int)A[i].size(); j++)	
			for(int k=j; k < (int)A[i].size(); k++){	
				diff.insert(H.query(j, k));
			}
		
		for(auto j: diff)
			S[j] += 1;		
	}
	
	int64 sol = 0;
	for(int i=1; i<=N; i++){
		H = hasher(A[i]);
		
		if( S.find(H.query(0, A[i].size()-1)) != S.end() )
			sol += S[H.query(0, A[i].size()-1)] - 1;
	}
	
	printf("%lld\n", sol);
	
   return 0;
}
