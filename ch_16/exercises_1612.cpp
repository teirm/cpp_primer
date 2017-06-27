/* Some of the exercises from 16.1.2 */

template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List();
    List(const List&);
    List& operator=(const List&);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front; // Can't use template scope applied to class List
    ListItem<elemType> *back;
};


