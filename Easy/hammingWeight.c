int hammingWeight(uint32_t n) {
    uint32_t k = 1;
    int cou = 0;
    for(int i = 0; i < 32; i++)
    {
        k = n>>i & k;
        if( k == 1)
            cou++;
        else
            k = 1;
    }
    return cou;
}
