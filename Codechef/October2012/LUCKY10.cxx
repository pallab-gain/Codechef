/*
 * LUCKY10.cxx
 *
 *  Created on: 12:45:25 AM Oct 5, 2012
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
		c = getchar();
	while (c > 33) {
		a = (a * 10) + (c - '0');
		c = getchar();
	}
	return a;
}
const int LIMIT = 200005;
char A[LIMIT], B[LIMIT];
int l;
inline void read() {
	gets(A), gets(B);
	l = strlen(A);
}
int C1[10], C2[10];
inline void f1() {
	SET(C1, 0);
	SET(C2, 0);
	fo(i,l)
	{
		C1[A[i] - '0']++;
		C2[B[i] - '0']++;
	}
}
inline int f2() {
	int &tot = C1[7];
	int initial = tot;
	for (int i = 6; i >= 5; --i) {
		if (C2[i] == tot) {
			tot -= C2[i];
			C2[i] = 0;
			break;
		} else if (C2[i] > tot) {
			C2[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C2[i];
			C2[i] = 0;
		}
	}
	for (int i = 0; i <= 4; ++i) {
		if (C2[i] == tot) {
			tot -= C2[i];
			C2[i] = 0;
			break;
		} else if (C2[i] > tot) {
			C2[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C2[i];
			C2[i] = 0;
		}
	}
	return initial - tot;
}
inline int f3() {
	int &tot = C2[7];
	int initial = tot;
	for (int i = 6; i >= 5; --i) {
		if (C1[i] == tot) {
			tot -= C1[i];
			C1[i] = 0;
			break;
		} else if (C1[i] > tot) {
			C1[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C1[i];
			C1[i] = 0;
		}
	}
	for (int i = 0; i <= 4; ++i) {
		if (C1[i] == tot) {
			tot -= C1[i];
			C1[i] = 0;
			break;
		} else if (C1[i] > tot) {
			C1[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C1[i];
			C1[i] = 0;
		}
	}
	return initial - tot;
}
inline int f4() {
	int &tot = C1[4];
	int initial = tot;
	for (int i = 0; i <= 4; ++i) {
		if (C2[i] == tot) {
			tot -= C2[i];
			C2[i] = 0;
			break;
		} else if (C2[i] > tot) {
			C2[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C2[i];
			C2[i] = 0;
		}
	}
	return initial - tot;
}
inline int f5() {
	int &tot = C2[4];
	int initial = tot;
	for (int i = 0; i <= 4; ++i) {
		if (C1[i] == tot) {
			tot -= C1[i];
			C1[i] = 0;
			break;
		} else if (C1[i] > tot) {
			C1[i] -= tot;
			tot = 0;
			break;
		} else {
			tot -= C1[i];
			C1[i] = 0;
		}
	}
	return initial - tot;
}
inline void myprint(int n7, int n4) {
	while (n7 > 0) {
		putchar('7');
		--n7;
	}
	while (n4 > 0) {
		putchar('4');
		--n4;
	}
	line;
}
inline void proc() {
	f1();
	//------------
	int a71 = f2();
	int a72 = f3();
	int a73 = min(C1[7], C2[7]);

	int a41 = f4();
	int a42 = f5();
	int a43 = min(C1[4], C2[4]);

	myprint(a71 + a72 + a73, a41 + a42 + a43);

}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("LUCKY10/in1", "r", stdin))
		puts("error opening file LUCKY10/in1 "), assert(0);
	kase = 1;
#endif
	scanf("%d\n", &kase);
	fo(i,kase)
	{
		read();
		proc();
	}
	return 0;
}