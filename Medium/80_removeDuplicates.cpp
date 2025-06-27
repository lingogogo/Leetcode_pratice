class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> unmap;
        int output=n;
        // for(int i = 0;i < n; i++)
        int ind = 0;
        while(ind < nums.size())
        {
            // if(nums[i])
            unmap[nums[ind]]++;
            if(unmap[nums[ind]] > 2){
                output--;
                nums.erase(nums.begin() + ind - 1);
                continue;
            } 
            ind++;
        }
        // cout << output << endl;
        // for(auto it:unmap)
        // {
            // output+= max(0,it.second - 2);
        // }

        return output;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size==1) {
            return 1;
        }
        int cnt = 1, res=1;;
        for (int i=1; i<size; i++) {
            if (nums[i-1]!=nums[i]) {
                cnt=1;
            } else {
                cnt++;
            }
            if (cnt>2) {
                continue;
            }
            if (i!=res) {
                nums[res] = nums[i];
            }
            res++;
        }
        return res;
    }
};
