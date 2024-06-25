#include "Buttons.h/ResumeGameCommand.h"
#include <iostream>

StateOptions ResumeGameCommand::execute()
{
	std::cout << "Resume button clicked!" << std::endl;
	return ResumeScrn;
}
