//
// Created by Joel Courtney on 2019-03-10.
//

#include "Syntax/BreakSnake.h"

BreakSnake::BreakSnake(const BreakSnake& s) {
    std::copy(s.snake.begin(),s.snake.end(),std::back_inserter(snake));
}

void BreakSnake::push(BreakSegment s) {
    snake.push_back(s);
}

BreakSegment BreakSnake::pop() {
    BreakSegment s = snake.back();
    snake.pop_back();
    return s;
}

std::string BreakSnake::toString() const {
    std::string result = "<";
    for (BreakSegment s : snake) {
        switch (s) {
            case Dash:
                result += "-";
                break;
            case Tilde:
                result += "~";
                break;
            case Equal:
                result += "=";
                break;
        }
    }
    return result;
}
