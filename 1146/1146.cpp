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
#define N 100
const int inf=1e9;
int sum[N];
int p[N][N];
int main()
{
  int n;
  scanf("%d",&n);
  FOR(i,0,n)
    FOR(j,0,n)
    scanf("%d",&p[i][j]);
  int ans=-inf;
  FOR(i,0,n)
    {
      memset(sum,0,sizeof(sum));
      FOR(j,i,n)
	{
	  FOR(k,0,n)
	    sum[k]+=p[j][k];
	  int r=0;
	  FOR(k,0,n)
	    {
	      r+=sum[k];
	      ans=max(ans,r);
	      if(r<0)
		r=0;
	    }
	}
    }
  printf("%d",ans);
  return 0;
}
