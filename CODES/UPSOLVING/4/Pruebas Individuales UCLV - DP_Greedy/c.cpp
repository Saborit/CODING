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

int N, sol, cant1, cant2, tot = 0;
int c1[MX], c2[MX], p1[MX], p2[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1, a, b; i<=N; i++){
        scanf("%d%d", &a, &b);
        
        if( a==1 ) c1[++cant1] = b;   
        if( a==2 ) c2[++cant2] = b;
        
        tot += a;   
    }
    
    sort(c1+1, c1+cant1+1); 
    sort(c2+1, c2+cant2+1); 
    
    int sol = INF;
    
    for(int i=1; i<=cant1; i++)
        p1[i] = p1[i-1] + c1[i];
        
    for(int i=1; i<=cant2; i++)
        p2[i] = p2[i-1] + c2[i];
    
    for(int i=0; i<=cant1; i++)
        for(int j=0; j<=cant2; j++)
            if( p1[i] + p2[j] <= tot - i - 2*j )
                sol = min(sol, tot - i - 2*j);    
                
    printf("%d\n", sol);

   return 0;
}
