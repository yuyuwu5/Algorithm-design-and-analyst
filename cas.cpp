#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src,des,w,p;
	int w_p;
};
int id[1025]={0};
int find_root(int in){
	while(id[in]!=in){
		id[in]=id[id[in]];
		in=id[in];
	}return in;
}
bool cmp(Edge a,Edge b){
	return a.w_p<b.w_p;
}
int main(){
	int n,tmp;
	scanf("%d",&n);
	int total=(n+1)*n/2,c=0;
	vector<Edge> e;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%d",&tmp);
			Edge t;
			t.src=i;
			t.des=j;
			t.p=tmp;
			e.push_back(t);
		}
	}
	for(int i=0;i<n;i++){
		id[i]=i;
		for(int j=i+1;j<=n;j++){
			scanf("%d",&tmp);
			e[c].w_p=tmp-e[c].p;
			e[c++].w=tmp;
		}
	}id[n]=n;
	sort(e.begin(),e.end(),cmp);
	int prize=0,distance=0;
	for(int i=0;i<total;i++){
		int a=e[i].src,b=e[i].des,A=find_root(a),B=find_root(b);
//		printf("%d %d\n",a,b);
		if(A!=B){
			prize+=e[i].p;
			distance+=e[i].w;
			id[A]=id[B];
		}
	}
	int k=__gcd(prize,distance);
	printf("%d %d\n",prize/k,distance/k);
}
