class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
     string pre = "";
     for(int i=0;i<strs[0].length();i++){
         char c = strs[0][i];
         for(int j=1;j<strs.size();j++){
            if(i >= strs[j].length() || c != strs[j][i]){
                return pre;
            }
         }
         pre += c;
     }
     return pre; 
    }
};