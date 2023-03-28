// Easy Bogosort
// Riley Knybel

// It would be easier to learn algorithms like this.

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>

// could be a void with a pointer argument but I am lazy
std::vector<int> bogosort(std::vector<int> unsorted_list) {
    std::random_device rd;     // initialize engine
    std::mt19937 rng(rd());    //Mersenne-Twister rng algorithm

    while (!std::is_sorted(unsorted_list.begin(), unsorted_list.end())) // sorted() in paper
        std::shuffle(std::begin(unsorted_list), std::end(unsorted_list), rng); //applyRandomAction() in paper

    return unsorted_list;
}

int main()
{
    int num_it = 10; //number of iterations
    for (int i = 0; i < num_it; i++) {

        int n_max = 10;
        std::cout << "Iteration " << i << std::endl;

        for (int list_size = 1; list_size <= n_max; list_size++) {

            std::vector<int> unsorted_list(list_size);
            std::srand(unsigned(std::time(nullptr)));
            std::generate(unsorted_list.begin(), unsorted_list.end(), std::rand);

            auto t1 = std::chrono::high_resolution_clock::now();

            std::vector<int> sorted_list = bogosort(unsorted_list);

            auto t2 = std::chrono::high_resolution_clock::now();
            auto us_int = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
            std::cout << list_size << ", " << (long long)us_int.count() << std::endl;
        }
        std::cout << std::endl;
    }
}
