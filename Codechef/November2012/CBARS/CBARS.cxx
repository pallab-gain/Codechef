/*
 * CBARS.cxx
 *
 *  Created on: 12:53:32 AM Nov 3, 2012
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
inline int encodePos(int rpos, int cpos, int RR, int CC) {
	return rpos * CC + cpos;
}
inline int decodeR(int rpos, int RR, int CC) {
	return rpos / CC;
}
inline int decodeC(int cpos, int RR, int CC) {
	return cpos % CC;
}
int rr[] = { +0, +0, +1, +1 };
int cc[] = { +0, +1, +0, +1 };
int total, R, C;
inline bool is_good(int msk) {
	fo(i,total) {
		int r = decodeR(i, R, C);
		int c = decodeC(i, R, C);
		map<int, int> mp;
		fo(j,4)	{
			int tr = r + rr[j], tc = c + cc[j];
			if (tr < 0 || tc < 0 || tr >= R || tc >= C)
				continue;
			int temp = encodePos(tr, tc, R, C);
			int bt = (msk & (1 << temp) ? 1 : 0);
			mp[bt]++;
		}
		if (mp[1] == 4 || mp[0] == 4)
			return false;
	}
	return true;
}
Int dp[17][1<<17];
Int go(int cur, int msk) {
	if (cur >= total) {
		return is_good(msk) ? 1LL : 0LL;
	}
	Int &cnt = dp[cur][msk];
	if(cnt!=-1)return cnt;
	cnt=0;
	//0bosay
	cnt += go(cur + 1, msk);
	//1bosay
	cnt += go(cur + 1, msk | (1 << cur));
	return cnt;
}
inline void read() {
}
inline void proc() {
	foE(i,4,4){
		foE(j,1,4){
			R=i,C=j;
			total=R*C;
			SET(dp,-1);
			Int res=go(0,0);
			/*cout<<"[ ROW COL TOTAL result ] > "<<R<<" "<<C<<" = "<<res<<"\n";*/
			cout<<res<<',';
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

