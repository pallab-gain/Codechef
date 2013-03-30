/*  KDevelop 4.3.1
 *  CVOTE.cxx
 *
 * 	Author : Pallab
 * 	Created on: 8:58:41 PM - 2013:1:1
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

map<string,string> IDs;
map<string,int> countries,names;
int chefCount,emailCount;
inline void read() {
    countries.clear();
    names.clear();
    IDs.clear();
    //---------------------------------------------------
    chefCount=fastIn<int>(),emailCount=fastIn<int>();
    int i;
    string name,country;
    for ( i=0; i<chefCount; ++i ) {
        cin>>name>>country;
        IDs[name]=country;
    }
    for ( i=0; i<emailCount; ++i ) {
        cin>>name;
        names[name]++;
        countries[ IDs[name] ]++;
    }
}
inline void proc() {
    string bstCountry,bstChef;
    int bst=-1;
    int i;
    for ( map<string,int> :: iterator it = countries.begin() ; it != countries.end(); ++it ) {
        if ( it->second > bst ) {
            bst=it->second;
            bstCountry=it->first;
        } else if ( it->second==bst && it->first<bstCountry ) {
            bstCountry=it->first;
        }
    }
    bst=-1;
    for ( map<string,int> :: iterator it = names.begin() ; it != names.end(); ++it ) {
        if ( it->second > bst ) {
            bst=it->second;
            bstChef=it->first;
        } else if ( it->second==bst && it->first<bstChef ) {
            bstChef=it->first;
        }
    }
    cout<<bstCountry<<"\n"<<bstChef<<"\n";
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    freopen ( "in1", "r", stdin );
    kase = 1;
#endif
    for ( int i=1; i<=kase; ++i ) {
        read();
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
