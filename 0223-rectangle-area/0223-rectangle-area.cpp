class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);
        int cx1=max(ax1,bx1) , cy1=max(ay1,by1);
        int cx2=min(ax2,bx2) , cy2=min(ay2,by2);
        int l1=cx2-cx1;
        int b1=cy2-cy1;
        int carea=0;
        if(l1>0 && b1>0){
            carea=l1*b1;
        }
        return area1+area2-carea;
    }
};