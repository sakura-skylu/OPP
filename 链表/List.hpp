#include<cstddef>//size_t
using t_appdata = int; //泛型设计
class Node;
class Iterator;

class List{
    private:
    Node *head,*tail;
    size_t count;
    List(const List&) =delete;//用一个 List 对象创建另一个 List 对象。
    List& operator=(const List&) = delete;

    public:
    List() :head(nullptr),tail(nullptr),count(0){}
    ~List() {clear();}
    size_t size() const{
        return count;
    }
    bool empty() const {
        return count == 0;
    }
    void clear();

    List& prepend(t_appdata x);//头
    List& append(t_appdata x);//尾
    t_appdata& operator[](size_t index) const;
    Iterator begin();
    Iterator end();
};

class Iterator{
    private:
      Node* currentNode;
      Iterator(Node* node) :currentNode(node){}//构造函数
    public:
      t_appdata& operator*() const;
      //call by reference 解引用后希望得到可修改的原始对象，而不是拷贝
      t_appdata* operator->() const;
      //operator-> 需要返回一个 指针（t_appdata*）
      //这样编译器才能继续对返回的对象使用连续的 -> 访问成员
      ~Iterator(){}

      Iterator& operator ++();//前缀
      Iterator& operator --();
      Iterator  operator ++(int);//后缀
      Iterator  operator --(int);
    
    friend class List;
    friend bool operator==(const Iterator&lhs,const Iterator&rhs);
    friend bool operator!=(const Iterator&lhs,const Iterator&rhs);
};

//inline！！！
inline bool operator == (const Iterator&lhs,const Iterator&rhs){
    return lhs.currentNode==rhs.currentNode;//内存地址是否相同
}

inline bool operator != (const Iterator&lhs,const Iterator&rhs){
    return !(lhs==rhs);
}