
/*
 * DDISH.cxx
 *
 *  Created on: 11:16:18 AM Nov 3, 2012
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
	while (c < 33)
		c = getchar();
	while (c > 33) {
		a = (a * 10) + (c - '0');
		c = getchar();
	}
	return a;
}
Int lo, hi;
inline void read() {
	lo = fastIn<Int>(), hi = fastIn<Int>();
}
int vi[20];
int cnt;
inline void Convert(Int n) {
	cnt = 0;
	while (n > 0) {
		vi[cnt++] = (n % 10);
		n /= 10;
	}
	reverse(vi, vi + cnt);
}
bool vis[10][1 << 10][2];
int dp[10][1 << 10][2];
//left, right , msk, smaller, smaller flag
int go(int l, int f, int s) {
	if (l >= cnt) {
		return 1;
	}
	if (vis[l][s])
		return dp[l][s];
	vis[l][s] = true;
	int var = 0;

	int upto = (s == 1 ? 9 : vi[l]);
	for (int d = (l == 0 ? 1 : 0); d <= upto; ++d) {
		if (!(f & (1 << d))) {
			int nxts = s | (d < vi[l] ? 1 : 0);
			var += go(l + 1, f | (1 << d), nxts);
		}
	}
	return dp[l][s] = var;
}
int lenSum[] = { 0, 9, 90, 738, 5274, 32490, 168570, 712890, 2345850, 5611770,
		8877690 };
inline int Count(Int p) {
	if (p <= 0)
		return 0;
	Convert(p);
	int ret = 0;
	if (cnt <= 10) {
		SET(vis, false);
		ret += go(0, 0, 0);
		ret += lenSum[cnt - 1];
	} else {
		ret += lenSum[10];
	}
	return ret;
}
inline void proc() {
	int p = Count(hi);
	int q = Count(lo - 1);
	//cout << hi<<" "<<lo<<" "<<p << " " << q << " and ";
	//cout << p - q << " " << hi - (p - q) << '\n';
	cout << p - q << "\n";
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	kase = fastIn<int>();
	fo(i,kase)
	{
		read();
		proc();
	}
	for (int i = 1; i <= 20; ++i) {
	 lo = 1, hi = i;
	 cout << hi << " ";
	 proc();
	 }
	return 0;
}

