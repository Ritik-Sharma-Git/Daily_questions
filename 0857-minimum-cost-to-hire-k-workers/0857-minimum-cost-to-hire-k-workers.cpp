class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int numWorkers = quality.size();
        vector<pair<double, int>> workerRatios(numWorkers); // This will contain wage/quality ratio and quality.
      
        // Generate wage to quality ratios for all workers and store them with the quality.
        for (int i = 0; i < numWorkers; ++i) {
            workerRatios[i] = {(double) wage[i] / quality[i], quality[i]};
        }
      
        // Sort the workers based on their wage/quality ratio. Lower ratio means more cost-effective.
        sort(workerRatios.begin(), workerRatios.end());
      
        priority_queue<int> qualityMaxHeap; // Max heap to maintain the top k largest qualities.
        double minCost = 1e9; // Initialize minimum cost with an high value.
        int totalQuality = 0; // Total quality of the hired workers.
      
        // Loop through the sorted worker ratios
        for (auto& [ratio, workerQuality] : workerRatios) {
            totalQuality += workerQuality; // Add current worker's quality to the total quality.
            qualityMaxHeap.push(workerQuality); // Add current worker's quality to max heap.
          
            // Once we have a group of k workers.
            if (qualityMaxHeap.size() == k) {
                // Calculate the cost of hiring the current group and update minimum cost if necessary.
                minCost = min(minCost, totalQuality * ratio);
                // Remove the worker with the highest quality as we want to try for a more cost-effective group next.
                totalQuality -= qualityMaxHeap.top();
                qualityMaxHeap.pop();
            }
        }
        // Return the minimum cost found for hiring k workers.
        return minCost;
        
    }
};