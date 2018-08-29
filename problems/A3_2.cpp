#include "stdafx.h"

#include <algorithm>
#include <iostream>

using namespace std;

// returns maximum in arr[] of size n
int largest(int arr[], int n)
{
	return *max_element(arr, arr + n);
}

int smallest(int arr[], int n)
{
	return *min_element(arr, arr + n);
}

int getClosest(int val1, int val2, int target)
{
	if(target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}

// Returns element closest to target in arr[]
int findClosest(int arr[], int n, int target)
{
	// Corner cases
	if(target <= arr[0])
		return arr[0];
	if(target >= arr[n - 1])
		return arr[n - 1];

	// Doing binary search
	int i = 0, j = n, mid = 0;
	while(i < j) {
		mid = (i + j) / 2;

		if(arr[mid] == target)
			return arr[mid];

		/* If target is less than array element,
			then search in left */
		if(target < arr[mid]) {

			// If target is greater than previous
			// to mid, return closest of two
			if(mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
								  arr[mid], target);

			/* Repeat for left half */
			j = mid;
		}

		// If target is greater than mid
		else {
			if(mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
								  arr[mid + 1], target);
			// update i
			i = mid + 1;
		}
	}

	// Only single element left after search
	return arr[mid];
}

int main()
{
	int arr[] = {4, 6, 7, 3, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n);
	int x = smallest(arr, n);
	int z = largest(arr, n);
	int y = findClosest(arr, n, (x + z) / 2.0f);

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;

	cout << "max(|y-x| + |z-y|) = " << abs(y - x) + abs(z - y) << endl;

	cin.get();

	return 0;
}
