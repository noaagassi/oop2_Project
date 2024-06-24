#pragma once

#include "Buttons.h/CommandButton.h"

class ResumeGameCommand : public CommandButton {
public:
    StateOptions execute() override;
};
