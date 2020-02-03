
 #include <bits/stdc++.h>

 #define MAXN 50001

 using namespace std;

 int N, M, K, from, to, with;

 char mat[MAXN][16];

 struct ST{
     int off[4*MAXN], on[4*MAXN], moff[4*MAXN], mon[4*MAXN], col;
     bool mk[4*MAXN], W[4*MAXN];
     void lazy( int a, int b, int nod ){
          if ( !mk[nod] || a == b )
             return;
          int L = nod*2, R = nod*2+1;
          if ( W[nod] )
             on[L] = mon[L], on[R] = mon[R], off[L] = off[R] = 0;
          else
             off[L] = moff[L], off[R] = moff[R], on[L] = on[R] = 0;
          W[L] = W[R] = W[nod];
          mk[L] = mk[R] = true;
          mk[nod] = false;
     }
     void build( int a, int b, int nod ){
         if ( a == b ){
            off[nod] = (mat[a][col] == '0');
            on[nod] = 0;
            moff[nod] = off[nod];
            mon[nod] = off[nod]^1;
            return;
         }
         int mid = (a+b)/2, L = nod*2, R = nod*2+1;
         build( a, mid, L ), build( mid+1, b, R );
         off[nod] = off[L]+off[R];
         on[nod] = 0;
         moff[nod] = off[nod];
         mon[nod] = mon[L]+mon[R];
         return;
     }
     void update( int a, int b, int nod ){
         lazy( a, b, nod );
         if ( a > to || b < from )
            return;
         if ( a >= from && b <= to ){
            if ( with )
               on[nod] = mon[nod], off[nod] = 0;
            else
               off[nod] = moff[nod], on[nod] = 0;
            W[nod] = with;
            mk[nod] = true;
            return;
         }
         int mid = (a+b)/2, L = nod*2, R = nod*2+1;
         update( a, mid, L ), update( mid+1, b, R );
         on[nod] = on[L]+on[R];
         off[nod] = off[L]+off[R];
         return;
     }
 }data[16];

 int main(){

     freopen( "holpaint.in", "r", stdin );
     freopen( "holpaint.out", "w", stdout );

     scanf( "%d %d %d\n", &N, &M, &K );

     for ( int i = 1; i <= N; i++ ){
         for ( int j = 1; j <= M; j++ )
             scanf( "%c", &mat[i][j] );
         scanf( "\n" );
     }
     for ( int i = 1; i <= M; i++ )
         data[i].col = i, data[i].build( 1, N, 1 );

     for ( int ans, a, b, i; K--; ){
         scanf( "%d %d %d %d %d", &from, &to, &a, &b, &with );
         for ( ans = 0, i = 1; i <= M; i++ ){
             if ( i >= a && i <= b )
                data[i].update( 1, N, 1 );
             ans += data[i].on[1]+data[i].off[1];
         }
         printf( "%d\n", ans );
     }

 return 0;
 }
