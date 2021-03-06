#include "CollisionManager.hpp"
#include <iostream>

CollisionManager::CollisionManager(Player& p_player, Map& p_gameMap):player(p_player), gameMap(p_gameMap), lObstacles(p_gameMap.getListeObstacles())
{

}

bool CollisionManager::CollisionJoueur(float x, float y){

    collision = false;
    update_x = false;
    update_y = false;
    deplacement_x = 0.0f;
    deplacement_y = 0.0f;

    if(CheckIfOutOfWindow(player.getPosition(), x, y, player.getRayon())){

        collision = true;
        CalculDistanceAParcourirBordMap(x, y);
    }
    else{

        for(std::list<Obstacle>::const_iterator it = lObstacles.begin(); it != lObstacles.end() && !collision; ++it){

            if(player.getGlobalBounds().intersects(it->getCollisionBox())){

                collision = true;
                CalculDistanceAParcourir(x, y, it->getCollisionBox());
            }
        }
    }

    return collision;
}

bool CollisionManager::CheckIfOutOfWindow(sf::Vector2f Position, float p_deplacement_x, float p_deplacement_y, float rayon)
{
    if( static_cast<int>(Position.x-rayon) < 0                    ||
            static_cast<unsigned int>(Position.x+rayon) > gameMap.getWidth() ||
            static_cast<int>(Position.y-rayon) < 0                    ||
            static_cast<unsigned int>(Position.y+rayon) > gameMap.getHeight())

        return true;

    else
        return false;
}

void CollisionManager::CalculDistanceAParcourir(float p_deplacement_x, float p_deplacement_y, sf::FloatRect rect){

    if(p_deplacement_x>0 && rect.left-player.getPosition().x-p_deplacement_x-player.getRayon() < player.getVitesse())
            deplacement_x=rect.left-(player.getPosition().x-p_deplacement_x)-player.getRayon();
    if(p_deplacement_x<0 && player.getPosition().x-p_deplacement_x-player.getRayon()-rect.left-rect.width < player.getVitesse())
            deplacement_x= -(player.getPosition().x-p_deplacement_x-player.getRayon()-rect.left-rect.width);
    if(p_deplacement_y>0 && rect.top -player.getPosition().y-p_deplacement_y-player.getRayon() < player.getVitesse())
            deplacement_y=rect.top-(player.getPosition().y-p_deplacement_y)-player.getRayon();
    if(p_deplacement_y<0 && player.getPosition().y-p_deplacement_y-player.getRayon()-rect.top-rect.height < player.getVitesse())
            deplacement_y= -(player.getPosition().y-p_deplacement_y-player.getRayon()-rect.top-rect.height);

            //std::cout << deplacement_x << std::endl;
}

void CollisionManager::CalculDistanceAParcourirBordMap(float p_deplacement_x, float p_deplacement_y){

    if(p_deplacement_x>0 && gameMap.getWidth()-player.getPosition().x-p_deplacement_x-player.getRayon() < player.getVitesse()){

            deplacement_x=gameMap.getWidth()-(player.getPosition().x-p_deplacement_x)-player.getRayon();
            update_x=true;
    }
    if(p_deplacement_x<0 && player.getPosition().x-p_deplacement_x-player.getRayon() < player.getVitesse()){

            deplacement_x=-(player.getPosition().x-p_deplacement_x)+player.getRayon();
            update_x=true;
    }
    if(p_deplacement_y>0 && gameMap.getHeight()-player.getPosition().y-p_deplacement_y-player.getRayon() < player.getVitesse()){

            deplacement_y=gameMap.getHeight()-(player.getPosition().y-p_deplacement_y)-player.getRayon();
            update_y=true;
    }
    if(p_deplacement_y<0 && player.getPosition().y-p_deplacement_y-player.getRayon() < player.getVitesse()){

            deplacement_y=-(player.getPosition().y-p_deplacement_y)+player.getRayon();
            update_y=true;
    }

    if(!update_x)
            deplacement_x = p_deplacement_x;
    if(!update_y)
            deplacement_y = p_deplacement_y;
}

float CollisionManager::getDeplacementX(){

    return deplacement_x;
}

float CollisionManager::getDeplacementY(){

    return deplacement_y;
}

CollisionManager::~CollisionManager()
{
    //dtor
}
