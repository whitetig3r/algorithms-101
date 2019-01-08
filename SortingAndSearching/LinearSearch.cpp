#include <iostream>

using namespace std;

// function to perform the linear search
int linearSearch(int search, int myInputArray[], int n){
    for (int i=0;i<n;i++){
        if (myInputArray[i] == search)
        {
            return i; //return the index
        }
    }
    return -1; //return -1 if not found
}

int main(){
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int myInputArray[n];
    cout<<"Enter "<<n<<" integers:"<<endl;
    for(int i=0; i<n;i++){
        cin>>myInputArray[i];
    }
    int search;
    cout<<"Enter element to search:"<<endl;
    cin>>search;
    int result = linearSearch(search, myInputArray, n); //store index of queried element in an integer variable
    if(result != -1){
        cout << "Found Element: " << search << " at index: "<<result+1<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}