class Solution {
public:
int binrysrch(vector<int>&potions , long long success , int spell){
    int m=potions.size();
    int low=0;
    int high=m-1;
    int idx=m;
    while(low<=high){
        int mid= low+(high-low)/2;
        long long val =(long long)spell * potions[mid];
        if(val>=success){
            idx=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return idx;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size();
        int m=potions.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int findidx=binrysrch(potions,success,spells[i]);
            ans[i]=m-findidx;
        }
        return ans;

    }
};

// class Solution {
// public:
//     static inline int binarySearch(int k, vector<int>& potions, int m){
//         int l=0, r=m-1;
//         while(l<r){
//             int mid=l+(r-l)/2;
//             if(potions[mid]>= k)
//                 r=mid;
//             else
//                 l=mid+1;
//         }
//         return l;
//     }
//     static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end());
//         const int n=spells.size();
//         vector<int> result(n, 0);
        
//         const int m=potions.size();
//         const int maxPotion=potions[m - 1];

        
//         for (int i=0; i<n; i++) {
//             int spell=spells[i];
//             long long k=(success+spell-1)/spell;
//             if (k <=maxPotion) {
//                 result[i]=m-binarySearch(k, potions, m);
//             }
//         }       
//         return result;
//     }
// };