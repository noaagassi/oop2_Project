#include "BaseButton.h"

class ExitButton : public BaseButton {
public:
    ExitButton(const std::string& imagePath, float x, float y);
    StateOptions handleClick() override;
};