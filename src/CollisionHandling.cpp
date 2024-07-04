#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "SoundsHandler.h"

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
#include "Objects.h/BallObject.h"
#include "Objects.h/RocketObject.h"
#include "Objects.h/SmallFastEnemyObject.h"
#include "Objects.h/BigSlowEnemyObject.h"





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


        

        real_bush.makeTranslucent();
        real_player.setInBush(true);
    }

    void playerWall (BaseObject& player, BaseObject& wall)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        WallObject& real_wall = dynamic_cast<WallObject&>(wall);

        

        sf::FloatRect playerBounds = real_player.getSprite().getGlobalBounds();
        sf::FloatRect wallBounds = real_wall.getSprite().getGlobalBounds();

        stopAdvance(playerBounds, wallBounds, real_player);
    }
    
    
    void playerTree(BaseObject& player, BaseObject& tree)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        TreeObject& real_tree = dynamic_cast<TreeObject&>(tree);

        

        sf::FloatRect playerBounds = real_player.getSprite().getGlobalBounds();
        sf::FloatRect treeBounds = real_tree.getSprite().getGlobalBounds();

        stopAdvance(playerBounds, treeBounds, real_player);
    }

    void playerPortal(BaseObject& player, BaseObject& portal)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        PortalObject& real_portal = dynamic_cast<PortalObject&>(portal);

       
        SoundsHandler::getInstance().playSound(Sound_Id::PORTAL_ENTER);


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
        SoundsHandler::getInstance().playSound(Sound_Id::EXTRA_LIFE);

        real_player.ateLiveGift();

        real_life.toDelete(true);

    }

    void playerFreeze(BaseObject& player, BaseObject& freeze)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        FreezeGiftObject& real_freeze = dynamic_cast<FreezeGiftObject&>(freeze);

       

        real_freeze.toDelete(true);
        SoundsHandler::getInstance().playSound(Sound_Id::FREEZE);


    }

    void playerWeapon(BaseObject& player, BaseObject& weapon)
    {
        PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
        WeaponGiftObject& real_weapon = dynamic_cast<WeaponGiftObject&>(weapon);

        

        real_weapon.toDelete(true);
        SoundsHandler::getInstance().playSound(Sound_Id::WEAPON_GIFT);
        real_player.weaponGift();
       
    }

    //void playerPoison(BaseObject& player, BaseObject& poison)
    //{
    //    PlayerObject& real_player = dynamic_cast<PlayerObject&>(player);
    //    PoisonObject& real_poison = dynamic_cast<PoisonObject&>(poison);
    //    //SoundsHandler::getInstance().playSound(Sound_Id::POISON_HIT);
    //}
    void ballWall(BaseObject& bullet, BaseObject& wall)
    {
        
        BallObject& real_bullet = dynamic_cast<BallObject&>(bullet);
        WallObject& real_wall = dynamic_cast<WallObject&>(wall);
        SoundsHandler::getInstance().playSound(Sound_Id::BALL_HIT);
        
        real_bullet.toDelete(true);

    }
    void ballTree(BaseObject& bullet, BaseObject& tree)
    {

        BallObject& real_bullet = dynamic_cast<BallObject&>(bullet);
        TreeObject& real_tree = dynamic_cast<TreeObject&>(tree);

        
        SoundsHandler::getInstance().playSound(Sound_Id::BALL_HIT);
        
        real_bullet.toDelete(true);

    }


   

    
    void rocketTree(BaseObject& bullet, BaseObject& tree)
    {

        RocketObject& real_bullet = dynamic_cast<RocketObject&>(bullet);
        TreeObject& real_tree = dynamic_cast<TreeObject&>(tree);
        SoundsHandler::getInstance().playSound(Sound_Id::BALL_HIT);
        
        real_bullet.toDelete(true);

    }


    

    

    void smallEnemyTree(BaseObject& enemy, BaseObject& tree)
    {
        SmallFastEnemyObject& real_enemy = dynamic_cast<SmallFastEnemyObject&>(enemy);
        TreeObject& real_tree = dynamic_cast<TreeObject&>(tree);

        

        sf::FloatRect enemyBounds = real_enemy.getSprite().getGlobalBounds();
        sf::FloatRect treeBounds = real_tree.getSprite().getGlobalBounds();

        stopAdvance(enemyBounds, treeBounds, real_enemy);
    }

    void smallEnemyWall(BaseObject& enemy, BaseObject& wall)
    {
        SmallFastEnemyObject& real_enemy = dynamic_cast<SmallFastEnemyObject&>(enemy);
        WallObject& real_wall = dynamic_cast<WallObject&>(wall);

       

        sf::FloatRect enemyBounds = real_enemy.getSprite().getGlobalBounds();
        sf::FloatRect wallBounds = real_wall.getSprite().getGlobalBounds();

        stopAdvance(enemyBounds, wallBounds, real_enemy);
    }

    void smallEnemyPortal(BaseObject& enemy, BaseObject& portal)
    {
        SmallFastEnemyObject& real_enemy = dynamic_cast<SmallFastEnemyObject&>(enemy);
        PortalObject& real_portal = dynamic_cast<PortalObject&>(portal);

        SoundsHandler::getInstance().playSound(Sound_Id::PORTAL_ENTER);


        PortalObject* target_portal = real_portal.getRandomPortal();
        sf::Vector2f target_position = target_portal->getSprite().getPosition();
        sf::Vector2f offset(0.f, 40.f);
        target_position += offset;
        real_enemy.setPosition(target_position);

    }


    void smallEnemyPoison(BaseObject& enemy, BaseObject& poison)
    {
        SmallFastEnemyObject& real_enemy = dynamic_cast<SmallFastEnemyObject&>(enemy);
        PoisonObject& real_poison = dynamic_cast<PoisonObject&>(poison);
        //SoundsHandler::getInstance().playSound(Sound_Id::POISON_HIT);

        



    }







    void nothingToDo(BaseObject& a, BaseObject& b)
    {

    }
    
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
        //phm[Key(typeid(PlayerObject), typeid(PoisonObject))] = &playerPoison;

        phm[Key(typeid(BallObject), typeid(WallObject))] = &ballWall;
        phm[Key(typeid(BallObject), typeid(TreeObject))] = &ballTree;
        phm[Key(typeid(BallObject), typeid(LifeGiftObject))] = &nothingToDo;
        phm[Key(typeid(BallObject), typeid(FreezeGiftObject))] = &nothingToDo;
        phm[Key(typeid(BallObject), typeid(WeaponGiftObject))] = &nothingToDo;
        phm[Key(typeid(BallObject), typeid(BallObject))] = &nothingToDo;
        phm[Key(typeid(PlayerObject), typeid(BallObject))] = &nothingToDo;
        phm[Key(typeid(BallObject), typeid(PlayerObject))] = &nothingToDo;
        phm[Key(typeid(RocketObject), typeid(WallObject))] = &nothingToDo;
        phm[Key(typeid(RocketObject), typeid(TreeObject))] = &rocketTree;
        phm[Key(typeid(RocketObject), typeid(LifeGiftObject))] = &nothingToDo;
        phm[Key(typeid(RocketObject), typeid(FreezeGiftObject))] = &nothingToDo;
        phm[Key(typeid(RocketObject), typeid(WeaponGiftObject))] = &nothingToDo;

        phm[Key(typeid(SmallFastEnemyObject), typeid(BushObject))] = &nothingToDo;
        phm[Key(typeid(SmallFastEnemyObject), typeid(WallObject))] = &smallEnemyWall;
        phm[Key(typeid(SmallFastEnemyObject), typeid(TreeObject))] = &smallEnemyTree;
        phm[Key(typeid(SmallFastEnemyObject), typeid(PortalObject))] = &smallEnemyPortal;
        phm[Key(typeid(SmallFastEnemyObject), typeid(LifeGiftObject))] = &nothingToDo;
        phm[Key(typeid(SmallFastEnemyObject), typeid(FreezeGiftObject))] = &nothingToDo;
        phm[Key(typeid(SmallFastEnemyObject), typeid(WeaponGiftObject))] = &nothingToDo;
        phm[Key(typeid(SmallFastEnemyObject), typeid(PoisonObject))] = &smallEnemyPoison;

        phm[Key(typeid(BigSlowEnemyObject), typeid(BushObject))] = &nothingToDo;
        //phm[Key(typeid(BigSlowEnemyObject), typeid(WallObject))] = &bigEnemyWall;
        //phm[Key(typeid(BigSlowEnemyObject), typeid(TreeObject))] = &bigEnemyTree;
        //phm[Key(typeid(BigSlowEnemyObject), typeid(PortalObject))] = &bigEnemyPortal;
        phm[Key(typeid(BigSlowEnemyObject), typeid(LifeGiftObject))] = &nothingToDo;
        phm[Key(typeid(BigSlowEnemyObject), typeid(FreezeGiftObject))] = &nothingToDo;
        phm[Key(typeid(BigSlowEnemyObject), typeid(WeaponGiftObject))] = &nothingToDo;
       // phm[Key(typeid(BigSlowEnemyObject), typeid(PoisonObject))] = &bigEnemyPoison;
       
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
