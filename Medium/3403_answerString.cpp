class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size();

        //  lexicographically largest string
        int num = n - numFriends + 1;
        string output = "";
        // cout << "num: " << num << endl;
        int ind = 0;
        // while(ind + num - 1 < n){
        //     string temp = word.substr(ind,num);
        //     if(temp > output){
        //         output = temp;
        //         cout << output << endl;
        //     }
        //     ind++;
        // }
        for(int i = 0; i < n; i++)
        {
            string temp = word.substr(i,num); //len:if the string is shorter, as many characters as possible are used
            if(temp > output){
                output = temp;
                // cout << output << endl;
            }
            // output = word.substr(i,num);
        }
        return output;
    }
};
