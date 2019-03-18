#include<stdio.h>
#include<string.h>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
unsigned int dp[1001][2][3][12][3][3][3]={0},l; //index,smaller,mod3,even,odd,numbers of 3,6,9
unsigned char digit[1002];
int Abs(int k){
	return k>=0?k:11+k;
}
unsigned int fill_table(unsigned int index,unsigned int smaller,unsigned int sum,int even,int odd,int three,int six,int nine){
	if(!(index-l)){
		if(!sum&&even==odd&&!six&&!three&&!nine)return 1;
		return 0;
	}if(dp[index][smaller][sum][Abs(even-odd)][three][six][nine]!=-1){
		return dp[index][smaller][sum][Abs(even-odd)][three][six][nine];
	}unsigned int limit=9,i,smaller_or_not;
	if(smaller)limit=digit[index]-48;
	unsigned long count=0;
	for(i=0;i<=limit;i++){
		smaller_or_not=0;
		if(smaller&&(i==digit[index]-48))smaller_or_not=1;
		if(i==3){
			if(index&1){
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,(even+i)%11,odd,(three+1)%3,six,nine);
			}else{
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,even,(odd+i)%11,(three+1)%3,six,nine);
			}
		}else if(i==6){
			if(index&1){
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,(even+i)%11,odd,three,(six+1)%3,nine);
			}else{
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,even,(odd+i)%11,three,(six+1)%3,nine);
			}
		}else if(i==9){
			if(index&1){
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,(even+i)%11,odd,three,six,(nine+1)%3);
			}else{
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,even,(odd+i)%11,three,six,(nine+1)%3);
			}
		}else{
			if(index&1){
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,(even+i)%11,odd,three,six,nine);
			}else{
				count+=fill_table(index+1,smaller_or_not,(sum+i)%3,even,(odd+i)%11,three,six,nine);
			}
		}
	}count%=1000000007;
	dp[index][smaller][sum][Abs(even-odd)][three][six][nine]=count;
	return count;
}
int main(){
	char left[1002],right[1002];
	scanf("%s%s",left,right);
	memset(dp,-1,sizeof(dp));
	memcpy(digit,right,sizeof(right));
	l=strlen(right);
	int tmp=fill_table(0,1,0,0,0,0,0,0),tmp2;
	memset(dp,-1,sizeof(dp));
	memcpy(digit,left,sizeof(left));
	l=strlen(left);
	tmp2=fill_table(0,1,0,0,0,0,0,0);
	printf("%d\n",tmp-tmp2>=0? tmp-tmp2:tmp-tmp2+1000000007);
}
