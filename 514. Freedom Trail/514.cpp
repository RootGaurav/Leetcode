class Solution {
public:
    using VI = vector<int>;
    int findRotateSteps(string ring, string key, int INF = 1e9 + 7) {
        int M = ring.size(),
            N = key.size();
        auto steps = [=](auto i, auto k) {
            return min(abs(i - k), M - abs(i - k)); // ⭐️ minimum of steps to rotate the ring from i..k (🚫 without wrap-around, ✅ with wrap-around)
        };
        VI pre(M); // 🤔 memo + 🛑 base case (ie. pre is default initialized to contain all 0s)
        for (auto j{ N - 1 }; 0 <= j; --j) {  // key j
            VI cur(M, INF);
            for (auto i{ 0 }; i < M; ++i)     // cur i
                for (auto k{ 0 }; k < M; ++k) // pre i (optimal k-th value is found as the recursive stack unwinds)
                    if (ring[k] == key[j])
                        cur[i] = min(cur[i], 1 + steps(i, k) + pre[k]); // 🎯 min steps to reach key[j] from each ring[i] is the min steps to reach key[j + 1] from ring[k], 🔍 find optimal k via exhaustive search
            swap(pre, cur);
        }
        return pre[0]; // 🚀 when the ring starts at i = 0 (ie. index 0 is aligned with the 12:00 direction of the ring) return the min steps to construct key[j = 0..N - 1]
    }
};