#include "Zombie.hpp"


Zombie::Zombie(sf::Vector2f init_Position, Player& init_Target)
{
Zombie::setRadius(50);
Zombie::setOrigin(sf::Vector2f(25,25));
Zombie::setPosition(init_Position);
Zombie::setFillColor(sf::Color::Red);

e_mx=8;
e_my=8;
d_radius=Zombie::getRadius();
my_behaviour=ATTACK;
my_target=&init_Target;
}

void Zombie::Update()
{
    if(my_behaviour==ATTACK)
    {
        sf::Vector2f Myposition = Zombie::getPosition(), Targetposition = my_target->getPosition();
        //float TargetDirection = GetAngle(Myposition.x, Myposition.y, Targetposition.x, Targetposition.y); référence indéfinie vers GetAngle() je ne comprends pas pourquoi
       sf::Vector2f vec1=Myposition;
       sf::Vector2f vec2=Targetposition;
    float a=vec2.x-vec1.x;
    float o=vec2.y-vec1.y;
    float TargetDirection;

    TargetDirection = atan2(-o, a);
       sf::Vector2f v;
        v.x=cos(TargetDirection) * e_mx;
        v.y=sin(TargetDirection) * e_my;
                //std::cout<<this<<" : x : "<<Myposition.x<<" y : "<<Myposition.y<<" angle : "<<TargetDirection<<std::endl;

float mvx = v.x+m_fx;
float mvy = v.y+m_fy;

        Zombie::move(mvx, -mvy);
        m_fy=0;
        m_fx=0;

    }
}
