#pragma once
#include "BaseButton.h"

class NewGameButton : public BaseButton
{
public:
    NewGameButton(const std::string& imagePath, float x, float y);
    StateOptions handleClick() override;
};