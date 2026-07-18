class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        int s2 = 0;
        int s1 = 0;
        int n1 = word1.length();
        int n2 = word2.length();
        while(s1 < n1 && s2 < n2){
            output += word1[s1++];
            output += word2[s2++];
           
        }
        // Append remaining characters from word1, if any
        while (s1 < n1) {
            output += word1[s1++];
        }
        
        // Append remaining characters from word2, if any
        while (s2 < n2) {
            output += word2[s2++];
        }
        return output;
    }
};