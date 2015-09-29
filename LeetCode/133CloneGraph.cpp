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

		}	 		
};
