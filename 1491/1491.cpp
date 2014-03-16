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
const int N = 1e5 + 7;
int cnt[N];
int n;
void add( int pos, int num )
{
  for(; pos <= n ; pos += (pos & (-pos)) )
    cnt[pos] += num;
}
int que( int pos )
{
  int r(0);
  for(; pos; pos ^= (pos & ( -pos ) ) )
    r += cnt[pos];
  return r;
}
int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i <= n; ++i)
    {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      add( a, c);
      add( b + 1, -c );
    }
  for( int i = 1; i <= n ; ++i )
    printf("%d ", que(i) );
  return 0;
}
