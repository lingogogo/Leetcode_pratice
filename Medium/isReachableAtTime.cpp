class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dif_x = abs(fx - sx);
        int dif_y = abs(fy - sy);
        int min = 0;
        if(dif_x > dif_y)
        {
            min = dif_x;
        }else{
            min = dif_y;
        }
        cout << min <<endl;
        if(t < min && min !=0) return false;
        if(min == 0 && t ==1) return false;
        return true;
    }
};
