#include <iostream>
#include "Location2D.h"
#include "Stack.h"

#include <Windows.h>

// �� ������ ����.
const size_t MAZE_SIZE = 20;
// 0:�̵����� 1:���̵��Ұ� s:������ġ e:��ǥ��ġ
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

// �̵��Ϸ��� ��ġ�� ��ȿ�� ��ġ���� Ȯ��.
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
    // Ŀ�� ���� ������ ���� ����ü ����. #include <window.h>
    CONSOLE_CURSOR_INFO info = {};
    // Ŀ�� �׸���
    info.dwSize = 1;
    info.bVisible = FALSE;

    // �ܼ� ��� ���� �ڵ� (������) ��������
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ŀ�� ������
    SetConsoleCursorInfo(handle, &info);

    // ȭ�� ��ǥ �ű��.
    SetConsoleCursorPosition(handle, { 0,0 });

    // �� ���� ���.
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

// �� ��� �Լ�
void PrintLocation(int row, int column, int delay)
{
    // ������.
    Sleep(delay);

    // ȭ�� �����.
    ClearScreen();

    for (int ix = 0; ix < MAZE_SIZE; ++ix)
    {
        for (int jx = 0; jx < MAZE_SIZE; ++jx)
        {
            if (ix == row && jx == column)
            {
                std::cout << "�� ";
                continue;
            }
            std::cout << map[ix][jx] << " ";
        }
        std::cout << '\n';
    }
}
int main() {
    // ���� ��ġ �˻� 
    int startRaw = 0;
    int startColumn = 0;

    // �̷��� ���� ���� �˻�.
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

    // �������� ���ÿ� ����
    Stack<Location2D> stack;
    stack.Push(Location2D(startRaw, startColumn));

    // �̷� Ž��
    while (!stack.IsEmpty())
    {
        Location2D current;
        stack.Pop(current);

        int row = current.row;
        int column = current.column;

        // Ž���� ��ġ ���
        //std::cout << "(" << row << ", " << column << ")";
        //std::cout << "(" << column<< ", " << row<< ")";

        PrintLocation(row, column, 500);

        if (map[row][column] == 'e')
        {
            std::cout << "\n �̷� Ž�� ���� \n";
            std::cin.get();
            return 0;
        }
        // �湮�� ���� �ٸ� ���ڷ� ����.
        map[row][column] = '.';
        // �����¿� ��ġ �� �̵��� ��ġ�� ���� ����
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