[1mdiff --git a/example/HelloWorld/.gitignore b/example/HelloWorld/.gitignore[m
[1mindex e52bc1f..ed2762b 100644[m
[1m--- a/example/HelloWorld/.gitignore[m
[1m+++ b/example/HelloWorld/.gitignore[m
[36m@@ -5,4 +5,5 @@[m
 /install_manifest.txt[m
 /CMakeCache.txt[m
 /Testing[m
[31m-/Makefile[m
\ No newline at end of file[m
[32m+[m[32m/Makefile[m
[32m+[m[32m/HelloWorld[m
\ No newline at end of file[m
[1mdiff --git a/example/HelloWorld/CMakeLists.txt b/example/HelloWorld/CMakeLists.txt[m
[1mindex af77d2c..a4bc443 100644[m
[1m--- a/example/HelloWorld/CMakeLists.txt[m
[1m+++ b/example/HelloWorld/CMakeLists.txt[m
[36m@@ -37,6 +37,9 @@[m [minclude(CheckCXXCompilerFlag)[m
 check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)[m
 check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)[m
 [m
[32m+[m[32mset(SOURCE_FILES Main.cpp)[m
[32m+[m[32madd_executable(HelloWorld ${SOURCE_FILES})[m
[32m+[m
 if (COMPILER_SUPPORTS_CXX11)[m
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")[m
 elseif (COMPILER_SUPPORTS_CXX0X)[m
[36m@@ -59,7 +62,7 @@[m [melse ()[m
     set(OPENSSL_ROOT_DIR "C:/Program Files (x86)/GnuWin32/include")[m
 endif ()[m
 [m
[31m-# Set root directory for OpenSSL[m
[32m+[m[32m# Set root directory for OpenSSLH[m
 set(OPENSSL_ROOT_DIR "${OPENSSL_ROOT_DIR}")[m
 [m
 # Detect installed components[m
[1mdiff --git a/example/HelloWorld/Main.cpp b/example/HelloWorld/Main.cpp[m
[1mindex 1fef3e3..d253dc9 100644[m
[1m--- a/example/HelloWorld/Main.cpp[m
[1m+++ b/example/HelloWorld/Main.cpp[m
[36m@@ -1,8 +1,10 @@[m
 #include "Person.hpp"[m
[31m-char *a = (char*) calloc(1000000, sizeof(char));[m
[31m-int main()[m
[31m-{[m
[31m-	printf("asdasdasdas\n");[m
[31m-//     person.setFirstName("First name");[m
[32m+[m[32mint main() {[m
[32m+[m[32m    Person anhKhoa;[m
[32m+[m
[32m+[m[32m    anhKhoa.setFirstName("Nguyen");[m
[32m+[m
[32m+[m[32m    printf("%s\n", anhKhoa.getFirstName().toString());[m
[32m+[m
 	return 0;[m
 }[m
[1mdiff --git a/example/HelloWorld/Person.hpp b/example/HelloWorld/Person.hpp[m
[1mindex f989aaa..3a04e45 100644[m
[1m--- a/example/HelloWorld/Person.hpp[m
[1m+++ b/example/HelloWorld/Person.hpp[m
[36m@@ -5,26 +5,24 @@[m
 [m
 class Person {[m
 private:[m
[31m-	char* firstName;[m
[32m+[m	[32mString firstName;[m
[32m+[m
 public:[m
 	Person() {[m
[32m+[m
 	}[m
[32m+[m
 	~Person() {[m
[32m+[m
 	}[m
[32m+[m
 	Person &setFirstName(String firstName) {[m
 		return *this;[m
 	}[m
[31m-	[m
[31m-//	String &getFirstName() {[m
[31m-//		return self.firstName;[m
[31m-//	}[m
[31m-//	Person &setLastName(String lastName) {[m
[31m-//		self.lastName = lastName;[m
[31m-//		return self;[m
[31m-//	}[m
[31m-//	String &getLastName() {[m
[31m-//		return self.lastName;[m
[31m-//	}[m
[32m+[m
[32m+[m[32m    String getFirstName() {[m
[32m+[m[32m        return this->firstName;[m
[32m+[m[32m    }[m
 };[m
 [m
 #endif //NATIVE_EXAMPLE_PERSON_HPP[m
[1mdiff --git a/example/HelloWorld/Teacher.cpp b/example/HelloWorld/Teacher.cpp[m
[1mindex 1506d9f..841f76a 100644[m
[1m--- a/example/HelloWorld/Teacher.cpp[m
[1m+++ b/example/HelloWorld/Teacher.cpp[m
[36m@@ -1,5 +1 @@[m
[31m-//[m
[31m-// Created by loint on 15/06/2017.[m
[31m-//[m
[31m-[m
 #include "Teacher.hpp"[m
[1mdiff --git a/example/HelloWorld/debug b/example/HelloWorld/debug[m
[1mindex b5c9e06..8e6f4b1 100755[m
[1m--- a/example/HelloWorld/debug[m
[1m+++ b/example/HelloWorld/debug[m
[36m@@ -4,5 +4,7 @@[m [msudo make uninstall[m
 make native -j8[m
 sudo make install[m
 cd example/HelloWorld[m
[32m+[m[32mcmake .[m
 make[m
[31m-valgrind --track-origins=yes  --error-exitcode=42 --show-leak-kinds=all --show-reachable=yes --leak-check=full ./bin/main[m
\ No newline at end of file[m
[32m+[m[32mvalgrind --track-origins=yes  --error-exitcode=42 --show-leak-kinds=all --show-reachable=yes --leak-check=full ./HelloWorld[m
[32m+[m[32m./HelloWorld[m
\ No newline at end of file[m
