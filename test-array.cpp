#include "array.h"
#include "string.h"
#include <iostream>
#include <stddef.h>

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

        bool equals(Object* other) { 
            TestObject* o = dynamic_cast<TestObject*>(other);
            return s != nullptr && this->index == o->index;
        }

        size_t hash() {
            return index;
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
    delete object1, object2, arr;
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
    delete object1, object2, arr;
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
    delete object1, object2, object3, arr;
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
    delete object1, object2, arr;
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
    delete object1, object2, object3, arr;
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
    delete object1, object2, object3, arr;
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
    delete object1, object2, object3, arr;
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
    delete object1, object2, object3, object4, arr;
}

void testStringPush() { 
    String* str1 = new String("hi");
    String* str2 = new String("there");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    t_true(arr->length() == 2);
    delete str1, str2, arr;
}

void testStringPop() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    t_true(arr->length() == 2);
    arr->pop();
    t_true(arr->get(0)->equals(str1));
    t_true(arr->length() == 1);
    delete str1, str2, arr;
}

void testAddStringFront() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    String* str3 = new String("test");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    arr->addFront(str3);
    t_true(arr->length() == 3);
    t_true(arr->get(0)->equals(str3));
    delete str1, str2, str3, arr;
}

void testRemoveStringFront() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    arr->removeFront();
    t_true(arr->length() == 1);
    t_true(arr->get(0)->equals(str2));
    delete str1, str2, arr;
}

void testStringSet() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    String* str3 = new String("test");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    arr->insert(str3, 1);
    t_true(arr->length() == 3);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str3));
    t_true(arr->get(2)->equals(str2));
    delete str1, str2, str3, arr;
}

void testStringInsert() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    String* str3 = new String("test");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    arr->set(str3, 0);
    t_true(arr->length() == 2);
    t_true(arr->get(0)->equals(str3));
    t_true(arr->get(1)->equals(str2));
    delete str1, str2, str3, arr;
}

void testStringRemove() {
    String* str1 = new String("hi");
    String* str2 = new String("there");
    String* str3 = new String("test");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    arr->push(str3);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    t_true(arr->get(2)->equals(str3));
    t_true(arr->length() == 3);
    arr->remove(1);
    t_true(arr->length() == 2);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str3));
    delete str1, str2, str3, arr;
}

void testStringContainsAndIndexOf() { 
    String* str1 = new String("hi");
    String* str2 = new String("there");
    String* str3 = new String("test");
    String* str4 = new String("wow");
    Array * arr = new Array();
    arr->push(str1);
    arr->push(str2);
    arr->push(str3);
    t_true(arr->get(0)->equals(str1));
    t_true(arr->get(1)->equals(str2));
    t_true(arr->get(2)->equals(str3));
    t_true(arr->contains(str1));
    t_true(arr->contains(str2));
    t_true(arr->contains(str3));
    t_false(arr->contains(str4));
    t_true(arr->indexOf(str1) == 0);
    t_true(arr->indexOf(str2) == 1);
    t_true(arr->indexOf(str3) == 2);
    delete str1, str2, str3, str4, arr;
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
    testStringPush();
    testStringPop();
    testAddStringFront();
    testRemoveStringFront();
    testStringSet();
    testStringInsert();
    testStringRemove();
    testStringContainsAndIndexOf();
    return 0;
}
