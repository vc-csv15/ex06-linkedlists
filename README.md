## Exercise: Linked List (30 Points)

The purpose of this assignment is for your to implement your first Abstract Data Type(ADT), the Linked List.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions
[here](https://github.com/vcc-csv15-fall2018/Course-Information/wiki)
to get started.

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

### Problem Description

The problem for this assignment to complete the implementation of a linked list.

Also, if templates are confusing see (this)[http://www.cplusplus.com/doc/oldtutorial/templates/] article that hopefully
explains what's going on better.

The linked list class declaration looks like the following:

```cpp
#include <cstdlib>
#include <utility>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template<class T>
    class LinkedList {
    private:
        struct Node {
            Node(T data, Node *next) : _data(data), _next(next) {}
            Node* _next;
            T _data;
        };
    public:
        class iterator {
        public:
            iterator(Node *node): _node(node) {}
            iterator(const iterator &other) : _node(other._node) {}

        public:
            const T &operator*() { return _node->_data; }
            const T &operator*() const { return _node->_data; }
            iterator &operator++() { _node = _node->_next; return *this; }
            iterator operator++(int) { iterator before(*this); _node = _node->_next; return before; }
            bool operator==(const iterator &other) { return other._node == _node; }
            bool operator!=(const iterator &other) { return !operator==(other); }
            Node *node() { return _node; }
        private:
            Node *_node;
        };

    public:
        LinkedList() {}
        LinkedList(const LinkedList &other): _size(0), head(nullptr), tail(nullptr) {}

        ~LinkedList() {}

    public:
        bool empty() const {}
        T &front() {}
        const T &front() const {}
        T &back() {}
        const T &back() const {}
        size_t size() const {}

    public:
        iterator begin() {}
        const iterator begin() const {}
        iterator end() {}
        const iterator end() const {}

    public:
        void clear() {}
        iterator insert(iterator where, const T &value) {}
        iterator erase(iterator where) {}
        iterator erase(iterator first, iterator last) {}
        void push_back(const T &value) {}
        void pop_back() {}
        void push_front(const T &value) {}
        void pop_front() {}

    public:
        void swap(LinkedList &other) {}

    private:
        Node *head;
        Node *tail;
        size_t _size;
    };
}}}}
```

Your job, should you choose to accept it, is to implement the code between the `{}` in all the functions
above that are not implemented. You can add more data members besides `head`, `tail`, and `_size`. But
that should be necessary. Also, feel free to change any of those names to something that makes more sense 
to you, but you probably don't want to change the type.

The following table describes what each function should do:

| Function name | Returns        | Input Parameters    | Description |
|---------------|----------------|---------------------|-------------------|
| LinkedList    | N/A            | none                | Default constructor. Should set `head` and `tail` to `null`, and `_size` to 0. |
| LinkedList    | N/A            | `LinkedList &other` | Copy constructor. Copies the list from one list to the one begin constructed. |
| ~LinkedList   | N/A            | none                | Destructor. Clears the list and deletes all the nodes. |
| empty         | bool           | none                | Returns true if the list is empty, false otherwise. |
| front         | T &            | none                | Returns a reference to the value at the front of the list. |
| front         | const T &      | none                | Returns a constant reference to the value at the front of the list. |
| back          | T &            | none                | Returns a reference to the value at the back of the list. |
| back          | const T &      | none                | Returns a constant reference to the value at the back of the list. |
| size          | size_t         | none                | Returns the number of nodes currently in the list. |
| begin         | iterator       | none                | Returns an iterator pointing to the first element of the list. |
| begin         | const iterator | none                | Returns a constant iterator pointing to the first element of the list. |
| end           | iterator       | none                | Returns an iterator pointing to one beyond the end of the list (NULL). |
| end           | const iterator | none                | Returns a constant iterator pointing to one beyond the end of the list (NULL). |
| clear         | none           | none                | Clears all the elements of the list and frees the memory back to the heap. |
| insert        | iterator       | iterator where, const T &value | Inserts an element to the list as the next item after the iterator `where`. 
| erase         | iterator       | iterator where      | Erases the element in the list pointed to by the node at the iterator. |
| erase         | iterator       | iterator first, iterator last | Erases all the elements in the list from the node pointed to by the first iterator to the last iterator. |
| push_back     | none           | const T &value      | Push a new node to the tail of the list. |
| pop_back      | none           | none                | Remove the last node in the linked list. This will require walking the list to the end because the list is singly linked. |
| push_front    | none           | const T &value      | Push a new node to the head of the list. |
| pop_front     | none           | none                | Remove the first node in the linked list. |
| swap          | none           | LinkedList &other   | Swaps two linked lists. This should be as simple as swapping the head, tail and size of `this` and `other`. |

### Writing the code for this Project

Writing the code for this project is very simple. Simply create the one file below
`main.cc` in CLion
and then copy the content into the files.

#### Header file

In CLion in the project explorer, right-click the `include` directory
and chose `New => C++ Header File`.

Under **Name** fill in
list. CLion will add the extension, but by default
adds the `.h` extension. You should now see the file `list.h` in
the project explorer in the `include` directory.

Properly set up the namespaces and declare the function described above in this file.

#### Implementation file

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`.

Under **Name** fill in
main, for the code you write for testing and completing the assignment.
CLion will add the extension, but by default
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

Properly set up the namespaces and implement the function described above in this file.

### Running the code for this project

Running this code should be straightforward. In the drop-down
menu in the upper right-hand corner you should see a **Run
Configuration** called `LinkedList | Debug`. Make sure this
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output
of running the program. It should look something like this:

```bash
/Users/username/githubusername/ex05-radixsort/bin/
before: {1, 4, 10, 11, 2}
after: {1, 2, 4, 10, 11}

Process finished with exit code 0
```
Success! Now you can move on to testing your code. Remember that your output might be
different, but should look similar to this.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `LinkedList_Gtest` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from RadixSortTest
[ RUN      ] RadixSortTest.BaseCase
[       OK ] RadixSortTest.BaseCase (0 ms)
[ RUN      ] RadixSortTest.LargeNumbersCheckMSV
[       OK ] RadixSortTest.LargeNumbersCheckMSV (0 ms)
[ RUN      ] RadixSortTest.LargeNumbersCheckLSV
[       OK ] RadixSortTest.LargeNumbersCheckLSV (0 ms)
[ RUN      ] RadixSortTest.NullPtrCheck
[       OK ] RadixSortTest.NullPtrCheck (1 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 4 tests from RadixSortTest (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.

Process finished with exit code 0
```

Remember, red good, green bad. If your tests pass you should see green
text and your code ran fine. You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`.
Make sure only the files you want to push are selected, `main.cc` and `list.h`.
Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Leave `Run git hooks` checked. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.

Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/vcc-csv15-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
