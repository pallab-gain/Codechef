/*  KDevelop 4.3.1
 *  LEALCO.cxx
 *
 * 	Author : Pallab
 * 	Created on: 1:13:30 PM - 2013:1:2
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
template<class T>
    inline int bc ( T msk ) {
    int c=0;
    for ( c=0; msk ; ++c ) {
        msk&= ( msk-1 );
    }
    return c;
}
int N,K,M;
int R[20];
inline void read() {
    N=fastIn<int>(),K=fastIn<int>(),M=fastIn<int>();
    for ( int i=0; i<N; ++i ) R[i]=fastIn<int>();
}

inline int range_max ( int frm,int to ) {
    int mx=0;
    while ( frm<to )
        mx=max ( mx,R[frm] ),++frm;

    return mx;
}
inline void add ( int msk ) {
    for ( int i=0; i<N; ++i ) if ( msk& ( 1<<i ) ) ++R[i];
}
inline void rmv ( int msk ) {
    for ( int i=0; i<N; ++i ) if ( msk& ( 1<<i ) )--R[i];
}
inline bool OK ( int msk ) {
    int i,j,k,d,Mx;

    for ( i=0; i+K<=N; ++i ) {
        d=0;
        Mx= range_max ( i,i+K );
        for ( j=i,k=1; k<=K; ++k,++j ) {
            if ( R[j]==Mx ) ++d;
            if ( d>=M ) {
                return false;
            }
        }
    }
    return true;
}
const int inf=1023456789;
inline void proc() {
    int bst=inf;
    for ( int i=0,_i= ( 1<<N ); i<_i; ++i ) {
        add ( i );
        if ( OK ( i ) ) bst=min ( bst,bc<int> ( i ) );
        rmv ( i );
    }
    cout<< ( bst!=inf?bst :-1 ) <<'\n';

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

