//
// Created by Tu Cao on 5/21/17.
//

#ifndef NATIVE_ABSTRACTCOLLECTION_H
#define NATIVE_ABSTRACTCOLLECTION_H

extern "C" {
#include "../../builtin.h"
};

#include <iostream>

namespace Java {
    namespace Lang {
        template<class T>
        class AbstractCollection {
            protected:
                AbstractCollection();
                ~AbstractCollection();

                virtual bool add(T const &);
                //virtual bool addAll(Collection c);
                virtual void clear();
                virtual bool contains(T);
                //virtual bool containsAll(Collection c);
                virtual bool isEmpty();
                virtual bool remove(T);
                virtual bool removeAll();
                virtual int size();
        };

    }
}

#endif //NATIVE_ABSTRACTCOLLECTION_H
