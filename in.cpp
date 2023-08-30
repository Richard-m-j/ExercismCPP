class Solution
{
public:
    int volume(int h1, int h2, int w)
    {
        if (h1 > h2)
            return h2 * w;
        return h1 * w;
    }

    int maxArea(vector<int> &height)
    {
        ios_base::sync_with_stdio(false);

        int n = height.size();
        int maxVol = volume(height[0], height[n - 1], n - 1);
        int left = 0, right = n - 1;

        while (left < right)
        {
            int shorter = min(height[left], height[right]);

            if (height[left] < height[right])
            {
                int current = volume(height[left], height[right], right - left);
                if (current > maxVol)
                {
                    maxVol = current;
                }
                while (left < right && height[left] <= shorter)
                    left++;
            }
            else
            {
                int current = volume(height[left], height[right], right - left);
                if (current > maxVol)
                {
                    maxVol = current;
                }
                while (left < right && height[right] <= shorter)
                    right--;
            }
        }

        return maxVol;
    }
};
