/*
  Phidias, by wizard98
  dp
  C++11 Code
  21.8.2017
*/
 #include <bits/stdc++.h>
 using namespace std;

 int N, M, n;
 int dp[610][610];

 int f(int x, int y){
    if( dp[x][y] < (1<<30) )
        return dp[x][y];

    dp[x][y] = x * y;

    for(int i=1; i < x; i++)
        dp[x][y] = min(dp[x][y], f(i, y) + f(x-i, y) );
    for(int i=1; i < y; i++)
        dp[x][y] = min(dp[x][y], f(x, i) + f(x, y-i) );

    return dp[x][y];
 }

 main(void){
    //~ freopen("phidias.in", "r", stdin);
    //~ freopen("phidias.out", "w", stdout);

    scanf("%d%d\n%d", &N, &M, &n);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            dp[i][j] = (1<<30);

    for(int i=1, a, b; i<=n; i++){
        scanf("%d%d", &a, &b);
        dp[a][b] = 0;
    }

    printf("%d\n", f(N, M));

    return 0;
}
