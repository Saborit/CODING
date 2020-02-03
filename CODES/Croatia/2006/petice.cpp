/* Code by Saborit 
 * 
 * greedy
 * */
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

int N, K;
char S[20], A[20];

int count(char *S){
    int ans = 0;
    
    for(int i=1; i<=16; i++)    
        ans += S[i] == '5';
    
    return ans;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%s %d", S+1, &K);
    N = strlen(S+1);
    
    for(int i=0; i<=16; i++)
        A[i] = '0';
    A[17] = '\0';
    
    for(int i=16, j=N; j > 0; i--, j--)
        A[i] = S[j];
    
    for(int i=16; i > 0; ){
        if( A[i] + 1 == '5' ){
            A[i]++;
            i--;
            if( count(A) == K ) break;             
            continue;    
        }
        
        for(int j=i; j > 0; j--)
            if( A[j] + 1 == ':' )
                A[j] = '0';
            else{
                A[j]++;
                break;    
            }
            
        if( count(A) == K ) break;             
    }
    
    bool ok = false;
    for(int i=1; i<=16; i++){
        if( A[i] != '0' ) ok = true;    
        if( ok ) printf("%c", A[i]);
    }printf("\n");    
        
   return 0;
}


