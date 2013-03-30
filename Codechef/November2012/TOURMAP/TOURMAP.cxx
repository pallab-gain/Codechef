/*
 * TOURMAP.cxx
 *
 *  Created on: 1:06:42 AM Nov 2, 2012
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

const int MX = 5005;
string names[MX ];
int route_count;
map<string, int> mp;
struct info {
	string u, v;
	int c;
	void print() {
		cout << u << "_" << v << "_" << c << "\n";
	}

};
info vi[MX];
int total;
inline void read() {
	mp.clear();
	route_count = fastIn();
	char ch;
	fo(i,route_count-1)
		cin >> vi[i].u >> vi[i].v >> vi[i].c >> ch;
}
vector<pair<int, int> > adj[MX ];
bool marked[MX ];
int costs;
inline void solve(int parent) {
	foit(it,adj[parent]){
		int to = it->first, c = it->second;
		cout << names[parent] << ' ' << names[to] << ' ' << c << "$\n";
		costs += c;
		solve(to);
	}
}
inline void proc() {
	int id = 0;
	fo(i,route_count-1)
	{
		string u = vi[i].u, v = vi[i].v;
		if (!mp.count(u)) {
			++id;
			mp[u] = id;
			names[id] = u;
		}
		if (!mp.count(v)) {
			++id;
			mp[v] = id;
			names[id] = v;
		}
	}
	total = id;
	foE(i,0,total)
		adj[i].clear();
	SET(marked, true);
	fo(i,route_count-1){
		string u = vi[i].u, v = vi[i].v;
		marked[mp[v]] = false;
		adj[mp[u]].pb(mk(mp[v], vi[i].c));
	}
	costs = 0;
	foE(i,1,total){
		if (marked[i] == true) {
			solve(i);
		}
	}
	cout << costs << "$\n";
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

