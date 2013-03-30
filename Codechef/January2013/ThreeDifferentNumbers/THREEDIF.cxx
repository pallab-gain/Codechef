/*  KDevelop 4.3.1
 *  THREEDIF.cxx
 *
 * 	Author : Pallab
 * 	Created on: 10:06:09 PM - 2013:1:7
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
    while ( c<33 ) {
        c=getchar();
    }
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
const Int mod= ( Int ) 1e9+7LL;
template<class T>
    inline T domod ( T value ) {
    value%=mod;
    if ( value<T ( 0 ) ) {
        value+=mod;
    }
    return value;
}

Int number[3];
Int mul[3];
inline void read() {
    for ( int i=0; i<3; ++i ) {
        number[i]=fastIn<Int>();
    }
}
inline void proc() {
    sort ( number,number+3,less<Int>() );
    Int result=1LL;
    for ( int i=0; i<3; ++i ) {
        if ( i!=0 ) {
            number[i]-= ( i );
        }
        number[i] = domod<Int> ( number[i] );
        result = domod<Int> ( result*number[i] );
    }
    cout<<result<<'\n';
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


