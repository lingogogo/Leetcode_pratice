Leetcode account: https://leetcode.com/u/CianSyue/

# Leetcode-answer
Daily Update 

practice C or C++ coding

# Note
int snprintf ( char * str, size_t size, const char * format, ... );
char** arr = (char**)malloc(sizeof(char*)*r);

A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

Binary search: arrangeCoins.c

Find target by high and low values.

Difference array: Difference array D[i] of a given array A[i] is defined as D[i] = A[i]-A[i-1] (for 0 < i < N ) and D[0] = A[0] considering 0 based indexing. Difference array can be used to perform range update queries “l r x” where l is left index, r is right index and x is value to be added and after all queries you can return original array from it. Where update range operations can be performed in O(1) complexity.

If the problem time complexity is too large, binary search might be the better solution.

常見的場景應用: 搜尋排序數組、查找邊界值、優化競技類問題、矩陣搜尋 (Leetcode problem: Zero Array Transformation II, minimum time to repair cars)



# problem

1. What is *(int*)a in compare function on the internet.

  ans:

  The function takes a void*, but somehow it knows (perhaps it's required in some documentation somewhere) that the pointer it's given actually points to an int.
  So, (int*)number is "the original pointer, converted to an int* so that I can read an int from it", and *(int*)number is the int value that it points to.
  
