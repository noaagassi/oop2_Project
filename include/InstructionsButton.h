#include "BaseButton.h"

class InstructionsButton : public BaseButton {
public:
    InstructionsButton (const std::string& imagePath, float x, float y);
    void onClick() override;
};