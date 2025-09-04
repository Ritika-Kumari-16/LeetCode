class Solution {
public:
    int findClosest(int x, int y, int z) {
        int time_x = abs(x-z);
        int time_y= abs(y-z);
        if(time_x== time_y) return 0;
        if(time_x < time_y) return 1;
        return 2;
        
    }
};