class Solution {
public:
    int myAtoi(string s) {
        int i =0;
        int n = s.length();
        int sign = 1;
        int result = 0;
         //for white spaces
        while(i < n && s[i] == ' '){
            i++;
        }
        //for sign
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
           sign = 1;
           i++;
        }
        else{
            sign = 1;
        }

        //for digit reading
        while(i<n && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
           
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = 10*result + digit;
            i++;
        }
        return result*sign;

    }
};