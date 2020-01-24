#include "array.h"

void FAIL() {   exit(1);    }
void OK(const char* m) { std::cout << m; }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

/**
 * Utility class to make debugging easier
 */
class TestObject : public Object {
    public:
        int index;
        
        TestObject(int i) {
            index = i;
        }

        void hash_me() {
            hash_ = index;
        }

        bool equals(Object* other) { 
            return this->hash_ == other->hash_; 
        }       
};

void testPush() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    t_true(arr->length() == 2);
}

void testPop() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    t_true(arr->length() == 2);
    arr->pop();
    t_true(arr->get(0)->equals(object1));
    t_true(arr->length() == 1);
}

void testAddFront() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new  TestObject(2);
    TestObject* object3 = new TestObject(3);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    arr->addFront(object3);
    t_true(arr->length() == 3);
    t_true(arr->get(0)->equals(object3));
}

void testRemoveFront() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    arr->removeFront();
    t_true(arr->length() == 1);
    t_true(arr->get(0)->equals(object2));
}

void testSet() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    TestObject* object3 = new TestObject(3);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    arr->set(object3, 0);
    t_true(arr->length() == 2);
    t_true(arr->get(0)->equals(object3));
    t_true(arr->get(1)->equals(object2));
}

void testInsert() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    TestObject* object3 = new TestObject(3);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    arr->insert(object3, 1);
    t_true(arr->length() == 3);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object3));
    t_true(arr->get(2)->equals(object2));
}

void testRemove() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    TestObject* object3 = new TestObject(3);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    arr->push(object3);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    t_true(arr->get(2)->equals(object3));
    t_true(arr->length() == 3);
    arr->remove(1);
    t_true(arr->length() == 2);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object3));
}

void testContainsAndIndexOf() { 
    TestObject* object1 = new TestObject(1);
    TestObject* object2 = new TestObject(2);
    TestObject* object3 = new TestObject(3);
    TestObject* object4 = new TestObject(4);
    Array * arr = new Array();
    arr->push(object1);
    arr->push(object2);
    arr->push(object3);
    t_true(arr->get(0)->equals(object1));
    t_true(arr->get(1)->equals(object2));
    t_true(arr->get(2)->equals(object3));
    t_true(arr->contains(object1));
    t_true(arr->contains(object2));
    t_true(arr->contains(object3));
    t_false(arr->contains(object4));
    t_true(arr->indexOf(object1) == 0);
    t_true(arr->indexOf(object2) == 1);
    t_true(arr->indexOf(object3) == 2);
}

int main() {
    testPush();
    testPop(); 
    testAddFront();
    testRemoveFront();
    testSet();
    testInsert();
    testRemove();
    testContainsAndIndexOf();
    return 0;
}