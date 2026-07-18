int isVowel(char c){
    char s;
    s = tolower(c);
    return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
}
//using two pointers approach to solve this:
char* reverseVowels(char* s) {
   int left = 0; //for left side 
   int right = strlen(s) - 1; //for right side 
   char temp;
   while(left<right){
     while(left <right && !isVowel(s[left])){
        left++;
     }
     while(left <right && !isVowel(s[right])){
        right--;
     }
     //swap
     if(left<right){
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
     }
   }
   return s;
}