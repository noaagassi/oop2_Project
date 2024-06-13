file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "Menu.cpp"  "../include/Menu.h" "../include/BaseButton.h" "BaseButton.cpp" "../include/NewGameButton.h" "NewGameButton.cpp" "../include/TextureHandler.h" "TextureHandler.cpp" "../include/Board.h" "Board.cpp" "../include/BaseObject.h" "BaseObject.cpp"
"../include/screenFolder.h/GameState.h" "../src/screenFolder.cpp/GameState.cpp")
