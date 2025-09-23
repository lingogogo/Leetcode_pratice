class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int ind1 = 0, ind2 = 0;
        int val1 = 0, val2 = 0;
        int len = max(version1.size(),version2.size());
        // int ind1 = found1 + 1, ind2 = found2 + 1;
        while(ind1 < len && ind2 < len)
        {
            string temp1, temp2;
            while(ind1 < version1.size() && version1[ind1] != '.')
            {
                temp1+=version1[ind1];
                ind1++;
            }
            while(ind2 < version2.size() && version2[ind2] != '.')
            {
                temp2+=version2[ind2];
                ind2++;
            }
            // cout << "temp1 : " << temp1 << " temp2: " << temp2 << endl;
            int val1 = temp1.empty() ? 0 : stoi(temp1);
            int val2 = temp2.empty() ? 0 : stoi(temp2);
            // cout << "val1: " << val1 << " val2: " << val2 << endl;
            if(val1 < val2) return -1;
            else if(val1 > val2) return 1;
            ind1++;ind2++;
        }

        return 0;
       
        if(val1 <val2)
        {
            return -1;
        }else if(val1 >val2)
        {
            return 1;
        }else{
            return 0;
        }
    }
};
