class Solution {
    unordered_map<string, unordered_map<string, double>> graph;

    bool dfs(string curr, string target, unordered_set<string>& visited,
             double& result, double product) {
        if (curr == target) {
            result = product;
            return true;
        }
        visited.insert(curr);
        for (auto& neighbor : graph[curr]) {
            if (!visited.count(neighbor.first)) {
                if (dfs(neighbor.first, target, visited, result,
                        product * neighbor.second)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0], B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0 / val;
        }

        vector<double> results;

        for (auto& q : queries) {
            string src = q[0], dest = q[1];

            if (!graph.count(src) || !graph.count(dest)) {
                results.push_back(-1.0);
            } else if (src == dest) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = -1.0;
                dfs(src, dest, visited, result, 1.0);
                results.push_back(result);
            }
        }

        return results;
    }
};
