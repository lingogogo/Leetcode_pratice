int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

double average(int* salary, int salarySize){
    qsort(salary, salarySize, sizeof(int), cmpfunc);
    double sum = 0;
    for(int i = 1; i < salarySize - 1; i++)
    {
        sum+=salary[i];
    }
    sum/=(salarySize - 2);
    return sum;

}
