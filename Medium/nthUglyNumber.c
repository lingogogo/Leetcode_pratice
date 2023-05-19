#define min(a, b) (a < b ? a : b)

int nthUglyNumber(int n){
    int uglyarray[n];
    int t2 = 0, t3 = 0, t5 = 0;
    int next2 = 0, next3 = 0, next5 = 0;
    int final_next = 0;
    uglyarray[0] = 1;
    for(int i = 1; i < n; i++)
    {
        next2 = 2*uglyarray[t2];
        next3 = 3*uglyarray[t3];
        next5 = 5*uglyarray[t5];
        final_next = min(next2,min(next3,next5));
        if(final_next == next2) t2++;
        if(final_next == next3) t3++;
        if(final_next == next5) t5++;
        uglyarray[i] = final_next;
    }
    return uglyarray[n - 1];
}
