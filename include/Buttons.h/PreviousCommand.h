#pragma once

#include "Buttons.h/CommandButton.h"


class PreviousCommand : public CommandButton {
public:
    StateOptions execute() override;
};
