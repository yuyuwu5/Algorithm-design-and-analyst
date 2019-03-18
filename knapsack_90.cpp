#include<bits/stdc++.h>
using namespace std;
int n,W;
long long v[1005],w[1005],V=0;
int main(){
	scanf("%d%d",&n,&W);
	vector<pair<float,int> >ratio;
	vector<pair<long long,int> >big;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&v[i],&w[i]);
		ratio.push_back(make_pair((float)v[i]/(float)w[i],i));
		big.push_back(make_pair(v[i],i));
		V+=v[i];
	}
	sort(ratio.begin(),ratio.end());
	sort(big.begin(),big.end());
	reverse(ratio.begin(),ratio.end());
	reverse(big.begin(),big.end());
	long long vmax,vr=0,vb=0,wr=0,wb=0;
	for(int i=0;i<ratio.size();i++){
		if(w[ratio[i].second]+wr<=W){
			wr+=w[ratio[i].second];
			vr+=v[ratio[i].second];
		}else break;
	}
	for(int i=0;i<big.size();i++){
		if(w[big[i].second]+wr<=W){
			wb+=w[big[i].second];
			vb+=v[big[i].second];
		}else break;
	}
	vmax=vr>=vb?vr:vb;
	vmax*=2;
	float scale=0.08*(float)vmax/(float)n;
	V=floor((float)vmax/scale);
	for(int i=0;i<n;i++)v[i]=floor((float)v[i]/scale);
	vector<vector<long long> >dp;
	for(int i=0;i<=n;i++){
		vector<long long>tmp(V+1,LLONG_MAX-INT_MAX);
		dp.push_back(tmp);
	}
	pair<int,long long> pos;
	pos.second=-1;
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=V;j>0;j--){
			if(j-v[i-1]>=0){
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1]);
				if(dp[i][j]==dp[i-1][j-v[i-1]]+w[i-1]&&dp[i][j]<=W){
					if(pos.second<j){
						pos.second=j;
						pos.first=i;
					}
				}
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int count=0,out[1005];
	while(pos.second>0){
		if(dp[pos.first][pos.second]!=dp[pos.first-1][pos.second]){
			out[count++]=pos.first;
			pos.second-=v[pos.first-1];
		}pos.first--;
	}
	printf("%d\n",count);
	for(int i=count-1;i>=0;i--)printf("%d%c",out[i]," \n"[i==0]);
}
