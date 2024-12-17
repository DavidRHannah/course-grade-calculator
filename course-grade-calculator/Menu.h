#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <functional>
using std::vector;
using std::function;
using std::string;

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;

class Menu {
private:
    unsigned int m_optionCount;
    vector<string> m_labels;
    vector<function<void()>> m_actions;

public:
    Menu(const vector<string>& labels, const vector<function<void()>>& actions);
    void run() const;
private:
    void display(int selected) const;
};
