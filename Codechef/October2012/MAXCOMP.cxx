/*
 * MAXCOMP.cxx
 *
 *  Created on: 5:57:00 PM Oct 1, 2012
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
struct Event {
	int s;
	int e;
	int c;
	Event(int x = 0, int e = 0, int c = 0) :
			s(s), e(e), c(c) {
	}
};
inline bool operator<(const Event &l, const Event &r) {
	if (l.e == r.e) {
		return l.s < r.s || (l.s == r.s && l.c > r.c);
	}
	return l.e < r.e;
}
const int MX = 2005;
Event events[MX];
int event_count;
inline void read() {
	event_count = fastIn();
	fo(i,event_count) events[i].s=fastIn(),
events	[i].e=fastIn(),events[i].c=fastIn();
}
int dp[50],dpnxt[50];
inline void proc() {
	sort(events , events + event_count );
	SET(dp,0);
	SET(dpnxt,0);
	for(int i=0;i<=48;++i){
		for(int j=0;j<event_count;++j){
			int s=events[j].s;
			int e=events[j].e;
			int w=events[j].c;
			if( i<=s)
				dpnxt[e] = max(dpnxt[e], w+ dp[i]);
		}
		memcpy(dp,dpnxt,sizeof(dp));
	}
	int bst=0;
	for(int i=0;i<=48;++i){
		bst=max(bst, dp[i]);
	}
	cout<<bst<<'\n';
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("MAXCOMP/in1", "r", stdin))
		puts("error opening file MAXCOMP/in1 "), assert(0);
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