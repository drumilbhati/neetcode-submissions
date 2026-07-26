class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Set<List<Integer>> st = new HashSet<>();
        List<Integer> v = new ArrayList<>();

        dfs(0, nums, v, st);
        
        List<List<Integer>> ans = new ArrayList<>();
        for (List<Integer> l: st) {
            ans.add(l);
        }
        return ans;
    }

    void dfs(int i, int[] nums, List<Integer> v, Set<List<Integer>> st) {
        if (i >= nums.length) {
            st.add(new ArrayList<>(v));
            return;
        }

        // not take
        dfs(i+1, nums, v, st);

        // take
        v.add(nums[i]);
        dfs(i+1, nums, v, st);

        // reset v to its original state
        v.removeLast();
    }
}
