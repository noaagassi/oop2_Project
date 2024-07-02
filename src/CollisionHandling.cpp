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
#include "Objects.h/LifeGiftObject.h"
#include "Objects.h/FreezeGiftObject.h"
#include"Objects.h/PoisonObject.h"
#include"Objects.h/WeaponGiftObject.h"
#include "Objects.h/BulletObject.h"




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


    

    ////////////////////////////////////////////////////////////////////////////////////
    // primary collision-processing functions
    void playerBush (BaseObject& player, BaseObject& bush)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        BushObject&  real_bush  = dynamic_cast<BushObject&>(bush);


        std::cout << "Player and Bush collision!\n";

        real_bush.makeTranslucent();
        real_player.setInBush(true);
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
        
        PortalObject* target_portal = real_portal.getRandomPortal();
        sf::Vector2f target_position = target_portal->getSprite().getPosition();
        sf::Vector2f offset(0.f, 40.f);
        target_position += offset;
        real_player.setPosition(target_position);

    }

    void playerLife(BaseObject& player, BaseObject& life)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        LifeGiftObject& real_life = dynamic_cast<LifeGiftObject&>(life);

        std::cout << "Player and Life Gift collision!\n";

        real_life.toDelete(true);

    }

    void playerFreeze(BaseObject& player, BaseObject& freeze)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        FreezeGiftObject& real_freeze = dynamic_cast<FreezeGiftObject&>(freeze);

        std::cout << "Player and Freeze Gift collision!\n";

        real_freeze.toDelete(true);


    }

    void playerWeapon(BaseObject& player, BaseObject& weapon)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        WeaponGiftObject& real_weapon = dynamic_cast<WeaponGiftObject&>(weapon);

        std::cout << "Player and Weapon Gift collision!\n";

        real_weapon.toDelete(true);
       
    }

    void playerPoison(BaseObject& player, BaseObject& poison)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        PoisonObject& real_poison = dynamic_cast<PoisonObject&>(poison);

        std::cout << "Player and Poison collision!\n";

       

    }
    /*
    void playerBullet(BaseObject& player, BaseObject& bullet)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        BulletObject& real_bullet = dynamic_cast<BulletObject&>(bullet);

        std::cout << "Player and Bullet collision!\n";

    }

    void bulletPlayer(BaseObject& bullet, BaseObject& player)
    {
        playerBullet(player, bullet);
    }
    */
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
        phm[Key(typeid(PlayerObject), typeid(LifeGiftObject))] = &playerLife;
        phm[Key(typeid(PlayerObject), typeid(FreezeGiftObject))] = &playerFreeze;
        phm[Key(typeid(PlayerObject), typeid(WeaponGiftObject))] = &playerWeapon;
        phm[Key(typeid(PlayerObject), typeid(PoisonObject))] = &playerPoison;
        //phm[Key(typeid(PlayerObject), typeid(BulletObject))] = &playerBullet;
        //phm[Key(typeid(BulletObject), typeid(PlayerObject))] = &bulletPlayer;

       
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
