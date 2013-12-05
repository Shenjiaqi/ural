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
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int main()
{
  int n,m;
  n=100;
  m=n*(n-1);
  cout<<n<<' '<<m<<endl;
  FOR(i,0,m)
    {
      int a=rand()%n;
      int b;
      for(;a==(b=rand()%n);)
	;
      cout<<a<<' '<<b<<' '<<(1+rand()%300)<<endl;
    }
  return 0;
}
