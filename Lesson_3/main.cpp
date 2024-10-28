#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

int main() {
    const int num_experiments = 1000;  // Number of experiments
    const int num_balls = 32749;       // Number of balls
    const int num_bins = 32749;        // Number of bins

    std::vector<int> max_balls_per_bin(num_experiments);
    std::vector<double> avg_balls_per_bin(num_experiments);

    // Seed for random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Run multiple experiments
    for (int exp = 0; exp < num_experiments; ++exp) {
        std::vector<int> bins(num_bins, 0);  // Initialize bins

        // Randomly assign balls to bins
        for (int i = 0; i < num_balls; ++i) {
            int bin_index = std::rand() % num_bins;
            bins[bin_index]++;
        }

        // Find the max and average number of balls in bins
        int max_balls = *std::max_element(bins.begin(), bins.end());
        double avg_balls = std::accumulate(bins.begin(), bins.end(), 0.0) / num_bins;

        max_balls_per_bin[exp] = max_balls;
        avg_balls_per_bin[exp] = avg_balls;
    }

    // Calculate overall average max balls per bin
    double avg_max_balls = std::accumulate(max_balls_per_bin.begin(), max_balls_per_bin.end(), 0.0) / num_experiments;
    double avg_of_avg_balls = std::accumulate(avg_balls_per_bin.begin(), avg_balls_per_bin.end(), 0.0) / num_experiments;

    // Output the results
    std::cout << "Gennemsnitligt maksimalt antal bolde i en beholder: " << avg_max_balls << std::endl;
    std::cout << "Gennemsnitligt antal bolde pr. beholder: " << avg_of_avg_balls << std::endl;

    return 0;
}
