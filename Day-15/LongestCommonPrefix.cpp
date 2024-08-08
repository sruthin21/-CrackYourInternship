class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        for(int i=1;i<strs.size();i++){
            string str = "";
            int i1 = 0;
            int j1 = 0;
            while(i1< word.length() && j1<strs[i].length()){
                if(word[i1]==strs[i][j1]){
                    str = str+word[i1];
                }
                else{
                    break;
                }
                i1++;
                j1++;
            }
            word = str;
        }
        return word;
    }
};