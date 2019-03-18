#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	vector<pair<long,long> > neighbor;
}Node;
Node node[100005];
int main(){
	int n,m,p1,p2,w;
	scanf("%d%d",&n,&m);
	vector<long> dis(n+1,LONG_MAX);
	vector<int> test(n+1,0);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&p1,&p2,&w);
		node[p1].neighbor.push_back(make_pair(p2,w));
		node[p2].neighbor.push_back(make_pair(p1,w));
	}dis[1]=0;
	priority_queue <pair<long,long>, vector<pair<long,long> >,greater<pair<long,long> > >pq;
	pq.push(make_pair(dis[1],1));
	int visited=n;
	while(visited&&pq.empty()==false){
		pair<long,long>top=pq.top();
		if(test[top.second]!=0){
				pq.pop();
				continue;
		}test[top.second]=1;
		visited--;
		pq.pop();
		for(int i=0;i<node[top.second].neighbor.size();i++){
			if(test[node[top.second].neighbor[i].first]==0&&top.first!=LONG_MAX&&top.first+node[top.second].neighbor[i].second<dis[node[top.second].neighbor[i].first]){
				dis[node[top.second].neighbor[i].first]=top.first+node[top.second].neighbor[i].second;
				pq.push(make_pair(dis[node[top.second].neighbor[i].first],node[top.second].neighbor[i].first));
			}
		}
	}long max=-1,k=-1;
	for(int i=1;i<=n;i++){
		if(max<dis[i])max=dis[i];
	}printf("%ld\n",max==LONG_MAX? k:max);
}
