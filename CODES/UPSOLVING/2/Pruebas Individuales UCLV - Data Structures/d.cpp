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

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int N, t;
ordered_set S;    

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1, a; i<=N; i++){
         scanf("%d", &a);
         
         S.insert({a, t++});
         
         double media = 0.0;
         
         if( (int)S.size() & 1 ){
              media = (S.find_by_order((int)S.size()/2))->first;   
         }
         else{
             auto it = S.find_by_order((int)S.size()/2);
             media += it->first;
             it--;
             media += it->first;
             
             media /= 2.0;    
         }
         
         printf("%.1f\n", media);    
    } 
        
   return 0;
}
