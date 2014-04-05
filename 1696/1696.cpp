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
const int K = 207;
int dp[2][K][K];
int n, k, p;
int add( int a, int b)
{
  return ( a + b ) % p;
}
int mul( int a, int b )
{
  return ( (ll)a * (ll)b ) % p;
}
int main()
{
  scanf("%d%d%d", &n, &k, &p);
  int f, t;
  f = 0, t = 1;
  for( int i = 1; i <= k; ++i )
    dp[f][i][ k + 1 ] = 1;
  for( int i = 1; i < n; ++i )
    {
      memset( dp[t], 0, sizeof(dp[t]) );
      for( int j = 1; j <= k + 1; ++j )
	{
	  int sum = dp[f][j][ k + 1 ];
	  // dp[t][j][ k + 1 ] = dp[f][j][ k + 1 ];
	  for( int l = k; l > j; --l )
	    {
	      sum = add( sum, dp[f][j][l] );
	      dp[t][j][l] = sum;
	    }
	}
      for( int l = 1; l <= k + 1; ++l )
	{
	  int sum = 0;
	  for( int j = l - 1; j > 0; --j )
	    {
	      sum = add( sum, dp[f][j][l] );
	      dp[t][j][l] = add( sum, dp[t][j][l] );
	    }
	}
      swap( f, t);
    }
  int ans(0);
  // for( int i = 1; i <= k; ++i )
  //   {
  //     for( int j = 1; j <= k + 1; ++j )
  // 	cout << dp[f][i][j] << ' ' ;
  //     cout << endl;
  //   }
  for( int i = 1; i <= k; ++i )
    for( int j = i + 1; j <= k + 1; ++j )
      ans = add( ans, dp[f][i][j] );
  printf("%d", ans + 1 );
  return 0;
}
