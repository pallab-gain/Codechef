/*  KDevelop 4.3.1
 *  CHEFHACK.cxx
 *
 *      Author : Pallab
 *      Created on: 10:44:39 AM - 2013:1:3
 *      "I have not failed, I have just found 10000 ways that won't work."
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

const int inf = ( int ) 10000005;
bool used[inf+10];
int primes[664579+5],cnt;
inline bool isPrime ( int num ) {
    if ( num<2 ) return false;
    if ( num==2 ) return true;
    if ( ! ( num&1 ) ) return false;
    return !used[num] ;
}
inline void sieve() {
    int sqrtN = ( int ) sqrt ( ( double ) inf ) +1;
    SET ( used,false );
    int i,j;
    for ( i=3; i<=sqrtN; i+=2 ) {
        if ( !used[i] ) {
            for ( j=i*i; j<inf; j+=i ) {
                used[j]=1;
            }
        }
    }
    cnt=0;
    primes[cnt++]=2;
    for ( i=3; i<=inf; i+=2 ) {
        if ( !used[i] ) primes[cnt++]=i;
    }
}
const int MX=400;
int grid[MX][MX];
int R;
inline void read() {
    R=fastIn<int>();
    int i,j;
    for ( i=1; i<=R; ++i )
        for ( j=1; j<=R; ++j ) grid[i][j]=fastIn<int>();
}
//value , type 0=even,1=odd
bool seen[MX][MX];
inline bool alreadyMarked ( int row,int col ) {
    return seen[row][col];
}
const int rr[]= {-1,+1,+0,+0, -1,-1,+1,+1};
const int cc[]= {+0,+0,-1,+1, -1,+1,+1,-1};
inline void markedThem ( int row,int col,int type ) {
    if ( alreadyMarked ( row,col ) || isPrime ( grid[row][col] ) ) return ;

    seen[row][col]=true;
    for ( int i=0; i<4; ++i ) {
        int tr=row+rr[i],tc=col+cc[i];
        if ( tr<1||tc<1||tr>R||tc>R ) continue;
        if ( ( grid[tr][tc]&1 ) == type ) {
            markedThem ( tr,tc,type );
        }
    }

}
inline int stepNeeds ( int value ) {
    int tmp= ( value>>1 );
    if ( value&1 ) {
        tmp+=2;
    }
    return tmp;
}
inline void proc() {
    SET ( seen,false );
    int i,j,type,d,value;
    Int result=0;
    for ( i=1; i<=R; ++i ) {
        for ( j=1; j<=R; ++j ) {
            if ( isPrime ( grid[i][j] ) ) {
                d = lower_bound ( primes,primes+cnt, grid[i][j] )-primes;
                result= result+ d ;
            } else {
                if ( alreadyMarked ( i,j ) ==false ) {
                    d= stepNeeds ( grid[i][j] );
                    result+=d;
                    markedThem ( i,j, ( grid[i][j]&1 ) );
                }

            }
        }
    }
    cout<<result<<'\n';
}
int main() {
    //for(int i=0;i<=10;++i)cout<<i<<' '<<stepNeeds(i)<<'\n';
    sieve();
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
