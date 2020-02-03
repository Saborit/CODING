/* Code by wizard98
 * 
 * greedy brute_force
 *  */
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
 
 int N, sol;
 int A[MN+10];
 
 main(void){
	 
	//#ifdef OJUDGE
    	freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    //#endif 
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
     
    sort(A+1, A+N+1, greater<int>());
    
    for(int i=1; i<=N; i++)
        sol += A[i] >= i-1;        
    
    printf("%d\n", sol);            

    return 0;
}


