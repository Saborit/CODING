/* Turnos de Limpieza, by wizard98
  sweep_line
  C++11 Code
  27.8.2017
*/
 #include <bits/stdc++.h>
 using namespace std;

 struct event{
     int x, ty, id, cost;

     bool operator < (const event p)const{
         return (p.x==x) ? p.ty < ty : p.x > x;
     }
 };

 int N, A, B, dp, sol = (1<<30);
 int cost[25010];
 vector<event> E;
 multiset<int> S;


 main(void){
    freopen("clean.in", "r", stdin);
    freopen("clean.out", "w", stdout);

    scanf("%d%d%d", &N, &A, &B);
    for(int i=1, a, b, c; i<=N; i++){
        scanf("%d%d%d", &a, &b, &c);
        b++;
        E.push_back((event){a, 1, i, c});
        E.push_back((event){b, 0, i, c});
    }

    sort( E.begin(), E.end() );

    if( E[0].x > A or E[E.size()-1].x < B + 1 ){
        printf("-1\n");
        return 0;
    }

    for(int i=0; i < E.size(); i++){
        if( E[i].x==A )
            dp = 0;
        else if( S.empty() ){
            printf("-1\n");
            return 0;
        }
        else{
            dp = *S.begin();
        }

        if( E[i].ty ){
           cost[ E[i].id ] = dp + E[i].cost;
           S.insert( dp + E[i].cost );
        }
        else{
           S.erase( S.find(cost[ E[i].id ]) );
           cost[ E[i].id ] = 0;
        }
        if( E[i].x - 1 == B )
            sol = min(sol, dp);
    }

    printf("%d\n", sol);

}
