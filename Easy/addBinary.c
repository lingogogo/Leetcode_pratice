char * addBinary(char * a, char * b){
    int sizea = strlen(a);
    int sizeb = strlen(b);
    int sizeoutput = (sizea > sizeb ? sizea : sizeb) + 1;
    char * output = malloc((sizeOutput + 1)*sizeof(char));
    int sum = 0;
    
    output[sizeoutput] = '\0';
    while(sizea > 0 || sizeb > 0|| sum > 0)
    {
        if(sizea>0)
        {
            sizea -=1;
            sum+= a[sizea] - '0';
        }
        if(sizeb>0)
        {
            sizeb -=1;
            sum+= b[sizeb] - '0';
        }
        sizeoutput-=1;
        output[sizeoutput] = sum % 2 + '0';
        sum/=2;
    }
    // if sizeoutput = 0, it means that there is fixed space for the output pointer
    
    return output+sizeoutput;
}
