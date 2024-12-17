#include "Menu.h"

Menu::Menu(const std::vector<std::string>& labels, const std::vector<std::function<void()>>& actions)
    : m_labels(labels), m_actions(actions), m_optionCount(labels.size()) {}
 
void Menu::run() const {
    int selected = 1;
    while (true) {
        display(selected);
        int key = _getch();
        switch (key) {
        case KEY_UP:
            selected = (selected == 1) ? m_optionCount : selected - 1;
            break;
        case KEY_DOWN:
            selected = (selected == m_optionCount) ? 1 : selected + 1;
            break;
        case KEY_ENTER:
            this->m_actions[selected - 1]();
            return;
        }
    }
}

void Menu::display(int selected) const {
    std::system("CLS");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < m_labels.size(); ++i) {
        if (i + 1 == selected) {
            SetConsoleTextAttribute(console, 240);
            std::cout << m_labels[i] << std::endl;
            SetConsoleTextAttribute(console, 15);
        }
        else {
            std::cout << m_labels[i] << std::endl;
        }
    }
}