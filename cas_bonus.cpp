#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
struct Edge{
	int src,des,w,p;
};
int id[1025]={0},out=0;
int find_root(int in){
	while(id[in]!=in){
		id[in]=id[id[in]];
		in=id[in];
	}return in;
}
double factor;
bool cmp(Edge a,Edge b){
	return a.p-factor*a.w>b.p-factor*b.w;
}
vector<Edge> e;
int n,total;
double kruskal(){
	for(int i=0;i<=n;i++)id[i]=i;
	sort(e.begin(),e.end(),cmp);
	int prize=0,distance=0;
	double res=0;
	for(int i=0;i<total;i++){
		int a=e[i].src,b=e[i].des,A=find_root(a),B=find_root(b);
		if(A!=B){
			prize+=e[i].p;
			distance+=e[i].w;
			res+=(double)e[i].p-factor*(double)e[i].w;
			id[A]=id[B];
		}
	}
	if(out){
		int k=__gcd(prize,distance);
		printf("%d %d\n",prize/k,distance/k);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	total=(n+1)*n/2;
	int c=0,type=0,tmp;
	double upper=0,lower=1000,t,mid;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%d",&tmp);
			Edge t;
			t.src=i;
			t.des=j;
			t.p=tmp;
			if(t.p!=1)type=1;
			e.push_back(t);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%d",&tmp);
			t=tmp/e[c].p;
			if(t<lower)lower=t;
			if(t>upper)upper=t;
			e[c++].w=tmp;
		}
	}
	if(type==0){
		factor=1;
		out=1;
		kruskal();
		return 0;
	}
	for(int i=0;i<13;i++){
		factor=(upper+lower)/2;
		t=kruskal();
		if(t>=0){
			lower=factor;
		}else{
			upper=factor;
		}
	}
	out=1;
	factor=lower;
	kruskal();	
}

