class Solution {
public:
    int countHomogenous(string s) {
        //map<string,int> dic;
        int num = 1;
        int temp = 0;
        long long tot = 1;
        for(int i = 1; i < s.size();i++)
        {
            
            if(s[temp] != s[i])
            {
                temp = i;
                num = 1;
                tot+=1;
                continue;
            }
            num++;
            //cout << "num: " <<num << endl;
            tot+=num;
            //cout << "tot: " <<tot << endl;
        }

        

        return int(tot%1000000007);
    }
};
