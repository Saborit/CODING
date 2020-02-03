/* Code by Saborit */
 #include<bits/stdc++.h>
 #define mid (x+xend)/2
 #define izq nod*2
 #define der nod*2+1
 using namespace std;

 int duty, q, a, b, asw, off, range;
 bool OK;

 struct inter{
    int s, f, vac, pos;
    bool mk;
 };

 struct Segmtree{
    int l;
    inter T[200010];

    void build(int x, int xend, int nod){
        if(x==xend){
           T[nod].s = T[nod].f = T[nod].vac = 1,
           T[nod].pos = x, T[nod].mk = 1;
        return;
        }

        T[nod].s = T[nod].f = T[nod].vac = xend - x + 1;
        T[nod].pos = x;
        build(x, mid, izq);
        build(mid+1, xend, der);
    }

    inter update(int x, int xend, int nod){
        if(T[nod].mk && x < xend)
           lazy(x, xend, nod);

        if(a<=x && xend<=b){
           T[nod].mk = 1;
           if(off){
              T[nod].s = T[nod].f = T[nod].vac = xend - x + 1;
              T[nod].pos = x;
           }
           else
              T[nod].s = T[nod].f = T[nod].vac = T[nod].pos = 0;
           return T[nod];
        }

        if(x > b || xend < a)
           return T[nod];

        inter IZQ = update(x, mid, izq);
        inter DER = update(mid+1, xend, der);

        if(IZQ.vac > DER.vac)
           T[nod].vac = IZQ.vac, T[nod].pos = IZQ.pos;
        else
           T[nod].vac = DER.vac, T[nod].pos = DER.pos;

        T[nod].s = IZQ.s, T[nod].f = DER.f;
        if(IZQ.s==IZQ.f && IZQ.s == mid - x + 1)
           T[nod].s += DER.s;
        if(DER.s==DER.f && DER.s == xend - mid)
           T[nod].f += IZQ.f;

        if(IZQ.f + DER.s > T[nod].vac)
           T[nod].vac = IZQ.f + DER.s, T[nod].pos = mid - IZQ.f  + 1;
        if(T[nod].s > T[nod].vac)
           T[nod].vac = T[nod].s, T[nod].pos = x;
        if(T[nod].f > T[nod].vac)
           T[nod].vac = T[nod].f, T[nod].pos = xend - T[nod].f + 1;

       return T[nod];
    }

    void query(int x, int xend, int nod){
       if(T[nod].mk && x < xend)
          lazy(x, xend, nod);

       if(T[izq].vac >= range){
          if(!OK) query(x, mid, izq);
          return;
       }
       if(T[izq].f + T[der].s >= range){
          asw = mid - T[izq].f + 1;
          OK = 1;
          return;
       }
       if(T[der].vac >= range){
          if(!OK) query(mid+1, xend, der);
          return;
       }

       OK = 1, asw = 0;
    }

    void lazy(int x, int xend, int nod){
        T[nod].mk = 0;
        T[izq].mk = T[der].mk = 1;

        if(!T[nod].s){
           T[izq].s = T[izq].f = T[izq].pos = T[izq].vac = 0;
           T[der].s = T[der].f = T[der].pos = T[der].vac = 0;
        }
        else{
           T[izq].s = T[izq].f = T[izq].vac = mid - x + 1;
           T[izq].pos = x;
           T[der].s = T[der].f = T[der].vac = xend - mid;
           T[der].pos = mid + 1;
        }
    }
 }ST;

 main(){
     //freopen("hotel.in", "r", stdin);
     //freopen(".out", "w", stdout);

     scanf("%d%d", &ST.l, &q);
     ST.build(1, ST.l, 1);

     while(q--){
        scanf("%d", &duty);
        if(duty==1){
           scanf("%d", &range);
           OK = 0;
           ST.query(1, ST.l, 1);
           printf("%d\n", asw);
           off = 0;
           if(asw){
              a = asw, b = asw + range - 1;
              ST.update(1, ST.l, 1);
           }
        }
        else{
           scanf("%d%d", &a, &b);
           b = b + a - 1;
           off = 1;
           ST.update(1, ST.l, 1);
        }
     }
 return 0;
 }
