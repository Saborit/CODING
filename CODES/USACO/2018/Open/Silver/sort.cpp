/* Code by wizard98 
 * 
 * ad_hoc
 * */
 #include <bits/stdc++.h>
 #define MN 100000
 #define INF (1<<30)
 #define EPS 1e-9
 #define mid (x+xend)/2
 #define izq nod*2
 #define der nod*2+1
 #define MOD 1000000007
 #define debug(_fmt,...) fprintf(stderr,"("#__VA_ARGS__ ") = (" _fmt")\n",__VA_ARGS__)
 using namespace std;
 typedef long long int64;
 
 int N, sol, t;
 int A[MN+10], sorted[MN+10];
 map<int, int> M;
 
 int main(void){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        sorted[i] = A[i];
    }      
    
    sort(sorted+1, sorted+N+1);
    
    for(int i=1; i<=N; i++){
	    int pos = upper_bound(sorted+1, sorted+N+1, A[i]) - sorted;
	    
	    sol = max(sol, i - pos + 1);
	}
    
    printf("%d\n", sol+1);
    
    return 0;
}


