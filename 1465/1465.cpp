// THERE is circle!
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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int p[1000];
int main()
{
  p[0]=0;
  p[1]=1;
  for(int i=2;i<1000;++i)
    {
      int j=i-2;
      vector<int> q;
      q.PB(p[j]);
      --j;
      for(int k=0;k<=j;++k,--j)
	q.PB(p[k]^p[j]);
      sort(q.begin(),q.end());
      q.resize(unique(q.begin(),q.end())-q.begin());
      j=0;
      for(int k=0;k<q.size();++k,++j)
	if(j!=q[k])
	  break;
      p[i]=j;
      cout<<i<<' '<<j<<endl;;
    }
  return 0;
}
