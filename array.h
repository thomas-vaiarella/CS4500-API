#pragma once

#include "object.h"

//TODO_TREVOR Should the `Object`s be pointers or just normal? 
class Array : public Object {
    public:
        Array() { }

        /**
         * Adds an item to the end of an array
         * @param item Object that will be added to an array
         */
        void push(Object* item) { }

        /**
         * Removes the last item of an array
         * @return the removed item
         */
        Object* pop() { }

        /**
         * Gets the array's element at index
         * @param index The index at which the item will be retreived from
         * @return The object residing at the index
         */
        Object* get(size_t index) { }

        /**
         * Adds an item to the start of an array
         * @param item Object that will be added to an array
         */
        void addFront(Object* item) { }

        /**
         * Removes the first item of an array
         * @return The removed item
         */
        Object* removeFront() { }

        /**
         * Sets the array's element at index to the item
         * @param item The item to be inserted
         * @param index The index at which the item will be inserted
         * @return The object that was replaced
         */
        Object* set(Object* item, size_t index) { }

        /**
         * Inserts the element at the given index
         * @param item The item to be inserted
         * @param index The index at which the item will be inserted
         */
        void insert(Object* item, size_t index) { }

        /**
         * Removes the element at the given index
         * @param index The index at which the item will be removed
         * @return The object that was removed
         */
        Object* remove(size_t index) { }

        /**
         * Returns the length of the array
         * @return length of the array
         */
        size_t length() { }

        /**
         * Returns if the array contains the item
         * @return 1 if contains item, 0 otherwise
         */
        size_t contains(Object* item) { }

        /**
         * Returns the index of the item
         * @return index of the item. -1 if it does not contain the item
         */
        size_t indexOf(Object* item) { }
};