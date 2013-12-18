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
const int N=5007;
int p[N][3];
int f[N*2][2];
int gfa(int a)
{
  int t=f[a][0];
  if(a==t)
    return a;
  f[a][0]=gfa(t);
  f[a][1]^=f[t][1];
  return f[a][0];
}
bool joi(int a,int b,int v)
{
  int c=gfa(a),d=gfa(b);
  if(c==d)
    {
      if(v!=(f[a][1]^f[b][1]))
	return false;
    }
  else
    {
      f[d][0]=c;
      f[d][1]=f[b][1]^v^f[a][1];
    }
  return true;
}
int main()
{
  for(int l,t=0;;++t)
    {
      scanf("%d",&l);
      if(l>=0)
	{
	  if(t)
	    printf("\n");
	  int n;
	  scanf("%d",&n);
	  map<int,int> mapp;
	  FOR(i,0,n)
	    {
	      int a,b;
	      char s[10];
	      scanf("%d%d%s",&a,&b,s);
	      p[i][0]=a,p[i][1]=b;
	      mapp[p[i][0]-1]=mapp[p[i][1]]=0;
	      if(s[0]=='o')
		p[i][2]=1;
	      else p[i][2]=0;
	    }
	  int ans=n;
	  int cnt=0;
	  FR(i,mapp)
	    i->SEC=cnt++;
	  FOR(i,0,cnt+1)
	    f[i][0]=i,f[i][1]=0;
	  FOR(i,0,n)
	    {
	      assert(mapp.find(p[i][0]-1)!=mapp.end() && 
		     mapp.find(p[i][1])!=mapp.end());
	      if(!joi(mapp[p[i][0]-1],mapp[p[i][1]],p[i][2]))
		{
		  ans=i;
		  break;
		}
	    }
	  printf("%d",ans);
	}
      else break;
    }
  return 0;
}
