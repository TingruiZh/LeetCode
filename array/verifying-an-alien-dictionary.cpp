class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++){
          mp[order[i]]= i;
        }
        for(int j=0;j<words.size()-1;j++){
            bool same =true;
            for(int z=0;z<words[j].size();z++){
                if(mp[words[j][z]]>mp[words[j+1][z]]){
                    return false;
                }else if(mp[words[j][z]]<mp[words[j+1][z]]){
                    same =false;
                    break;
                }
            
            }if(same&&words[j].size()>words[j+1].size()){return false;}
            
        }
        return true;
    }
};