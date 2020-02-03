/*
  Cleaning Shifts, by wizard98
  sweep_line
  C++11 Code
  27.8.2017
*/
 #include <bits/stdc++.h>
 using namespace std;

 struct event{
     int x, ty, id;

     bool operator < (const event p)const{
         return (p.x==x) ? p.ty < ty : p.x > x;
     }
 };

 int N, D, dp, sol = (1<<30);
 int cost[25010];
 vector<event> E;
 multiset<int> S;

 main(void){
    freopen("cleaning.in", "r", stdin);
    freopen("cleaning.out", "w", stdout);

    scanf("%d%d", &N, &D);
    for(int i=1, a, b; i<=N; i++){
        scanf("%d%d", &a, &b);
        b++;
        E.push_back((event){a, 1, i});
        E.push_back((event){b, 0, i});
    }

    sort( E.begin(), E.end() );

    if( E[0].x > 1 or E[E.size()-1].x < D + 1 ){
        printf("-1\n");
        return 0;
    }

    for(int i=0; i < E.size(); i++){
        if( E[i].x==1 )
            dp = 0;
        else if( S.empty() ){
            printf("-1\n");
            return 0;
        }
        else{
            dp = *S.begin();
        }

        if( E[i].ty ){
           cost[ E[i].id ] = dp + 1;
           S.insert( dp + 1 );
        }
        else{
           S.erase( S.find(cost[ E[i].id ]) );
           cost[ E[i].id ] = 0;
        }
        if( E[i].x - 1 == D )
            sol = min(sol, dp);
    }

    printf("%d\n", sol);

}
