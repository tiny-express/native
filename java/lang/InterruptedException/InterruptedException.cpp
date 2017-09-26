//
// Created by home on 9/26/17.
//

#include "InterruptedException.hpp"

InterruptedException::InterruptedException() : Exception() {

}

InterruptedException::InterruptedException(String message) :
        Exception(message) {

}

InterruptedException::InterruptedException(Throwable *cause) :
        Exception(cause){

}

InterruptedException::InterruptedException(String message, Throwable *cause)
        : Exception(message, cause) {

}
