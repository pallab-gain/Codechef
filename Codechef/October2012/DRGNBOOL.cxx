/*
 * DRGNBOOL.cxx
 *
 *  Created on: 7:44:34 PM Oct 1, 2012
 *  Author: Pallab
 *
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
#include <numeric>
#include <deque>
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
#define T int
inline T fastIn() {
	register char c = 0;
	register T a = 0;
	while (c < 33)
		c = getchar();
	while (c > 33) {
		a = (a * 10) + (c - '0');
		c = getchar();
	}
	return a;
}
const int MX = 101;
int soint_count, sofloat_count;
int sum1[101];
int sum2[101];
inline void read() {
	soint_count = fastIn(), sofloat_count = fastIn();
	SET(sum1, 0);
	SET(sum2, 0);
	fo(i,soint_count)
	{
		int power = fastIn(), level = fastIn();
		sum1[level] += power;
	}
	fo(i,sofloat_count)
	{
		int power = fastIn(), level = fastIn();
		sum2[level] += power;
	}
}
inline int solve(int level) {
	int v = sum1[level] - sum2[level];
	return v < 0 ? -v : 0;
}
inline void proc() {
	int res = 0;
	for (int level = 1; level < MX; ++level) {
		int delta = solve(level);
		res += delta;
	}
	cout << res << '\n';
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("DRGNBOOL/in1", "r", stdin))
		puts("error opening file DRGNBOOL/in1 "), assert(0);
	kase = 1;
#endif
	kase = fastIn();
	fo(i,kase)
	{
		read();
		proc();
	}
	return 0;
}