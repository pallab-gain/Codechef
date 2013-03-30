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
//N = row number
//M = column number
int N, M, Q, sx, sy;
int P1[6], P2[6];
int ROW[35],COL[35];
Int QQ[101];
int sz;
inline void read() {
	N = fastIn<int>(), M = fastIn<int>(), Q = fastIn<int>();
	sx = fastIn<int>() - 1, sy = fastIn<int>() - 1;
	sz = N * M;
	fo(i,6)
	{
		P1[i] = fastIn<int>(), P2[i] = fastIn<int>();
	}
	fo(i,Q)
	{
		QQ[i] = fastIn<Int>();
	}
}
int R1[] = { -1, +0, -1, +0, +1, +0 };
int C1[] = { +0, -1, +0, +1, +0, -1 };
int R2[] = { +1, +0, +0, +1, +0, -1 };
int C2[] = { +0, +1, +1, +0, -1, +0 };
inline int encodePos(int rpos, int cpos, int RR, int CC) {
	return rpos * CC + cpos;
}
inline int decodeR(int rpos, int RR, int CC) {
	return rpos / CC;
}
inline int decodeC(int cpos, int RR, int CC) {
	return cpos % CC;
}

inline bool is_invalid(int tr, int tc) {
	return tr < 0 || tc < 0 || tr >= N || tc >= M;
}
Int grid, g;
inline void move(int ir, int ic, int dr, int dc, int d) {
	while (true) {
		ir = ir + (dr * d);
		ic = ic + (dc * d);
		if (is_invalid(ir, ic)) {
			break;
		}
		grid ^= (1LL << encodePos(ir, ic, N, M));
	}
}
inline int get(int r, int c) {
	int x = 0;
	fo(i,M)
		x += ((g & (1LL << encodePos(r, i, N, M))) ? 1 : 0);
	fo(i,N)
		x += ((g & (1LL << encodePos(i, c, N, M))) ? 1 : 0);

	x -= ((g & (1LL << encodePos(r, c, N, M))) ? 1 : 0);
	return x;
}
inline void print(Int w) {
	Int k = 1;
	fo(i,N)
	{
		fo(j,M)
		{
			cout << (w & k ? 1 : 0);
			k <<= 1;
		}
		line;
	}
}
inline Int encodeM() {
	return grid;
}
inline void ready_get(){
	fo(i,N){
		ROW[i]=0;
		fo(j,M){
			ROW[i]+= ((g & (1LL << encodePos(i, j, N, M))) ? 1 : 0);
		}
	}
	fo(i,M){
		COL[i]=0;
		fo(j,N){
			COL[i]+= ((g & (1LL << encodePos(j, i, N, M))) ? 1 : 0);
		}
	}
}
inline int get2(int r, int c){
	return ROW[r]+COL[c]-1;
}
map<Int, int> seen;
int cycle_starts, cycle_ends;
const int MX = 1000000;
Int psum[MX + 1];
Int sum;
int itr;
inline Int test() {
	Int bc = grid & ((1LL << 35) - 1);
	return (__builtin_popcount(bc));
}
inline int bc(Int msk) {
	int c=0;
	for(c=0; msk ; ++c){
		msk&= (msk-1);
	}
	return c;
}
inline void Calc() {
	sum+=bc(grid);
	/*assert(sum>0);*/
}
inline void simulate() {
	grid = 0LL;
	grid |= (1LL << encodePos(sx, sy, N, M));

	sum = psum[0] = 1;
	itr = 0;
	for (itr = 1; ;++itr) {
		g = grid;
		Int value = encodeM();
		if (seen.count(value)) {
			cycle_starts = seen[value];
			cycle_ends = itr - 1;
			//print(g);
			break;
		} else {
			seen[value] = itr;
		}
		ready_get();
		fo(i,sz){
			if (g & (1LL << i)) {
				int ii=decodeR(i, N, M),jj=decodeC(i, N, M);
				int x = get2(ii, jj) % 6;
				int d1r = R1[x], d1c = C1[x], d1p = P1[x];
				int d2r = R2[x], d2c = C2[x], d2p = P2[x];
				move(ii, jj, d1r, d1c, d1p);
				move(ii, jj, d2r, d2c, d2p);
			}
		}
		Calc();
		psum[itr] += sum;
		/*assert( psum[itr]>0);
		assert( itr<MX );*/
	}
}
inline Int solve(Int at) {
	int cycle_length = cycle_ends - cycle_starts + 1;
	if (at < cycle_starts)
		return psum[at];
	Int retval = 0;
	retval += psum[cycle_starts - 1];
	Int new_indx = at - (cycle_starts - 1);
	Int factor = new_indx / cycle_length;
	retval += (psum[cycle_ends] - psum[cycle_starts - 1]) * factor;
	if (new_indx % cycle_length != 0) {
		Int tmp = cycle_starts + (new_indx % cycle_length) - 1;
		retval += (psum[tmp] - psum[cycle_starts - 1]);
	}
	return retval;
}
inline void proc() {
	simulate();
	//cout << "CYCLE " << cycle_ends << ' ' << cycle_starts << '\n';
	fo(i,Q){
		cout << solve(QQ[i]) << "\n";
	}
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file Blade/in1 "), assert(0);
	kase = 1;
#endif
	fo(i,kase)
	{
		read();
		proc();
	}
	return 0;
}