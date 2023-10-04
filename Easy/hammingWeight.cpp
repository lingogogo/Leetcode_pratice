class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t one = 1;
        
        int count = 0;
        for(int i =0 ; i < 32; i++)
        {   
            one = (n>>i)&one;
            if(one == 1)
            {
                count++;
            }else one = 1;
        }
        return count;
        
    }
};
