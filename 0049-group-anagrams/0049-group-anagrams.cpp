class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,vector<string>> anagramMap;

        for(const string& str: strs){
            string sorted = str;

            sort(sorted.begin(),sorted.end());
            anagramMap[sorted].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& pair : anagramMap){
            result.push_back(move(pair.second));
        }
        return result;

    }
};