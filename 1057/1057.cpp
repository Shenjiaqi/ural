#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
ll x,y,k,b;
ll dp[37][2][21];
ll que(ll v)
{
  int tmp[40],ti=0;
  for(;v;v/=b)
    tmp[ti++]=v%b;
  int kk=k;
  ll r=0;
  for(int i=ti-1;i>=0 && kk>=0;--i)
    if(tmp[i]==1)
      r+=dp[i][0][kk],--kk;
    else if(tmp[i]>1)
      {
	r+=dp[i][1][kk];
	break;
      }
  return r;
}
int main()
{
  cin>>x>>y>>k>>b;
  dp[0][0][0]=dp[0][1][0]=1;
  dp[0][1][1]=1;
  for(int i=1;i<37;++i)
    {
      dp[i][0][0]=dp[i][1][0]=1;
      for(int j=1;j<=k;++j)
	{
	  dp[i][0][j]=dp[i-1][1][j];
	  dp[i][1][j]=dp[i][0][j]+dp[i-1][1][j-1];
	}
    }
  cout<<que(y+1)-que(x)<<endl;
  return 0;
}
