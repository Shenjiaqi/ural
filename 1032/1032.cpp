#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
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
const int N = 1e4 + 7;
int dp[N][2];
int main()
{
  int n;
  scanf("%d", &n );
  memset(dp, -1, sizeof( dp ) );
  dp[0][0] = 0;
  for( int i = 0 ; i < n ; ++i )
    {
      int v;
      scanf("%d", &v);
      for( int j = 0; j < n; ++j )
	if( dp[j][1] != i && dp[j][0] >= 0 )
	  {
	    int t = ( j + v ) % n;
	    if( dp[t][0] <= 0 )
	      dp[t][0] = v, dp[t][1] = i;
	    if( t == 0 )
	      break;
	  }
      if( dp[0][0] != 0 )
	{
	  vector<int> ans;
	  for( int i = 0; ; )
	    {
	      ans.push_back( dp[i][0] );
	      i = ( i - ( dp[i][0] % n ) + n ) % n;
	      if( i == 0 )
		break;
	    }
	  printf("%d\n", (int)ans.size() );
	  for( auto i : ans )
	    printf("%d\n", i);
	  return 0;
	}
    }
  printf("0");
  return 0;
}
