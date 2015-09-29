class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) {
				return nullptr;
		}

		if (_hash.find(node) != _hash.end()) {
				return _hash[node];
		}

		UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
		_hash[node] = root;
		for (UndirectedGraphNode* neighbor : node->neighbors) {
				UndirectedGraphNode *copy = cloneGraph(neighbor);
				root->neighbors.push_back(copy);
		}

		//_hash[node] = root; Put it here will lead to infinite copy.
		return root;
	}

		UndirectedGraphNode* Clone_Graph::cloneGraphBFS(UndirectedGraphNode *node) {
			queue<UndirectedGraphNode*> nodeStk;
			UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
			_hash[node] = root;
			nodeStk.push(node);
			while (!nodeStk.empty()) {
				UndirectedGraphNode *front = nodeStk.front();
				nodeStk.pop();
				UndirectedGraphNode *copy = _hash[front];
				for (UndirectedGraphNode *neighbor : front->neighbors) {
					if (_hash.find(neighbor) == _hash.end()) {
						UndirectedGraphNode *tmp = new UndirectedGraphNode(neighbor->label);
						_hash[neighbor] = tmp;
						nodeStk.push(neighbor);
					}
					copy->neighbors.push_back(_hash[neighbor]);
				}
			}
			return root;
		} 		
};
