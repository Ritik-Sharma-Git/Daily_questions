class Solution {
public:
    void fillwith(string word , int count[26] ){
        for(char &ch:word){
            count[ch-'a']++;
        }
    }
    
    
    vector<string> commonChars(vector<string>& words) {
            vector<string> ans;
            int n=words.size();  

            int count[26]={0};
            fillwith(words[0],count);

            for(int i=0;i<n;i++){
                int temp[26]={0};
                
                fillwith(words[i],temp);
                
                for(int j=0;j<26;j++){
                    count[j]=min(count[j],temp[j]);
                }

            }
        for(int i=0;i<26;i++){
            int c = count[i];
            while(c--){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
        }
};