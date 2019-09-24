class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0) return false;
        
        int i = 0, j = array[i].size()-1;
        while(i<array.size() && j>=0) {
            if(target > array[i][j]) ++i;
            else if(target < array[i][j]) --j;
            else return true;
        }
        return false;
    }
};
