#include <iostream>
#include <algorithm>
using namespace std;

// function to perform the binary search recursively
int binarySearch(int l, int r, int myInputArray[], int search)
{
    if(r>=l){
        int mid = l + r-l/2;
        if(myInputArray[mid] == search) return mid;
        else if(myInputArray[mid]>search) return binarySearch(l,mid-1,myInputArray,search);
        else return binarySearch(mid+1,r,myInputArray,search);
    }
    return -1; //return -1 if not found
}

// function to perform the binary search iteratively
int binaryIterativeSearch(int l, int r, int myInputArray[], int search)
{
    while(r >= l){
        int mid = l + r - l / 2;
        if (myInputArray[mid] == search)
            return mid;
        else if (myInputArray[mid] > search)
            r = mid-1;
        else
            l = mid+1;
    }
    return -1; //return -1 if not found
}

int main()
{
    int n, search;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int myInputArray[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> myInputArray[i];
    }
    sort(myInputArray, myInputArray + n);
    cout<<"Sorted array is:"<<endl;
    for(int j=0;j<n;j++ ){
        cout<<myInputArray[j]<<" ";
    }
    cout <<endl<<"Enter element to search:" << endl;
    cin >> search;
    int result = binarySearch(0,n-1,myInputArray,search); //store index of queried element in an integer variable
    //int result = binaryIterativeSearch(0, n - 1, myInputArray, search);
    if (result != -1)
    {
        cout << "Found Element: " << search << " at index: " << result + 1 << " in the sorted array."<<endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }
    return 0;
}