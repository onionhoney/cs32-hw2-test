// test_maze.cpp


#include <string>
#include <iostream>
#define check(EX) (handle(#EX, EX))
using namespace std;

string message;

bool handle(const char *msg, bool result) {
    if (result) {
        message = "Success";
        return true;
    } else {
        message = msg;
        return false;
    }
}


bool pathExists(std::string maze[], int nRows, int nCols,
                int sr, int sc, int er, int ec);


const string MAZE[10] = {
    "XXXXXXXXXX",
    "X........X",
    "XX.X.XXXXX",
    "X..X.X...X",
    "X..X...X.X",
    "XXXX.XXX.X",
    "X.X....XXX",
    "X..XX.XX.X",
    "X...X....X",
    "XXXXXXXXXX"
};

const int TOTAL_TEST_CASE = 10;

bool test(int testIndex) {
    // testIndex : index of the test number
    // corresponding to switch statement
    string maze[10];
    for (int i = 0; i < 10; ++i)
        maze[i] = MAZE[i];

    switch (testIndex) {
    case 0:
        return check(pathExists(maze, 10,10, 6,4, 1,1));

    case 1:
        return check(!pathExists(maze, 10,10, 7,1, 1,2));

    case 2:
        return check(pathExists(maze, 10,10, 6,3, 1,8));

    case 3:
        return check(pathExists(maze, 10,10, 4,1, 3,7));

    case 4:
        return check(pathExists(maze, 10,10, 7,8, 3,8));

    case 5:
        return check(!pathExists(maze, 10,10, 8,2, 6,5));

    case 6:
        return check(pathExists(maze, 10,10, 3,1, 4,6));

    case 7:
        return check(!pathExists(maze, 10,10, 7,8, 8,1));

    default:
        return true;
    }
}

int main() {
    cout << "====== RUNNING TEST CASE FOR MAZE ======"
         << endl;

    int passed = 0;
    for (int i = 0; i < TOTAL_TEST_CASE; ++i) {
        if(!test(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl;
        else
            ++passed;
    }

    if (passed == TOTAL_TEST_CASE)
        cout << "****** ALL TESTS PASSED ******" << endl;

    cout << "====== TEST CASE FOR MAZE ENDS ======"
         << endl;

    return 0;
}
