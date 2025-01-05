#include <iostream>
#include <algorithm> // For std::max_element, std::accumulate, std::sort
#include <numeric>   // For std::accumulate

int main() {
    int N;

    // Taking input for size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> N;

    // Create a dynamic array of pointers
    int* arr[N];

    // Taking input for elements of the array
    std::cout << "Enter " << N << " elements:" << std::endl;
    for (int i = 0; i < N; ++i) {
        arr[i] = new int; // Allocate memory for each element
        std::cin >> *arr[i]; // Store input in allocated memory
    }

    // Finding the maximum element using std::max_element
    int** maxPtr = std::max_element(arr, arr + N, [](int* a, int* b) {
        return *a < *b;
    });

    // Calculating the sum of all elements using std::accumulate
    int sum = std::accumulate(arr, arr + N, 0, [](int total, int* value) {
        return total + *value;
    });

    // Sorting the array using std::sort
    std::sort(arr, arr + N, [](int* a, int* b) {
        return *a < *b;
    });

    // Outputting results
    std::cout << "Maximum element: " << **maxPtr << std::endl;
    std::cout << "Sum of all elements: " << sum << std::endl;

    std::cout << "Sorted elements: ";
    for (int i = 0; i < N; ++i) {
        std::cout << *arr[i] << " ";
        delete arr[i]; // Free allocated memory
    }
    std::cout << std::endl;

    return 0;
}















#include <iostream>
#include <set>
#include <vector>

int main() {
    // Example vector with some numbers (including duplicates)
    std::vector<long long> numbers = {1, 2, 3, 2, 1, 4, 5, 4};

    // Create a set to store distinct numbers
    std::set<long long> distinctNumbers;

    // Insert numbers into the set
    for (long long number : numbers) {
        distinctNumbers.insert(number);
    }

    // The size of the set gives the number of distinct numbers
    std::cout << "Number of distinct numbers: " << distinctNumbers.size() << std::endl;

    return 0;
}
















#include <iostream>
#include <unordered_map>

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::unordered_map<int, int> frequency;
    for (int i = 0; i < size; ++i) {
        frequency[arr[i]]++;
    }

    int count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            count++;
        }
    }

    std::cout << "Quantity of numbers that have been repeated more than once: " << count << std::endl;

    delete[] arr;
    return 0;
}










#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long t;
    cin >> t;
    while (t--) {
        long long n, c, d;
        cin >> n >> c >> d;

        vector<long long> a(n);
        for (long long p = 0; p < n; p++) {
            cin >> a[p];
        }

        sort(a.rbegin(), a.rend());

        vector<long long> cs(n + 1, 0);
        for (long long p = 1; p <= n; p++) {
            cs[p] = cs[p - 1] + a[p - 1];
        }

        if (d * a[0] < c) {
            cout << "Impossible" << endl;
            continue;
        }
        if (c <= cs[d < n ? d : n]) {
            cout << "Infinity" << endl;
            continue;
        }

        long long res = 0, left = 1, right = d;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long stopA = (mid <= n) ? mid : n;
            long long stopB = (d % mid <= n) ? (d % mid) : n;
            long long sum = (d / mid) * cs[stopA] + cs[stopB];
            if (c <= sum) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << res - 1 << endl;
    }

    return 0;
}