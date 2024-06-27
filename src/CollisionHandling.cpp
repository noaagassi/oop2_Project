#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Objects.h/PlayerObject.h"
#include "Objects.h/BushObject.h"
#include "Objects.h/WallObject.h"
#include "Objects.h/PortalObject.h"
#include "Objects.h/TreeObject.h"




namespace // anonymous namespace — the standard way to make function "static"
{
    void stopAdvance(sf::FloatRect& subjectBounds, const sf::FloatRect& objectBounds, MovingObject& subject)
    {
        float overlapLeft = subjectBounds.left + subjectBounds.width - objectBounds.left;
        float overlapRight = objectBounds.left + objectBounds.width - subjectBounds.left;
        float overlapTop = subjectBounds.top + subjectBounds.height - objectBounds.top;
        float overlapBottom = objectBounds.top + objectBounds.height - subjectBounds.top;

        bool moveLeft = overlapLeft < overlapRight;
        bool moveUp = overlapTop < overlapBottom;

        float minOverlapX = moveLeft ? overlapLeft : overlapRight;
        float minOverlapY = moveUp ? overlapTop : overlapBottom;

        sf::Vector2f newPosition = subject.getSprite().getPosition();

        if (minOverlapX < minOverlapY) {
            newPosition.x = moveLeft ? objectBounds.left - subjectBounds.width : objectBounds.left + objectBounds.width;
        }
        else {
            newPosition.y = moveUp ? objectBounds.top - subjectBounds.height : objectBounds.top + objectBounds.height;
        }

        subject.setPosition(newPosition);
    }


    PortalObject& getRandomPortal(const PortalObject& currentPortal, const std::vector<std::unique_ptr<StaticObject>>& portals)
    {
        std::srand(static_cast<unsigned int>(std::time(0))); 
        PortalObject* randomPortal = nullptr;
        do {
            int randomIndex = std::rand() % portals.size();
            randomPortal = dynamic_cast<PortalObject*>(portals[randomIndex].get());
        } while (randomPortal == &currentPortal || randomPortal == nullptr);

        return *randomPortal;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    // primary collision-processing functions
    void playerBush (BaseObject& player, BaseObject& bush)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        BushObject&  real_bush  = dynamic_cast<BushObject&>(bush);


        std::cout << "Player and Bush collision!\n";
    }

    void playerWall (BaseObject& player, BaseObject& wall)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        WallObject& real_wall = dynamic_cast<WallObject&>(wall);

        std::cout << "player and wall collision!\n";

        sf::FloatRect playerBounds = real_player.getSprite().getGlobalBounds();
        sf::FloatRect wallBounds = real_wall.getSprite().getGlobalBounds();

        stopAdvance(playerBounds, wallBounds, real_player);
    }
    
    
    void playerTree(BaseObject& player, BaseObject& tree)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        TreeObject& real_tree = dynamic_cast<TreeObject&>(tree);

        std::cout << "Player and Tree collision!\n";

        sf::FloatRect playerBounds = real_player.getSprite().getGlobalBounds();
        sf::FloatRect treeBounds = real_tree.getSprite().getGlobalBounds();

        stopAdvance(playerBounds, treeBounds, real_player);
    }

    void playerPortal(BaseObject& player, BaseObject& portal)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        PortalObject& real_portal = dynamic_cast<PortalObject&>(portal);

        std::cout << "Player and Portal collision!\n";
        /*
        PortalObject& target_portal = real_portal.getRandomPortal();
        std::cout << "tengo un  potal";
        sf::Vector2f target_position = target_portal.getSprite().getPosition();
        real_player.setPosition(target_position);

        sf::FloatRect playerBounds = real_player.getSprite().getGlobalBounds();
        sf::FloatRect portalBounds = real_portal.getSprite().getGlobalBounds();

        stopAdvance(playerBounds, portalBounds, real_player);
        std::cout << "cambie de lugar"; 
        */
    }

    //...

    // secondary collision-processing functions that just
    // implement symmetry: swap the parameters and call a
    // primary function
    void bushPlayer (BaseObject& bush, BaseObject& player)
    {
        playerBush(player, bush);
    }

    void WallPlayer(BaseObject& wall, BaseObject& player)
    {
        playerWall(player, wall);
    }
    void portalPlayer(BaseObject& wall, BaseObject& player)
    {
        playerPortal(player, wall);
    }
    //...
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    using HitFunctionPtr = void (*)(BaseObject&, BaseObject&);
   
    using Key = std::pair<std::type_index, std::type_index>;
   
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(PlayerObject), typeid(BushObject))] = &playerBush;
        phm[Key(typeid(PlayerObject), typeid(WallObject))] = &playerWall;
        phm[Key(typeid(PlayerObject), typeid(TreeObject))] = &playerTree;
        phm[Key(typeid(PlayerObject), typeid(PortalObject))] = &playerPortal;

        phm[Key(typeid(BushObject), typeid(PlayerObject))] = &bushPlayer;
        phm[Key(typeid(WallObject), typeid(PlayerObject))] = &WallPlayer;
        phm[Key(typeid(PortalObject), typeid(PlayerObject))] = &portalPlayer;

       
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(BaseObject& object1, BaseObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
