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
int v[N];
int vis[N];
int main()
{
  int n;
  scanf("%d", &n);
  int sum = 0;
  for( int i = 0 ; i < n; ++i )
    {
      scanf("%d", v + i);
      sum = ( sum + v[i] ) % n;
      if( sum == 0 || vis[sum] )
	{
	  printf("%d\n", i - vis[sum] + 1 );
	  for( int j = vis[sum]; j <= i; ++j )
	    printf("%d\n", v[j]);
	  return 0;
	}
      vis[sum] = i + 1;
    }
  return 0;
}
