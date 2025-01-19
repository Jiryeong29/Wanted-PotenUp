// crt_fgets.c
// This program uses fgets to display
// the first line from a file.

#include <stdio.h>
#include <iostream>
int main(void)
{
    FILE* stream = nullptr;
    wchar_t line[100];
    if (fopen_s(&stream, "자기소개영어.txt", "r") == 0)
    {
        if (fgetws(line, 1, stream) == nullptr)
            printf("fgets error\n");
        else
        {
            while (true)
            {
                wprintf(line);

                if (fgetws(line, 1, stream) == nullptr)
                {
                    break;
                }

            }
        }
        fclose(stream);
    }
}