#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times,int N,int K){
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=0;i<times.size();i++){
        int u=times[i][0],v=times[i][1],w=times[i][2];
        g[u].push_back({v,w});
    }

    vector<int> dist(N+1,1e9);
    dist[K]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,K});

    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(d>dist[node]) continue;
        for(int i=0;i<g[node].size();i++){
            int v=g[node][i].first;
            int w=g[node][i].second;
            if(dist[node]+w<dist[v]){
                dist[v]=dist[node]+w;
                pq.push({dist[v],v});
            }
        }
    }

    int ans=0;
    for(int i=1;i<=N;i++) ans=max(ans,dist[i]);
    return ans>=1e9 ? -1 : ans;
}

int main(){
    vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
    cout<<networkDelayTime(times,4,2);
}
