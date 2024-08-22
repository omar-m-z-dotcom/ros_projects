#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function prototypes for calculating square and cube
void calculateSquare(int n);
void calculateCube(int n);

// Modified Calculate function to use function pointers
void Calculate(const std::array<int, 5> &arr_num,
               void (*calculateSquare)(int),
               void (*calculateCube)(int))
{
    for (int num : arr_num)
    {
        if (num % 2 == 0)
        {
            calculateSquare(num);
        }
        else
        {
            calculateCube(num);
        }
    }
}

// Function definitions
void calculateSquare(int n)
{
    std::cout << "Square of " << n << " is " << n * n << std::endl;
}

void calculateCube(int n)
{
    std::cout << "Cube of " << n << " is " << n * n * n << std::endl;
}

int main()
{
    // 1. Sort an Array in Ascending and Descending Order
    std::vector<int> arr = {5, 9, 3, 7, 1};

    // Sort in ascending order
    std::sort(arr.begin(), arr.end());
    std::cout << "Ascending order: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort in descending order
    std::sort(arr.begin(), arr.end(), [](int a, int b)
              { return a > b; });
    std::cout << "Descending order: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 2. Multiply Each Element in an Array by 2
    std::vector<int> arr2 = {100, 1, 2, 50, 17};

    // Multiply each element by 2
    std::for_each(arr2.begin(), arr2.end(), [](int &n)
                  { n *= 2; });

    // Print the modified array
    std::cout << "Array after multiplying by 2: ";
    for (const int &num : arr2)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int x = 5, y = 10;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    std::array<int, 5> arr_num = {1, 2, 17, 50, 100};

    // Call Calculate with function pointers
    Calculate(arr_num, calculateSquare, calculateCube);
}
