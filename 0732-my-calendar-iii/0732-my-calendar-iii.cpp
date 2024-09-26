class MyCalendarThree
{
public:
    map<int, int> mp;
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int cur = 0;
        int ans = 0;
        for (auto &x : mp)
        {
            cur += x.second;
            ans = max(cur, ans);
        }
        return ans;
    }
};