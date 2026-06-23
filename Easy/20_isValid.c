bool isValid(char * s){
  char stack[10000];
  unsigned short int i, c = 0;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      stack[c] = s[i];
      stack[c + 1] = '\0';
      ++c;
    }
    else if (s[i] == ')' && strlen(stack) && stack[strlen(stack) - 1] == '(') {
      stack[strlen(stack) - 1] = '\0';
      --c;
    }
    else if (s[i] == '}' && strlen(stack) && stack[strlen(stack) - 1] == '{') {
      stack[strlen(stack) - 1] = '\0';
      --c;
    }
    else if (s[i] == ']' && strlen(stack) && stack[strlen(stack) - 1] == '[') {
      stack[strlen(stack) - 1] = '\0';
      --c;
    }
    else return false;
  }
  return strlen(stack) == 0;
}
// Method 2
// bool isValid(char* s) {
//     size_t len = strlen(s);
//     int stack[len];
//     int leftpar = -1;
//     for(int i = 0 ;i < len; i++)
//     {
//         if(s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             // leftpar++;
//             stack[++leftpar] = s[i];
            
//         }else{
//             // check the last paranthesses
//             if(leftpar < 0) return false;
//             int top = stack[leftpar--];
//             if((s[i] == ')' && top != '(')||
//                (s[i] == ']' && top != '[')||
//                (s[i] == '}' && top != '{')){
//                 return false;
//             }
            
//         }
//     }
//     if(leftpar < 0)
//         return true;
//     return false;
// }
