#include<stdio.h>
int x[100005],y[100005],ans[100005]={0};
int Abs(int k){
	return k>0? k:-k;
}int lonely(int p1,int p2){
	int X=Abs(x[p1]-x[p2]),Y=Abs(y[p1]-y[p2]);
	int timer=0,max=X>=Y?X:Y,min=X<Y?X:Y;
	if(max>=min*2){
		timer+=min*2;
		timer+=max-min*2;
	}else{
		timer+=(max-min)*2;
		min-=(max-min);
		max=min;
		timer+=max/3*4;
		if(max%3==1)timer+=2;
		else if(max%3==2)timer+=3;
	}
	return timer;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int tmp=lonely(i,j);
			ans[i]+=tmp;
			ans[j]+=tmp;
		}
	}for(int i=0;i<n;i++)printf("%d\n",ans[i]);
}
