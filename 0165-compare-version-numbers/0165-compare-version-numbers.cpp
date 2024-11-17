class Solution {
public:
    vector<string>gettokens(string version){
        vector<string>ans;
        string token="";
        stringstream ss(version);
        while(getline(ss, token , '.')){
            ans.push_back(token);
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1=gettokens(version1);
        vector<string>v2=gettokens(version2);
        int i=0;
        int n= v1.size();
        int m=v2.size();
        while(i<n || i<m){
            int a = i<n ? stoi(v1[i]) :0;
            int b= i<m ? stoi(v2[i]) : 0;
            if(a<b){
                return -1;
            }
            else if( a>b){
                return 1;
            }
            else {
                i++;
            }
        }
        return 0;
        
    }
};