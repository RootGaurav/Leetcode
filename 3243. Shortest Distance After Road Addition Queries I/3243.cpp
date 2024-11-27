class Solution {
    int dk(vector<int> adj[], int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> ans = vector<int>(n, INT_MAX);

        q.push({0, 0});
        ans[0] = 0;

        while (q.size() != 0) {
            pair<int, int> t = q.top();
            q.pop();

            int distance = t.first;
            int node = t.second;

            for (int i = 0; i<adj[node].size(); i++) {
                if (ans[adj[node][i]] > (distance + 1) ) {
                    ans[adj[node][i]] = distance + 1;
                    q.push({ans[adj[node][i]], adj[node][i]});
                }
            }

        }

        return ans[n-1];
    }

    int bfs(vector<int> adj[], int n) {
        queue<int> q;
        vector<int> v =  vector<int>(n, INT_MAX);

        q.push(0);
        v[0] = 0;
        int count = 0;

        while (q.size() != 0) {
            int l = q.size();

            for (int i = 0; i<l; i++) {
                int t = q.front();
                q.pop();

                // cout << "\nPoP " << t;

                if (t==n-1) {
                    return count;
                }

                for (int j = 0; j<adj[t].size(); j++) {
                    if (v[adj[t][j]] == INT_MAX) {
                        q.push(adj[t][j]);
                        v[adj[t][j]] = count+1;
                        // cout << "\nPush " << adj[t][j];
                    }
                }
            }
            count++;
        }

        return -1;
    }


public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int> adj[n];
        vector<int>  ans;
        for (int i = 0; i<n-1; i++) adj[i].push_back(i+1);

        for (int i = 0; i<q.size(); i++) {
            adj[q[i][0]].push_back(q[i][1]);
            // cout << "\n\n";
            // ans.push_back(dk(adj, n));
            ans.push_back(bfs(adj, n));
        }

        return ans;
    }
};