#include <SFML/Graphics.hpp>


class GameState {
public:
	GameState();

	virtual void draw(sf::RenderWindow & window)=0;
	virtual void update(sf::RenderWindow & window)=0;

	virtual GameState* isStateChanged() = 0;



private:

};