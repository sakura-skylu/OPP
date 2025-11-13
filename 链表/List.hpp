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
    t_appdata operator[](size_t index) const;
    Iterator begin();
    Iterator end();
};