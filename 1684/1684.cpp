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
const int L = 75007;
char s[2][L];
int pre[L];
int idx[L];
void pt( int i )
{
  if( i != idx[i] )
    {
      pt( i - idx[i] - 1);
      printf(" ");
    }
  for( int j = i - idx[i]; j <= i; ++j )
    printf("%c", s[1][j] );
}
int main()
{
  scanf("%s%s", s[0], s[1]);
  int l[2];
  l[0] = strlen(s[0]);
  l[1] = strlen(s[1]);
  pre[0] = -1;
  for( int i = 1, j = 0; i <= l[0]; ++i, ++j )
    {
      if( j < 0 ||  s[0][j] != s[0][i] )
	{
	  pre[i] = j;
	  for( ; j >=0 && s[0][j] != s[0][i]; j = pre[j] )
	    ;
	}
      else
	pre[i] = pre[j];
    }
  for( int i = 0, j = 0 ; i < l[1]; ++i, ++j )
    {
      for( ; j >= 0 && s[0][j] != s[1][i]; j = pre[j] )
	;
      if( j < 0 )
	{
	  printf("Yes");
	  return 0;
	}
      idx[i] = j;
    }
  printf("No\n");
  pt( l[1] - 1 );
  return 0;
}
