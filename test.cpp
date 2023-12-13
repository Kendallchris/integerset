//
// Created by Carlos R. Arias on 3/28/23.
//

#include "integer_set.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::stringstream;



void Test(bool condition, const char* message);

int main(int argc, char* argv[]) {
    bool flag;
    stringstream messenger, in, out;
    IntegerSet a(5);
    Test(a.IsEmpty(), "01 - IsEmpty");
    for (size_t i=0; i<6; i++){
        messenger.str("");
        messenger << "0" << i + 2 << " - Belongs(" << i << ")";
        Test(!a.Belongs(i), messenger.str().c_str());
    }
    Test(a.ToString() == "{}", "08 - ToString");
    Test(a.ToJSON() == "{\"set\": []}", "09 - ToJSON");
    Test(a.Complement().ToString() == "{0, 1, 2, 3, 4}", "10 - Complement");
    cout << string(82, '-') << endl;
    flag = a.AddElement(0);
    Test(flag, "11 - Successful AddElement");
    flag = a.AddElement(2);
    Test(flag, "12 - Successful AddElement");
    flag = a.AddElement(3);
    Test(flag, "13 - Successful AddElement");
    flag = a.AddElement(5);
    Test(!flag, "14 - Unsuccessful AddElement");
    Test(a.ToString() == "{0, 2, 3}", "15 - ToString");
    Test(a.ToJSON() == "{\"set\": [0, 2, 3]}", "16 - ToJSON");
    IntegerSet b(a);
    Test(a.Equals(b), "17 - Equals & Copy Constructor");
    Test(b.ToString() == "{0, 2, 3}", "18 - ToString");
    Test(!b.IsEmpty(), "19 - Not an Empty Set");
    b.Clear();
    Test(b.IsEmpty(), "20 - Empty after Clean");
    cout << string(82, '-') << endl;
    int setA[] = {1, 2, 6, 7};
    IntegerSet c(sizeof(setA)/ sizeof(setA[0]), setA);
    Test(!c.Equals(a), "21 - Equals and Array Constructor");
    Test(c.ToString() == "{1, 2, 6, 7}", "22 - ToString and Array Constructor");
    IntegerSet d(20);
    d = c.Complement();
    Test(!c.Equals(d), "23 - Equals and Complement");
    Test(d.ToString() == "{0, 3, 4, 5}", "24 - ToString and Complement");
    IntegerSet e(10);
    in.str("0 1 2 7");
    e.Read(in);
    in.clear();
    in.str("");
    Test(e.ToString() == "{0, 1, 2, 7}", "25 - ToString and Read");
    e.Write(out);
    Test(out.str() == "0 1 2 7 ", "26 - ToString and Write");
    out.str("");
    IntegerSet f(3);
    in.str("0 4 9");
    f.Read(in);
    in.clear();
    in.str("");
    Test(f.ToString() == "{0}", "27 - Input outside of universe");
    b = a.Union(c);
    Test(b.ToString() == "{0, 1, 2, 3, 6, 7}", "28 - ToString and Union");
    b = a.Intersection(c);
    Test(b.ToString() == "{2}", "29 - ToString and Intersection");
    b = e.Intersection(c).Complement();
    Test(b.ToString() == "{0, 3, 4, 5, 6, 8, 9}", "30 - Cascade, Intersection and Complement");
    cout << string(82, '-') << endl;
    Test(a.CartesianProduct(c) == "{(0, 1), (0, 2), (0, 6), (0, 7), (2, 1), (2, 2), (2, 6), (2, 7), (3, 1), (3, 2), (3, 6), (3, 7)}", "99 - Cartesian Product");
    return 0;
}

void Test(bool condition, const char* message){
    static auto passedTests = 0;
    if (condition){
        cout << "TEST PASSED (" << left << setw(50) << message << ") Total Passed: " << ++passedTests << endl;
    }else{
        cout << "TEST FAILED (" << left << setw(50) << message << ") **************" << endl;
    }
}