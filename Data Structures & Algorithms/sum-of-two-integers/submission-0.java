class Solution {
    public int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for (int i=0; i<32; i++) {
            int aSet = (a >> i) & 1;
            int bSet = (b >> i) & 1;
            int curr = aSet ^ bSet ^ carry;
            carry = (aSet & bSet) | (aSet & carry) | (bSet & carry);

            if (curr != 0) {
                ans |= (1 << i);
            }
        }
        // if (ans > 0x7FFFFFFF) {
        //     ans = ~(ans ^ 0xFFFFFFFF);
        // }
        return ans;
    }
}
