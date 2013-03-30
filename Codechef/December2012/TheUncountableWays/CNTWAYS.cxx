 /*
*	ID : Pallab
* 	PROG : CNTWAYS2
* 	LANG : C++
* 	2012-12-03-15.54.50 Monday
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
const Int mod=1000000007;
const int LIMIT=400000;
Int modInverse[LIMIT+5];

inline Int domod(Int num) {
    num=num%mod;
    if(num<0)num+=mod;
    return num;
}
inline void inverseArray(int n, Int m) {
    modInverse[0] = 0;
    modInverse[1] = 1;
    for(int i = 2; i <= n; i++) {
        modInverse[i] = (-(m/i) * modInverse[ (m % i) ]) % m + m;
    }
}
inline Int moduleInverse(Int a) {
    return modInverse[a];
}
struct solver {
    int n;
    Int cnt[LIMIT+5];
    solver() {
        n=0;
    }
    solver(int n_) {
        n=n_;
    }
    inline void ncr() {
        cnt[0]=1;
        for(int i=1,from=n+1; i<=LIMIT; ++i,++from) {
            cnt[i] = domod( domod(from*cnt[i-1]) * moduleInverse(i) );
        }
    }
};
inline Int main2(int R, int C, int r, int c) {
    if(c==C||r==R) {
        return 0;
    }
    int r1=R,c1=C-c;
    int r2=R-r,c2=c;

    solver ob1(c1-1);
    solver ob2(c2-1);
    ob1.ncr();
    ob2.ncr();

    Int result=0;
    for(int i=R-1,j=0; i>=r; --i,++j) {
        result = domod(result+ domod(ob1.cnt[i]*ob2.cnt[j]));
    }
    return result;
}
inline void proc(int R, int C, int r, int c) {
    R+=1,C+=1;
    Int result = main2(R,C,r,c);
    cout<<result<<'\n';
}
int main() {
    inverseArray(LIMIT,mod);
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("in1", "r", stdin))
        puts("error opening file in "), assert(0);
    kase = 1;
#endif
    int R,C,r,c;
    kase=fastIn<int>();
    fo(i,kase) {
        R=fastIn<int>(),C=fastIn<int>(),r=fastIn<int>(),c=fastIn<int>();
        proc(R,C,r,c);
    }
    return 0;
}