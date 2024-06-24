#pragma once

#include "Buttons.h/CommandButton.h"

class StartGameCommand : public CommandButton {
public:
    StateOptions execute() override;
};
