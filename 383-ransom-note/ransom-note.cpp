class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
         unordered_map<char,int>need;
         unordered_map<char,int>have;
        for (int i=0;i<n;i++){
            need[ransomNote[i]]++;
        }
        for (int j=0;j<m;j++){
            have[magazine[j]]++;
        }
        //dupe kardenge
         for (auto i:need){
            char c=i.first; //key of need
            int fneed= i.second; //freq of need hashmap
            int fhave = have[c]; //freq of have hashmap
            if (fhave<fneed){
                return false;
            }
         }
        return true;
    }
};