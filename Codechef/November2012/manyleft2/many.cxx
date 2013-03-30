/*
 * many.cxx
 *
 *  Created on: 7:58:41 PM Nov 8, 2012
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
const int w[] = { 23, 19, 17, 7 };
inline int encode(int rpos, int cpos, int CC) {
	return rpos * CC + cpos;
}
inline int decodeY(int rpos, int CC) {
	return rpos / CC;
}
inline int decodeX(int cpos, int CC) {
	return cpos % CC;
}
int X;
struct Node {
	int P, Q;
	Node() {
		P = Q = 0;
	}
	Node(int P_, int Q_) {
		P = P_, Q = Q_;
	}
	void print() {
		cout << decodeX(P, X) << ' ' << decodeY(P, X) << ' ' << decodeX(Q, X)
				<< ' ' << decodeY(Q, X) << '\n';
	}
};
int cnt = 0;
const int MX = 30;
Node result[MX * MX];
const int inf = 1023456789;
int xx[] = { -2, +0, +2, +0 };
int yy[] = { +0, +2, +0, -2 };
int dx[] = { -1, +0, +1, +0 };
int dy[] = { +0, +1, +0, -1 };

int dir[] = { 0, 1, 2, 3 };
inline bool inside(int x, int y) {
	return x >= 0 && x < X && y >= 0 && y < X;
}
set<int> positions;
inline void read() {
	scanf("%d\n", &X);
	char ch;
	fo(y,X)
	{
		fo(x,X)
		{
			scanf(" %c", &ch);
			if (ch == '*')
				positions.insert(encode(y, x, X));
		}
	}
}

inline int vulnarable_count(set<int> &st) {
	int d = 0;
	foit(it, st)
	{
		int x1 = decodeX(*it, X);
		int y1 = decodeY(*it, X);

		int y21 = y1 - 1;
		int y22 = y1 + 1;

		int pos1 = encode(y21, x1, X);
		int pos2 = encode(y22, x1, X);
		if (inside(x1, y21) && inside(x1, y22)) {
			int c = 0;
			if (st.count(pos1))
				++c;
			if (st.count(pos2))
				++c;
			if (c == 1) {
				++d;
				continue;
			}
		}

		int x21 = x1 - 1;
		int x22 = x1 + 1;
		pos1 = encode(y1, x21, X);
		pos2 = encode(y1, x22, X);
		if (inside(x21, y1) && inside(x22, y1)) {
			int c = 0;
			if (st.count(pos1))
				++c;
			if (st.count(pos2))
				++c;
			if (c == 1)
				++d;
		}

	}
	return d;
}
inline void do_move(int xy1, set<int>&st, int dir) {
	int x1 = decodeX(xy1, X);
	int y1 = decodeY(xy1, X);

	int x2 = x1 + xx[dir];
	int y2 = y1 + yy[dir];
	int xy2 = encode(y2, x2, X);

	int mx = (x1 + x2) >> 1;
	int my = (y1 + y2) >> 1;
	int mxy = encode(my, mx, X);
	st.erase(xy1);
	st.erase(mxy);
	st.insert(xy2);
	result[cnt++] = Node(xy1, xy2);
	return;
}
inline bool can_move(int xy1, set<int>&st, int dir) {
	int x1 = decodeX(xy1, X);
	int y1 = decodeY(xy1, X);

	int x2 = x1 + xx[dir];
	int y2 = y1 + yy[dir];
	if (!inside(x2, y2))
		return false;
	int xy2 = encode(y2, x2, X);
	if (st.count(xy2))
		return false;

	int mx = (x1 + x2) >> 1;
	int my = (y1 + y2) >> 1;
	int mxy = encode(my, mx, X);
	if (!st.count(mxy))
		return false;

	return true;

}
inline void proc() {
	set<int> st = positions;

	while (1) {
		int bst = inf;
		int who = -1;
		int dir = -1;
		foit(it,st)
		{
			int x1 = decodeX(*it, X), y1 = decodeY(*it, X), xy1 = *it;
			fo(i,4)
			{
				if (can_move(xy1, st, i)) {
					int mx = dx[i], my = dy[i];
				}
			}

		}
		cout << who << ' ' << dir << ' ' << bst << '\n';
		if (bst == 0)
			break;
		do_move(who, st, dir);
	}
	cout << "HEY " << vulnarable_count(st) << "\n";
}
inline void show() {
	cout << cnt << '\n';
	fo(i,cnt)
	{
		result[i].print();
	}
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	cnt = 0;
	fo(i,kase)
	{
		read();
		proc();
		show();
	}
	return 0;
}
