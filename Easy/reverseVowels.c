char * reverseVowels(char * s){
    
    int len = strlen(s);
    if(len == 1) return s;
    int forward = 0;
    int backward = len - 1;
    char temp = 0;
    while(true)
    {
        while(forward < len)
        {
            if(s[forward] == 'a' || s[forward] == 'e' || s[forward] == 'i' \
            || s[forward] == 'o'  || s[forward] == 'u'|| s[forward] == 'A' \
            ||s[forward] == 'E' || s[forward] == 'I' ||s[forward] == 'O' ||\
            s[forward] == 'U')
            {
                break;
            }
            forward++;
        }
        while(backward >= 0)
        {
            if(s[backward] == 'a' || s[backward] == 'e' || s[backward] == 'i' \
            || s[backward] == 'o'  || s[backward] == 'u'||s[backward] == 'A' \
            ||s[backward] == 'E' || s[backward] == 'I' ||s[backward] == 'O' ||\
            s[backward] == 'U')
            {
                break;
            }
            backward--;
        }
        if(forward >= backward) break;
        temp = s[forward];
        s[forward] = s[backward];
        s[backward] = temp;
        forward++;backward--;

    }

    return s;
}

/*
int isVowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char *reverseVowels(char *s){
    size_t size = strlen(s);
    unsigned int idx1 = 0;
    unsigned int idx2 = size;

    while (idx1 < idx2) {
        if (isVowels(s[idx1]) && isVowels(s[idx2])) {
            char tmp = s[idx1];
            s[idx1] = s[idx2];
            s[idx2] = tmp;

            idx1++;
            idx2--;
        } else {
            if (!isVowels(s[idx1]))
                idx1++;
            if (!isVowels(s[idx2]))
                idx2--;
        }
    }

    return s;
}
*/
