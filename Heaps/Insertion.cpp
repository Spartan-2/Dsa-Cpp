#include<iostream>
#include<vector>

using namespace std;

void insertion(int val,vector<int> &heap){

    heap.push_back(val);
    int index = heap.size() - 1;

    while(index > 1){
        int parent = index / 2;
        if(heap[parent] < heap[index]){
            swap(heap[parent],heap[index]);
            index = parent;
        }else{
            break;
        }
    }
}

int main(){
    vector<int> heap(1,0);
    insertion(60,heap);
    insertion(20,heap);
    insertion(40,heap);
    insertion(50,heap);
    insertion(30,heap);

    for(auto it: heap){
        cout<<it<<"\t";
    }
    return 0;
}