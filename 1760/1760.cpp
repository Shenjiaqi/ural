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
int main()
{
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n );
  ll ans(0);
  for( int i = 0 ; i < n ; ++i )
    {
    // ra = min( a - 1 - ( i % a ), n - i - 1 )
    // rb = min( b - 1 - ( i % b ), n - i - 1 )
    // ans += max( ra - rb, 0 )
      int ra = min( a - 1 - ( i % a ), n - i - 1);
      int rb = min( b - 1 - ( i % b ), n - i - 1);
      ans += max( ra - rb, 0 );
    }
  cout << ans;
  return 0;
}
