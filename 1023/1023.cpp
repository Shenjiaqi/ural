#include <cstdio>
int main()
{
  int k;
  scanf("%d",&k);
  for(int i=3;i*i<=k;++i)
    if((k%i)==0)
      {
	printf("%d",i-1);
	return 0;
      }
  if((k%2)==0 && (k>>1)-1>=2)
    printf("%d",(k>>1)-1);
  else
    printf("%d",k-1);
  return 0;
}
