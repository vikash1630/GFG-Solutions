class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        unordered_map<int, int> ladder;
        unordered_map<int, int> snake;

        for (int i = 0; i < lad.size(); i += 2) {
            ladder[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            snake[sn[i]] = sn[i + 1];
        }

        vector<int> dist(N + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == N)
                return dist[curr];

            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > N)
                    break;

                // Take ladder/snake immediately
                if (ladder.find(next) != ladder.end()) {
                    next = ladder[next];
                }
                else if (snake.find(next) != snake.end()) {
                    next = snake[next];
                }

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};