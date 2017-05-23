//
// Created by Tu Cao on 5/23/17.
//

extern "C" {
#include "../../../unit_test.h"
}

#include "HashMap.hpp"
#include "../../Lang.hpp"

using namespace Java::Util;

template <class K, class V>
class SampleClass {
private:
    std::map<K, V> hashMap;
public:
    SampleClass();
    ~SampleClass();

    V get(K key);
    void put(K key, V value);
};

template<class K, class V>
SampleClass<K, V>::SampleClass() { }

template<class K, class V>
SampleClass<K, V>::~SampleClass() { }

TEST(JavaUtil, HashMap) {

    //SampleClass<string, string> qwe = SampleClass<string, string>();

    HashMap<string, string> asd = HashMap<string, string>();

}