class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size() - 1;
        int max_water = 0;
        int h = 0;
        while(left < right)
        {
            h = min(height[left],height[right]);

            if(max_water < (h*(right-left))) max_water = h*(right-left);
            
            if(height[left] < height[right])
            {
                left++;
            }else{
                right--;
            }
        }
        return max_water;
    }
};
