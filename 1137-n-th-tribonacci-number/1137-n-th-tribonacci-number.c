int memo[40]; 
int tribonacci(int n) {
    if(n == 0){
        return 0;
    }else if(n == 1 || n == 2){
        return 1;
    }
    if(memo[n] != 0){   // already computed
        return memo[n];
        }

  memo[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
  return memo[n];
}