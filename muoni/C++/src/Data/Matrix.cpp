//
// Created by Joel Courtney on 2019-03-02.
//

#include "Data/Matrix.h"

Matrix::Matrix(Type t) : Numeric(t) {}

std::string Matrix::formatMatrix(const std::string& str)
{
    const std::string& delimiter = "\n";
    std::vector<std::string> lines;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        lines.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    lines.push_back(str.substr(prev));
    int rows = lines.size();
    if (rows == 1) {
        return '(' + lines[0] + ')';
    }
    std::string s = "⎛" + lines[0] + "⎞";
    for (int i = 1; i < rows - 1; i++) {
        s += "\n⎜" + lines[i] + "⎟";
    }
    s += "\n⎝" + lines[rows-1] + "⎠";
    return s;
}