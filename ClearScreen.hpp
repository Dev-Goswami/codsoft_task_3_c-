#include <cstdlib> // this for clear screen 
#ifdef _WIN32 // if system is window 
    #define CLEAR_COMMAND "cls"
#else //otherwise fro unix or moc 
#define CLEAR_COMMAND "clear"
#endif

using namespace std;
void clearScreen() {
    system(CLEAR_COMMAND);
}
//here i try to write a corss platform clearSreen function 