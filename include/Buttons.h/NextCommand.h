#pragma once

#include "Buttons.h/CommandButton.h"


class NextCommand : public CommandButton {
public:
    StateOptions execute() override;
};
