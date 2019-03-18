#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct{
	int x,y,multi;
}Point;
typedef struct{
	long long x_sum,y_sum,total;
}Information;
Point p[100005];
long long sum=0;
Information *merge(int start,int middle,int end,Information *l,Information *r){
	Point tmp[end-start+1];
	long long now=0,left=middle-start+1,right=end-middle,
		  left_x=l->x_sum,left_y=l->y_sum,left_all=l->total,
		  right_x=r->x_sum,right_y=r->y_sum,right_all=r->total;
	//printf("%lld %lld %lld %lld %lld %lld\n",left_x,left_y,left_all,right_x,right_y,right_all);
//	printf("%d %d %d\n",start,middle,end);
	while(left&&right){
		if(p[middle-left+1].y<=p[end-right+1].y){
			sum+=right*p[middle-left+1].multi+right_all-p[middle-left+1].x*right_y-p[middle-left+1].y*right_x;
			left_x-=p[middle-left+1].x;
			left_y-=p[middle-left+1].y;
			left_all-=p[middle-left+1].multi;
			tmp[now].x=p[middle-left+1].x;
			tmp[now].y=p[middle-left+1].y;
			tmp[now++].multi=p[middle-left+1].multi;
			left--;
		}else{
			sum+=-left*p[end-right+1].multi-left_all+p[end-right+1].x*left_y+p[end-right+1].y*left_x;
			right_x-=p[end-right+1].x;
			right_y-=p[end-right+1].y;
			right_all-=p[end-right+1].multi;
			tmp[now].x=p[end-right+1].x;
			tmp[now].y=p[end-right+1].y;
			tmp[now++].multi=p[end-right+1].multi;
			right--;
		}
	}
	while(left){
		tmp[now].x=p[middle-left+1].x;
		tmp[now].y=p[middle-left+1].y;
		tmp[now++].multi=p[middle-left+1].multi;
		left--;
	}
	while(right){
		tmp[now].x=p[end-right+1].x;
		tmp[now].y=p[end-right+1].y;
		tmp[now++].multi=p[end-right+1].multi;
		right--;
	}
	l->x_sum+=r->x_sum;
	l->y_sum+=r->y_sum;
	l->total+=r->total;
	memcpy(&p[start],tmp,sizeof(Point)*(end-start+1));
	return l;
}
Information *devide(int start,int end){
	if(start==end){
		Information *t=(Information*)malloc(sizeof(Information));
		t->x_sum=p[start].x;
		t->y_sum=p[start].y;
		t->total=p[start].multi;
		return t;
	}
	int q=(start+end-1)/2;
	Information *a=devide(start,q);
	Information *b=devide(q+1,end);
	return merge(start,q,end,a,b);
}
int cmp(const void *p1,const void *p2){
	Point *s1=(Point*)p1,*s2=(Point*)p2;
	if(s1->x<s2->x)return -1;
	if(s1->x>s2->x)return 1;
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].multi=p[i].x*p[i].y;
	}qsort(p,n,sizeof(Point),cmp);
	devide(0,n-1);
	printf("%lld\n",sum);
}
