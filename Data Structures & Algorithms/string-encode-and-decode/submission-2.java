class Solution {
    Map<String, List<String>> mp = new HashMap<>();
    
    public String encode(List<String> strs) {
        String key = UUID.randomUUID().toString();
        mp.put(key, strs);
        return key;
    }

    public List<String> decode(String str) {
        return mp.get(str);
    }
}
