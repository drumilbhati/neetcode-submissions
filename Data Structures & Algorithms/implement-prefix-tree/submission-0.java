class Node {
    boolean isComplete;
    Node[] children = new Node[26];
}
class PrefixTree {
    Node root = new Node();
    public PrefixTree() {
         
    }

    public void insert(String word) {
        Node node = root;
        for (char c: word.toCharArray()) {
            if (node.children[c-'a'] == null) {
                node.children[c-'a'] = new Node();
            }
            node = node.children[c-'a'];
        }
        node.isComplete = true;
    }

    public boolean search(String word) {
        Node node = root;
        for (char c: word.toCharArray()) {
            if (node.children[c-'a'] == null) {
                return false;
            }
            node = node.children[c-'a'];
        }
        return node.isComplete == true;
    }

    public boolean startsWith(String prefix) {
        Node node = root;
        for (char c: prefix.toCharArray()) {
            if (node.children[c-'a'] == null) {
                return false;
            }
            node = node.children[c-'a'];
        }
        return true;
    }
}
