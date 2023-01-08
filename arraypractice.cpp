#include <bits/stdc++.h>
using namespace std;

bool search(int arr[],int n,int key){
    int l = 0 ,r = n-1;
    while (l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==key){
            return 1;
        }else if(arr[mid]>key){
             r=mid-1;
        }else if(arr[mid]<key){
             l=mid+1;
        }
    }
    return 0;
}
void commonelement(int arr1[] , int arr2[],int arr3[],int n1, int n2, int n3){
    int temp[10];
    int c =0;
    sort(arr1,arr1+n1);
    sort(arr2,arr2+n2);
    sort(arr3,arr3+n3);
    for (int i = 0; i < n1; i++){
        if(search(arr2,n2,arr1[i])==1){
            temp[c]=arr1[i];
            c++;
        }
    }
    int n = sizeof(temp)/sizeof(temp[0]);
    for (int i = 0; i < n; i++)
    {
        if(search(arr3,n,temp[i])!=1){
            temp[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(temp[i] >=0){
            cout << temp[i] << " ";
        }
    }
}
int main(){
    int arr1[5] = {1,10,3,4,5};
    int arr2[5] = {3,7,2,4,1};
    int arr3[5] = {2,4,1,6,7};
    commonelement(arr1,arr2,arr3,5,5,5);
} 
