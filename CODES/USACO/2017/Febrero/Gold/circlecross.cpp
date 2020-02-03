/* Code by Saborit 
 * 
 * mo
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

struct mo{
    struct query{
        int x, xend, id, ans;
    };
    
    struct bundle{
        int cant;
        bool C[MX];
        bundle(): cant(0){}
        
        void add(int x){
            if( C[x] ) cant--;
            else cant++;
            
            C[x] ^= 1;   
        }    
    };
    
    int N;
    int A[MX];
    vector<query> Q;
    
    void add_query(int a, int b, int id){
        Q.pb({a, b, id, -1});
    }
    
    vector<int> solve(){
        sort(all(Q), [this](query& a, query& b){
            int sq = sqrt(Q.size());   
            if( a.x/sq != b.x/sq ) return a.x/sq < b.x/sq;
            return a.xend/sq < b.xend/sq; 
        }); 
        
        int l = 1, r = 0;
        bundle B;
        
        for(auto& q: Q){
            while( r < q.xend )
                B.add(A[++r]);    
            while( l < q.x )
                B.add(A[l++]);
            while( r > q.xend )
                B.add(A[r--]);
            while( l > q.x ) 
                B.add(A[--l]); 
                
            q.ans = B.cant;              
        } 
        vector<int> ans(Q.size() + 1);
        for(auto q: Q)
            ans[q.id] = q.ans;
        
        return ans;          
    }    
}M;

vector<int> A[MX];

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &M.N);
    for(int i=1; i<=2*M.N; i++){
        scanf("%d", &M.A[i]);
        
        A[ M.A[i] ].pb(i); 
    } 
    
    for(int i=1; i<=M.N; i++){
        if( A[i][0] > A[i][1] ) swap(A[i][0], A[i][1]);
        
        M.add_query(A[i][0], A[i][1], i);
    }
    
    int64 sol = 0ll;
    for(auto i: M.solve()) sol += i;
    
    printf("%lld\n", sol/2ll);

   return 0;
}


