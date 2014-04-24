#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 1e5 + 7;
int p[ N * 4 ][ 'z' - 'a' + 1], poi, idx;
int len[ N * 4];
int pre[ N * 4];
int posM[ N * 4];
char sN[N], sM[N];
int n, m;
const int MOD = 1e9 + 7;
const int T = 37;
// ll hv[N][2][2];
int hv[N][2];
int addM( int a, int b, int mod )
{
  int r = ( ( ( a + b ) % mod ) + mod ) % mod;
  assert( r >= 0 );
  return r;
}
int subM( int a, int b, int mod )
{
  int r = addM( a, -b, mod );
  assert( r >= 0 );
  return r;
}
int mulM( int a, int b, int mod )
{
  return ( (ll)a * (ll)b ) % mod;
}
int powM( int v, int r, int mod )
{
  int ret = 1;
  for( ; r; r >>= 1, v = mulM( v, v, mod) )
    if( 1 & r )
      ret = mulM( ret, v, mod);
  return ret;
}
void add( int v, int id )
{
  ++idx;
  memset( p[idx], -1, sizeof( p[idx] ) );
  posM[idx] = id;
  len[idx] = len[poi] + 1;
  int i = poi;
  poi = idx;
  for(  ; i >= 0 && p[i][v] < 0; i = pre[i])
    p[i][v] = poi;
  if( i < 0 )
    pre[poi] = 0;
  else
    {
      int j = p[i][v];
      if( len[i] + 1 != len[j] )
	{
	  ++idx;
	  memcpy( p[idx], p[j], sizeof( p[idx] ) );
	  posM[idx] = posM[j];
	  len[idx] = 1 + len[i];
	  pre[idx] = pre[j];
	  pre[poi] = pre[j] = idx;
	  for( ; i >= 0 && j == p[i][v]; i = pre[i] )
	    p[i][v] = idx;
	}
      else
	pre[poi] = j;
    }
}
int hasH( int a, int b)
{
  return addM( mulM( T, a, MOD), b, MOD);
  // return ( ( (ll)T * a + b) % ( MOD ) ) + 1;
}
int main()
{
  scanf("%s%s", sN, sM);
  n = strlen(sN);
  m = strlen(sM);
  pre[0] = -1;
  memset( p[0], -1, sizeof(p[0]) );
  for( int i = 0; i < 2; ++i )
    for( int j = m - 1; j >= 0; --j)
      add( sM[j] - 'a', j );
  int d = n - m;
  int md = d / 2;
  if( md > 0 )
    {
      int hVal(0);
      int Tr = powM( T, md, MOD);
      for( int i = 0; i < md; ++i )
	hVal = hasH( hVal, sN[i] - 'a');
      for( int i = 0, j = 0, k = md; i < n; ++i)
	{
	  hv[i][1] = subM( hVal, mulM( j, Tr, MOD), MOD );
	  j = hasH( j, sN[i] - 'a');
	  hVal = hasH( hVal, sN[k] - 'a' );
	  k = addM( k, 1, n);
	}
      hVal = 0;
      for( int i = 0; i < md; ++i )
	hVal = hasH( hVal, sN[ n - 1 - i] - 'a' );
      for( int i = n - 1, j = 0, k = n - 1 - md; i >= 0; --i )
	{
	  hv[i][0] = subM( hVal, mulM( j, Tr, MOD), MOD);
	  hVal = hasH( hVal, sN[k] - 'a');
	  j = hasH( j, sN[i] - 'a');
	  k = subM( k, 1, n);
	}
    }
  // int f, t;
  // f = 0, t = 1;
  // for( int i = 0; i < N; ++i)
  //   hv[i][f][0] = hv[i][f][1] = hasH( sN[i] - 'a', 0);
  // int de = 1;
  // for( ; 2 * de <= d / 2;)
  //   {
  //     for( int j = 0; j < n; ++j )
  // 	{
  // 	  hv[j][t][0] = hasH( hv[ subM( j, de, n ) ][f][0],
  // 			      hv[j][f][0] );
  // 	  hv[j][t][1] = hasH( hv[ addM( j, de, n ) ][f][1],
  // 			      hv[j][f][1] );
  // 	}
  //     de <<= 1;
  //     swap( f, t );
  //   }
  for( int j = 0, pi = 0, l = 0; j < 2; ++j )
    {
      for( int i = 0; i < ( j ? m : n ); ++i)
	{
	  int v = sN[i] - 'a';
	  if( p[pi][v] >= 0 )
	    pi = p[pi][v], ++l;
	  else
	    {
	      for( ; pi >= 0 && p[pi][v] < 0; pi = pre[pi])
		  ;
	      if( pi >= 0 )
		l = min( l + 1, len[pi] + 1), pi = p[pi][v];
	      else
		pi = 0, l = 0;
	    }
	  if( l >= m )
	    {
	      int m1, m2;
	      if( d & 1 )
		m1 = addM( i, d / 2, n ), m2 = addM( m1, 2, n);
	      else
		m1 = addM( i, d / 2, n), m2 = addM( 1, m1, n );
	      // if( ( d <= 1 || hv[m1][f][0] == hv[m2][f][1] ) && 
	      // 	  ( d / 2 <= de || hv[ subM( m1, d / 2 - de, n) ][f][0] == 
	      // 	    hv[ addM( m2, d / 2 - de, n ) ][f][1] ) )
	      if( d <= 1 || ( hv[m1][0] == hv[m2][1] ) )
		{
		  int sn = subM( i, m - 1, n );
		  int sm = posM[pi];
		  printf("Yes\n%d %d", sn + 1, sm + 1);
		  return 0;
		}
	    }
	}
    }
  printf("No");
  return 0;
}
