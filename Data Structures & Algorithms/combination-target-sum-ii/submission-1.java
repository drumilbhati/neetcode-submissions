class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Set<List<Integer>> st = new HashSet<>();
        List<Integer> v = new ArrayList<>();

        Arrays.sort(candidates);

        dfs(0, candidates, target, v, st);
        List<List<Integer>> ans = new ArrayList<>();
        for (List<Integer> l: st) {
            ans.add(l);
        }
        return ans;
    }

    void dfs(int i, int[] candidates, int target, List<Integer> v, Set<List<Integer>> st) {
        if (target == 0) {
            st.add(new ArrayList<>(v));
            return;
        }

        for (int j = i; j < candidates.length; j++) {
            if (candidates[j] > target) break;

            if (j > i && candidates[j] == candidates[j-1]) continue;

            v.add(candidates[j]);
            dfs(j+1, candidates, target - candidates[j], v, st);
            v.removeLast();
        }
    }
}
