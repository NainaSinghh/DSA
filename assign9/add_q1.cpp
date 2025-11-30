#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V,0);
    int comps=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            comps++;
            stack<int> st;
            st.push(i);
            vis[i]=1;
            while(!st.empty()){
                int node=st.top();
                st.pop();
                for(int x:adj[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        st.push(x);
                    }
                }
            }
        }
    }
    cout<<comps;
    return 0;
}
