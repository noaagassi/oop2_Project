#include "BaseButton.h"

class InstructionsButton : public BaseButton {
public:
    InstructionsButton (const std::string& imagePath, float m_x, float m_y);
    void onClick() override;
};