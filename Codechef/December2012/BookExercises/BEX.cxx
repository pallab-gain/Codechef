/*
*	ID : Pallab
* 	PROG : BEX
* 	LANG : C++
* 	2012-12-02-01.26.10 Sunday
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
inline void readword(char *buffer) {
    int c, cnt = 0;
    c = getchar();
    while (c >= 0 && c <= ' ') {
        c = getchar();
    }
    if (c < 0) {
        buffer[cnt] = 0;
        return;
    }
    while (c > ' ') {
        buffer[cnt++] = c;
        c = getchar();
    }
    buffer[cnt] = 0;
}
const int inf = 1023456789;
char tmp_buff[20];
struct node {
    string name;
    int rank;
    int cur_min;
};
inline void simulate() {
    int itr=fastIn<int>();
    int tmp;
    stack<node> st;
    while(itr>0) {
        tmp=fastIn<int>();
        if(tmp==-1) {
            //is a query
            int mn=st.top().cur_min,cnt=0;
            while(1) {
                if( st.top().rank==mn ) {
                    cout<<cnt<<' '<<st.top().name<<'\n';
                    st.pop();
                    break;
                } else {
                    ++cnt;
                    st.pop();
                }
            }
        } else {
            node d;
            readword(tmp_buff);
            if(tmp>0) {
                d.name=(string)(tmp_buff),d.rank=tmp;
                d.cur_min=min(tmp, st.empty()?tmp:st.top().cur_min);
                st.push(d);
            }
        }
        --itr;
    }
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("in1", "r", stdin))
        puts("error opening file in "), assert(0);
    kase = 1;
#endif
    fo(i,kase) {
        simulate();
    }
    return 0;
} 
