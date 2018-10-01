//
// Created by aknight on 9/26/18.
//

#ifndef LINKEDLISTS_LIST_H
#define LINKEDLISTS_LIST_H

namespace edu { namespace sbcc { namespace cs140 {
    template<class T>
    class LinkedList {
    private:
        struct Node {
            Node(T &data) : _data(data) {}
            Node* _next;
            T &_data;
        };
    public:
        class iterator {
        public:
            iterator(Node<T> *node): _node(node) {}
        public:
            T &operator*(): { return *node._data;}
            const T &operator() const { return *node._data; }
            T &operator++() { node = _data->next; return *this; }
            T &operator++(int) { Node<T> *before = node; node = node->next; *before; }

        private:
            Node<T> *node;
        };

    public:
        LinkedList();
        LinkedList(const T &other);
        LinkedList(iterator begin, iterator end);

        ~LinkedList();

    public:
        bool empty() const;
        T &front();
        const T &front() const;
        T &back();
        const T &back() const;
        size_t size() const;

    public:
        iterator begin();
        const iterator cbegin();
        iterator end();
        const iterator cend();

    public:
        void clear();
        iterator insert(iterator where, const T &value);
        iterator erase(iterator where);
        iterator erase(iterator first, iterator last);
        iterator push_back(const T &value);
        iterator pop_back();
        iterator push_front(const T &value);
        iterator pop_front();

    public:
        void swap(list &other);

    private:
        Node *head;
        Node *tail;
        size_t size;
    };
}}}
#endif //LINKEDLISTS_LIST_H
