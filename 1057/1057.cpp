#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll x,y,k,b;
int ans;
void dfs(ll v,int cnt,ll val,int left)
{
  if(cnt==0)
    {
      if(v>=x)
	++ans;
    }
  else if((ll)v+(ll)val<=y && left>=cnt && v+c[left][cnt]>=x)
    {
      dfs(v+val,cnt-1,val*b,left-1);
      dfs(v,cnt,val*b,left-1);
    }
}
int main()
{
  cin>>x>>y>>k>>b;
  int m=0;
  for(ll v=1;v<=y;++m)
    v*=b;
  for(int i=0;i<m;++i)
    for(int j=0;j<
  dfs(0,k,1,m);
  printf("%d",ans);
  return 0;
}
