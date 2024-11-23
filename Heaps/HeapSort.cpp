#include<iostream>
#include<vector>

using namespace std;


void heapifyMAX(vector<int> &arr,int i,int size){


    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapifyMAX(arr,largest,size);
    }

}

void heapSort(vector<int> &arr,int size){

    if(size < 1){
        return;
    }
    swap(arr[size -1],arr[0]);
    size --;

    heapifyMAX(arr,0,size);
    heapSort(arr,size);
}


int main(){
    vector<int> arr = {23,67,4,1,46,24};
    int size = arr.size();

    for(int i=size-1/2;i>=0;i--){
        heapifyMAX(arr,i,size);
    }

    heapSort(arr,size);

    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}