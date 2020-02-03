/*
  Secret Milk Pipes, by wizard98
  graphs mst
  C++11 Code
  17.8.2017
*/
 #include<bits/stdc++.h>
 using namespace std;

 struct edge{
    int nod, nwn, cost, inTree;

    bool operator < (const edge &p)const{
       return cost < p.cost;
    }
 };

 struct par{
    int nod, cost;

    bool operator < (const par &p)const{
       return cost < p.cost;
    }
 };

 int cn, ca, setNod, setNwn, mst, add = (1<<30);
 int S[2010], R[2010], M[2010][2010];
 bool mk[2010];
 vector<edge> G;
 vector<par> T[2010];

 int find_set(int nod){
    if( S[nod] != nod )
       return S[nod] = find_set(S[nod]);
    return S[nod];
 }

 void join_set(int nod, int nwn){
     if( R[nod] > R[nwn] )
        S[nwn] = nod, R[nod]++;
     else
        S[nod] = nwn, R[nwn]++;
 }

 void fillRow(int nod, int ni){
     mk[nod] = 1;

     for(int i=0; i < T[nod].size(); i++){
         int nwn = T[nod][i].nod;

         if( !mk[nwn] ){
            M[ni][nwn] = max( M[ni][nod], T[nod][i].cost );
            fillRow(nwn, ni);
         }
     }
 }

 main(void){
    freopen("secret.in", "r", stdin);
    freopen("secret.out", "w", stdout);

    scanf("%d%d", &cn, &ca);
    for(int i=0, a, b, c; i < ca; i++){
        scanf("%d%d%d", &a, &b, &c);
        G.push_back((edge){a, b, c, 0});
    }

    sort( G.begin(), G.end() );

    for(int i=1; i<=cn; i++)
        S[i] = i, R[i] = 1;

    for(int i=0; i < G.size(); i++){
        setNod = find_set(G[i].nod);
        setNwn = find_set(G[i].nwn);

        if( setNod != setNwn ){
           mst += G[i].cost;
           G[i].inTree = 1;

           T[G[i].nod].push_back((par){G[i].nwn, G[i].cost});
           T[G[i].nwn].push_back((par){G[i].nod, G[i].cost});

           join_set(setNod, setNwn);
        }
    }

    for(int i=1; i<=cn; i++){
        for(int j=1; j<=cn; j++)
            mk[j] = 0, M[i][j] = -(1<<30);
        fillRow(i, i);
    }

    for( auto edge: G ){
        if( edge.inTree )
            continue;

        add = min( add, edge.cost - M[edge.nod][edge.nwn] );
    }

    printf("%d\n", mst + add);

    return 0;
}
