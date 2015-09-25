/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */

//BFS
//Use Queue
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node==null) return null;
        Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>();
        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        queue.add(node);
        UndirectedGraphNode copyHead = new UndirectedGraphNode(node.label);
        map.put(node, copyHead);
        while(!queue.isEmpty()) {
            UndirectedGraphNode curr = queue.remove();
            List<UndirectedGraphNode> neighbors = curr.neighbors;
            for(UndirectedGraphNode neighbor : neighbors) {
                if(!map.containsKey(neighbor)) {
                    UndirectedGraphNode copyNeighbor = new UndirectedGraphNode(neighbor.label);
                    map.put(neighbor, copyNeighbor);
                    map.get(curr).neighbors.add(copyNeighbor);
                    queue.add(neighbor);
                } else {
                    map.get(curr).neighbors.add(map.get(neighbor));
                }
            }
            
        }
        return copyHead;
    }
    
}


//DFS
//Use Stack
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node==null) return null;
        Stack<UndirectedGraphNode> stack = new Stack<UndirectedGraphNode>();
        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        stack.push(node);
        UndirectedGraphNode copyHead = new UndirectedGraphNode(node.label);
        map.put(node, copyHead);
        while(!stack.isEmpty()) {
            UndirectedGraphNode curr = stack.pop();
            List<UndirectedGraphNode> neighbors = curr.neighbors;
            for(UndirectedGraphNode neighbor : neighbors) {
                if(!map.containsKey(neighbor)) {
                    UndirectedGraphNode copyNeighbor = new UndirectedGraphNode(neighbor.label);
                    map.put(neighbor, copyNeighbor);
                    map.get(curr).neighbors.add(copyNeighbor);
                    stack.push(neighbor);
                } else {
                    map.get(curr).neighbors.add(map.get(neighbor));
                }
            }
            
        }
        return copyHead;
    }
}