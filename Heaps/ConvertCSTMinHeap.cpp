#include<iostream>
#include<vector>

using namespace std;

void convertMinHeap(vector<int> &CBT,int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int size = CBT.size();

    if(left < size && CBT[left] < CBT[smallest]){
        smallest = left;
    }
    if(right < size && CBT[right] < CBT[smallest]){

    }
        if(left < size && right < size && CBT[left] > CBT[right]){
        swap(CBT[left],CBT[right]);
    }
    if(smallest != i){
        swap(CBT[smallest],CBT[i]);
        convertMinHeap(CBT,smallest);
    }
}


int main(){

    vector<int> arr = {0,3,4,1,9,2,5,7};
    int i = arr.size()/2;
    int size = arr.size();

    for(int j=i;i>0;i--){
        convertMinHeap(arr,i);
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