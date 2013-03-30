/*
 * CANDYGAM.cxx
 *
 *  Created on: 6:09:37 PM Nov 2, 2012
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
inline bool cmp(pair<Int, int> a, pair<Int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int mr1[] = { +1, +0, +0, +0 };
int mc1[] = { +0, +0, +1, +0 };
int mr2[] = { +0, -1, +0, +0 };
int mc2[] = { +0, +0, +0, -1 };

#define T Int
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

#if !defined( xerxes_pc )
const int MX = 50+5;
#else
const int MX = 20 + 5;
#endif

Int G[MX][MX], total;
int R, C;
inline void read() {
	R = fastIn(), C = fastIn(), total = 0;
	fo(i,R)
		fo(j,C)
		{
			G[i][j] = fastIn();
			total += G[i][j];
		}
}
namespace MatrixSum {
Int gSum[MX][MX], rowSum[MX][MX], colSum[MX][MX];
int M, N;
inline void row_sum() {
	for (int i = 0; i < M; ++i) {
		Int sum = 0;
		for (int j = 0; j < N; ++j) {
			sum += G[i][j];
			rowSum[i][j] = sum;
		}
	}
}

inline void col_sum() {
	for (int i = 0; i < N; ++i) {
		Int sum = 0;
		for (int j = 0; j < M; ++j) {
			sum += G[j][i];
			colSum[j][i] = sum;
		}
	}
}

inline void cumulative_sum() {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == 0 && j == 0)
				gSum[i][j] = G[i][j];
			else if (i == 0)
				gSum[i][j] = rowSum[i][j];
			else if (j == 0)
				gSum[i][j] = colSum[i][j];
			else
				gSum[i][j] = rowSum[i][j] + colSum[i][j] + gSum[i - 1][j - 1]
						- G[i][j];
		}
	}
}

inline Int solve(int x, int y, int i, int j) {
	///     returns the rectangle sum, where [0<=(x,y)<(M,N)] is the top left corner of
	///     the rectangle and 'i' is row height 'j' is col width 0<i<=(M-x) & 0<j<=(N-y)

	if (x == 0 && y == 0)
		return gSum[i - 1][j - 1];
	else if (x == 0)
		return gSum[i - 1][y + j - 1] - gSum[i - 1][y - 1];
	else if (y == 0)
		return gSum[x + i - 1][j - 1] - gSum[x - 1][j - 1];
	else
		return gSum[x + i - 1][y + j - 1] - gSum[x - 1][y + j - 1]
				- gSum[x + i - 1][y - 1] + gSum[x - 1][y - 1];
}
inline void init(int _R, int _C) {
	SET(gSum, 0);
	SET(rowSum, 0);
	SET(colSum, 0);
	M = _R, N = _C;
	row_sum(), col_sum(), cumulative_sum();
}
}
Int dp[MX][MX][MX][MX][2];
pair<Int, int> vi[4];
Int go1(int r1, int c1, int r2, int c2, int who) {
	if (r1 > r2 || r2 < r1 || c1 > c2 || c2 < c1)
		return 0LL;

	Int &bst = dp[r1][c1][r2][c2][who];
	if (bst != -1)
		return bst;
	bst = 0LL;
	if (who == 0) {
		Int sum1 = MatrixSum::solve(r1, c1, 1, c2 - c1 + 1);
		Int sum2 = MatrixSum::solve(r2, c1, 1, c2 - c1 + 1);
		Int sum3 = MatrixSum::solve(r1, c1, r2 - r1 + 1, 1);
		Int sum4 = MatrixSum::solve(r1, c2, r2 - r1 + 1, 1);
		vi[0] = (mk(sum1, 0));
		vi[1] = (mk(sum2, 1));
		vi[2] = (mk(sum3, 2));
		vi[3] = (mk(sum4, 3));
		sort(vi, vi + 4, less<pair<Int, int> >());
		int id = vi[0].second;
		bst = go1(r1 + mr1[id], c1 + mc1[id], r2 + mr2[id], c2 + mc2[id], 1);
	} else {
		Int sum1 = MatrixSum::solve(r1, c1, 1, c2 - c1 + 1);
		Int sum2 = MatrixSum::solve(r2, c1, 1, c2 - c1 + 1);
		Int sum3 = MatrixSum::solve(r1, c1, r2 - r1 + 1, 1);
		Int sum4 = MatrixSum::solve(r1, c2, r2 - r1 + 1, 1);
		sum1 += go1(r1 + mr1[0], c1 + mc1[0], r2 + mr2[0], c2 + mc2[0], 0);
		bst = max(bst, sum1);
		sum2 += go1(r1 + mr1[1], c1 + mc1[1], r2 + mr2[1], c2 + mc2[1], 0);
		bst = max(bst, sum2);
		sum3 += go1(r1 + mr1[2], c1 + mc1[2], r2 + mr2[2], c2 + mc2[2], 0);
		bst = max(bst, sum3);
		sum4 += go1(r1 + mr1[3], c1 + mc1[3], r2 + mr2[3], c2 + mc2[3], 0);
		bst = max(bst, sum4);
	}

	return bst;
}
inline void proc() {
	if (R == 1 && C == 1) {
		cout << G[0][0] << '\n';
		return;
	}
	MatrixSum::init(R, C);
	SET(dp, -1);
	Int res = go1(0, 0, R - 1, C - 1, 0);
	if (total - res == res) {
		cout << res + res << '\n';
	} else if (total - res < res) {
		cout << res << '\n';
	} else {
		assert(0);
	}
}

int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
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

