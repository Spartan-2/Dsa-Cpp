#include<iostream>
#include<vector>

using namespace std;

int deletion(vector<int> &heap){

    int size = heap.size();

    if( size == 1){
        return -1;
    }

    int index = size - 1;
    int popped = heap[1];
    heap[1] = heap[index];
    heap.pop_back();
    int i = 1;

    while(i < index){
        int left = 2*i;
        int right = 2*i + 1;

        if(left < index && heap[left] > heap[i]){
            swap(heap[i],heap[left]);
            i = left;
        }else if(right < index && heap[right] > heap[i]){
            swap(heap[i],heap[right]);
            i = right;
        }else{
            return popped;
        }
    }
    return popped;
}

int main(){
    vector<int> heap(1,0);
    heap.push_back(60);
    heap.push_back(50);
    heap.push_back(40);
    heap.push_back(20);
    heap.push_back(30);

    int popped = deletion(heap);
    cout<<"Element popped "<<popped<<"\t";
    popped = deletion(heap);
    cout<<"Element popped "<<popped<<endl;

    for(auto it: heap){
        cout<<it<<"\t";
    }
    return 0;
}