#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossSum = maxCrossingSum(arr, low, mid, high);

    return max(leftSum, rightSum, crossSum);
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, 0, n - 1);
    cout << "Maximum subarray sum is: " << maxSum << endl;
    return 0;
}
