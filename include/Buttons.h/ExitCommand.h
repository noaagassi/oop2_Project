#pragma once

#include "Buttons.h/CommandButton.h"


class ExitCommand : public CommandButton {
public:
    StateOptions execute() override;
};