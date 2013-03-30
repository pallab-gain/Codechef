/*

 * lucky9.cxx
 *
 *  Created on: 5:06:12 PM Nov 6, 2012
 *      Author: Pallab
 * "I have not failed, I have just found 10000 ways that won't work.


#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

#define foR(i1,st,ed) for(int i1 = st , j1 = ed ; i1 < j1 ; ++i1 )
#define fo(i1,ed) foR( i1 , 0 , ed )
#define foE(i1,st,ed) foR( i1, st, ed+1 )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait(double seconds) {
	double endtime = clock() + (seconds * CLOCKS_PER_SEC);
	while (clock() < endtime) {
		;
	}
}
template<class T>
inline T fastIn() {
	register char c = 0;
	register T a = 0;
	bool neg = false;
	while (c < 33)
		c = getchar();
	while (c > 33) {
		if (c == '-') {
			neg = true;
		} else {
			a = (a * 10) + (c - '0');
		}
		c = getchar();
	}
	return neg ? -a : a;
}
template<class T>
inline void myOut(T a) {
	if (a) {
		int v = a % 10;
		myOut(a / 10);
		putchar((char) (v + '0'));
	}

}
template<class T>
inline void fastOut(T a) {
	if (a == (T) 0) {
		putchar('0');
	} else if (a < (T) 0) {
		putchar('-');
		myOut(-a);
	} else {
		myOut(a);
	}
}
inline bool balanced(vector<int> &vi) {
	int f, s, x;
	foE(i,1,SZ(vi))
	{
		x = i - 1, f = s = 0;
		for (int j = 0; j < x; ++j)
			if (vi[j] == 4)
				++f;
		for (int j = x + 1; j < SZ(vi) ; ++j)
			if (vi[j] == 7)
				++s;
		if (f == s)
			return true;
	}
	return (f == s ? true : false);
}
inline void test(int f, int s) {
	cout << f << ' ' << s;

	vector<int> vi;
	while (f--)
		vi.pb(4);
	while (s--)
		vi.pb(7);
	set<vector<int> > st;
	do {
		if (balanced(vi))
			st.insert(vi);
	} while (next_permutation(vi.begin(), vi.end()));
	cout <<" = "<< SZ(st) << "\n";
	puts("----------");
}
inline void read() {
}
inline void proc() {
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	for (int f = 3; f <= 3; ++f)
		for (int s = 0; s <= 7; ++s)
			if (f || s)
				test(f, s);
	fo(i,kase){
	 read();
	 proc();
	 }
	return 0;
}

*/
