#include"List.hpp"
#include<iostream>
using t_appdata=int;

class Node{
  private:
    Node(const t_appdata&) =delete;
    Node& operator=(const t_appdata&) =delete;
    friend class List;
    friend class Iterator;//友元
  public:
   t_appdata data;
   Node *prev;
   Node *next;
   Node(t_appdata x,Node* p,Node* n):data(x),prev(p),next(n){}
   ~Node(){ }
};

void List::clear(){//需要引入List.hpp
  Node *node=head;
  while(head!=nullptr){
    head=node->next;
    delete node;
    node=head;
  }
  count = 0;
  head=tail=nullptr;
}

t_appdata& List::operator[](size_t index)const{//返回类型需要和.hpp一致
    Node* node=head;
    for(size_t i=1;i<=index;i++){
       node=node->next;
    }
    return node->data;
}

t_appdata& Iterator::operator*() const{
    return currentNode->data;//返回引用，可以直接修改 
}

t_appdata* Iterator::operator->() const{
    return &(currentNode->data);
}

Iterator& Iterator::operator++(){
    if(currentNode!=nullptr){
        currentNode=currentNode->next;
    }
    return *this;//先递增再返回
}

Iterator Iterator::operator++(int){
    Iterator old=*this;//可以old = currentNode 后缀需要返回完整的迭代器
    ++(*this);
    return old;//先返回再递增
}

Iterator& Iterator::operator--(){
    if(currentNode==nullptr||currentNode->prev==nullptr){
        throw std::out_of_range("wrong");
    }
    currentNode=currentNode->prev;
    return *this;
}

Iterator Iterator::operator--(int){
    Iterator old=*this;
    --(*this);
    return old;
}

List& List::prepend(t_appdata x){//头插
    Node* newNode=new Node(x,nullptr,head);
    if(head!=nullptr){
        head->prev=newNode;
    }else{
        tail= newNode;
    }

    head=newNode;
    ++count;
    return *this;
}

List& List::append(t_appdata x){//尾插
    Node* newNode=new Node(x,tail,nullptr);
    if(tail!=nullptr){
        tail->next=newNode;
    }else{
        head=newNode;
    }
    tail=newNode;
    ++count;
    return *this;
}

Iterator List::begin(){
    return Iterator(head);
}

Iterator List::end(){
    return Iterator(nullptr);
}