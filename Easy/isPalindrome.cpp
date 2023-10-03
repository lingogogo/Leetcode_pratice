class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size()-1;

        if(s.size() == 1) return true;
        //int correct = 0;
        while(p1 < p2)
        {
            
            
                //cout << "p1 and p2 number: " << p1 << " " << p2 << endl;
                //cout << s[p1] << " " << s[p2] <<endl;
            
            if((tolower(s[p1]) < 'a' && (tolower(s[p1]) <'0' || tolower(s[p1]) > '9')) || (tolower(s[p1]) > 'z'))
            {
                p1++;
            }else if((tolower(s[p2]) < 'a' && (tolower(s[p2]) <'0' || tolower(s[p2]) > '9'))|| tolower(s[p2]) > 'z')
            {
                p2--;
            }else if(tolower(s[p1]) != tolower(s[p2]))
            {
                return false;
            }else
            {
                p1++;
                p2--;
                //correct++;
            }
        }
        //cout << correct << endl;
        //if(correct > 0) return true;
        //else return false;
        return true;
        
        
    }
};
