#pragma once

#include "object.h"
#include <stddef.h>

class Array : public Object {
    public:

        Object** vals_;
        size_t filled_elements_;
        size_t max_elements_;

        Array() {
            filled_elements_ = 0;
            max_elements_ = 1;
            vals_ = new Object*[1];
        }

        void expand_vals_(size_t size) {
            Object** newvals_ = new Object*[size];
            for (size_t i = 0; i < max_elements_; i++) {
                newvals_[i] = vals_[i];
            }
            delete[] vals_;
            vals_ = newvals_;
            max_elements_ = size;
        }

        /** Destructor */
        virtual ~Array() {
            delete[] vals_;
        };

        /**
         * Adds an item to the end of an array
         * @param item Object that will be added to an array
         */
        void push(Object* item) { 
            if (filled_elements_ >= max_elements_) {
                expand_vals_(max_elements_ * 2);
            }
            vals_[filled_elements_++] = item;
        }

        /**
         * Removes the last item of an array
         * @return the removed item
         */
        Object* pop() {
            return this->remove(this->filled_elements_ - 1);
         }

        /**
         * Gets the array's element at index
         * @param index The index at which the item will be retreived from
         * @return The object residing at the index
         */
        Object* get(size_t index) {
            if (index >= filled_elements_) {
                return nullptr;
            }
            return vals_[index];
         }

        /**
         * Adds an item to the start of an array
         * @param item Object that will be added to an array
         */
        void addFront(Object* item) { 
            this->insert(item, 0);
        }

        /**
         * Removes the first item of an array
         * @return The removed item
         */
        Object* removeFront() { 
            return this->remove(0);
        }

        /**
         * Sets the array's element at index to the item
         * @param item The item to be inserted
         * @param index The index at which the item will be inserted
         * @return The object that was replaced
         */
        Object* set(Object* item, size_t index) { 
            if (index >= filled_elements_) {
                return nullptr;
            }
            vals_[index] = item;
            return vals_[index];
        }

        // Move all the values forward ahead of i with an offset of off
        void move(size_t i, size_t num_to_insert) {
            int position = filled_elements_ - 1 + num_to_insert;
            for (int z = 0; z < filled_elements_ - i; z++) {
                vals_[position - z] = vals_[filled_elements_ - 1 - z];
            }
        }

        /**
         * Inserts the element at the given index
         * @param item The item to be inserted
         * @param index The index at which the item will be inserted
         */
        void insert(Object* item, size_t index) { 
            if (index > max_elements_) {
                index = max_elements_;
            }
            if (filled_elements_ >= max_elements_) {
                expand_vals_(max_elements_ * 2);
            }
            move(index, 1);
            vals_[index] = item;
            filled_elements_ += 1;
        }

        /**
         * Removes the element at the given index
         * @param index The index at which the item will be removed
         * @return The object that was removed
         */
        Object* remove(size_t index) { 
            Object* obj_t = vals_[index];
            if (index >= filled_elements_) {
                return nullptr;
            }
            for (size_t z = index; z + 1 < filled_elements_; z++) {
                vals_[z] = vals_[z + 1]; 
            }
            filled_elements_ -= 1;
            return obj_t;
        }

        /**
         * Returns the length of the array
         * @return length of the array
         */
        size_t length() { 
            return this->filled_elements_;
        }

        /**
         * Returns if the array contains the item
         * @return 1 if contains item, 0 otherwise
         */
        size_t contains(Object* item) {
            return this->indexOf(item) > -1 ? 1 : 0;
        }

        /**
         * Returns the index of the item
         * @return index of the item. -1 if it does not contain the item
         */
        int indexOf(Object* item) {
            for (int i = 0 ; i < filled_elements_; i++) {
                if (vals_[i]->equals(item)) {
                    return i;
                }
            }
            return -1;
        }
};