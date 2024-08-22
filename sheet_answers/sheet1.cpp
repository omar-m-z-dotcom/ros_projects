#include <iostream>
#include <cmath> // for pow function
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

vector<vector<int>> getTruthTable(int nbits)
{
    int totalRows = 1 << nbits; // equivalent to 2^n
    vector<vector<int>> truth_table(totalRows, vector<int>(nbits, 0));
    for (int i = 0; i < totalRows; ++i)
    {
        for (int j = 0; j < nbits; ++j)
        {
            // Fill the truth table by directly checking if the j-th bit is set to 1 in the binary representation of i
            truth_table[i][nbits - j - 1] = (i >> j) & 1;
        }
    }
    return truth_table;
}

int main()
{
    // 1) Find a pair of elements in an array whose sum is equal to 15
    int A[] = {1, 5, 3, 6, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 15;
    // for every element at index i
    bool pairFound = false;
    for (int i = 0; i < n; i++)
    { //  for every element at index j, such that j = i + 1, check if A[i] + A[j] = 15
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == target)
            {
                cout << "Pair found: (" << A[i] << ", " << A[j] << ")" << endl;
                pairFound = true;
            }
        }
    }
    if (!pairFound)
    {
        cout << "No pair found." << endl;
    }

    // 2) Divide the array into two parts such that the absolute difference between the sum of the two parts is minimal
    int nums[] = {1, 6, 11, 5};
    n = sizeof(nums) / sizeof(nums[0]);
    // Half the sum of all elements in the array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    target = sum / 2;
    vector<vector<int>> truthTable = getTruthTable(n);
    int minDiff = INT_MAX; // initialize to maximum value
    vector<int> min_arrays;
    for (int i = 0; i < truthTable.size(); i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (truthTable[i][j] == 1)
            {
                sum1 += nums[j];
            }
            else
            {
                sum2 += nums[j];
            }
        }
        int diff = abs(sum1 - sum2);
        if (diff < minDiff)
        {
            minDiff = diff;
            min_arrays = truthTable[i];
        }
    }
    cout << "The two arrays are: ";
    for (int i = 0; i < n; i++)
    {
        if (min_arrays[i] == 1)
        {
            cout << nums[i] << " ";
        }
    }
    cout << "and ";
    for (int i = 0; i < n; i++)
    {
        if (min_arrays[i] == 0)
        {
            cout << nums[i] << " ";
        }
    }
    cout << endl;

    // 3) What is the sum of elements [0:4] and ]What is the sum of elements [2:5]
    // Initialize the array
    int B[] = {2, 5, 5, 3, 5, 2};
    n = sizeof(B) / sizeof(B[0]); // Size of the array

    // Compute prefix sums using a simple array
    int prefix[n];
    prefix[0] = B[0];
    for (int i = 1; i < n; ++i)
    {
        prefix[i] = prefix[i - 1] + B[i];
    }

    // Compute sums using prefix sums
    int sum_0_4 = prefix[4];
    int sum_2_5 = prefix[5] - prefix[1];

    // Output results
    cout << "Sum [0:4]: " << sum_0_4 << endl;
    cout << "Sum [2:5]: " << sum_2_5 << endl;

    // 4) how many times five was introduced in [1:3], find prefix_five
    vector<int> C = {2, 5, 5, 3, 5, 2};
    vector<int> prefix_five(C.size(), 0);

    prefix_five[0] = (C[0] == 5) ? 1 : 0;
    for (int i = 1; i < C.size(); i++)
    {
        prefix_five[i] = prefix_five[i - 1] + (C[i] == 5 ? 1 : 0);
    }

    int count_1_3 = prefix_five[3] - prefix_five[0];
    cout << "Number of 5s in [1:3]: " << count_1_3 << endl;

    // 5) Find the frequency of each distinct in the array
    int a[] = {3, 3, 5, 8, 9, 8, 9, 10, 17, 10, 11, 17, 10};
    n = sizeof(a) / sizeof(a[0]);

    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++)
    {
        frequency[a[i]]++;
    }

    for (auto &entry : frequency)
    {
        cout << "Element: " << entry.first << ", Frequency: " << entry.second << endl;
    }

    return 0;
}