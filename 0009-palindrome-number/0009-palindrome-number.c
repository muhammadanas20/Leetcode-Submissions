bool isPalindrome(int x) {
   int temp = x;
   long long y = 0;
  while(temp>0 ){
    int digit = temp%10;
     y = (y*10) + digit;
     temp /= 10;
  }
 return x==y;
}