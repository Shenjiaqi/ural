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
int q[N][N];
vector<pp> p[N];
bool vis[N];
int le[N];
int pre[N];
int ansl;
void pt(int k)
{
  int s=k>>10;
  int t=k&((1<<10)-1);
  for(int i=s;;s=pre[s])
    {
      printf("%d",s);
      if(s==t)
	break;
      printf(" ");
    }
}
int dfs(int v,int from,int len,int lim)
{
  if(len<lim)
    {
      pre[v]=from;
      le[v]=len;
      FR(i,p[v])
	{
	  int t=i->first;
	  int length=i->second;
	  if(!vis[t] && t!=from)
	    {
	      if(pre[t])
		{
		  ansl=length+len-le[t];
		  if(ansl<=lim)
		    return (v<<10)|t;
		}
	      else
		{
		  int tmp=dfs(t,v,len+length,lim);
		  if(tmp)
		    return tmp;
		}
	    }
	}
      pre[v]=0;
    }
  return 0;
}
int test(int n,int len)
{
  memset(pre,0,sizeof(pre));
  for(int i=1;i<=n;++i)
    {
      int tmp=dfs(i,-1,0,len);
      if(tmp)
	return tmp;
      vis[i]=true;
    }
  return 0;
}
int main()
{
  for(int n,m,cnt=0;2==scanf("%d%d",&n,&m);++cnt)
    {
      if(n<0)
	break;
      memset(q,1<<6,sizeof(q));
      int inf=q[0][0];
      FOR(i,0,m)
	{
	  int a,b,l;
	  scanf("%d%d%d",&a,&b,&l);
	  q[a][b]=q[b][a]=min(l,q[b][a]);
	}
      FOR(i,1,n+1)
	{
	  p[i].resize(0);
	  FOR(j,1,n+1)
	    if(q[i][j]<inf)
	      p[i].push_back(pp(j,q[i][j]));
	}
      int ans=-1;
      for(int f=1,t=301*101;f<=t;)
	{
	  int mid=(f+t)>>1;
	  if(test(n,mid))
	    ans=ansl,t=ansl-1;
	  else
	    {
	      f=mid+1;
	      memset(vis,0,sizeof(vis));
	    }
	}
      if(cnt)
	printf("\n");
      if(ans>0)
	{
	  memset(vis,0,sizeof(vis));
	  pt(test(n,ans));
	}
      else printf("No solution.");
    }
  return 0;
}
