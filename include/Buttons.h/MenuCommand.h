#include "Buttons.h/CommandButton.h"


class MenuCommand : public CommandButton {
public:
    StateOptions execute() override;
};
