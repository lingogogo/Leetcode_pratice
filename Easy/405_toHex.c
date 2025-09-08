// method 1;
int power(int a, int power){
    if(power == 0) return 1;
    for(int i = 0;i < (power - 1);i++)
    {

        a*=2;
    }
    return a;
}

void reverse(char* ch)
{
    int i = 0;
    int j = 7;

    while(i<j)
    {
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        i++;j--;
    }
    return;
}

int counter(char* ch)
{
    int count = 0;
    for(int i = 0;i < 8;i++)
    {
        if(ch[i] == '0')
        {
            count++;
        }else break;
    }

    return count;
    
}
char* toHex(int num) {
    // every four bit to become a hexadecimal
    // int counter = 0;
    if(num==0) return "0";
    unsigned int num1 = num;
    int sum4bits = 0;
    char* output = malloc(9*sizeof(char));
    output[8] = '\0';// remember the string must add this end.
    int chind = 0;
    for(int i = 0;i < 32; i++)
    {
        if(i!=0 && i%4 == 0)
        {
            if(sum4bits < 10)
            {
                output[chind] = '0' + sum4bits;
            }else{
                // printf("%d",sum4bits);
                output[chind] = 'a' + sum4bits%10;
            }
            sum4bits = 0;
            chind++;
        }
        if((num1 >>i & 1) == 1){
            sum4bits+= power(2,i%4);
        }
            
    }
    // printf("%s", output);
    if(sum4bits < 10)
    {
        output[chind] = '0' + sum4bits;
    }else{
        output[chind] = 'a' + sum4bits%10;
    }
    reverse(output);
    
    return output + counter(output);
}
// method 2;
static inline char hexDigit(int num) {
    return (num < 10) ? (num + '0') : ('a' + (num - 10));
}

char* toHex(int num) {
    unsigned int n = (unsigned int)num;
    int k = 8;
    char* hex = (char*)malloc(k + 1);
    *(hex + k) = '\0';
    if (n == 0)
        hex[--k] = '0';
    else {

        while (n > 0) {
            hex[--k] = hexDigit(n % 16);
            n /= 16;
        }
    }
    return hex + k;
}
