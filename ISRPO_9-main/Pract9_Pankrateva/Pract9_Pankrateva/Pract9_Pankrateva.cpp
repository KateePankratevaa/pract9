#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI Factorial(LPVOID iNum) {
    long long n = 1;
    for (int i = 1; i <= (int)iNum; i++) 
    {
        n *= i;
    }
    return n;
}

int main()
{
    int num1 = 5;
    int num2 = 3;
    HANDLE hThread[2]; //дескриптор потока(потоков 2 в данном случае) специальный индетификатор для управления потоком
    DWORD IDThread;
    hThread[0] = CreateThread(NULL, 0, Factorial, (void*)num1, 0, &IDThread);

    hThread[1] = CreateThread(NULL, 0, Factorial, (void*)num2, 0, &IDThread);

    if (hThread[0] == NULL || hThread[1] == NULL) {
        return GetLastError();
    }

    WaitForSingleObject(hThread[0], INFINITE);  
    CloseHandle(hThread[0]);

    WaitForSingleObject(hThread[1], INFINITE); 
    CloseHandle(hThread[1]);

    return 0;
}

