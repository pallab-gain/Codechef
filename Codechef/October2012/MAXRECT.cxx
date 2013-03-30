/*
 * MAXRECT.cxx
 *
 *  Created on: 9:22:05 AM Oct 6, 2012
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
const int MX = 305;
int R, C;
int grid[MX][MX];
inline void read() {
	R = fastIn(), C = fastIn();
	fo(i,R)
		fo(j,C)
			grid[i][j] = fastIn();
}
Int ps[MX][MX], hs[MX][MX];
inline void VerticalPrefixSum() {
	SET(ps, 0);
	fo(col,C)
	{
		Int sum = 0;
		fo(row,R)
		{
			sum += grid[row][col];
			ps[row][col] = sum;
		}
	}
}
inline void HorizontalPrefixSum() {
	SET(hs, 0);
	fo(row,R)
	{
		Int sum = 0;
		fo(col,C)
		{
			sum += grid[row][col];
			hs[row][col] = sum;
		}
	}
}
struct REM {
	int r0;
	int c0;
	int r1;
	int c1;
	REM(int r0 = 0, int c0 = 0, int r1 = 0, int c1 = 0) :
			r0(r0), c0(c0), r1(r1), c1(c1) {
		;
	}
};

inline bool cmp(pair<Int, REM> A, pair<Int, REM> B) {
	return A.first > B.first;
}
pair<Int, REM> w[4005];
int w1c;

int r1[4005], c1[4005];
int er1[4005], er2[4005], ec1[4005], ec2[4005], allR[4005], allC[4005];
int er1c, er2c, ec1c, ec2c, allRc, allCc;
int r1c, c1c;
Int bst;

inline void solve(REM retval) {
	er1c = er2c = ec1c = ec2c = allRc = allCc = 0;
	for (int col = 0; col < retval.c1 - 1; ++col) {
		Int tmp = ps[retval.r0][col]
				- (retval.r1 != 0 ? ps[retval.r1 - 1][col] : 0);
		if (tmp > 0)
			ec1[ec1c++] = (col);
	}
	for (int col = retval.c0 + 1; col < C; ++col) {
		Int tmp = ps[retval.r0][col]
				- (retval.r1 != 0 ? ps[retval.r1 - 1][col] : 0);
		if (tmp > 0)
			ec2[ec2c++] = col;
	}

	for (int row = 0; row < retval.r1 - 1; ++row) {
		Int sum = 0;
		fo(i,(ec1c))
			sum += grid[row][ec1[i]];
		fo(i,(ec2c))
			sum += grid[row][ec2[i]];
		foE(i,retval.c1,retval.c0)
			sum += grid[row][i];
		if (sum > 0)
			er1[er1c++] = row;
	}
	for (int row = retval.r0 + 1; row < R; ++row) {
		Int sum = 0;
		fo(i,(ec1c))
			sum += grid[row][ec1[i]];
		fo(i,(ec2c))
			sum += grid[row][ec2[i]];
		foE(i,retval.c1,retval.c0)
			sum += grid[row][i];
		if (sum > 0)
			er2[er2c++] = (row);
	}
	fo(i,er1c)
		allR[allRc++] = er1[i];
	for (int row = retval.r1; row <= retval.r0; ++row) {
		allR[allRc++] = row;
	}
	fo(i,er2c)
	{
		allR[allRc++] = er2[i];
	}
	//----------------------------------------------------------------
	fo(i,ec1c)
		allC[allCc++] = ec1[i];

	for (int col = retval.c1; col <= retval.c0; ++col) {
		allC[allCc++] = col;
	}
	fo(i,ec2c)
		allC[allCc++] = ec2[i];

	//-----------------------------------------------------------------
	Int tmpSum = 0;
	fo(i,allRc)
	{
		fo(j,allCc)
		{
			tmpSum += grid[allR[i]][allC[j]];
		}
	}
	if (tmpSum > bst) {
		bst = tmpSum;
		r1c = c1c = 0;
		fo(i,allRc)
		{
			r1[r1c++] = allR[i];
		}
		fo(i,allCc)
		{
			c1[c1c++] = allC[i];
		}
	}

}
inline void Kadane() {
	Int maxSum = 0;
	REM retval = REM(0, 0, 0, 0);
	w1c = 0;
	for (int rowa = 0; rowa < R; ++rowa) {
		for (int rowb = 0; rowb <= rowa; ++rowb) {
			Int currentMaxSum = 0;
			for (int col = 0, c0 = 0; col < C; ++col) {
				currentMaxSum +=
						(ps[rowa][col] - (rowb ? ps[rowb - 1][col] : 0));
				if (c0 == -1)
					c0 = col;
				if (currentMaxSum > maxSum) {
					maxSum = currentMaxSum;
					retval = REM(rowa, col, rowb, c0);
					w[w1c++] = mk(maxSum, retval);
				}
				if (currentMaxSum < 0) {
					currentMaxSum = 0;
					c0 = -1;
				}
			}
		}
	}
	sort(w, w + w1c, cmp);

	bst = 0;
	int sz = min(w1c, 1100);
	fo(i,sz)
	{
		solve(w[i].second);
	}
	cout << (r1c) << ' ' << (c1c) << '\n';
	fo(i,r1c)
	{
		cout << r1[i] << ' ';
	}
	line;
	fo(i,c1c)
	{
		cout << c1[i] << ' ';
	}
}
inline void proc() {
	VerticalPrefixSum();
	//HorizontalPrefixSum();
	Kadane();
	line;
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("MAXRECT/in1", "r", stdin))
		puts("error opening file MAXRECT/in1 "), assert(0);
	kase = 1;
#endif
	fo(i,kase)
	{
		read();
		proc();
	}
	return 0;
}