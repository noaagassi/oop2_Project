#pragma once
#include "Utilities.h"
class CommandButton {
public:
    virtual ~CommandButton() {}
    virtual StateOptions execute() = 0;
};
