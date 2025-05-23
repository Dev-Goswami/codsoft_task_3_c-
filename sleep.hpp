#ifdef _WIN32
    #include <windows.h>
    void sleep_program(int milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void sleep_program(int milliseconds) {
        usleep(milliseconds * 1000); // usleep takes microseconds
    }
#endif