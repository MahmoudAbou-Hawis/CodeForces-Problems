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


struct Node
{
    int id;
    vector<Node*>neighbors = {};
    bool visited = 0;
    int relations = 0;
    int leafs = 0;
    Node(int _id) : id(_id) {}
};

int n,m;
vector<Node*>graph;
int result = 0;

void bfs()
{
    set<Node*>q;
    set<Node*>temp;
    for(int i = 1; i <= n; i++)
    {
        if(graph[i]->relations == 1)
        {
            graph[i]->leafs++;
            q.insert(graph[i]);
        }
    }
    int sz = q.size();
    while(!q.empty())
    {
        Node * node = *q.rbegin();
        q.erase(node);
        sz--;
        node->visited = true;
        for(int i = 0 ; i < node->neighbors.size();i++)
        {
            node->neighbors[i]->relations--;           
            if(node->neighbors[i]->relations == 1 && !node->neighbors[i]->visited )
            {
                temp.insert(node->neighbors[i]);
            }
        }
        if(sz == 0)
        {
            result++;
            for(auto &i :temp)
            {
                if(i->relations == 1)
                {
                    q.insert(i);
                }
                
            }
            temp.clear();
            sz = q.size();
        }
    }
}

int main()
{
    Code By Abou_Hawis
    cin >> n >> m;
    graph = vector<Node*>(n+3);
    int i = 0;
    for(auto &node : graph)
    {
        node = new Node(i++);
    }
    int a,b;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        graph[a]->neighbors.push_back(graph[b]);
        graph[b]->neighbors.push_back(graph[a]);
        graph[a]->relations++;
        graph[b]->relations++;
    }

    bfs();
    cout << result;
    return 0;
}