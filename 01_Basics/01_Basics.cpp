#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 1. Print dynamic array
void PrintDynamicArray(vector<int> arr) {
    string out = "(";

    for (int i = 0; i < arr.size(); i++)
        out += to_string(arr[i]) + ", ";

    if (!arr.empty()) out.erase(out.length() - 2, 2);
    out += ")\n";

    std::cout << out;
}

// 2. Fibonacci Sequence
vector<int> Fibonacci(unsigned int amount) {

    vector<int> out = { 1, 1 };

    if (amount == 0)
        return {};
    if (amount == 1)
        return { 1 };

    for (int i = 0; i < amount - 2; i++)
        out.push_back(out.end()[-1] + out.end()[-2]);

    return out;
}

// 3. Calculate Maximum
int Maximum(std::vector<int> numbers) {
    if(numbers.empty()) return INT_MIN;
    else return *max_element(numbers.begin(), numbers.end());
}

// 4. Analyze data

struct Results {
    float mean, median, variance, standardDeviation, min, max;
};

Results AnalyzeData(std::vector<float> data) {
    Results out;
    int data_size = data.size();
    if (data_size == 0) {
        return {};
    }

    sort(data.begin(), data.end());

    // mean
    out.mean = accumulate(data.begin(), data.end(), 0.0) / data_size;

    // median
    if (data_size % 2 == 1)
        out.median = data[data_size / 2 + 1];
    else
        out.median = (data[data_size / 2 - 1] + data[data_size / 2]) / 2;

    // variance
    float data_mean = out.mean;
    auto sigma = [&data_mean, &data_size](float a, const float b) {
        return a + ((b - data_mean) * (b - data_mean) / data_size);
        };

    out.variance = accumulate(data.begin(), data.end(), 0.0, sigma);

    // standardDeviation
    out.standardDeviation = sqrt(out.variance);

    // min
    out.min = data[0];

    // max
    out.max = data.end()[-1];

    return out;
}

ostream& operator<<(ostream& os, const Results& results) {
    return os   << "Mean: " << results.mean << endl
                << "Median: " << results.median << endl
                << "Variance: " << results.variance << endl
                << "standardDeviation: " << results.standardDeviation << endl
                << "min: " << results.min << endl
                << "max: " << results.max << endl;
}

int main(){

    // Test PrintDynamicArray & Fibonacci Sequence
    PrintDynamicArray(Fibonacci(0));
    PrintDynamicArray(Fibonacci(1));
    PrintDynamicArray(Fibonacci(2));
    PrintDynamicArray(Fibonacci(3));
    PrintDynamicArray(Fibonacci(5));
    PrintDynamicArray(Fibonacci(10));

    cout << endl;

    // Maximum
    cout << to_string(Maximum({})) << endl;
    cout << to_string(Maximum(Fibonacci(5))) << endl;
    cout << to_string(Maximum({1, 2, 8, 7, 6, 2, 3,})) << endl;

    cout << endl;

    // AnalyzeData
    cout << AnalyzeData({1.0, 2.0, 3.0, 4.0, 5.0}) << endl;
    cout << AnalyzeData({0.0, 1.0, 2.0, 3.0, 4.0, 5.0}) << endl;
    cout << AnalyzeData({2.0, 8.0, 6.0, 4.0}) << endl;
    cout << AnalyzeData({}) << endl;

    return 0;

}