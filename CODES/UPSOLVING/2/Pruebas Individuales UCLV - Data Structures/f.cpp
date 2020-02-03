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
        return a==p.a && b == p.b;    
    }     
};

char S[MX];

struct suffix_array{
    int ls, k, del;
    vector<vector<int> > P; 
    suffix L[MX];
    
    suffix_array():
        P(MX, vector<int>(20, 0))
    {}
    
    void build(char *S){
        ls = strlen(S);
        
        for(int i=0; i < ls; i++)
            P[i][0] = S[i];
           
        for(k=del=1; (del>>1) < ls; k++, del<<=1) {
            for(int i=0; i < ls; i++){
                L[i].a = P[i][k-1];
                L[i].b = (i + del < ls) ? P[i+del][k-1] : -1;
                L[i].p = i;
            }
            sort(L, L+ls);
            
            for(int i=0; i < ls; i++)
                P[ L[i].p ][k] = (i && L[i] == L[i-1]) ? P[ L[i-1].p ][k] : i;
        }   
    }
    
    int lcp(int x, int y){
        if( x==y ) return ls-x;
        
        int ans = 0;
        
        for(int i=k-1; i>=0 && x < ls && y < ls; i--){
            if( P[x][i] == P[y][i] ) 
                x += (1<<i), y += (1<<i), ans+=(1<<i);    
        }   
        return ans; 
    }
};

int T;
suffix_array SA;

void solve(){
    scanf("%s ", &S);
    SA.build(S);
    
    int64 sol = 0ll;
    
    for(int i=0; i < SA.ls; i++){
        sol += SA.lcp(0, i);
    }
    printf("%lld\n", sol);    
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d\n", &T);
    while(T--){
        solve();    
    }
    
   return 0;
}

