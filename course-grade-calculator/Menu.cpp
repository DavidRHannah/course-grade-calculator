#include "Menu.h"

Menu::Menu(const std::vector<std::string>& labels, const std::vector<std::function<void()>>& actions)
    : labels(labels), actions(actions), optionCount(labels.size()) {}

void Menu::run() const {
    int selected = 1;
    while (true) {
        displayMenu(selected);
        int key = _getch();
        switch (key) {
        case KEY_UP:
            selected = (selected == 1) ? optionCount : selected - 1;
            break;
        case KEY_DOWN:
            selected = (selected == optionCount) ? 1 : selected + 1;
            break;
        case KEY_ENTER:
            actions[selected - 1]();
            return;
        }
    }
}

void Menu::displayMenu(int selected) const {
    std::system("CLS");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (size_t i = 0; i < labels.size(); ++i) {
        if (i + 1 == selected) {
            SetConsoleTextAttribute(console, 240);
            std::cout << labels[i] << std::endl;
            SetConsoleTextAttribute(console, 15);
        }
        else {
            std::cout << labels[i] << std::endl;
        }
    }
}