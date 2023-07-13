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
    ll dist = LOO;
    vector<pair<ll,Node*>>neighbors = {};
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
        for(ll i = 0 ; i < NodesNumber ; i++)
        {
            Nodes[i] = new Node;
        }
    }
    public :

    void addEdge(ll FirstNode , ll SecondNode , ll Cost)
    {
        Nodes[FirstNode-1]->neighbors.push_back({Cost,Nodes[SecondNode-1]});
        Nodes[SecondNode-1]->neighbors.push_back({Cost,Nodes[FirstNode-1]});
    }

    weightedGraph(ll _NodeNumber ,ll _EdgesNumber) : NodesNumber(_NodeNumber) ,EdgesNumber(_EdgesNumber) 
    {
        graphInit();
    }
};

class Buy_a_Ticket : public weightedGraph
{
    private :
    void DijkstraAlg()
    {
        priority_queue<pair<ll,Node*>,vector<pair<ll,Node*>>,greater<pair<ll,Node*>>>CheapestNodes;
        for(auto & _node : Nodes)
        {
            CheapestNodes.push({_node->dist , _node});    
        }
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
                    CheapestNodes.push({Neighbour.second->dist,Neighbour.second});
                }
            }

        }
    }
    public :
    friend void GetDijkstraResult(Buy_a_Ticket &Obj);

    void setDist(ll _dist, ll idx)
    {
        Nodes[idx]->dist = _dist;
    }
    Buy_a_Ticket(ll NodesNumber , ll EdgesNumber) : weightedGraph(NodesNumber , EdgesNumber) {}
};

void GetDijkstraResult(Buy_a_Ticket &Obj)
{
    Obj.DijkstraAlg();
    for(ll i = 0 ; i < Obj.NodesNumber ;i++)
    {
        cout << Obj.Nodes[i]->dist << ' ';
    }
}

int main()
{
    Code By Abou_Hawis
    ll n, m;
    cin >> n >> m;
    Buy_a_Ticket dijkstra(n,m);
    for(ll i = 0 ; i < m ; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dijkstra.addEdge(a,b,2 * c);
    }   
    ll cost;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> cost;
        dijkstra.setDist(cost,i);
    }
    GetDijkstraResult(dijkstra);
    return 0;
}