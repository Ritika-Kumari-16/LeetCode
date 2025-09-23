class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss(version1);
        stringstream pp(version2);
        string v1;
        string v2;
        while(true){
            if(!getline(ss,v1,'.')) v1="0";
            if(!getline(pp,v2,'.')) v2="0";
            int val1=stoi(v1);
            int val2=stoi(v2);
            if(val1<val2) return -1;
            else if(val1>val2) return 1;
            if(!ss && !pp) break;
        }
        return 0;
    }
};