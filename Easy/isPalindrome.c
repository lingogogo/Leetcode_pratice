bool isPalindrome(char * s){
    char* left = s;
    char* right = s + strlen(s) - 1;
    //use isalnum check the string.
    while(left < right)
    {
        if(isalnum(*left)&& isalnum(*right))
        {
            if(tolower(*left) != tolower(*right))
                return false;
            left++;
            right--;
        }
            
        else
        {
            if(isalnum(*left))
                right--;
            else
                left++;
        }
    }

    return true;
    

    
    
}
