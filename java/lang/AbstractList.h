//
// Created by Tu Cao on 5/21/17.
//

#ifndef NATIVE_ABSTRACTLIST_H
#define NATIVE_ABSTRACTLIST_H

#include "AbstractCollection.h"

namespace Java {
    namespace Lang {
        template <class T>
        class AbstractList: public AbstractCollection {
            protected:
                virtual void add(int index, T element);
                //virtual void addAll(int index, Collection c);
                virtual bool equals(T element);
                virtual int hashCode();
                virtual T get(int index);
                virtual bool remove(int index);
                virtual bool removeRange(int fromIndex, int toIndex);
                virtual bool set(int index, T element); //replace element with index
                //virtual [T] subList(int fromIndex, int toIndex);
        };
    }
}



#endif //NATIVE_ABSTRACTLIST_H