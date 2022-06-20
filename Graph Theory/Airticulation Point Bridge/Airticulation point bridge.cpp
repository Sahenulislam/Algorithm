#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxn=1e4+10;
vector<ll>g[mxn+10];
set<pair<ll,ll>>bridge;
ll Time=0,Start[mxn+10],End[mxn+10],low[mxn+10],vi[mxn+10];
void dfs(ll u,ll pa=-1)
{
    vi[u]=1;
    Start[u]=++Time;
    low[u]=Start[u];
    for(auto v:g[u])
    {
        if(vi[v]==0)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=pa)
        {
            low[u]=min(low[u],Start[v]);
        }
    }
    //cout<<u<<" "<<pa<<" "<<low[u]<<" "<<Start[u]<<endl;
    if(pa!=-1&&low[u]>=Start[u])
    {
        if(pa<u)
        {
            bridge.insert({pa,u});
        }
        else
        {
            bridge.insert({u,pa});
        }
    }

    End[u]=Time;
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll u,v;
            cin>>u;
            char s;
            cin>>s;
            ll x;
            cin>>x;
            char k;
            cin>>k;
            for(ll j=0; j<x; j++)
            {
                cin>>v;
                //cout<<u<<" "<<v<<endl;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(ll i=0; i<n; i++)
        {
            if(!vi[i])
            {
                Time=0;
                dfs(i);
            }
        }
        cout<<"Case "<<tt++<<": "<<endl;
        cout<<bridge.size()<<" critical links"<<endl;
        for(auto i:bridge)
        {
            cout<<i.first<<" - "<<i.second<<endl;
        }
        for(ll i=0; i<=n+5; i++)
        {
            g[i].clear();
            vi[i]=0;
            low[i]=0;
            End[i]=0;
            Start[i]=0;
        }
        bridge.clear();
        Time=0;
    }
}
