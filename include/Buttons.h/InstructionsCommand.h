#pragma once
#include "Buttons.h/CommandButton.h"

class InstructionsCommand : public CommandButton {
public:
    StateOptions execute() override;
};
