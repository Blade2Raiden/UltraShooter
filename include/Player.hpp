#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalFunctions.h"

class Player : public sf::CircleShape
{
public:
Player(sf::Vector2f init_position);
void SetRenderWindow(const sf::RenderWindow &mynewWindow);
float Shoot(sf::Vector2f TargetPosition);
~Player();

private:

    bool IamImmune;
    float rayon, ImmuneTime;
    //Immunity Timer
    unsigned long Score;
    unsigned short Life;
sf::RenderWindow* myWindow;

  std::string PlayerName;
};

#endif // PLAYER_HPP_INCLUDED