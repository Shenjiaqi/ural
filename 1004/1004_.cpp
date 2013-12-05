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
typedef pair<int,int> pp;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 101
int p[N][N];
int frm[N][N];
int main()
{
  for(int n,m;2==scanf("%d%d",&n,&n);)
    {
      memset(p,1<<6,sizeof(p));
      memset(frm,0,sizeof(frm));
      int inf=p[0][0];
      FOR(i,0,m)
	{
	  int a,b,l;
	  scanf("%d%d%d",&a,&b,&l);
	  p[a][b]=p[b][a]=min(p[b][a],l);
	}
      FOR(k,1,n+1)
	FOR(i,1,n+1)
	if(i!=k && p[i][k]<inf)
	  FOR(j,1,n+1)
	    if(j!=k && p[k][j]<inf)
	      {
		int tmp=p[i][k]+p[k][j];
		if(tmp<p[i][j])
		  p[i][j]=tmp,frm[i][j]=k;
	      }
      FOR(i,1,n+1)
	FOR(j,i+1,n+1)
	if(p[i][j]<inf && frm[i][j]==0)
	  {
	    
	  }
    }
}
