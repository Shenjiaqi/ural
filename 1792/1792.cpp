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
int main()
{
  int p[7];
  FOR(i,0,7)
    scanf("%d",&p[i]);
  int t[3];
  t[0] = p[1] ^ p[2] ^ p[3] ^ p[4] ;
  t[1] = p[0] ^ p[2] ^ p[3] ^ p[5] ;
  t[2] = p[0] ^ p[1] ^ p[3] ^ p[6] ;
  if( t[0] && t[1] && t[2] )
    p[3] ^= 1;
  else if( t[1] && t[2] )
    p[0] ^= 1;
  else if( t[0] && t[2] )
    p[1] ^= 1;
  else if( t[0] && t[1] )
    p[2] ^= 1;
  else 
    for(int i=0;i<3;++i)
      if(t[i])
	p[i+4] ^= 1;
  FOR(i,0,7)
    printf("%d ",p[i]);
  return 0;
}
