// test_eval.cpp


#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

int evaluate(std::string infix, const Map& values,
             std::string& postfix, int& result);


const int TOTAL_TEST_CASE = 21;

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
        return (evaluate("a+ e", m, pf, answer) == 0  &&
               pf == "ae+"  &&  answer == -6);

    case 1:
        return (evaluate("     (a+e  )", m, pf, answer) == 0 &&
               pf == "ae+"  &&  answer == -6);

    case 2:
        return (evaluate("     (a+e  )", m, pf, answer) == 0 &&
               pf == "ae+"  &&  answer == -6);

    case 3:
        return (evaluate("", m, pf, answer) == 1  &&  answer == 999);

    case 4:
        return (evaluate("a+", m, pf, answer) == 1  &&  answer == 999);

    case 5:
        return (evaluate("a)", m, pf, answer) == 1 && answer == 999);

    case 6:
        return (evaluate("a i", m, pf, answer) == 1  &&  answer == 999);

    case 7:
        return (evaluate("ai", m, pf, answer) == 1  &&  answer == 999);

    case 8:
        return (evaluate("ai+", m, pf, answer) == 1  &&  answer == 999);

    case 9:
        return (evaluate("()", m, pf, answer) == 1  &&  answer == 999);

    case 10:
        return (evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);

    case 11:
        return (evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);

    case 12:
        return (evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);

    case 13:
        return (evaluate("-a", m, pf, answer) == 1  &&  answer == 999);

    case 14:
        return (evaluate("o/(-a+e)", m, pf, answer) == 1 && answer == 999);

    case 15:
        return (evaluate("   -a+b", m, pf, answer) == 1 && answer == 999);

    case 16:
        return (evaluate("a*b", m, pf, answer) == 2  &&
               pf == "ab*"  &&  answer == 999);

    case 17:
        return (evaluate("y +o *(   a-u)  ", m, pf, answer) == 0 &&
               pf == "yoau-*+"  &&  answer == -1);

    case 18:
        return (evaluate("o/(y-y)", m, pf, answer) == 3  &&
               pf == "oyy-/"  &&  answer == 999);

    case 19:
        return (evaluate(" a  ", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

    case 20:
        return (evaluate("((a))", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

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
                 << "fails test case " << i << endl;
        else
            ++passed;
    }

    if (passed == TOTAL_TEST_CASE)
        cout << "ALL TESTS PASSED" << endl;

    cout << "====== TEST CASE FOR EVAL ENDS ======"
         << endl;

    return 0;
}
