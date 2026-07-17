class Solution {
public:
    string removeStars(string s) {
        for(int i=0;i<s.length();i++){
             if(s[i] == '*'){
                s.erase(i-1,2);
                 i -= 2;
             }
        }
        return s;
        // O n2

        // string result = "";
        // for( char c : s){
        //     if(c == '*'){
        //         result.pop_back();
        //     }else{
        //         result.push_back(c);
        //     }
        // }
        // return result;
    }
};