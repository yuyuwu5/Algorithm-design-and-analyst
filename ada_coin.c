#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int in[200000];
	long long max=-10001,now=-10001;
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		if(now+in[i]>=in[i])now+=in[i];
		else now=in[i];
		if(max<now)max=now;
	}printf("%lld\n",max);
}
