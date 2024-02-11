#include "HeaderException.h"
Exceptions_struct::Exceptions_struct(const char* string) {
    exception = string;
}

const char* Exceptions_struct::getinfo() const {
    return exception;
}

TypeMismatch::TypeMismatch(const char* string) {
    exception = string;
    Exceptions_struct::exception = string;
}

ClearEmpty::ClearEmpty(const char* string) {
    exception = string;
    Exceptions_struct::exception = string;
}
SearchEmptyList::SearchEmptyList (const char* string) {
    exception = string;
    Exceptions_struct::exception = string;
}
Exceptions_struct::Exceptions_struct() {};
