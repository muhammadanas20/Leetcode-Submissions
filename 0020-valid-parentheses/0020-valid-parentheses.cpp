class Solution {
public:
    bool isValid(string s) {
       std::stack <char> stack;
       std::unordered_map <char,char> CloseToOpen = {
        {')','('},
        {'}','{'},
        {']','['}
       };
       for(char c : s){
        if(CloseToOpen.count(c)){
             if(!stack.empty() && stack.top() == CloseToOpen[c]){
                stack.pop();
            }else{
                return false;
            }
        }else{
            stack.push(c);
        }
            
       }
       return stack.empty();
    }
};