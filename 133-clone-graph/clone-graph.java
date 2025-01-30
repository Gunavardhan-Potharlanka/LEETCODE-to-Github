/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        HashMap<Integer, Node> visited = new HashMap<>();
        Node clone = new Node(node.val);
        Queue<Node> q1 = new LinkedList<>(), q2 = new LinkedList<>();
        q1.add(node);
        q2.add(clone);
        visited.put(clone.val, clone);
        while(q1.isEmpty() == false && q2.isEmpty() == false) {
            Node cur = q1.remove();
            Node curclone = q2.remove();
            for(Node n : cur.neighbors) {
                Node insertingNode;
                if(visited.get(n.val) == null) {
                    insertingNode = new Node(n.val);
                    q1.add(n);
                    q2.add(insertingNode);
                    visited.put(n.val, insertingNode);
                } else insertingNode = visited.get(n.val);
                curclone.neighbors.add(insertingNode);
            }
        }
        return clone;
    }
}