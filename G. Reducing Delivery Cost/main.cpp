#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 9 ;

struct Node
{
    int id = 0;
    ll dist = LOO;
    vector<pair<ll,Node*>>neighbors = {};
    Node(int _id) : id(_id){}
};

struct Edge
{
    int from = 0;
    int to   = 0;
};

class weightedGraph
{
    protected :
    vector<Node*>Nodes;
    int NodesNumber;
    int EdgesNumber;
    private :
    void graphInit()
    {
        Nodes = vector<Node*>(NodesNumber);
        for(int i = 0 ; i < NodesNumber ; i++)
        {
            Nodes[i] = new Node(i+1);
        }
    }
    public :

    void addEdge(int FirstNode , int SecondNode , int Cost)
    {
        Nodes[FirstNode-1]->neighbors.push_back({Cost,Nodes[SecondNode-1]});
        Nodes[SecondNode-1]->neighbors.push_back({Cost,Nodes[FirstNode-1]});
    }

    weightedGraph(int _NodeNumber ,int _EdgesNumber) : NodesNumber(_NodeNumber) ,EdgesNumber(_EdgesNumber) 
    {
        graphInit();
    }
};

class Reducing_Delivery_Cost : public weightedGraph
{
    private :
    vector<vector<int>>Costs;
    void DijkstraAlg(Node * Src)
    {
        priority_queue<pair<ll,Node*>,vector<pair<ll,Node*>>,greater<pair<ll,Node*>>>CheapestNodes;
        Src->dist = 0;
        CheapestNodes.push({Src->dist,Src});
        while(!CheapestNodes.empty())
        {
            auto CurrNode = CheapestNodes.top();
            CheapestNodes.pop();
            if(CurrNode.first != CurrNode.second->dist)
            {
                continue;
            }
            for(auto &Neighbour : CurrNode.second->neighbors)
            {
                if(Neighbour.second->dist > CurrNode.first + Neighbour.first)
                {

                    Neighbour.second->dist = CurrNode.first + Neighbour.first;
                    Costs[Src->id][Neighbour.second->id] = Neighbour.second->dist;
                    CheapestNodes.push({Neighbour.second->dist,Neighbour.second});
                }
            }

        }
    }
    public :
    void AllDijkstra()
    {
        for(int i = 0 ; i < NodesNumber ; i++)
        {
            for(int e = 0 ; e < NodesNumber ; e++)
            {
                Nodes[e]->dist = LOO;
            }
            DijkstraAlg(Nodes[i]);
        }
    }
    int getValue(int i , int e)
    {
        return Costs[i][e];
    }
    Reducing_Delivery_Cost(int NodesNumber , int EdgesNumber) : weightedGraph(NodesNumber , EdgesNumber) 
    {
        Costs = vector<vector<int>>(NodesNumber+10 , vector<int>(NodesNumber+10,0));
    }
};



int main()
{
    Code By Abou_Hawis
    int n, m, k;
    cin >> n >> m >>k;
    Reducing_Delivery_Cost dijkstra(n,m);
    vector<Edge>Edges(m);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dijkstra.addEdge(a,b,c);
        Edges[i].from = a;
        Edges[i].to   = b;
    }
    dijkstra.AllDijkstra();
    vector<pi>paths;
    for(int i = 0 ; i < k ; i++)
    {
        int a, b;
        cin >> a >> b;
        paths.pb({a,b});
    }
    ll result = INT64_MAX;
    for(int i = 0 ;i  < m ; i++)
    {
        auto _Edge = Edges[i];
        ll sum = 0;
        for(int j = 0 ; j < k ; j++)
        {
            sum += min({dijkstra.getValue(paths[j].f , paths[j].s)
                       ,dijkstra.getValue(paths[j].f , _Edge.from) + dijkstra.getValue(_Edge.to ,paths[j].s ) 
                       ,dijkstra.getValue(paths[j].f , _Edge.to)   + dijkstra.getValue(_Edge.from ,paths[j].s)});
        }
        result = min(result , sum);
    }
    cout << result << '\n';
    return 0;
}