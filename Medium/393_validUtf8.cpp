bool validUtf8(int* data, int dataSize) {
    // check MSB for each one;
    int i = 0;
    while(i < dataSize)
    {
        int move = 7;
        int count_bits = 0;
        while(true)
        {
            if(move < 0) break;
            if(((data[i] >> move) & 1 )== 0) break;
            --move;
            ++count_bits;
        }
        if(count_bits == 1 || count_bits > 4) return false; // UTF-8 doesn't have 10xxxxxx.
        // output result
        // printf("count_bits: %d, cur_i: %d\n", count_bits, i);
        // Now, we get the n-bytes, and we check the last n - 1 binary to fulfill the rule.
        
        ++i;
        if(count_bits == 0) continue;
        // Start to check the following 8 bits.
        int pass_8bits = 0;
        while(i < dataSize)
        {
            if(((data[i] >> 7) & 1) == 1 && ((data[i] >> 6) & 1) == 0) pass_8bits++; // pass the rule
            else return false;// It cannot fulfill the condition, break and return false; or return false directly
            ++i; 
            if(pass_8bits == count_bits - 1) break;
        }
        if(pass_8bits < count_bits - 1) return false;
    }
    return true;

}
