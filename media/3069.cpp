#include <iostream>
#include <string>
#include <Windows.h>


int main() {
    
    for (size_t i = 0; i < 10000; i++)
    {
        _CrtDbgBreak();
        Sleep(10000);
        MessageBoxA(0, "hi", "hi2", 0);
        Sleep(10000);

        _CrtDbgBreak();

    }

    return 0;
}