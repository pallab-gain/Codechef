/*
 * DIAMOND.cxx
 *
 *  Created on: 8:33:17 PM Oct 2, 2012
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
		c = getchar_unlocked();
	while (c > 33) {
		a = (a * 10) + (c - '0');
		c = getchar_unlocked();
	}
	return a;
}
int diamond_count;
double val[2001][2001];
inline void pregen() {
	int n = 2000;
	val[0][0] = 0;
	val[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		int lim = i / 2;
		foE(j,0,lim){
			if (j == 0) {
				val[i][j] = (val[i - 1][j] + val[i - 2][j]) / 2;
			} else if (j == 1) {
				val[i][j] = val[i][j - 1] - val[i - 1][j] / 2;
			} else if ((i & 1) == 0 && j == lim)
				val[i][j] = val[i][j - 1];
			else {
				val[i][j] = val[i][j - 1]
						+ (val[i - 1][j - 2] - val[i - 1][j]) / 2;
			}
		}
	}
}
inline void solve() {
	diamond_count=fastIn();
	double res=0;
	int lim = diamond_count/2;
	for(int i=0;i<=lim;++i){
		res+= (val[diamond_count][i]*fastIn());
	}
	--lim;
	if( !(diamond_count&1))--lim;
	for(int i=lim;i>=0;--i){
		res+= (val[diamond_count][i]*fastIn());
	}
	cout<<res<<'\n';
}
int main() {
	cout << setprecision(6) << fixed;
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("DIAMOND/in1", "r", stdin))
		puts("error opening file DIAMOND/in1 "), assert(0);
	kase = 1;
#endif
	pregen();
	kase = fastIn();
	fo(i,kase)
	{
		solve();
	}
	return 0;
}