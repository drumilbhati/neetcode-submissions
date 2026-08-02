/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> dq = new LinkedList<>();

        dq.add(root);
        while (!dq.isEmpty()) {
            TreeNode node = dq.poll();

            if (node == null) {
                sb.append("null,");
                continue;
            }

            sb.append(node.val).append(",");
            
            dq.add(node.left);
            dq.add(node.right);
        }
        if (sb.length() > 0)
            sb.setLength(sb.length()-1);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.equals("null") || data.isEmpty()) {
            return null;
        }
        List<String> list = new ArrayList<>(Arrays.asList(data.split(",")));

        int index = 0;
        TreeNode root = new TreeNode(Integer.parseInt(list.get(index++)));

        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.addLast(root);

        while (!dq.isEmpty() && index < list.size()) {
            TreeNode node = dq.removeFirst();

            if (!list.get(index).equals("null")) {
                node.left = new TreeNode(Integer.parseInt(list.get(index)));
                dq.addLast(node.left);
            }

            index++;

            if (index < list.size() && !list.get(index).equals("null")) {
                node.right = new TreeNode(Integer.parseInt(list.get(index)));
                dq.addLast(node.right);
            }
            index++;
        }

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));