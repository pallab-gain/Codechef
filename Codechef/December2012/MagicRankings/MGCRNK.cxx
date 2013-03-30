/*
*	ID : Pallab
* 	PROG : MGCRNK
* 	LANG : C++
* 	2012-12-01-20.56.01 Saturday
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
inline int encodePos(int rpos, int cpos, int RR, int CC) {
    return rpos*CC + cpos ;
}
inline int decodeR(int rpos, int RR, int CC) {
    return rpos/CC;
}
inline int decodeC(int cpos, int RR, int CC) {
    return cpos%CC;
}
const int MX=105;
int G[MX][MX];
int R,C;

inline void read() {
    R=fastIn<int>();
    C=R;
    fo(i,R) {
        fo(j,C) {
            G[i][j]=fastIn<int>();
        }
    }
}
inline int Get(int R) {
    return ((R-2)<<1)|1;
}
const int inf=1023456789;
int dp[MX][MX];
inline void proc() {
    //dp approach
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            if(i==0) {
                dp[i][j]= j?dp[i][j-1]+G[i][j]:0;
            } else if(j==0) {
                dp[i][j]= i?dp[i-1][j]+G[i][j]:0;
            } else {
                int a=G[i][j]+(dp[i-1][j]);
                int b=G[i][j]+(dp[i][j-1]);
                dp[i][j]=max(a,b);
            }
        }
    }
    if(dp[R-1][C-1]>=0) {
        double tmp=dp[R-1][C-1];
        tmp/=Get(R);
        cout<<tmp;
        line;
    } else {
        puts("Bad Judges");
    }
}
int main() {
    cout<<setprecision(6)<<fixed;
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("in1", "r", stdin))
        puts("error opening file in "), assert(0);
    kase = 1;
#endif
    kase=fastIn<int>();
    fo(i,kase) {
        read();
        proc();
    }
    return 0;
} 
