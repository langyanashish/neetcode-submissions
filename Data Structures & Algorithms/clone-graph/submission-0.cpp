/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, auto& mp)
    {
        if(!node)
            return NULL;
        if(mp.count(node))
            return mp[node];
        Node * newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto ni : node->neighbors)
            newNode->neighbors.push_back(dfs(ni, mp));
        return newNode; 
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};
