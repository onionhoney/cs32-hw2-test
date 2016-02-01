#include <cstdio>
inline
extern void handle_assert (const char *msg, const char *file, int line){
    printf("Assertion failed: %s, file %s, line %d.\n", msg, file, line);
}
#define assert(EX) (void)((EX) || (handle_assert (#EX, __FILE__, __LINE__),0))
