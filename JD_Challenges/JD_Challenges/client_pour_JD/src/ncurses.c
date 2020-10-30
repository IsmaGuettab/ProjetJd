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
        case "CECI EST UNE ACTION":     /**/
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
        /*
         *
         * */
        case KEY_BACKSPACE :
            endwin();
            exit(0);
        case 27:
            endwin();
            exit(0);
        default:
            printw("Ces boutons ne servent a rien ! Par contre tu peux afficher la carte à la place de ce texte...\n");
    }
    printw("%s\n", select->map);
    return 0;
}
