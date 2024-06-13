#include <SFML/Graphics.hpp>
#include "BaseObject.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "brawl stars");          //����� ���� ����� 800*600



        
    
    sf::Texture exampleMapTexture;                          
    if (!exampleMapTexture.loadFromFile("exampleMap.png"))  //����� ������� ���� ����� �����
    {
        return -1;
    }
    sf::Sprite mapSprite(exampleMapTexture);                   //����� ������ ���� �� �������� ���
    mapSprite.setScale(window.getSize().x / mapSprite.getLocalBounds().width,
        window.getSize().y / mapSprite.getLocalBounds().height);             //����� ���� ����� �����
    

    sf::Texture examplePlayerTexture;       //������� �����
    if (!examplePlayerTexture.loadFromFile("examplePlayer.png"))
    {
        return -1;
    }

    sf::Vector2f position(300.0f, 200.0f);  //����� ����� 
    BaseObject myPlayer(examplePlayerTexture, position);      //���� �� ����� �� ��� ����� ��������
    myPlayer.setSpriteScale(0.05f, 0.05f);    //����� ���� ������� �� �����

    sf::View view(sf::FloatRect(0, 0, 400, 300));           //����� ��� ����� ����� ����� �� ��� ��� ����� ����
    view.setCenter(myPlayer.getSpriteLocation());         //����� �� ���� ���� ����� ����� ���� ����� ����� ����� ���� ��� ������



    while (window.isOpen())                         //����� ����� �� ���� �� ���� �� �����
    {
        sf::Event event;                                //����� ����� ������ ����� �� ����� 
        while (window.pollEvent(event))             //����� ��� �� �������
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))            //����� ���� ����� ���� ����� ���� �� ������ ������ ����� ��� ����� ������� ���� �� �� �����
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

        view.setCenter(myPlayer.getSpriteLocation());           //����� ���� �� ��� �� ������� ���� �����
        window.setView(view);           //��� ������ ����� ������ ������� ���� ��� ���� ������ 

       
        window.clear();             
        window.draw(mapSprite);         //���� ����
        myPlayer.draw(window);       //���� �����
        window.display();       //���� �� �����
    }



}

