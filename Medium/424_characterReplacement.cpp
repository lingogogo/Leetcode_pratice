// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         // k is the number of words to change.
//         int n = s.size();
//         if(n == 1) return 1;
//         int repeat_count = 1; // left is counted;
//         int output = 0;
//         int left = 0;
//         int right = 1;
//         int dif_counter = 0, dif_start_index = 0;
//         char present_char = s[0];
//         while(left < right && right < n)
//         {
//             // left is my target for the window
//             if(s[right] == present_char){
//                 repeat_count++;
//             }else if(s[right] != present_char)
//             {
//                 dif_counter++;
//                 if(dif_counter == 1)
//                     dif_start_index = right;
                
//                 if(dif_counter <= k)
//                 {
//                     repeat_count++;
//                 }else{
//                     dif_counter = 0;
//                     left = dif_start_index;
//                     repeat_count = 1;
//                     right = left+1;
//                     present_char = s[left];
//                     output = max(output,repeat_count);
//                     continue;
//                 }
//             }
//             cout << "repeat_count: " << repeat_count << endl;
//             output = max(output,repeat_count);
//             right++;
//         }
//         // another direction to find out the longest repeating character.
//         right = n - 1;
//         left = right - 1;
//         repeat_count = 1;
//         dif_counter = 0, dif_start_index = 0;
//         present_char = s[right];

//         while(left < right && left >= 0)
//         {
//             // left is my target for the window
//             if(s[left] == present_char){
//                 repeat_count++;
//             }else if(s[left] != present_char)
//             {
//                 dif_counter++;
//                 if(dif_counter == 1)
//                     dif_start_index = left;
                
//                 if(dif_counter <= k)
//                 {
//                     repeat_count++;
//                 }else{
//                     dif_counter = 0;
//                     right = dif_start_index;
//                     repeat_count = 1;
//                     left = right+1;
//                     present_char = s[right];
//                     output = max(output,repeat_count);
//                     continue;
//                 }
//             }
//             output = max(output,repeat_count);
//             left--;
//         }

//         return output;
        
//     }
// };
//https://leetcode.com/problems/longest-repeating-character-replacement/solutions/6146343/animated-video-sliding-window-template-and-visualization
class Solution{
    public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            freqs[s[j]]++;
            maxFreq = max(maxFreq, freqs[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freqs[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
    
};
