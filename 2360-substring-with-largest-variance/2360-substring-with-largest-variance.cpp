class Solution {
public:
    int largestVariance(string s) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;

        }
        int result=0;
        for(int i=0;i<26;i++){
            if(arr[i]==0) continue;
            for(int j=0;j<26;j++){
                if( i==j||arr[j]==0){
                    continue;
                }
                int firstcount=0;
                int secondcount=0;
                bool visitedsec=false;
                for(char &ch : s){
                    if(i==ch-'a'){
                        firstcount++;
                    }
                    if(j==ch-'a'){
                        secondcount++;
                    }
                    if(secondcount>0){
                        result=max(result,firstcount-secondcount);

                    }
                    else{
                        if(visitedsec==true){
                            result=max(result,firstcount-1);
                        }
                    }
                    if(secondcount > firstcount){
                        firstcount=0;
                        secondcount=0;
                        visitedsec=true;
                    }

                }
            }
        }
        return result;
    }
};