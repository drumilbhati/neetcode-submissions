class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        Set<List<Integer>> st = new HashSet<>();
        List<Integer> v = new ArrayList<>();
        dfs(target, nums, v, st);

        List<List<Integer>> ans = new ArrayList<>();
        for (List<Integer> l: st) {
            ans.add(l);
        }
        return ans;
    }

    void dfs(int target, int[] nums, List<Integer> v, Set<List<Integer>> st) {
        if (target == 0) {
            List<Integer> temp = new ArrayList<>(v);
            Collections.sort(temp);
            st.add(temp);
            return;
        }

        for (int x: nums) {
            if (target >= x) {
                v.add(x);
                dfs(target - x, nums, v, st);
                v.removeLast();
            }
        }
    }
}
