#include <SFML/Graphics.hpp>
#include "BaseObject.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "brawl stars");          //יצירת חלון בגודל 800*600
	
    
    
    
    
    sf::Texture exampleMapTexture;                          
    if (!exampleMapTexture.loadFromFile("exampleMap.png"))  //יצירת טקסטורה למפה שתוצג בחלון
    {
        return -1;
    }
    sf::Sprite mapSprite(exampleMapTexture);                   //יצירת ספרייט למפה עם הטקסטורה שלה
    mapSprite.setScale(window.getSize().x / mapSprite.getLocalBounds().width,
        window.getSize().y / mapSprite.getLocalBounds().height);             //התאמת המפה לגודל החלון
    

    sf::Texture examplePlayerTexture;       //טקסטורה לשחקן
    if (!examplePlayerTexture.loadFromFile("examplePlayer.png"))
    {
        return -1;
    }

    sf::Vector2f position(300.0f, 200.0f);  //מיקום לשחקן 
    BaseObject myPlayer(examplePlayerTexture, position);      //בנאי של השחקן על ידי מיקום וטקסטורה
    myPlayer.setSpriteScale(0.05f, 0.05f);    //קביעת גודל הספרייט של השחקן

    sf::View view(sf::FloatRect(0, 0, 400, 300));           //יצירת ויו שישמש אותנו לראות רק חלק קטן מהמסך כולו
    view.setCenter(myPlayer.getSpriteLocation());         //המרכז של הויו יהיה השחקן כלומר הויו יתחיל מסביב השחקן כאשר הוא במרכזו



    while (window.isOpen())                         //לולאת החלון שם נזיז את הויו עם השחקן
    {
        sf::Event event;                                //יצירת אירוע לבדיקת תזוזה של השחקן 
        while (window.pollEvent(event))             //בדיקת האם יש אירועים
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))            //בדיקה איזה כפתור נלחץ למעלה למטה או לצדדים ובנוסף בדיקה שלא יצאנו מגבולות המפה על כל לחיצה
        {
            if (myPlayer.getSprite().getGlobalBounds().left > mapSprite.getGlobalBounds().left)
                myPlayer.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (myPlayer.getSprite().getGlobalBounds().left + myPlayer.getSprite().getGlobalBounds().width < mapSprite.getGlobalBounds().left + mapSprite.getGlobalBounds().width)
                myPlayer.move(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (myPlayer.getSprite().getGlobalBounds().top > mapSprite.getGlobalBounds().top)
                myPlayer.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (myPlayer.getSprite().getGlobalBounds().top + myPlayer.getSprite().getGlobalBounds().height < mapSprite.getGlobalBounds().top + mapSprite.getGlobalBounds().height)
                myPlayer.move(0, 1);
        }

        view.setCenter(myPlayer.getSpriteLocation());           //מיקום הויו כל פעם כך שבמרכזו יהיה השחקן
        window.setView(view);           //כאן אומרים לחלון שאנחנו מסתכלים עליו דרך הויו שיצרנו 

       
        window.clear();             
        window.draw(mapSprite);         //ציור המפה
        myPlayer.draw(window);       //ציור השחקן
        window.display();       //הצגה על החלון
    }

    return 0;
}


