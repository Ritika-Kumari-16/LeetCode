class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
	int cnt1=0,cnt2=0;
	int ele1=INT_MIN, ele2=INT_MIN;
	for(int i=0;i<v.size();i++){
		if(cnt1==0&&ele2!=v[i]) {
			cnt1=1;
			ele1=v[i];
		}
		else if( cnt2==0&&ele1!=v[i]){
			cnt2=1;
			ele2=v[i];
		}
		else if( ele1==v[i]) cnt1++;
		else if( ele2==v[i]) cnt2++;
		else {cnt1--;cnt2--;}
	}
	int m=v.size()/3;
	cnt1=0;cnt2=0;
	for(int i=0;i<v.size();i++){
		if(ele1==v[i]) cnt1++;
		if(ele2==v[i]) cnt2++;
	}
	vector<int>ans;
	if(cnt1>m) ans.push_back(ele1);
	if(cnt2>m) ans.push_back(ele2);
    return ans;
        
    }
};