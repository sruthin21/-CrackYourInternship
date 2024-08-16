class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int c1 = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;

        if (c1 == color) {
            return image;
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + (i == 1 ? 1 : (i == 3 ? -1 : 0));
                int ncol = c + (i == 0 ? -1 : (i == 2 ? 1 : 0));

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == c1) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};