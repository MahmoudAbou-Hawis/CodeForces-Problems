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
struct Node
{
    int id = 0 ;
    vector<pair<Node*,int>>neighbors ={};
    bool visited = 0;
    int level = 0;
    Node(int _id) : id(_id) {}
};

class graph
{
    protected:
    vector<Node*>_Nodes;
    int nodeNumber;
    private:
    int NodeId = 1;
    void GraphInit()
    {
        _Nodes = vector<Node*>(nodeNumber);
        for(auto &node : _Nodes)
        {
            node = new Node(NodeId++);
        }
    }
    public:
    void AddNode(int FirstNode,int SecondNode, int state)
    {
        _Nodes[FirstNode-1]->neighbors.push_back({_Nodes[SecondNode-1],state});
        _Nodes[SecondNode-1]->neighbors.push_back({_Nodes[FirstNode-1],state});
        _Nodes[FirstNode-1]->level++;
        _Nodes[SecondNode-1]->level++;
    }
    void GraphClear()
    {
        for(auto &node :_Nodes)
        {
            node->neighbors.clear();
        }
    }

    graph(int _nodesNumber ) : nodeNumber(_nodesNumber) 
    {
        GraphInit();
    }
};

class  Valera_and_Elections  : public graph
{
    private:
    vector<int> Nodes ;
    void SolveValera_and_Elections(Node * _Node)
    {        
        queue<Node*>q;
        q.push(_Node);
        while (!q.empty())
        {
            Node * __node = q.front();
            q.pop();
            __node->level--;
            for(auto &neighbour :__node->neighbors)
            {
                if(neighbour.second == 2)
                {
                    Nodes.push_back(__node->id);
                }
                else
                {
                    neighbour.first->level--;
                    if(neighbour.first->level == 1 && neighbour.first->id != 1)
                    {
                        q.push(neighbour.first);
                    }
                }
            }
        }
        
        
    }
    public:
    void PrintResult()
    {
        for(int i = 1 ; i < nodeNumber ; i++)
        {
            if(_Nodes[i]->level == 1)
            {
                SolveValera_and_Elections(_Nodes[i]);
            }
        }
        cout << Nodes.size() << '\n';
        for(auto &i : Nodes)
        {
            cout<<i << " ";
        }
    }

    
    Valera_and_Elections (int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n, u, v, w;
    cin>>n;
    Valera_and_Elections valera_and_Elections(n);
    for(int i = 0 ; i < n-1 ; i++)
    {
        cin >> u >> v >> w;
        valera_and_Elections.AddNode(u,v,w);
    }
    valera_and_Elections.PrintResult();

    return 0;
}