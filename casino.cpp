#include<bits/stdc++.h>
using namespace std;
int a[1<<10][1<<10],t;
struct Node{
	int src,des;
	int w; //weight
};
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	int n,c=0,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	vector<Node>first;
	vector<Node>end;
	vector<Node>other;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			scanf("%d",&t);
			if(i==0){
				Node tmp;
				tmp.src=0;
				tmp.des=j;
				tmp.w=t;
				first.push_back(tmp);
			}else if(j==n-1){
				Node tmp;
				tmp.src=i;
				tmp.des=j;
				tmp.w=t;
				end.push_back(tmp);
			}else{
				Node tmp;
				tmp.src=i;
				tmp.des=j;
				tmp.w=t;
				other.push_back(tmp);	
			}
		}
	}
	int des=0,visit[1025]={0},total=n;
	int min=10000000,id;
	for(int i=0;i<first.size();i++){
		if(first[i].w<min){
			min=first[i].w;
			id=i;
		}
	}
	visit[first[id].des]=1;
	first.erase(first.begin()+id);
	if(id!=n-1){
		Node k;
		k.src=0;
		k.des=n-1;
		k.w=first[first.size()-1].w;
		first.pop_back();
		end.push_back(k);
	}
	total--;
	des+=min;
	if(visit[n]==0){
		min=10000000;
		for(int i=0;i<end.size();i++){
			if(end[i].w<min){
				min=end[i].w;
				id=i;
			}
		}visit[n]=1;
		end.erase(end.begin()+id);
		total--;
		des+=min;
	}
	/*puts("first");
	for(int i=0;i<first.size();i++)printf("%d %d\n",first[i].src,first[i].des);
	puts("end");
	for(int i=0;i<end.size();i++)printf("%d %d\n",end[i].src,end[i].des);
	puts("other");
	for(int i=0;i<other.size();i++)printf("%d %d\n",other[i].src,other[i].des);
*/
	vector<Node> v;
	v.assign(first.begin(),first.end());
	v.insert(v.end(),end.begin(),end.end());
	v.insert(v.end(),other.begin(),other.end());
	sort(v.begin(),v.end(),cmp);
	//for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].src,v[i].des);
	//printf("%d\n",des);
	int now=0,count=2;
	while(total>0){
//		printf("%d %d\n",v[now].src,v[now].des);
		if(visit[v[now].des]==0){
			visit[v[now].des]=1;
			total--;
			des+=v[now].w;
			v.erase(v.begin()+now);
			count++;
		}else now++;
	}
	while(v.size()>0){
		float a=(float)(count+1)/(float)(v[0].w+des),b=(float)count/(float)des;
		if(a>b){
			count++;
			des+=v[0].w;
			v.erase(v.begin());
		}else break;
	}
	int tmp=__gcd(count,des);
	printf("%d %d\n",count/tmp,des/tmp);
	/*vector<Node> v;
	v.assign(node,node+n);*/
}
