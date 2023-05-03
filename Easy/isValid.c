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

