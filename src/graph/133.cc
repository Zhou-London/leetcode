/* Clone graph. */
// * Medium

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
  public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
  public:
    unordered_map<Node *, Node *> visited_;

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        if (visited_.find(node) != visited_.end())
            return visited_[node];

        Node *clone = new Node(node->val);
        visited_[node] = clone;

        for (auto neighbor : node->neighbors)
            clone->neighbors.push_back(cloneGraph(neighbor));

        return clone;
    }

    Node *cloneGraphBfs(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> visited;
        queue<Node *> q;

        visited[node] = new Node(node->val);
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (auto neighbor : curr->neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
