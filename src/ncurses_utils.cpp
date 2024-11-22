#include "ncurses_utils.h"
#include <ncurses.h>
#include <vector>
#include <string>

void display_menu(WINDOW* menu_win, const std::vector<std::string>& menu_items, size_t highlight)
{
    box(menu_win, 0, 0);  // ������ ����� ������ ����
    for (size_t i = 0; i < menu_items.size(); ++i)
    {
        if (highlight == i)
        {
            wattron(menu_win, A_REVERSE);  // �������� ������� ����� ����
            mvwprintw(menu_win, i + 1, 2, "%s", menu_items[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }
        else
        {
            mvwprintw(menu_win, i + 1, 2, "%s", menu_items[i].c_str());
        }
    }
    wrefresh(menu_win);
}

std::string inputFilePath(WINDOW* input_win) 
{
    char input[256] = { 0 };  // ����� ��� ����� ������
    int ch;
    int pos = 0;
    // ���������� ����������� � �����
    mvwprintw(input_win, 1, 1, "Put a path to file here:");
    wrefresh(input_win);
    while (true) 
    {
        ch = wgetch(input_win);  // �������� ������ �� ������������
        if (ch == '\n') 
        {  // Enter ��������� ����
            input[pos] = '\0';
            break;
        }
        else if (ch == KEY_BACKSPACE || ch == 127) 
        {  // Backspace
            if (pos > 0) 
            {
                --pos;
                input[pos] = '\0';
                mvwprintw(input_win, 2, 1, "%-255s", input);  // ������� ������
                wmove(input_win, 2, 1 + pos);  // ���������� ������
                wrefresh(input_win);
            }
        }
        else if (pos < 255) 
        {  // ��������� ������ � �����
            input[pos++] = ch;
            mvwaddch(input_win, 2, pos, ch);  // ���������� ��������� ������
            wrefresh(input_win);
        }
    }
    return std::string(input);  // ���������� ��������� ����
}