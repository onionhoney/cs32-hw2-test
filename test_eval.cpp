// test_eval.cpp


#include "Map.h"
#include <iostream>
#include <string>
#include "assert.h"
#define check(EX) (handle(#EX, EX))

using namespace std;
string message;

bool handle(const char *msg, bool result){
    if (result){
        message = "Success";
        return true;              
    }
    else{
        message = msg;
        return false;
    }
}


int evaluate(std::string infix, const Map& values,
             std::string& postfix, int& result);


const int TOTAL_TEST_CASE = 22;

bool test(int testIndex) {
    // testIndex : index of the test number
    // corresponding to switch statement

    char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
    int  vals[] = {  3,  -9,   6,   2,   4,   1  };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
        m.insert(vars[k], vals[k]);

    int answer = 999;
    string pf;

    switch (testIndex) {
    case 0:
        return check(evaluate("a+ e", m, pf, answer) == 0  &&
               pf == "ae+"  &&  answer == -6);

    case 1:
        return check(evaluate("     (a+e  )", m, pf, answer) == 0 &&
               pf == "ae+"  &&  answer == -6);

    case 2:
        return check(evaluate("     (a+e  )", m, pf, answer) == 0 &&
               pf == "ae+"  &&  answer == -6);

    case 3:
        return check(evaluate("", m, pf, answer) == 1  &&  answer == 999);

    case 4:
        return check(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);

    case 5:
        return check(evaluate("a)", m, pf, answer) == 1 && answer == 999);

    case 6:
        return check(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);

    case 7:
        return check(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);

    case 8:
        return check(evaluate("ai+", m, pf, answer) == 1  &&  answer == 999);

    case 9:
        return check(evaluate("()", m, pf, answer) == 1  &&  answer == 999);

    case 10:
        return check(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);

    case 11:
        return check(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);

    case 12:
        return check(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);

    case 13:
        return check(evaluate("-a", m, pf, answer) == 1  &&  answer == 999);

    case 14:
        return check(evaluate("o/(-a+e)", m, pf, answer) == 1 && answer == 999);

    case 15:
        return check(evaluate("   -a+b", m, pf, answer) == 1 && answer == 999);

    case 16:
        return check(evaluate("a*b", m, pf, answer) == 2  &&
               pf == "ab*"  &&  answer == 999);

    case 17:
        return check(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0 &&
               pf == "yoau-*+"  &&  answer == -1);

    case 18:
        return check(evaluate("o/(y-y)", m, pf, answer) == 3  &&
               pf == "oyy-/"  &&  answer == 999);

    case 19:
        return check(evaluate(" a  ", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

    case 20:
        return check(evaluate("((a))", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

    case 21:
        return check(evaluate("    (a+y)  ", m, pf, answer) == 0 &&
               pf == "ay+" && answer == 4);

    default:
        return true;
    }
}


int main() {
    cout << "====== RUNNING TEST CASE FOR EVAL ======"
         << endl;

    int passed = 0;
    for (int i = 0; i < TOTAL_TEST_CASE; ++i) {
        if (!test(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++passed;
    }

    if (passed == TOTAL_TEST_CASE)
        cout << "****** ALL TESTS PASSED ******" << endl;

    cout << "====== TEST CASE FOR EVAL ENDS ======"
         << endl;

    return 0;
}
