#include<bits/stdc++.h>

struct Node{
    int key,val;
    Node *next, *prev;
    Node(int key_,int val_){
        key = key_;
        val= val_;
        next=prev=NULL;
    }
};

class LRUCache
{   
    int cap;
    Node *head,*tail;
    unordered_map<int, Node* >m;

    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertNode(Node* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }
public:
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
         int ans=-1;
        if(!m.count(key)){
            return ans;
        }
        ans = m[key]->val;
        deleteNode(m[key]);
        insertNode(m[key]);
        return ans;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.count(key)){
            auto it=m[key];
            deleteNode(it);
            it->val = value;
            insertNode(it);
        }
        else{
            if(m.size()==cap){
                m[key] = new Node(key,value);
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
                insertNode(m[key]);
            }
            else{
                m[key] = new Node(key,value);
                insertNode(m[key]);
            }
        }
    }
};
