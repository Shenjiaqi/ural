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
ll gcd( ll a, ll b )
{
  return b == 0 ? a : gcd( b, a % b );
}
int main()
{
  ll a, n;
  cin >> a >> n;
  ll ans(0);
  int cnt(0), cnt3(0), cnt5(0);
  for( ll i = 1; i <= n; ++i )
    if( gcd( a * a + i * i , i + a ) > 1 )
      {
	cout << i << endl;
	if( i & 1 )
	  ++cnt;
	if( i % 3 == 0 && ( i & 1 ) == 0 )
	  ++cnt3;
	if( i % 5 == 0 && ( i & 1 ) == 0 )
	  ++cnt5;
	++ans;
      }
  cout << ans << ' ' << cnt << ' ' << cnt3 << ' ' << cnt5 << endl;
  return 0;
}
