class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> v = new ArrayList<>();
        boolean[] pick = new boolean[nums.length];
        dfs(nums, v, pick);
        return ans;
    }

    void dfs(int[] nums, List<Integer> v, boolean[] pick) {
        if (v.size() == nums.length) {
            ans.add(new ArrayList<>(v));
            return;
        }

        // take
        for (int j=0; j<nums.length; j++) {
            if (!pick[j]) {
                v.add(nums[j]);
                pick[j] = true;
                dfs(nums, v, pick);
                v.removeLast();
                pick[j] = false;
            }
        }
    }
}
