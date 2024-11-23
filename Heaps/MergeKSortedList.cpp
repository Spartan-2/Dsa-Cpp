// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Leetcode 23


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class comapre{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return  a->val > b->val;
        }
};

ListNode* mergeList(vector<ListNode*> list){
    priority_queue<ListNode*,vector<ListNode*>,comapre> pq;

    for(auto it:list){
        if(it){
            pq.push(it);
        }
    }

    ListNode* head = new ListNode();
    ListNode* tail = head;


    while(!pq.empty()){
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;

        if(node->next){
            pq.push(node->next);
        }
        
    }

    return head->next;
}

int main(){
    vector<ListNode*> arr;
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(4);
    node1->next = new ListNode(5);

    arr.push_back(node1);

    ListNode* node2 = new ListNode(1);
    node1->next = new ListNode(3);
    node1->next = new ListNode(4);
    arr.push_back(node2);

    ListNode* node3 = new ListNode(2);
    node1->next = new ListNode(6);
    arr.push_back(node3);

    ListNode* ans = mergeList(arr);

    while(ans != nullptr){
        cout<<ans->val<<" ";
    }
    return 0;
}

