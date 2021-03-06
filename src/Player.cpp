#include "Player.hpp"
#include "GlobalFunctions.h"
#include "Engine.hpp"

using namespace std;
using namespace sf;


Player::Player(sf::Vector2f init_position, sf::Font font, sf::Vector2f sizeWindow):Life(100), Score(0), hud(Life, Score, font, sizeWindow), rect(init_position.x-50, init_position.y-50, 100, 100)
{
    rayon=50.f;

    Player::setRadius(rayon);
    Player::setFillColor(sf::Color::Blue);
    Player::setPosition(init_position);
    Player::setOrigin(50.f, 50.f);
}

/*void Player::SetRenderWindow(sf::RenderWindow &mynewWindow)
{
mynewWindow.co;

}*/

float Player::Shoot(sf::Vector2f TargetPosition, sf::RenderWindow &myRenderWindow)
{
weapon_clock.restart();
    Vector2i player_pixel_position=Player::GetWindowPosition(myRenderWindow);

    sf::Vector2f converted_player_coord;

    converted_player_coord.x=(float)player_pixel_position.x;
    converted_player_coord.y=(float)player_pixel_position.y;

    float x1=converted_player_coord.x;
    float y1=converted_player_coord.y;
    float x2=TargetPosition.x;
    float y2=TargetPosition.y;
    float a=x2-x1;
    float o=y2-y1;
    float angle;

    Engine::getInstance()->getMusicManager()->playEvent("ressources/sounds/events/sf_laser_18.ogg");

    return  angle = atan2(-o, a);

//return GetAngle_v2f(Player::getPosition(), TargetPosition);
}

bool Player::ReadyToShoot() const
{
Int32 time=weapon_clock.getElapsedTime().asMilliseconds();
if (time>80) return true;
else return false;
}

sf::Vector2i Player::GetWindowPosition(sf::RenderWindow &theRenderWindow) const
{
    return theRenderWindow.mapCoordsToPixel(Player::getPosition(), theRenderWindow.getView());
}

sf::Text Player::getLifeHud()
{
    return hud.getLife();
}

sf::Text Player::getScoreHud()
{
    return hud.getScore();
}

void Player::move_myhud(float vx, float vy)
{
    hud.Move(vx, vy);
}

void Player::setSizeWindowHud(sf::Vector2f sizeWindow)
{
    hud.setSizeWindow(sizeWindow);
}

float Player::getRayon(){

    return rayon;
}

float Player::getVitesse() const{

    return vitesse;
}

sf::FloatRect Player::getCollisionBox(){

    return rect;
}

void Player::addPoints(int p)
{
Score=Score+p;
cout<<Score<<endl;
hud.updateScore(Score);
}

 Player::~Player()
{

}
