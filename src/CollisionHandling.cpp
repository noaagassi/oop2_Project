#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Objects.h/PlayerObject.h"
#include "Objects.h/BushObject.h"
#include "Objects.h/WallObject.h"


namespace // anonymous namespace — the standard way to make function "static"
{

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
    }

    
    //...

    // secondary collision-processing functions that just
    // implement symmetry: swap the parameters and call a
    // primary function
    void bushPlayer (BaseObject& bush, BaseObject& player)
    {
        playerBush(player, bush);
    }
    void WallPlayer(BaseObject& wall,
        BaseObject& player)
    {
        playerWall(player, wall);
    }
    //...

    using HitFunctionPtr = void (*)(BaseObject&, BaseObject&);
   
    using Key = std::pair<std::type_index, std::type_index>;
   
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(PlayerObject), typeid(BushObject))] = &playerBush;
        phm[Key(typeid(PlayerObject), typeid(WallObject))] = &playerWall;
        phm[Key(typeid(BushObject), typeid(PlayerObject))] = &bushPlayer;
        phm[Key(typeid(WallObject), typeid(PlayerObject))] = &WallPlayer;
       
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
