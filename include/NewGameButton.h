#pragma once
#include "BaseButton.h"

class NewGameButton : public BaseButton
{
public:
    NewGameButton(const std::string& imagePath, float m_x, float m_y);
    void onClick() override;
};