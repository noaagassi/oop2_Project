#pragma once

#include "Buttons.h/CommandButton.h"


class PauseGameCommand : public CommandButton {
public:
    StateOptions execute() override;
};
