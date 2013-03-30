/*
 * JABO.cxx
 *
 *  Created on: 8:58:29 AM Nov 5, 2012
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
const int inf = 1000000*4;
int query_count, R, C;
char query_string[15];
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
	if (now_node != parent[now_node]) {
		parent[now_node] = _Find(parent[now_node]);
	}
	return parent[now_node];
}
inline void _Union(int node_x, int node_y) {

	int parent_x = _Find(node_x);
	int parent_y = _Find(node_y);

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

inline void readword(char *buffer) {
	int c, cnt = 0;
	c = getchar();
	while (c >= 0 && c <= ' ') {
		c = getchar();
	}
	if (c < 0) {
		buffer[cnt] = 0;
		return;
	}
	while (c > ' ') {
		buffer[cnt++] = c;
		c = getchar();
	}
	buffer[cnt] = 0;
}
inline int decode(int row, int col) {
	int temp = ((row + 4) / 5) - 1;
	return temp * C + col;
}
inline int get_position(char a, char b) {
	int index = (isupper(a) ? a - 'A' : a - 'a' + 26) * 52;
	index += (isupper(b) ? b - 'A' : b - 'a' + 26);
	return index;
}
inline void read() {
	query_count = fastIn<int>(), R = fastIn<int>(), C = fastIn<int>();
}
inline void attach_wire(int x1, int y1, int x2, int y2) {
#if defined ( xerxes_pc )
	printf("Wire %d %d %d %d\n", x1, y1, x2, y2);
#endif
	int f1 = decode(y1,x1);
	int f2 = decode(y2,x2);

	_Union(f1, f2);
}
inline void attach_voltage(int x, int y) {
	int f1 = decode(y,x);
#if defined ( xerxes_pc )
	printf("voltage %d %d on %d amount %d\n", x, y,tmp,voltage[tmp]);
#endif
	voltage[_Find(f1)]++;
}
inline void remove_voltage(int x, int y) {
#if defined ( xerxes_pc )
	printf("R-voltage %d %d\n", x, y);
#endif
	int f1 = decode(y,x);
	voltage[_Find(f1)]--;

	voltage[_Find(f1)] = max(voltage[_Find(f1)], 0);
#if defined ( xerxes_pc )
	printf("voltage %d %d on %d amount %d\n", x, y,tmp,voltage[tmp]);
#endif
}

inline void put_led(int x1, int y1, int x2, int y2) {
#if defined(xerxes_pc)
	printf("Led %d %d %d %d\n", x1, y1, x2, y2);
#endif
	int f1 = decode(y1,x1);
	int f2 = decode(y2,x2);

	int pa = _Find(f1), pb = _Find(f2);

	int c = 0;
	int voltage_count_a = voltage[pa];
	if (voltage_count_a > 0)
		++c;
	int voltage_count_b = voltage[pb];
	if (voltage_count_b > 0)
		++c;

	puts(c == 1 ? "ON" : "OFF");
}
inline void proc() {
	_Make();
	int x1, y1, x2, y2, x, y;
	fo(i,query_count)
	{
		//test_read_query();
		readword(query_string);
		//puts(query_string);
		switch (query_string[0]) {
		case 'W':
			//attach wire in the Board
			// x1,y1 <=> x2,y2
			x1 = get_position(query_string[1], query_string[2]), y1 =
					get_position(query_string[3], query_string[4]);
			x2 = get_position(query_string[5], query_string[6]), y2 =
					get_position(query_string[7], query_string[8]);
			attach_wire(x1, y1, x2, y2);
			break;
		case 'V':
			//attach a voltage on the board
			// x,y
			x = get_position(query_string[1], query_string[2]), y =
					get_position(query_string[3], query_string[4]);
			attach_voltage(x, y);
			break;
		case 'R':
			//remove a voltage source
			// x,y
			x = get_position(query_string[1], query_string[2]), y =
					get_position(query_string[3], query_string[4]);
			remove_voltage(x, y);
			break;
		case 'L':
			//put a led on board
			//x1,y1 <-> x2,y2
			x1 = get_position(query_string[1], query_string[2]), y1 =
					get_position(query_string[3], query_string[4]);
			x2 = get_position(query_string[5], query_string[6]), y2 =
					get_position(query_string[7], query_string[8]);
			put_led(x1, y1, x2, y2);
			break;
		default:
			assert(0);
			break;
		}
	}
}
int main() {
	int kase = 1;
//#if defined( xerxes_pc )
#if defined(xx)
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
