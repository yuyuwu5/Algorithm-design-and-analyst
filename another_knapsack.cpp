#include<bits/stdc++.h>
using namespace std;
long long v[45],w[45],Max=-1;
int n,W,c[2]={0},type=0,limit;
struct Node{
	long long weight,value;
};
Node combination[2][2100000];
void rec(long long weight,long long value,int index){
	if(index==limit||weight+w[index]>W){
			combination[type][c[type]].value=value;
			combination[type][c[type]].weight=weight;
			c[type]++;
		return;
	}
	for(int i=index+1;i<=limit;i++){
		rec(weight+w[index],value+v[index],i);
	}
}
bool cmp(Node a,Node b){
	return b.value<a.value;
}
int main(){
	scanf("%d%d",&n,&W);
	for(int i=0;i<n;i++)scanf("%lld%lld",&v[i],&w[i]);
	limit=n/2;
	for(int i=0;i<n/2;i++)rec(0,0,i);
	type=1;
	limit=n;
	for(int i=n/2;i<n;i++)rec(0,0,i);
	int all_possible=1<<(n/2);
	long long vmax=-1;
	combination[0][c[0]].weight=0;
	combination[0][c[0]].value=0;
	combination[0][c[1]].weight=0;
	combination[0][c[1]].value=0;
	sort(combination[0],combination[0]+c[0],cmp);
	sort(combination[1],combination[1]+c[1],cmp);
	for(int i=0;i<=c[0];i++){
		for(int j=0;j<=c[1];j++){
			if(combination[0][i].weight+combination[1][j].weight<=W){
				if(vmax<combination[0][i].value+combination[1][j].value){
					vmax=combination[0][i].value+combination[1][j].value;
				}
				break;
			}
		}
	}
	printf("%lld\n",vmax);
}
