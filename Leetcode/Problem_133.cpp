#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        map<int, Node*> nodeCopies;
        return cloneGraphDFS(node, nodeCopies);
    }

    Node* cloneGraphDFS(Node* node, map<int, Node*>& nodeCopies) {
        int val = node->val;
        Node* copy = new Node(val);
        nodeCopies[val] = copy;

        for (auto neighbor : node->neighbors) {
            if (nodeCopies.find(neighbor->val) == nodeCopies.end()) {
                cloneGraphDFS(neighbor, nodeCopies);
            }
            copy->neighbors.push_back(nodeCopies[neighbor->val]);
        }
        return copy;
    }
};  
