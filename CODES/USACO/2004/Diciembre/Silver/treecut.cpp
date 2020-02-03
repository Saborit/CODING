/*
  Tree Cutting, by wizard98
  graphs trees
  C++11 Code
  28.8.2017
*/
 #include <bits/stdc++.h>
 using namespace std;

 int cn;
 bool mk[10010];
 vector<int> G[10010], S;

 int dfsGraph(int nod){
     mk[nod] = 1;

     int cantChilds = 0;
     bool isAnswer = 1;

     for( auto nwn: G[nod] ){
        if( !mk[nwn] ){
            int nwnChilds = dfsGraph(nwn) + 1;
            if( nwnChilds > double(cn/2) )
                isAnswer = 0;
            cantChilds += nwnChilds;
        }
     }

     if( cn - cantChilds - 1  > double(cn/2) )
        isAnswer = 0;

     if( isAnswer ) S.push_back(nod);

     return cantChilds;
 }

 main(void){
    freopen("treecut.in", "r", stdin);
    freopen("treecut.out", "w", stdout);

    scanf("%d", &cn);
    for(int i=1, a, b; i < cn; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfsGraph(1);

    sort( S.begin(), S.end() );

    for( auto i: S )
        printf("%d\n", i);

    return 0;
}
