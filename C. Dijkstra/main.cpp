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
    Node * par = NULL;
    ll dist = LOO;
    vector<pair<ll,Node*>>neighbors = {};
    Node(int _id) : id(_id){}
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

class Dijkstra : public weightedGraph
{
    private :
    void DijkstraAlg(Node * Src)
    {
        priority_queue<pair<ll,Node*>,vector<pair<ll,Node*>>,greater<pair<ll,Node*>>>CheapestNodes;
        Src->dist = 0;
        CheapestNodes.push({Src->dist,Src});
        while(!CheapestNodes.empty())
        {
            auto CurrNode = CheapestNodes.top();
            CheapestNodes.pop();
            if(CurrNode.second->id == NodesNumber)
            {
                break;
            }
            if(CurrNode.first != CurrNode.second->dist)
            {
                continue;
            }
            for(auto &Neighbour : CurrNode.second->neighbors)
            {
                if(Neighbour.second->dist > CurrNode.first + Neighbour.first)
                {
                    Neighbour.second->dist = CurrNode.first + Neighbour.first;
                    Neighbour.second->par  = CurrNode.second;
                    CheapestNodes.push({Neighbour.second->dist,Neighbour.second});
                }
            }

        }
    }
    public :
    friend void GetDijkstraResult(Dijkstra &Obj);
    Dijkstra(int NodesNumber , int EdgesNumber) : weightedGraph(NodesNumber , EdgesNumber) {}
};

void GetDijkstraResult(Dijkstra &Obj)
{
    Obj.DijkstraAlg(Obj.Nodes[0]);
    vector<int>CheapestPath;
    Node * SrcNode = Obj.Nodes[Obj.NodesNumber-1];
    while(SrcNode->par != NULL)
    {
        CheapestPath.push_back(SrcNode->id);
        SrcNode = SrcNode->par;
    }
    if(SrcNode->id == Obj.NodesNumber)
    {
        cout << -1;
        return;
    }
    CheapestPath.push_back(1);
    for(int i = CheapestPath.size() -1 ; i >= 0 ;i--)
    {
        cout << CheapestPath[i] << ' ';
    }
    return;
}

int main()
{
    Code By Abou_Hawis
    int n, m;
    cin >> n >> m;
    Dijkstra dijkstra(n,m);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dijkstra.addEdge(a,b,c);
    }   
    GetDijkstraResult(dijkstra);
    return 0;
}