#include <iostream>
#include "Location2D.h"
#include "Stack.h"

#include <Windows.h>

// 맵 데이터 선언.
const size_t MAZE_SIZE = 20;
// 0:이동가능 1:벽이동불가 s:시작위치 e:목표위치
char map[MAZE_SIZE][MAZE_SIZE] =
{

   {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
   {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
   {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
   {'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
   {'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
   {'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
   {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
   {'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
   {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
   {'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
   {'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
   {'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
   {'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
   {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
   {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
   {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
   {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// 이동하려는 위치가 유효한 위치인지 확인.
bool IsValidLocation(int row, int column)
{
    if (row >= MAZE_SIZE || column >= MAZE_SIZE)
    {
        return false;
    }
    if (row < 0 || column < 0)
    {
        return false;
    }
    return map[row][column] == '0' || map[row][column] == 'e';
}


void ClearScreen()
{
    // 커서 정보 설정을 위한 구조체 변수. #include <window.h>
    CONSOLE_CURSOR_INFO info = {};
    // 커서 그리기
    info.dwSize = 1;
    info.bVisible = FALSE;

    // 콘솔 제어를 위한 핸들 (포인터) 가져오기
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // 커서 가리기
    SetConsoleCursorInfo(handle, &info);

    // 화면 좌표 옮기기.
    SetConsoleCursorPosition(handle, { 0,0 });

    // 빈 문자 찍기.
   /* for (int y = 0;y < MAZE_SIZE; ++y)
    {
        for (int x = 0;x < MAZE_SIZE; ++x)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }*/
    SetConsoleCursorPosition(handle, { 0,0 });
}

// 맵 출력 함수
void PrintLocation(int row, int column, int delay)
{
    // 딜레이.
    Sleep(delay);

    // 화면 지우기.
    ClearScreen();

    for (int ix = 0; ix < MAZE_SIZE; ++ix)
    {
        for (int jx = 0; jx < MAZE_SIZE; ++jx)
        {
            if (ix == row && jx == column)
            {
                std::cout << "♥ ";
                continue;
            }
            std::cout << map[ix][jx] << " ";
        }
        std::cout << '\n';
    }
}
int main() {
    // 시작 위치 검색 
    int startRaw = 0;
    int startColumn = 0;

    // 미로의 시작 지점 검색.
    for (int ix = 0; ix < MAZE_SIZE; ++ix)
    {
        for (int jx = 0; jx < MAZE_SIZE; ++jx)
        {
            std::cout << map[ix][jx] << " ";

            if (map[ix][jx] == 's')
            {
                startRaw = ix;
                startColumn = jx;
            }
        }
        std::cout << "\n";
    }

    // 시작점을 스택에 삽입
    Stack<Location2D> stack;
    stack.Push(Location2D(startRaw, startColumn));

    // 미로 탐색
    while (!stack.IsEmpty())
    {
        Location2D current;
        stack.Pop(current);

        int row = current.row;
        int column = current.column;

        // 탐색한 위치 출력
        //std::cout << "(" << row << ", " << column << ")";
        //std::cout << "(" << column<< ", " << row<< ")";

        PrintLocation(row, column, 500);

        if (map[row][column] == 'e')
        {
            std::cout << "\n 미로 탐색 성공 \n";
            std::cin.get();
            return 0;
        }
        // 방문한 곳은 다른 문자로 설정.
        map[row][column] = '.';
        // 상하좌우 위치 중 이동한 위치를 스택 삽입
        if (IsValidLocation(row - 1, column) == true)
        {
            stack.Push(Location2D(row - 1, column));
        }
        if (IsValidLocation(row + 1, column) == true)
        {
            stack.Push(Location2D(row + 1, column));
        }
        if (IsValidLocation(row, column - 1) == true)
        {
            stack.Push(Location2D(row, column - 1));
        }
        if (IsValidLocation(row, column + 1) == true)
        {
            stack.Push(Location2D(row, column + 1));
        }
    }

}