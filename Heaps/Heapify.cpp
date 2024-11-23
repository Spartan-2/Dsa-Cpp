#include<iostream>
#include<vector>

using namespace std;

void heapifyMAX(vector<int> &arr,int i,int size){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

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


void heapifyMIN(vector<int> &arr,int i,int size){

    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }


    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapifyMIN(arr,smallest,size);
    }

}


int main(){

    vector<int> arr = {0,3,4,1,9,2,5,7};
    int i = arr.size()/2;
    int size = arr.size();

    for(int j=i;i>0;i--){
        heapifyMIN(arr,i,size);
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;

    // for(int j=i;i>0;i--){
    //     heapifyMIN(arr,i,size);
    // }
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    return 0;
}