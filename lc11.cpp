class Solution {
public:
    int maxArea(vector<int>& height) {
        int target = 0;
        int i,j;
        for (i = 0;i < height.size()-1;i++)
        {
            for (j = i+1;j < height.size();j++)
            {
                target = max(target, (j - i) * min(height[j],height[i]));
            }
        }
        return target;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int target = 0;
        int i = 0;
        int j = height.size() -1;
        while (i < j)
        {
            if (height[i] < height[j])
            {
                target = max(target, (j - i) * height[i]);
                i++;
            }
            else
            {
                target = max(target, (j - i) * height[j]);
                j--;
            }
        }
        return target;
    }
};
