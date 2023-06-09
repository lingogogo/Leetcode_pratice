char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    //I want the str1 is the longer one.
    if(len1 < len2) return gcdOfStrings(str2,str1);
    if(!strcmp(str1,str2)) return str2;
    else if(str1[0] != str2[0]) return "";
    return gcdOfStrings(str1 + len2, str2);

    
    //check the string
}
