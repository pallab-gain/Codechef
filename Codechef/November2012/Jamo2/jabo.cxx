/*
 * jabo.cxx
 *
 *  Created on: 10:14:13 PM Nov 5, 2012
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

char buff[100];
int N, R, C;
inline int point(char a, char b) {
	int x1 = ((a >= 'A' && a <= 'Z') ? (int) (a - 'A') : 26 + (int) (a - 'a'));
	int y1 = ((b >= 'A' && b <= 'Z') ? (int) (b - 'A') : 26 + (int) (b - 'a'));
	return (x1 * 52 + y1 * 1);
}
inline int decode(int row, int col) {
	/*int temp = ((row + 4) / 5) - 1;
	return temp * C + col;*/
	int temp = (((row - 1) / 5) * C) + col;
	return temp;
}
const int inf = 2000000;
int voltage[inf + 10];
//**********************************************
int parent[inf + 10];
int rank[inf + 10];
inline void _Make() {
	int i;
	for (i = 0; i < inf; ++i) {
		parent[i] = i;
		rank[i] = 0;
	}
}
inline int _Find(int now_node) {
	assert(now_node<inf);
	if (now_node != parent[now_node]) {
		parent[now_node] = _Find(parent[now_node]);
	}
	return parent[now_node];
}
inline void _Union(int node_x, int node_y) {
	assert(node_x<inf);
	assert(node_y<inf);
	int parent_x = _Find(node_x);
	int parent_y = _Find(node_y);
	if (parent_x == parent_y)
		return;

	if (rank[parent_x] > rank[parent_y]) {
		parent[parent_y] = parent_x;
		voltage[parent_x] += voltage[parent_y];
		voltage[parent_y] = 0;
	} else {
		parent[parent_x] = parent_y;
		voltage[parent_y] += voltage[parent_x];
		voltage[parent_x] = 0;
	}
	if (rank[parent_x] == rank[parent_y]) {
		rank[parent_y] += 1;
	}
}
//**********************************************
inline void read() {
	scanf("%d %d %d\n", &N, &R, &C);
}
inline void attach(int col1, int row1, int col2, int row2) {
	//printf("%d %d %d %d\n", col1, row1, col2, row2);
	int f1 = decode(row1, col1), f2 = decode(row2, col2);
	_Union(f1, f2);
}
inline void addvoltage(int col, int row) {
	//printf("%d %d\n", col, row);
	int f1 = decode(row, col);
	voltage[_Find(f1)]++;
}
inline void removevoltage(int col, int row) {
	//printf("%d %d\n", col, row);
	int f1 = decode(row, col);
	voltage[_Find(f1)]--;
}
inline void led(int col1, int row1, int col2, int row2) {
	/*printf("%d %d %d %d\n", col1, row1, col2, row2);*/
	int f1 = decode(row1, col1), f2 = decode(row2, col2);
	int pa = _Find(f1), pb = _Find(f2);
	/*if (pa == pb) {
		puts("OFF");
		return;
	}*/
	int cnt = 0;
	if (voltage[pa] > 0)
		++cnt;
	if (voltage[pb] > 0)
		++cnt;
	puts(cnt == 1 ? "ON" : "OFF");
}
inline void proc() {
	int x1, y1, x2, y2;
	_Make();
	SET(voltage, 0);
	fo(i,N)
	{
		scanf(" %s", buff);
		switch (buff[0]) {
		case 'W':
			//attach wire
			x1 = point(buff[1], buff[2]), y1 = point(buff[3], buff[4]);
			x2 = point(buff[5], buff[6]), y2 = point(buff[7], buff[8]);
			attach(x1, y1, x2, y2);
			break;
		case 'V':
			//add voltage
			x1 = point(buff[1], buff[2]), y1 = point(buff[3], buff[4]);
			addvoltage(x1, y1);
			break;
		case 'R':
			//remove voltage
			x1 = point(buff[1], buff[2]), y1 = point(buff[3], buff[4]);
			removevoltage(x1, y1);
			break;
		case 'L':
			//test led
			x1 = point(buff[1], buff[2]), y1 = point(buff[3], buff[4]);
			x2 = point(buff[5], buff[6]), y2 = point(buff[7], buff[8]);
			led(x1, y1, x2, y2);
			break;
		}
	}
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
