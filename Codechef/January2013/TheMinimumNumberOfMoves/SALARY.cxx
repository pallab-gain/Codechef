/*  KDevelop 4.3.1
 *  SALARY.cxx
 *
 * 	Author : Pallab
 * 	Created on: 11:52:58 AM - 2013:1:2
 * 	"I have not failed, I have just found 10000 ways that won't work."
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

#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
const int MX=105;
int numberCount;
int numbers[MX];
inline void read() {
    numberCount=fastIn<int>();
    int i;
    for ( i=0; i<numberCount; ++i ) numbers[i]=fastIn<int>();
}
inline void print ( int from ) {
    for ( int i=from; i<numberCount; ++i ) cout<<numbers[i]<<' ';
    line;
}
inline void proc() {
    sort ( numbers,numbers+numberCount,less<int>() );
    int i,j,cnt=0,d;
    for ( i=0; i<numberCount; ++i ) {
        d=numbers[numberCount-1]-numbers[i];
        cnt+=d;
        for ( j=i; j+1<numberCount; ++j ) {
            numbers[j]+=d;
        }
        sort(numbers,numbers+numberCount,less<int>());
    }
    cout<<cnt<<'\n';
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    freopen ( "in1", "r", stdin );
    kase = 1;
#endif
    kase=fastIn<int>();
    for ( int i=1; i<=kase; ++i ) {
        read();
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
