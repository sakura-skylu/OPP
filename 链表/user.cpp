#include <iostream>
#include "List.hpp"
using namespace std;

void printfBySubscript(List& list){
    size_t count=list.size();
    for(size_t i=0;i<count;i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

void printfData(t_appdata&v){
    cout<<v<<" ";
}

void printfByIterator(List& list){
    Iterator itr=list.begin();
    Iterator end=list.end();
    for(;itr!=end;++itr){
        printfData(*itr);
    }
    cout << endl;
}

void printfByForLoop(List& list){
    for( t_appdata& v:list){
        printfData(v);
    }
    cout <<endl;
}

int main(){
    List L;
    L.append(1).append(2).prepend(3);

    printfBySubscript(L);//基于下标
    printfByIterator (L);//基于迭代器
    printfByForLoop  (L);//基于循环

    return 0;
}