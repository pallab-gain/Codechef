 /*
*	ID : Pallab
* 	PROG : Granama
* 	LANG : C++
* 	2012-12-01-19.48.33 Saturday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
    register char c=0;
    register T a=0;
    bool neg=false;
    while(c<33)c=getchar();
    while(c>33) {
        if(c=='-') {
            neg=true;
        } else {
            a= (a*10)+(c-'0');
        }
        c=getchar();
    }
    return neg?-a:a;
}
int judge1[27],judge2[27];
char buff1[1005],buff2[1005];

inline bool f1() {
    fo(i,26) {
        if(judge1[i]&&judge2[i])continue;
        if(!judge1[i]&&!judge2[i])continue;

        return false;
    }
    return true;
}
inline bool f2() {
    fo(i,26) {
        if( judge1[i]==judge2[i] )continue;
        return false;
    }
    return true;
}
inline void proc() {
    scanf(" %s %s",buff1,buff2);
    SET(judge1,0);
    SET(judge2,0);

    fo(i,strlen(buff1))judge1[buff1[i]-'a']++;
    fo(i,strlen(buff2))judge2[buff2[i]-'a']++;

    bool ff1=f1(),ff2=f2();
    //if sets of ingridients used in both recipe are equal
    if( ff1 ) {
        if(ff2)puts("YES");
        else puts("NO");
    } else {
        puts("YES");
    }
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("in1", "r", stdin))
        puts("error opening file in "), assert(0);
    kase = 1;
#endif
    kase=fastIn<int>();
    fo(i,kase) {
        proc();
    }
    return 0;
}