class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0, mini = INT_MAX;

        while (i <= blocks.length() - k) {
            int count = 0;
            for (int z = i; z < i + k; ++z) {
                if (blocks[z] == 'W') {
                    count++;
                }
            }

            mini = min(mini, count);
            i++;
        }

        return mini;
    }
};