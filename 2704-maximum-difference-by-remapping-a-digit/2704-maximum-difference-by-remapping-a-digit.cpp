class Solution {
public:
    int minMaxDifference(int num) {
        string nums=to_string(num);
        char maxo;
        char mino;

        for(int i=0;i<nums.length();i++)
        {
            if(nums[i]!='9')
            {
                maxo=nums[i];
                break;
            }
        }
        for(int i=0;i<nums.length();i++)
        {
            if(nums[i]!='0')
            {
                mino=nums[i];
                break;
            }
        }

        string maxum=nums;
        string minum=nums;

        for(int i=0;i<nums.length();i++)
        {
            if(nums[i]==maxo)
            {
                maxum[i]='9';
            }

            if(nums[i]==mino)
            {
                minum[i]='0';
            }
        }

        int mx=stoi(maxum);
        int mn=stoi(minum);

        return mx-mn;


    }
};