class Solution {
public:
    int findLucky(vector<int>& arr) {
        int number=-1;
        map<int,int>hashmap;
        for(int i=0;i<arr.size();i++){
            hashmap[arr[i]]++;

        }
        for(auto it : hashmap){
            if(it.first==it.second){
                number=it.first;
            }
        }
        return number;
    }
};