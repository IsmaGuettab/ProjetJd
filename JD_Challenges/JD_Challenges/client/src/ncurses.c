//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/project.h"
#include <stdio.h>
#include <stdlib.h>

void init_ncurses()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

int ncurses_key(client_t *client, select_t *select)
{
    int ch = getch();
    switch (ch) {
        case ' ':
            select->text = malloc(sizeof(char) * 7);
            sprintf(select->text, "ACTION\n");
            select->type = 2;
            select->button = true;
            break;
        case KEY_UP:
            select->text = malloc(sizeof(char) * 3);
            sprintf(select->text, "UP\n");
            select->type = 2;
            select->action = true;
            break;
        case KEY_DOWN:
            select->text = malloc(sizeof(char) * 5);
            sprintf(select->text, "DOWN\n");
            select->type = 2;
            select->action = true;
            break;
        case KEY_LEFT:
            select->text = malloc(sizeof(char) * 5);
            sprintf(select->text, "LEFT\n");
            select->type = 2;
            select->action = true;
            break;
        case KEY_RIGHT:
            select->text = malloc(sizeof(char) * 6);
            sprintf(select->text, "RIGHT\n");
            select->type = 2;
            select->action = true;
            break;
        case KEY_BACKSPACE :
            endwin();
            exit(0);
        case 27:
            endwin();
            exit(0);
        default:
            printw("%s\n", select->map);
    }
    printw("%s\n", select->map);
    return 0;
}
