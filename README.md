For part 2, we decided to design an API for an Array. We chose to add methods 
that are common in Array/List/ArrayList implementations in other languages:

    void push(Object* item)
    Object* pop()
    Object* get(int index)
    void addFront(Object* item)
    Object* removeFront()
    Object* set(Object* item, int index)
    void insert(Object* item, int index)
    Object* remove(int index)
    int length()
    int contains(Object* item)
    int indexOf(Object* item)
    
All of the methods we chose to implement are self explanatory in name. 
Tests were written for every method, except for get() and length(), due 
to those methods being used in most other tests for validation. 