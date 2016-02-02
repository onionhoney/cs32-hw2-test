#include <cstdio>
extern void handle_assert (const char *msg, const char *file, int line){
    printf("Assertion failed: %s, file %s, line %d.\n", msg, file, line);
}
bool handle(const char *msg, bool result){
    if (result){
        return true;              
    }
    else{
        printf("Failed at: %s\n", msg);
        return false;
    }
}
#define check(EX) (handle(#EX, EX))
//#define assert(EX) (void)((EX) || (handle_assert (#EX, __FILE__, __LINE__),0) )
