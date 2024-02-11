#pragma once
#include <exception>
class Exceptions_struct {
public:
    Exceptions_struct(const char* string);
    explicit Exceptions_struct();
    const char* getinfo() const;
protected:
    const char* exception;
};


class ClearEmpty : public Exceptions_struct {
public:
    ClearEmpty(const char* string);
    //private:
    //   const char* exception;
};
class TypeMismatch : public Exceptions_struct {
public:
    TypeMismatch(const char* string);
};
class SearchEmptyList : public Exceptions_struct {
    public:
        SearchEmptyList(const char* string);
};