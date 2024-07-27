#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<long long>>& adjmatrix) {
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (adjmatrix[i][k] < LLONG_MAX && adjmatrix[k][j] < LLONG_MAX) {
                        adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        vector<vector<long long>> adjmatrix(26, vector<long long>(26, LLONG_MAX));
        
        // Initialize the diagonal to zero
        for (int i = 0; i < 26; ++i) {
            adjmatrix[i][i] = 0;
        }

        // Fill in the adjacency matrix with given costs
        for (int i = 0; i < original.size(); ++i) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adjmatrix[s][t] = min(adjmatrix[s][t], (long long)cost[i]);
        }

        // Perform Floyd-Warshall algorithm
        floydWarshall(adjmatrix);

        // Calculate the minimum cost to convert source to target
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            long long conversionCost = adjmatrix[source[i] - 'a'][target[i] - 'a'];
            if (conversionCost == LLONG_MAX) {
                return -1; // Conversion not possible
            }
            ans += conversionCost;
        }

        return ans;
    }
};
