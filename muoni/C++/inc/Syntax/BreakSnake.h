//
// Created by Joel Courtney on 2019-03-10.
//

#ifndef C_BREAKSNAKE_H
#define C_BREAKSNAKE_H

#include <vector>
#include <string>

enum BreakSegment {
    Dash,
    Tilde,
    Equal
};

class BreakSnake {
    std::vector<BreakSegment> snake;

public:
    BreakSnake() = default;
    BreakSnake(const BreakSnake&);

    void push(BreakSegment);
    BreakSegment pop();

    std::string toString() const;
};

#endif //C_BREAKSNAKE_H
