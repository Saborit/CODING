/* Patrones de leche, by wizard98 
 * 
 * strings hashing
 * */
 #include <bits/stdc++.h>
 #define ULL unsigned long long
 #define W 20000+1
 using namespace std;

 int k, st, ed, pos, best;
 const int p = 1e9+7;

 map<ULL, int>U;

 struct HASH {
     int l, S[20001];
     ULL H[20001], P[20005];

     void make_hash(){
        P[0] = 1;
        for(int i=1; i<=W; i++)
           P[i] = P[i-1]*p;
        for(int i=0; i < l; i++){
           H[i] = S[i]*P[i];
           if(i) H[i]+=H[i-1];
        }
     }

     ULL hashing(int a, int b){
        ULL HxPw = (H[b] +(1ull<<64)- H[a-1])*P[W-a];

        return HxPw;
     }
 }C;

 bool check(int n){

    U.clear();

    for(int i=0; i+n-1 < C.l; i++){
        ULL HxPw = C.hashing(i, i+n-1);
        U[HxPw]++;
    }
    for(map<ULL, int>::iterator i = U.begin(); i!=U.end(); ++i){
       if(i->second >= k)
           return true;
    }

    return false;
 }


 main(){
    freopen("patterns.in", "r", stdin);
    freopen("patterns.out", "w", stdout);

    scanf("%d%d", &C.l, &k);
    for(int i=0; i < C.l; i++)
        scanf("%d", &C.S[i]);

    C.make_hash();

    for(st=0, ed=C.l; st <= ed; ){
        pos = (st+ed)/2;

        if(check(pos) && check(pos+1)){
           st = pos + 1;
           continue;
        }
        if(!check(pos) && !check(pos+1)){
           ed = pos - 1;
           continue;
        }
        if(check(pos) && !check(pos+1)){
           best = pos;
           break;
        }
    }

    printf("%d\n", best);

}

