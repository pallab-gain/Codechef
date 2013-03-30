/*
 * CBARS.cxx
 *
 *  Created on: 2:09:31 AM Nov 3, 2012
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
#define T unsigned long long
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

#define MT vector< vector<Int> >
const Int mod = 1000000007LL;
inline Int domod(Int v) {
	Int result = v%mod;
	if(result<0)result+=mod;
	return result;
}
inline vector<vector<Int> > Multiply(MT A, MT B) {
	int ROW1 = SZ(A),ROW2 = SZ(B), COL=SZ(B[0]);
	MT result( ROW1, vector<Int>(COL,0) );

	for (int i = 0; i < ROW1; ++i) {
		for (int j = 0; j < ROW2; ++j) {
			for (int k = 0; k < COL; ++k) {
				Int var = domod( domod(A[i][j]) * domod(B[j][k]) );
				result[i][k] = domod(result[i][k] + var);
			}
		}
	}
	return result;
}
inline vector<vector<Int> > fastPow(MT A, Int upto) {
	MT res = A;
	while(upto>0) {
		if( upto&1 ) {
			res = Multiply(res,A);
		}
		A = Multiply(A,A);
		upto>>=1;
	}
	return res;
}
inline void print(MT A){
	fo(i,SZ(A)){
		fo(j,SZ(A[0]))cout<<A[i][j]<<' ';
		puts("");
	}
}
inline Int fastPow1(Int a, Int b) {
    Int x= (Int)1,y= domod(a);
    while (b>0) {
        if (b&1) {
            x= domod(x*y);
        }
        y=domod(y*y);
        b>>=1;
    }
    return domod(x);
}
inline Int slove_row1(Int col){
	return fastPow1(2LL,col);
}
inline Int solve_row2(Int col){
	if(col==1)return 4;
	if(col==2)return 14;
	MT matrix(2, vector<Int>(2,0));
	matrix[0][0]=3,matrix[0][1]=2;
	matrix[1][0]=1,matrix[1][1]=0;
	MT B= MT(2,vector<Int>(1,0));
	B[0][0]=4;B[1][0]=1;

	MT A= fastPow(matrix,col-1);
	MT C = Multiply(A,B);

	return C[1][0];
}
inline Int solve_row3(Int col){
	if(col==1)return 8;
	if(col==2)return 50;
	if(col==3)return 322;

	MT matrix(3, vector<Int>(3,0));
	matrix[0][0]=6,matrix[0][1]=1,matrix[0][2]=0;
	matrix[1][0]=3,matrix[1][1]=0,matrix[1][2]=1;
	matrix[2][0]=-2,matrix[2][1]=0,matrix[2][2]=0;
	MT B = MT(1, vector<Int>(3,0));
	B[0][0]=50,B[0][1]=8,B[0][2]=1;
	MT A = fastPow(matrix,col-3);
	MT C = Multiply(B,A);
	return C[0][0];
}
inline Int solve_row4(Int col){
	if(col==1)return 16;
	if(col==2)return 178;
	if(col==3)return 2066;
	if(col==4)return 23858;
	if(col==5)return 275690;
	MT matrix(5, vector<Int>(5,0));
	matrix[0][0]=10, matrix[0][1]=1,matrix[0][2]=0,matrix[0][3]=0,matrix[0][4]=0;
	matrix[1][0]=20, matrix[1][1]=0,matrix[1][2]=1,matrix[1][3]=0,matrix[1][4]=0;
	matrix[2][0]=-21,matrix[2][1]=0,matrix[2][2]=0,matrix[2][3]=1,matrix[2][4]=0;
	matrix[3][0]=-30,matrix[3][1]=0,matrix[3][2]=0,matrix[3][3]=0,matrix[3][4]=1;
	matrix[4][0]=8,  matrix[4][1]=0,matrix[4][2]=0,matrix[4][3]=0,matrix[4][4]=0;
	MT B = MT(1,vector<Int>(5,0));
	B[0][0]=275690,B[0][1]=23858,B[0][2]=2066,B[0][3]=178,B[0][4]=16;
	MT A = fastPow(matrix,col-6);
	MT C = Multiply(B,A);
	return C[0][0];
}
inline Int solve_row5(Int col){
	if(col==1)return 32LL;
	if(col==2)return 634LL;
	if(col==3)return domod(13262LL);
	if(col==4)return domod(275690LL);
	if(col==5)return domod(5735478LL);
	if(col==6)return domod(119310334LL);
	if(col==7)return domod(2481942354LL);
	if(col==8)return domod(51630303190LL);
	if(col==9)return domod(1074033301458LL);
	MT M(9,vector<Int>(9,0));
	M[0][0]=21,M[0][1]=1;
	M[1][0]=9, M[1][2]=1;
	M[2][0]=-278,M[2][3]=1;
	M[3][0]=73,M[3][4]=1;
	M[4][0]=790,M[4][5]=1;
	M[5][0]=-662,M[5][6]=1;
	M[6][0]=29,M[6][7]=1;
	M[7][0]=69,M[7][8]=1;
	M[8][0]=-10;
	MT B(9,vector<Int>(9,0));
	B[0][0]= domod(1074033301458LL),B[0][1]=domod(51630303190LL),B[0][2]=domod(2481942354LL);
	B[0][3]=domod(119310334LL),B[0][4]= domod(5735478LL),B[0][5]=domod(275690LL);
	B[0][6]=13262LL,B[0][7]=634LL,B[0][8]=32LL;

	MT A =fastPow(M,col-10);
	MT C = Multiply(B,A);
	return C[0][0];
}
inline Int solve_row6(Int col){
	if(col==1)return 64LL;
	if(col==2)return 2258LL;
	if(col==3)return 85126LL;
	if(col==4)return 3185462LL;
	if(col==5)return 119310334LL;
	if(col==6)return 468252386LL;
	if(col==7)return 341333373LL;
	if(col==8)return 120424565LL;
	if(col==9)return 733930200LL;
	if(col==10)return 669210003LL;
	if(col==11)return 533541711LL;
	if(col==12)return 486842637LL;
	if(col==13)return 54569745LL;
	if(col==14)return 550722139LL;
	if(col==15)return 438338918LL;
	if(col==16)return 88893786LL;
	if(col==17)return 394456513LL;
	if(col==18)return 927568251LL;
	MT m(18,vector<Int>(18,0));
	m[0][0]=36;m[0][1]=1;
	m[1][0]=120;m[1][2]=1;
	m[2][0]=-2391;m[2][3]=1;
	m[3][0]=-3905;m[3][4]=1;
	m[4][0]=50702;m[4][5]=1;
	m[5][0]=27152;m[5][6]=1;
	m[6][0]=-396016;m[6][7]=1;
	m[7][0]=154999;m[7][8]=1;
	m[8][0]=751787;m[8][9]=1;
	m[9][0]=-499260;m[9][10]=1;
	m[10][0]=-410368;m[10][11]=1;
	m[11][0]=355981;m[11][12]=1;
	m[12][0]=38077;m[12][13]=1;
	m[13][0]=-70276;m[13][14]=1;
	m[14][0]=6203;m[14][15]=1;
	m[15][0]=3386;m[15][16]=1;
	m[16][0]=-622;m[16][17]=1;
	m[17][0]=28;

	MT b(1, vector<Int>(18,0));
	b[0][0]=927568251LL,b[0][1]=394456513LL,b[0][2]=88893786LL,b[0][3]=438338918LL,b[0][4]=550722139LL;
	b[0][5]=54569745LL,b[0][6]=486842637LL,b[0][7]=533541711LL,b[0][8]=669210003LL,b[0][9]=733930200LL;
	b[0][10]=120424565LL,b[0][11]=341333373LL,b[0][12]=468252386LL,b[0][13]=119310334LL,b[0][14]=3185462LL;
	b[0][15]=85126LL,b[0][16]=2258LL,b[0][17]=64LL;

	MT A = fastPow(m,col-19);
	MT C = Multiply(b,A);
return C[0][0];
}
inline void proc(/*Int row,Int col*/) {
	Int row=fastIn(),col=fastIn();
	if(row==1){
		cout<<slove_row1(col)<<'\n';
	}
	else if(row==2){
		cout<<solve_row2(col)<<'\n';
	}
	else if(row==3){
		cout<<solve_row3(col)<<"\n";
	}
	else if(row==4){
		cout<<solve_row4(col)<<"\n";
	}
	else if(row==5){
		cout<<solve_row5(col)<<"\n";
	}
	else{
		cout<<solve_row6(col)<<"\n";
	}
}
int main() {
	int kase = 1;
#if defined( xerxes_pc )
	if (!freopen("in1", "r", stdin))
		puts("error opening file in "), assert(0);
	kase = 1;
#endif
	//kase=fastIn();
	fo(i,kase){
		proc();
	}
	/*for(Int col=1;col<=20;++col){
		cout<<col<<" ";proc(5,col);
	}*/
	return 0;
}

