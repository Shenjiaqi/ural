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
char mp['z'+1];
char s[107];
char dic[50007][57];
char bak[50007][57];
int len[50007];
int dp[107][3];
bool issub(char *t,int off)
{
  for(int i=0;t[i];++i,++off)
    if(s[off]!=t[i])
      return false;
  return true;
}
void pt(int l)
{
  assert(dp[l][0]==1);
  int pre=l-len[dp[l][1]];
  if(pre)
    {
      pt(pre);
      printf(" ");
    }
  printf("%s",bak[dp[l][1]]);
}
int main()
{
  mp['i']=mp['j']='1';
  mp['a']=mp['b']=mp['c']='2';
  mp['d']=mp['e']=mp['f']='3';
  mp['g']=mp['h']='4';
  mp['k']=mp['l']='5';
  mp['m']=mp['n']='6';
  mp['p']=mp['r']=mp['s']='7';
  mp['t']=mp['u']=mp['v']='8';
  mp['w']=mp['x']=mp['y']='9';
  mp['o']=mp['q']=mp['z']='0';
  for(int cnt=0;;++cnt)
    {
      scanf("%s",s);
      if(s[0]=='-')
	break;
      int k;
      scanf("%d",&k);
      FOR(i,0,k)
	{
	  scanf("%s",bak[i]);
	  int j;
	  for(j=0;bak[i][j];++j)
	    dic[i][j]=mp[bak[i][j]];
	  len[i]=j;
	}
      memset(dp,0,sizeof(dp));
      dp[0][0]=1;
      int l=strlen(s);
      for(int i=0;i<l;++i)
	{
	  if(dp[i][0])
	    {
	      for(int j=0;j<k;++j)
		{
		  int t=i+len[j];
		  if(t<=l && (dp[t][0]==0 ||
			      dp[t][2]>dp[i][2]+1))
		    {
		      if(issub(dic[j],i))
			{
			  dp[t][0]=1;
			  dp[t][1]=j;
			  dp[t][2]=1+dp[i][2]+1;
			}
		    }
		}
	    }
	}
      if(cnt)
	printf("\n");
      if(dp[l][0])
	pt(l);
      else printf("No solution.");
    }
  return 0;
}
