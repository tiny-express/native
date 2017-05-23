//
// Created by dquang on 5/23/17.
//

#include "../mock.h"
#include <python2.7/Python.h>

void *start_mock_server() {
    system("pkill python");
    FILE* file;
    Py_SetProgramName("mock server");
    Py_Initialize();
    file = fopen("./mock/mock_server.py","r");
    PyRun_SimpleFile(file, "./mock/mock_server.py");
    Py_Finalize();
}