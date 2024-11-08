// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<pair<int,char>>hashfreq(125,{0,0});
//         for(auto c : s){
//             hashfreq[c]={hashfreq[c].first++,c};
//         }
//         sort(hashfreq.begin(), hashfreq.end(), [](pair<int, char>& a, pair<int, char>& b) {
//             return a.first > b.first;  // Sort by frequency descending
//         });

//         // Build result string based on sorted frequency
//         string result = "";
//         for (auto it : hashfreq) {
//             result=string(it.first,it.second)+result;
//         }

//         return result;
        
//     }
// };


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        string result;
        for (const auto &p : freqVec) {
            result += string(p.second, p.first);
        }

        return result;        
    }
};
