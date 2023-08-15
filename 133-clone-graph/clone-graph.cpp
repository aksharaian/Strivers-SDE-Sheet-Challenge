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

// By DFS
class Solution {
public:
    unordered_map<Node*, Node*> copies;   //orig map corresponding->copy node  eg: 1->1'
    Node* cloneGraph(Node* node) {
          if(node == NULL ) return NULL;
        
        if(copies.find(node) == copies.end()){
            Node* temp = new Node (node->val, {});    //created copy of original node and stored it in map
            copies[node] = temp;
            for(Node* neighbors : node->neighbors){
               temp->neighbors.push_back( cloneGraph (neighbors));   //orig node neighb are pushed in copied node
            }


        }
        return copies[node];
    }
};