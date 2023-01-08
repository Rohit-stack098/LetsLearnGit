#include <iostream>
using namespace std;

int bubblesort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            int temp;
            temp = arr[i+1];
            arr[i+1]=arr[i];
            arr[i] = temp;
        }
    }
    cout<<"Your Array after sorting is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout<<endl;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    bubblesort(arr,n);
    return 0;
}