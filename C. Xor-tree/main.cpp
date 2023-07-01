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
    bool init = 0;
    bool goal = 0;
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

class  Xor_tree : public graph
{
    private:
    int NumberOfChanges = 0;
    int level = 0;
    int Changes = 0;
    vector<int>ChangedNode;
    void SolvePolandBall_and_Forest(Node * Node, int even = 0,int odd = 0)
    {
        Node->visited = true;
        level++;
        Changes = (((level&1)?odd:even)&1)?1:0;
        if(Changes)Node->init = !(Node->init);
        if(Node->init != Node->goal)
        {
            NumberOfChanges++;
            ChangedNode.push_back(Node->id);
            (level&1) ? odd++:even++;
        }
        for(auto &neighbour : Node->neighbors)
        {
            if(!neighbour->visited)
            {
                SolvePolandBall_and_Forest(neighbour,even,odd);
                level--;
            }
        }
    }
    public:
    void PrintResult()
    {
        SolvePolandBall_and_Forest(_Nodes[0]);
        cout << NumberOfChanges <<'\n';
        for(int i = 0 ; i < NumberOfChanges ;i ++)
        {
            cout << ChangedNode[i] << '\n';
        }
    }
    void SetInitValue(bool Value,int pos)
    {
        _Nodes[pos]->init = Value;
    }
    void SetGoalValue(bool Value, int pos)
    {
        _Nodes[pos]->goal = Value;
    }
    Xor_tree(int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n ,u ,v ,value;
    cin >> n;
    Xor_tree xor_tree(n);

    for(int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        xor_tree.AddNode(u,v);
    }

    for(int i = 0 ; i < n ; i++)
    {
        cin >> value;
        xor_tree.SetInitValue(value,i);
    }

    for(int i = 0 ; i < n ; i++)
    {
        cin >> value;
        xor_tree.SetGoalValue(value,i);
    }
    xor_tree.PrintResult();
    return 0;
}