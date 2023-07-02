#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define NO_TREES             0
#define ONE_NODE             1
map<pair<int,int>,int>allowed;
int dx[] = {1,-1,0,1,0,-1,1,-1};
int dy[] = {1,-1,1,0,-1,0,-1,1};
void bfs(int s1,int s2,int s3 ,int s4)
{
    queue<pair<int,int>>q;
    q.push({s1,s2});
    while(!q.empty())
    {
        pi current = q.front();
        if(current.f == s3 && current.second == s4) break;
        q.pop();
        for(int i = 0 ; i < 8 ; i++)
        {
            if(allowed.find({current.first + dx[i] , current.second +dy[i]}) != allowed.end() && allowed[{current.first + dx[i] , current.second +dy[i]}] == -1)
            {
                allowed[{current.first + dx[i] , current.second +dy[i]}] = allowed[{current.first , current.second }]+1 ;
                q.push({current.first + dx[i] , current.second +dy[i]});
            }
        }
    }

}
int main()
{
    Code By Abou_Hawis
    int s1, s2, e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    allowed[{s1,s2}] = 0;
    allowed[{e1,e2}] = -1; 
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int u,st,e;
        cin >> u >> st >> e;
        for(int w = st ; w <= e ; w++)
        {
            allowed.insert({{u,w},-1});
        }
    }
    bfs(s1,s2,e1,e2);
    cout << allowed[{e1,e2}];
    return 0;
}