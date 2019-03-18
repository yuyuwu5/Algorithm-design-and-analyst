#include<stdio.h>
int main(){
	int t,n,k,tmp,now;
	scanf("%d",&t);
	for(unsigned int i=0;i<t;i++){
		scanf("%d%d",&n,&k);
		int S[200001]={0},Pos[200001]={0},record[200001]={0};
		for(unsigned int j=1;j<=n;j++){
			scanf("%d",&tmp);
			S[j]=tmp;
		}for(unsigned int j=1;j<=n;j++){
			scanf("%d",&tmp);
			Pos[tmp]=j;
		}now=0;
		for(unsigned int j=1;j<=n;j++){
			if(record[S[Pos[j]]]==0){
				printf("%d%c",S[Pos[j]],now==k-1?'\n':' ');
				now++;
				record[S[Pos[j]]]=1;
			}
		}for(unsigned int j=1;j<=k;j++){
			if(record[j]==0){
				printf("%d%c",j,now==k-1?'\n':' ');
				now++;
				record[j]=1;
			}
		}
	}
}
