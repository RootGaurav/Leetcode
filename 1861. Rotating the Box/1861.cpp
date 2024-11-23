class Solution {
public:
    void swap (vector<vector<char>>& box, int i, int j, int ni, int nj) {
        char temp = box[i][j];
        box[i][j] = box[ni][nj];
        box[ni][nj] = temp;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        /*
        for (int i = 0; i<box.size(); i++) {
            for (int j = 0; j<box[0].size(); j++) {
                cout << box[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\n";
        */

        for (int i = 0; i<box.size(); i++) {
            int dropPoint = box[0].size()-1;

            for (int j = box[0].size()-1; j>=0; j--) {
                if (box[i][j] == '*') {
                    dropPoint = j-1;
                }

                if (box[i][j] == '#') {
                    swap(box, i, j, i, dropPoint);
                    dropPoint--;
                }
            }
        }

        /*
        for (int i = 0; i<box.size(); i++) {
            for (int j = 0; j<box[0].size(); j++) {
                cout << box[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\n";
        */


        // rotate the box
        vector<vector<char>> ans = vector<vector<char>>(box[0].size(), vector<char>(box.size(), '.'));
        for (int i = 0; i<box.size(); i++) {
            for (int j = 0; j<box[0].size(); j++) {
                ans[j][ans[0].size() - i -1] = box[i][j];
            }
        }

        /*
        for (int i = 0; i<ans.size(); i++) {
            for (int j = 0; j<ans[0].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        */

        return ans;
    }
};