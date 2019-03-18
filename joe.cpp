#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void karatsuba_multiply(long long *res,const long long *p,const long long *q, int size){
	long long t0[size], t1[size], r[size<<1]={0};
	if(size<=4){
		for(int i=0;i<size;i++)for(int j=0;j<size;j++)r[i+j]+=p[i]*q[j];
	}else{
		int nSize=(size>>1);
		for(int i=0;i<nSize;i++){
			t0[i]=p[i]+p[nSize+i];
			t1[i]=q[i]+q[nSize+i];
			t0[i+nSize]=t1[i+nSize]=0;
		}
		karatsuba_multiply(r+nSize,t0,t1,nSize);
		karatsuba_multiply(t0,p,q,nSize);
		karatsuba_multiply(t1,p+nSize,q+nSize,nSize);
		for(int i=0;i<size;i++){
			r[i]+=t0[i];
			r[i+nSize]-=t0[i]+t1[i];
			r[i+size]+=t1[i];
		}
	}memcpy(res, r, (size<<1) * sizeof(long long));
}long long in[1<<17]={0},out[1<<18]={0},t;
int main(){
	unsigned int n,tmp,q,magic;
	scanf("%u",&n);
	for(unsigned int i=0;i<n;i++){
		scanf("%u",&tmp);
		in[tmp]++;
	}
	karatsuba_multiply(out,in,in,(1<<17));
	for(int i=0;i<200001;i++){
		if(i<=100000)out[(i<<1)]-=in[i];
		out[i]=(out[i]>>1);
	}
	scanf("%u",&q);
	for(int i=0;i<q;i++){
		scanf("%u",&magic);
		t=magic<=200000?out[magic]:0;
		printf("%lld%c",t," \n"[i==q-1]);
	}
}
