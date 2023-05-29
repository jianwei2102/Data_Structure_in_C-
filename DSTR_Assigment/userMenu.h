#pragma once

#include <iostream>

#include "userMenuUI.h"
#include "repository.h"

struct userMenu {
    static void userLogin() {
        while (true)
        {
            system("cls");
            userMenuUI::loginMenu_UI();
            
            string username, password;
            cout << "Please enter user's username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Please enter user's password: ";
            getline(cin, password);

            Repository* r = Repository::getInstance();

            UserNode* currentUser = r->AllUserList->searchUser(username);
            if (currentUser->Username == username && currentUser->Password == password) {
                r->loginUser = currentUser;
                mainMenu();
                return;
            }
            else {
                cout << endl << "Invalid username and password!" << endl;
                cout << "1 - Retry login" << endl;
                cout << "2 - Return to Main Menu" << endl;

                int choice = 0;
                cout << "Select an Operation Number: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    userLogin();
                    break;
                case 2:
                    return;
                default:
                    userLogin();
                    break;
                }
            }
        }
    }

    static void mainMenu() {
        Repository* r = Repository::getInstance();

        while (true)
        {
            system("cls");
            int choice = userMenuUI::mainMenu_UI();

            switch (choice)
            {
            case 1:
                //r->AllUniList->displayUniList();
                break;
            case 2:
                r->AllUserList->displayUserList();
            case 3:
                // feedback
                break;
            case 4:
                return;
            default:
                mainMenu();
                break;
            }
        }
    }
};