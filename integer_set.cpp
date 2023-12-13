/* Title: Lab 1 - integer_set.cpp
   Purpose: The goal of the programming assignment is to implement the methods of the class `IntegerSet`, additionally you are expected to write
   the appropriate header comments to each one of the methods. Once you have *correctly* implemented them you will pass the 30 tests that are given to you in the `test.cpp` file.
   Author:     Chris Kendall
   Date:       April 7, 2023
*/

#include <cassert>
#include "integer_set.h"

/**
 * Constructor of the class.
 * @param size size_t that will be set to the number of elements that the set can hold
 */
IntegerSet::IntegerSet(size_t size): _size(size) {
    _elements = new bool[_size];
    for (size_t i = 0; i < _size; ++i) {
        _elements[i] = false;
    }
}

/**
 * Constructor of the class.
 * @param size size_t representing the number of integers in the array, elements
 * @param elements the array of integers to be put into the IntegerSet object
 */
IntegerSet::IntegerSet(size_t size, int* elements) {
    int max = elements[0];
    for (size_t i = 0; i < size; ++i) {
        if (max < elements[i]) {
            max = elements[i];
        }
    }
    _size = max + 1;
    _elements = new bool[_size];
    for (size_t i = 0; i < _size; ++i) {
         _elements[i] = false;
    }
    for (size_t i = 0; i < size; ++i) {
        _elements[elements[i]] = true;
    }
}

/**
 * Copy constructor of the class.
 * @param set the IntegerSet to be copied
 */
IntegerSet::IntegerSet(const IntegerSet &set): _size(set._size) {
    _elements = new bool[_size];
    for (size_t i = 0; i < _size; ++i) {
        _elements[i] = set._elements[i];
    }
}

/**
 * Destructor, deallocates the dynamically allocated memory.
 */
IntegerSet::~IntegerSet() {
    delete[] _elements;
}

/**
 * Copy assignment operator for the class.
 * @param rhs the old object
 * @return the newly assigned object
 */
const IntegerSet& IntegerSet::operator=(const IntegerSet& rhs) {
    if (this != &rhs) {
        // Free the old memory
        delete[] _elements;
        // Copy the new size and allocate new memory
        _size = rhs._size;
        _elements = new bool[_size];

        // Copy the elements
        for (size_t i = 0; i < _size; ++i) {
            _elements[i] = rhs._elements[i];
        }
    }
    return *this;
}

// TODO Finish Write Will be outputting the index, not the value...
/**
 * Writes the elements of the set to `output`. It will output the values of the elements separated by spaces.
 * The last element will also have a space after it.
 * @param output The output stream to be output to
 * @return The elements of the set, separated by spaces
 */
ostream &IntegerSet::Write(ostream &output) const {
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            output << i << " ";
        }
    }
    return output;
}

/**
 * Reads the elements from input.
 * @param input the input stream
 * @return the input values
 */
istream &IntegerSet::Read(istream &input) {
    // Read the elements from input
    int value;
    while (input >> value) {
        if (value >= _size) {
            continue;
        }
        if (value < _size) {
            // Allocate additional memory if needed
            bool* new_elements = new bool[_size];
            for (size_t i = 0; i < _size; ++i) {
                new_elements[i] = _elements[i];
            }
            for (size_t i = _size; i <= value; ++i) {
                new_elements[i] = false;
            }
            delete[] _elements;
            _elements = new_elements;
        }
        _elements[value] = true;
    }

    // Clear the failbit if needed
    input.clear();

    return input;
}

/**
 * Calculates the union by `this` and `rhs`.
 * @param rhs the IntegerSet to be combined with 'this'
 * @return the new IntegerSet that is both 'this' and 'rhs' combined
 */
IntegerSet IntegerSet::Union(const IntegerSet &rhs) const {
    size_t new_size = _size + rhs._size;

    IntegerSet union_set(new_size);
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            union_set.AddElement(i);
        }
    }
    for (size_t i = 0; i < rhs._size; ++i) {
        if (rhs._elements[i]) {
            union_set.AddElement(i);
        }
    }
    return union_set;
}

/**
 * Calculates the intersection by `this` and `rhs`.
 * @param rhs the IntegerSet to be compared with 'this'
 * @return the new IntegerSet only containing values both 'this' and 'rhs' have in common
 */
IntegerSet IntegerSet::Intersection(const IntegerSet &rhs) const {
    size_t new_size = max(_size, rhs._size);
    size_t smallest = min(_size, rhs._size);
    IntegerSet intersection(new_size);
    for (size_t i = 0; i < smallest; ++i) {
        intersection._elements[i] = _elements[i] && rhs._elements[i];
    }
    return intersection;
}

/**
 * Calculates the complement of the set represented by `this`. It will return a new set with the elements not in `this` and without those in `this`.
 * @return the new IntegerSet, the compliment of 'this'
 */
IntegerSet IntegerSet::Complement() const {
    IntegerSet complement(_size);
    for (size_t i = 0; i < _size; ++i) {
        if (!_elements[i]) {
            complement.AddElement(i);
        }
    }
    return complement;
}

/**
 * Checks if the parameter `element` is in the set.
 * @param element the size_t value to be looked for in the list
 * @return true or false whether or not the value was in the list
 */
bool IntegerSet::Belongs(size_t element) const {
    if (element >= _size) {
        return false;
    }
    return _elements[element];
}

/**
 * Adds the element represented by the parameter. If the element can be added (it belongs to the universe of `this`)
 * then it is added and the method returns `true`, it returns `false` otherwise.
 * @param element the size_t value to be added
 * @return true or false whether or not it was added
 */
bool IntegerSet::AddElement(size_t element) {
    if (element >= _size) {
        return false;
    }
    if (!_elements[element]) {
        _elements[element] = true;
        return true;
    }
    return false;
}

/**
 * Makes `this` an empty set.
 */
void IntegerSet::Clear() {
    for (size_t i = 0; i < _size; i++)
        _elements[i] = false;
}

/**
 * Returns a string representation of the set. For example: `A = {0, 3, 4}` when calling `A.ToString()` will return `{0, 3, 4}` as a string.
 * @return string representation of the set
 */
string IntegerSet::ToString() const {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            if (!first) {
                ss << ", ";
            }
            ss << i;
            first = false;
        }
    }
    ss << "}";
    return ss.str();
}

/**
 * Returns a [JSON] representation of the set. For example `A = {0, 2, 3}` when calling A.ToJSON() will return `{"set": [0, 2, 3]}`.
 * @return a string JSON representation of the set
 */
string IntegerSet::ToJSON() const {
    stringstream ss;
    ss << "{\"set\": [";
    bool first = true;
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            if (!first) {
                ss << ", ";
            }
            ss << i;
            first = false;
        }
    }
    ss << "]}";
    return ss.str();
}

/**
 * Determines if `this` and `rhs` are the same set.
 * @param rhs the set to be compared to 'this'
 * @return true/false
 */
bool IntegerSet::Equals(const IntegerSet &rhs) const {
    if (_size != rhs._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i] != rhs._elements[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Returns `true` if the `this` does not have any elements, `false` otherwise.
 * @return true/false whether or not it is empty
 */
bool IntegerSet::IsEmpty() const {
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            return false;
        }
    }
    return true;
}

/**
 * This method returns the cartesian product of 2 sets.
 * @param rhs the 2nd set to be cartesianed with 'this' set
 * @return string representation of the cartesian product of 2 set
 */
string IntegerSet::CartesianProduct(const IntegerSet &rhs) const {
    stringstream ss;
    ss << "{";
    bool first = true;
    for (size_t i = 0; i < _size; ++i) {
        if (_elements[i]) {
            for (size_t j = 0; j < rhs._size; ++j) {
                if (rhs._elements[j]) {
                    if (!first) {
                        ss << ", ";
                    }
                    ss << "(" << i << ", " << j << ")";
                    first = false;
                }
            }
        }
    }
    ss << "}";
    return ss.str();
}
