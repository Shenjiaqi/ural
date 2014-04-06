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
const int SA = 1000007;
vector<ll> d;
ll a, ra, n, ans;
void dfs( int lev, ll t, int cnt )
{
  if( t > n )
    return;
  if( lev >= d.size() )
    {
      if( t > 1 )
	{
	  ll tmp = n / t;
	  if( cnt & 1 )
	    {
	      if( ra & 1 )
		{
		  if( t & 1 )
		    ans += tmp / 2;
		  else ans += tmp;
		}
	      else ans += tmp;
	    }
	  else
	    {
	      if( ra & 1 )
		{
		  if( t & 1 )
		    ans -= tmp / 2;
		  else ans -= tmp;
		}
	      else
		ans -= tmp;
	    }
	}
    }
  else
    {
      dfs( lev + 1, t * d[lev], cnt + 1);
      dfs( lev + 1, t, cnt );
    }
}
int main()
{
  cin >> a >> n;
  ra = a;
  for( ll i = 2; i * i <= a; ++i )
    if( ( a % i ) == 0 )
      {
	d.push_back( i );
	for( ; ( a % i ) == 0; )
	  a /= i;
      }
  if( a > 1 )
    d.push_back(a);
  dfs(0, 1, 0);
  if( ra & 1 )
    ans += ( n + 1 ) / 2;
  cout << ans;
  return 0;
}
