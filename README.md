# Leetcode-answer
Daily Update 

practice C || C++ coding

# Note
int snprintf ( char * str, size_t size, const char * format, ... );
char** arr = (char**)malloc(sizeof(char*)*r);

A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

Binary search: arrangeCoins.c

Find target by high and low values.

# problem

1. What is *(int*)a in compare function on the internet.

  ans:

  The function takes a void*, but somehow it knows (perhaps it's required in some documentation somewhere) that the pointer it's given actually points to an int.
  So, (int*)number is "the original pointer, converted to an int* so that I can read an int from it", and *(int*)number is the int value that it points to.
  
