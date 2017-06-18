#include <native/library.hpp>
#include "HashMap.hpp"
int main()
{
	HashMap<String, String> *hashMap;
	hashMap = new HashMap<String, String>();
	delete hashMap;
	return 0;
}
