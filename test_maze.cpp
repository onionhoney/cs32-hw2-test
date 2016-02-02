// test_maze.cpp


#include <string>
#include <iostream>
using namespace std;

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
    string maze[10] (MAZE);

    switch (testIndex) {
    case 0:
        return pathExists(maze, 10,10, 6,4, 1,1);

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
        cout << "ALL TESTS PASSED" << endl;

    cout << "====== TEST CASE FOR MAZE ENDS ======"
         << endl;

    return 0;
}
