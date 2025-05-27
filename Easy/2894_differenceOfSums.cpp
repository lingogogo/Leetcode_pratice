class Solution {
public:
    int differenceOfSums(int n, int m) {
        // num1
        int num1 = 0;
        // num2
        int num2 = 0;
        // for num1
        for(int i = 1; i <= n ;i++){
            if(i % m != 0) num1+=i;
            else num2+=i;
        }
        
        return num1 - num2;
        
    }
};
