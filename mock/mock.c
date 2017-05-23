//
// Created by dquang on 5/23/17.
//

#include <stdlib.h>
#include "../mock.h"

void *start_mock_server() {
    system("pkill python");
    system("python ./mock/mock_server.py");
}