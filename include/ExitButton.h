#include "BaseButton.h"

class ExitButton : public BaseButton {
public:
    ExitButton(const std::string& imagePath, float m_x, float m_y);
    void onClick() override;
};