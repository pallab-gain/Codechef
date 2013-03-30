/*
 * lucky9_code.cxx
 *
 *  Created on: 9:06:00 PM Nov 6, 2012
 *      Author: Pallab
 * "I have not failed, I have just found 10000 ways that won't work.
 */

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
struct Triple {
	Int d;Int x;Int y;
	Triple(Int d, Int x, Int y) :
			d(d), x(x), y(y) {
		;
	}
};
Triple egcd(Int a, Int b) {
	if (!b)
		return Triple(a, 1, 0);
	Triple q = egcd(b, a % b);
	return Triple(q.d, q.y, q.x - a / b * q.y);
}
inline Int invmod(Int a, Int n) {
	Triple t = egcd(a, n);
	if (t.d > 1)
		return 0;
	Int r = t.x % n;
	return (r < 0 ? r + n : r);
}
const Int mod = 1000000007LL;
const int maxn = 5010;
inline Int domod(Int v) {
	if (v < 0)
		v += mod;
	return v % mod;
}
Int fact[maxn];
Int im[maxn]; //inverse mod
inline void findFactorials(int upto) {
	fact[0] = fact[1] = im[1] = 1;
	for (int i = 2; i <= upto; ++i) {
		im[i] = invmod(i, mod);
		fact[i] = (fact[i - 1] * i) % mod;
	}
}
Int C[maxn][maxn];
// find NcR
Int ncr(Int a, Int b) {
	int LM = min(b, a - b);
	if (C[a][LM])
		return C[a][LM];
	C[a][0] = 1LL;
	int LIM = (a + 3) >> 1;
	for (int U = a, D = 1; D < LIM; ++D, --U) {
		C[a][D] = (((C[a][D - 1] * U) % mod) * im[D]) % mod;
	}
	return C[a][LM];
}
inline Int solve(int f, int s) {
	if (f == 0 || s == 0)
		return 1LL;
	if (min(f, s) == 1)
		return (Int) (max(f, s));
	int to_add = f - 2;
	s = s + to_add;
	Int x1 = ncr(s, f);
	Int x2 = ncr(s, f - 1);
	Int x3 = ncr(s, f - 2);
	return (((x1 + x2) % mod) + x3) % mod;
}

inline void proc() {
	int four_count = 0, seven_count = 0;
	int c;
	c = getchar();
	while (c >= 0 && c <= ' ') {
		c = getchar();
	}
	while (c > ' ') {
		if (c == '4')
			++four_count;
		else
			++seven_count;
		c = getchar();
	}

	Int retval = solve(four_count, seven_count);
	cout << retval << "\n";
}
int main() {
	findFactorials(5000);
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	kase = fastIn<int>();
	fo(i,kase)
	{
		proc();
	}
	return 0;
}

