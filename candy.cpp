#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
struct Point{
	int degree,id,neighbor[25]={0};
};
int n,m,color[25]={0},Max=-1;
Point p[25];
void coloring(int now){
	if(Max>n/2)return;
	if(now==n+1){
		int one=0,two=0,three=0;
		for(int i=1;i<=n;i++){
			if(color[i]==1)one++;
			if(color[i]==2)two++;
			if(color[i]==3)three++;
		}
		if(one>0&&Max<one)Max=one;
		if(two>0&&Max<two)Max=two;
		if(three>0&&Max<three)Max=three;
		return;
	}
	int flag=0;
	for(int i=1;i<=3;i++){
		flag=0;
		for(int j=1;j<now;j++){
			if(p[now].neighbor[j]==1&&color[j]==i){
				flag=1;
				break;
			}
		}
		if(flag==1)continue;
		color[now]=i;
		coloring(now+1);
		if(now==1)break;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		p[i].id=i;
		p[i].degree=0;
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		p[a].neighbor[b]=1;
		p[b].neighbor[a]=1;
		p[a].degree++;
		p[b].degree++;
	}
	coloring(1);
	printf("%d\n",Max);
}
