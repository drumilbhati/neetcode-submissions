class Solution {
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();

        for (String s: strs) {
            sb.append(s.length()).append("_").append(s);
        }
        return sb.toString();
    }

    public List<String> decode(String s) {
        int n = s.length();
        List<String> strs = new ArrayList<>();

        for (int i=0; i<n; ) {
            int len = 0;
            while (s.charAt(i) != '_') {
                len = (10 * len) + (s.charAt(i) - '0');
                i++;
            }
            String t = s.substring(i+1, i+1+len);
            strs.add(t);

            i += len+1;
        }
        return strs;
    }
}
