#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool fun(vector<int>& bloomDay, long long j, int m, int k) {
    long long count = 0;
    long long bouno = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= j) {
            count++;
        } else {
            bouno += count / k;
            count = 0;
        }
    }
    bouno += count / k;
    if(bouno>=m) {return true;}
    return false;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (1ll*n < 1ll*m * k)
            return -1;
        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (fun(bloomDay, mid, m, k) == true) {
                ans=min(ans,mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};