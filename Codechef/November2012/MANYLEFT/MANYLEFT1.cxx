/*
 * MANYLEFT1.cxx
 *
 *  Created on: 7:22:21 AM Nov 7, 2012
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
#include <iterator>
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
const int MX = 30;
int xx[] = { -2, +2, +0, +0 };
int yy[] = { +0, +0, +2, -2 };
int X;
inline void print(bool gg[][MX]) {
	fo(i,X)
	{
		fo(j,X)
			cout << gg[i][j];
		line;
	}
}
inline bool inside(int x, int y) {
	return x >= 0 && x < X && y >= 0 && y < X;
}
bool g[MX][MX];
inline void read() {
	scanf("%d\n", &X);
	char ch;
	fo(i,X)
		fo(j,X)
		{
			scanf(" %c", &ch);
			g[i][j] = (ch == '*' ? true : false);
		}
}
struct info {
	int x1, y1, x2, y2;
	info() {
		x1 = y1 = x2 = y2 = 0;
	}
	info(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
	}
};
inline int myrand(int sz) {
	return (rand()) % sz;
}
info res[MX * MX];
int cnt;
const int w[]={23,19,17,7};
inline int meter3(int x1, int y1, set<pair<int, int> > &st) {
	int cnt = 0;
	fo(i,4)
	{
		int x2 = x1 + xx[i], y2 = y1 + yy[i];
		if (inside(x2, y2) && !(st.count(mk(x2, y2)))) {
			int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
			if (st.count(mk(mx, my))) {
				cnt+= (w[i]);
			}
		}
	}
	return cnt;
}
inline int meter2(int x1, int y1, set<pair<int, int> > &st) {
	int cnt = 0;
	fo(i,4){
		int x2 = x1 + xx[i], y2 = y1 + yy[i];
		if (inside(x2, y2) && !(st.count(mk(x2, y2)))) {
			int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
			if (st.count(mk(mx, my))) {
				cnt+=w[i];
				int tm=meter3(x2, y2, st);
				cnt+= tm;
			}
		}
	}
	return cnt;
}
inline int meter(int x1, int y1, set<pair<int, int> >&st) {
	int cnt = 0;
	fo(i,4)
	{
		int x2 = x1 + xx[i], y2 = y1 + yy[i];
		if (inside(x2, y2) && !(st.count(mk(x2, y2)))) {
			int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
			if (st.count(mk(mx, my))) {
				cnt+=w[i];
				int tm=meter2(x2, y2, st);
				cnt +=  tm==0?tm*19:tm;
			}
		}
	}
	return cnt;
}
struct p3 {
	int v, x, y;
	p3() {
		v = x = y = 0;
	}
	p3(int x_, int y_, int v_) {
		x = x_, y = y_, v = v_;
	}
};
p3 vt[30 * 30];
inline bool cmp(p3 A, p3 B) {
	return A.v < B.v;
}

void solve() {
	cnt = 0;
	set<pair<int, int> > st;
	fo(x1,X)
		fo(y1,X)
			if (g[y1][x1]) {
				st.insert(mk(x1, y1));
			}
	int sz;
	while (1) {
		bool change = false;
		sz=0;
		foit(it,st)
		{
			int x1 = it->first, y1 = it->second;
			vt[sz++] = (p3(x1, y1, meter(x1, y1, st)));
		}
		sort(vt, vt + sz, cmp);
		fo(k,sz)
		{
			int x1 = vt[k].x, y1 = vt[k].y;
			for (int i = 0; i < 4; ++i) {
				int x2 = x1 + xx[i], y2 = y1 + yy[i];
				if (inside(x2, y2) && !(st.count(mk(x2, y2)))) {
					int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
					if (st.count(mk(mx, my))) {
						st.erase(mk(mx, my));
						st.erase(mk(x1, y1));
						st.insert(mk(x2, y2));
						change = true;
						res[cnt++] = info(x1, y1, x2, y2);
						goto L1;
					}
				}
			}
		}
		//++itr;
		L1: if (!change)
			break;
	}
}
inline void proc() {

	solve();
	cout << cnt << '\n';
	fo(i,cnt)
		cout << res[i].x1 << ' ' << res[i].y1 << ' ' << res[i].x2 << ' '
				<< res[i].y2 << '\n';
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	fo(i,kase)
	{
		read();
		proc();
	}
	return 0;
}
