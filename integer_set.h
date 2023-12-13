/* Title: Lab 1 - integer_set.h
   Purpose: The goal of the programming assignment is to implement the methods of the class `IntegerSet`, additionally you are expected to write
   the appropriate header comments to each one of the methods. Once you have *correctly* implemented them you will pass the 30 tests that are given to you in the `test.cpp` file.
   Author:     Chris Kendall
   Date:       April 7, 2023
*/

#ifndef DYNAMIC_INTEGER_SET
#define DYNAMIC_INTEGER_SET

#include <iostream>
#include <string>
#include <sstream>

using std::ostream;
using std::istream;
using std::string;
using std::stringstream;
using std::min;
using std::max;
using std::cout;

class IntegerSet {
private:
    bool* _elements;
    size_t _size;
public:
    IntegerSet(size_t size);
    IntegerSet(size_t size, int* elements);
    IntegerSet(const IntegerSet& set);
    ~IntegerSet();
    const IntegerSet& operator=(const IntegerSet& rhs);
    ostream& Write(ostream& output)const;
    istream& Read(istream& input);
    IntegerSet Union(const IntegerSet& rhs)const;
    IntegerSet Intersection(const IntegerSet& rhs)const;
    IntegerSet Complement()const;
    bool Belongs(size_t element)const;
    bool AddElement(size_t element);
    void Clear();
    string ToString()const;
    string ToJSON()const;
    bool Equals(const IntegerSet& rhs)const;
    bool IsEmpty()const;
    string CartesianProduct(const IntegerSet& rhs)const;

};


#endif
