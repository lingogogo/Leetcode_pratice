// https://leetcode.com/problems/sum-of-two-integers/solutions/6141561/animated-video-bit-manipulation-masking-visualized
class Solution {
public:
    int getSum(int a, int b) {
        
        // deal with the carry;
        
        while(b!= 0)
        {
            int r1 = a^b; // no carry;
            int carry = (a&b) << 1;
            a = r1;
            b = carry;
        }

        // int output2 = a^b;

        return a;
    }
};
