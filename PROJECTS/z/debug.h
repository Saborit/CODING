/*
 Debug Library for Codeforces (C++17)

 Uso:

 - Para imprimir una matriz A usar
   db() << mt(A, n, m);

 - Para imprimir un arreglo de vectores, usar
   db() << mp(G, n)
 
 - Para imprimir un numero x en binario, usar
   db() << bin(x);

*/
#include <bits/stdc++.h>
#include <unistd.h>
#include "boost/pfr/precise.hpp"
using namespace std;
using namespace boost::pfr::ops;

#define endl '\n';
#define SEP true

#define VAR_NAME(X) #X

/* Definiciones Utiles */
template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

/* Estructura Debbuger */
struct db{
#ifdef LOCAL
	bool long_flag;

	db(): long_flag(false){}

	db& operator << (bool d) {
		long_flag = true;
		return *this;
	}

	/* Vector */
	template < class c >
	db& operator << (vector < c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Set */
	template < class c >
	db& operator << ( set< c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Multiset */
	template < class c >
	db& operator << ( multiset< c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Map */
	template < class c, class b >
	db& operator << ( map< b, c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Queue */
	template < class c >
	db& operator << ( queue< c > d) {
		vector<c> tmp;

		while( !d.empty() ){
			tmp.pb(d.front());
			d.pop();
		}

		for(auto i: tmp)
			d.push(i);

		return *this << range(begin(tmp), end(tmp));
	}

	/* Priority Queue */
	template < class c >
	db& operator << ( priority_queue< c > d) {
		vector<c> tmp;

		while( !d.empty() ){
			tmp.pb(d.top());
			d.pop();
		}

		for(auto i: tmp)
			d.push(i);

		return *this << range(begin(tmp), end(tmp));
	}


	/* Stack */
	template < class c >
	db& operator << ( stack< c > d) {
		vector<c> tmp;

		while( !d.empty() ){
			tmp.pb(d.top());
			d.pop();
		}

		reverse(tmp.begin(), tmp.end());

		for(auto i: tmp)
			d.push(i);

		return *this << range(begin(tmp), end(tmp));
	}

	/* List */
	template < class c >
	db& operator << ( list< c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Deque */
	template < class c >
	db& operator << ( deque< c > d) {
		return * this << range(begin(d), end(d));
	}

	/* Imprime un contenedor */
	template <class c>
	typename enable_if<sizeof dud<c>(0) == 1, db&>::type operator<<(c d){
		return * this << range(begin(d), end(d));
	}

	/* Imprime tipos no compuestos */
	template <class c>
	typename enable_if<sizeof dud<c>(0) != 1, db&>::type operator<<(c x){
		cerr << boolalpha << x;
		return *this;
    }

	/* Declaracion de la funcion que imprime un arreglo de vectores */
	template < class c >
	db& operator << (pair<vector<c>*, int>);

	/* Declaracion de la funcion que imprime un vector de vectores */
	template < class c >
	db& operator << (vector<vector<c>>);

	/* Imprime un pair */
	template < class c, class b >
	db& operator << (pair < b, c > d) {
		return * this << "(" << d.first << ", " << d.second << ")";
	}

	/* Imprime un rango */
	template < class c >
	db& operator << (rge<c> d) {
		if( !long_flag )
			*this << "[";
		else
			*this << "\n===================================\n";


		for(auto it = d.b; it != d.e; ++it)
			*this << (long_flag ? ",\n" : ", ") + 2 * (it == d.b) << *it;

		if( !long_flag )
			*this << "]";
		else
			*this << "\n===================================\n";

		return * this;
	}

	/* Destructor: imprime un cambio de linea */
	~db() { cerr << endl; }

#else
	/* Si no esta definida la bandera LOCAL, no hacer nada */
	template < class c >
	db& operator << (const c&){
		return * this;
	}
#endif
};

#ifdef LOCAL
	/* Imprime un arreglo de vectores */
	template < class c >
	db& db::operator << (pair<vector<c>*, int> pr) {
		for(int i=0; i<=pr.second; i++)
			*this << i << ": " << pr.first[i] << '\n';

		return *this;
	}

	/* Funcion que imprime un vector de vectores */
	template < class c >
	db& db::operator << (vector<vector<c>> V){
		*this << "\n===================================\n";
		for(int i=0; i < (int)V.size(); i++)
			*this << i << ": " << V[i] << '\n';
		*this << "===================================\n";
		return *this;
	}

#endif

/* Imprime el nombre de la variable, seguida de su valor */
#define imie(...) "<" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "> "
#define _sz(X) "<sz(" << #X << "): " << (X).size() << "> "

/* Imprime los los argumentos de un una funcion min. Colocar antes de min */
#define dmin(X, Y) \
	if( (X) > (Y) )  \
		db() << #X << " [" << (X) << "] " <<  " <- " << (Y); \
	else \
		db() << #X << " [" << (X) << "] " <<  "REJECTED: " << (Y);

/* Imprime los los argumentos de un una funcion max. Colocar antes de max */
#define dmax(X, Y) \
	if( (X) < (Y) )  \
		db() << #X << " [" << (X) << "] " <<  " <- " << (Y); \
	else \
		db() << #X << " [" << (X) << "] " <<  "REJECTED: " << (Y);

/* Convierte una matriz en un vector de vectores */
template < class c >
vector<vector<c>> mt(c A[][MX], int N, int M=-1){
	if( M < 0 )
		M = N;

	vector<vector<c>> ans(N+1, vector<c>(M+1));

	for(int i=0; i<=N; i++)
		for(int j=0; j<=M; j++)
			ans[i][j] = A[i][j];

	return ans;
}

/* Convierte un arreglo en un vector */
template < class c >
vector<c> mt(c A[], int N){
	vector<c> ans;

	for(int i=0; i<=N; i++)
		ans.push_back(A[i]);
	return ans;
}

/* Convierte un entero en una cadena de bits */
template < class c >
string bin(c x){
	if( x == 0 )
		return "0";
	
	string ans;

	while( x ){
		ans += '0' + (x % 2);
		x /= 2;	
	}
	reverse(ans.begin(), ans.end());
	
	return ans;
}
