#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r;
	vector<pair<long,long> > v;
	long long yesterday=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&l,&r);
		long long left=l,right=r;
		for(int j=0;j<v.size();j++){
			if(v[j].first>right)break;
			else if(v[j].first<left&&v[j].second>=left){
				left=v[j].first;
				if(v[j].second>r)right=v[j].second;
				yesterday-=(v[j].second-v[j].first)*(v[j].second-v[j].first);
				v.erase(v.begin()+j);
				j--;
			}else if(v[j].first>=left&&v[j].second<=right){
				yesterday-=(v[j].second-v[j].first)*(v[j].second-v[j].first);
				v.erase(v.begin()+j);
				j--;
			}else if(v[j].first>=left&&v[j].first<=right&&v[j].second>right){
				right=v[j].second;
				yesterday-=(v[j].second-v[j].first)*(v[j].second-v[j].first);
				v.erase(v.begin()+j);
				j--;
			}
		}yesterday+=(right-left)*(right-left);
		printf("%lld\n",yesterday);
		v.push_back(make_pair(left,right));
		sort(v.begin(),v.end());
	}
}
