#include <bits/stdc++.h>
using namespace std;
stack<int> s;
long long int k;
void dfs(long long int a[],int n,vector<int> adj[],int dp[],int u)
{
    vector<int> :: iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(dp[(*it)]==-1 && a[*it]-a[u]>k)
        {
            k=a[*it]-a[u];
            s.push(*it);
            dfs(a,n,adj,dp,*it);
        }
    }
    int max=-1;bool flag=0;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(dp[*it]>max && a[*it]-a[u]>k)
        {
            max=dp[*it];flag=0;
        }
    }
    if(flag==0)
    dp[u]=1;
    else
    dp[u]=1+max;
    s.pop();
    if(s.size()>1)
    {
        int c,d;c=s.top();s.pop();
        d=s.top();s.pop();k=a[c]-a[d];
        s.push(d);s.push(c);
    }
    else
    k=0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;long long int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    vector<int> adj[n];
	    for(int i=0;i<m;i++)
	    {
	        int x,y;cin>>x>>y;
	        adj[x-1].push_back(y-1);
	        adj[y-1].push_back(x-1);
	    }
	    int dp[n];
	    for(int i=0;i<n;i++)dp[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1)
            {
                s.push(i);k=0;
                dfs(a,n,adj,dp,i);
            }
        }
        int max=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>max)
            max=dp[i];
        }
        cout<<max<<endl;
	}
	return 0;
}
