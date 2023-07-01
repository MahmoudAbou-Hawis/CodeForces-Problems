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
#define NO_TREES   0
#define ONE_NODE             1
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    bool visited = 0;
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
    void AddNode(int FirstNode,int SecondNode)
    {
        _Nodes[FirstNode-1]->neighbors.push_back(_Nodes[SecondNode-1]);
        _Nodes[SecondNode-1]->neighbors.push_back(_Nodes[FirstNode-1]);
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

class PolandBall_and_Forest : public graph
{
    private:
    int NumberOfTrees = NO_TREES;
    void SolvePolandBall_and_Forest(Node * Node)
    {
        Node->visited = true;
        for(auto &neighbour : Node->neighbors)
        {
            if(!neighbour->visited)
            {
                SolvePolandBall_and_Forest(neighbour); 
            }
          
        }
        return ;
    }
    public:
    int GetResult()
    {
        for(int i = 0 ; i < nodeNumber ; i++)
        {
            if(!_Nodes[i]->visited)
            {
                NumberOfTrees++;
                SolvePolandBall_and_Forest(_Nodes[i]);
            }
        }
        return NumberOfTrees;
    }
    PolandBall_and_Forest(int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n , p;
    cin >> n;
    PolandBall_and_Forest polandBall_and_forest(n);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p;
        polandBall_and_forest.AddNode(i,p);
    }    
    cout << polandBall_and_forest.GetResult();
    return 0;
}