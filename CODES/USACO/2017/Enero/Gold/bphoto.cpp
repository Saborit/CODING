/* Code by Saborit
 * 
 * implementation data_structures stl
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

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int N, t;
int A[MX], L[MX], R[MX];
ordered_set S;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]); 
    
    
    for(int i=1; i<=N; i++){
        L[i] = S.size() - S.order_of_key(A[i] + 1);    
        S.insert(A[i]);
    }
    
    S.clear();
    
    for(int i=N; i > 0; i--){
        R[i] = S.size() - S.order_of_key(A[i] + 1);
        S.insert(A[i]);    
    }
    
    int sol = 0;
    for(int i=1; i<=N; i++)
        sol += max(L[i], R[i]) > 2 * min(L[i], R[i]);   
    
    printf("%d\n", sol);     

    return 0;
}
