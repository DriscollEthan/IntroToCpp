#include <iostream>

struct Vector2D
{
  float x, y;
};

class Enemy
{
public:
  Enemy() { Position = Vector2D(); }

  Enemy(const Vector2D & InitPosition) { Position = InitPosition; }

  virtual void Update() 
  {
    std::cout << "Enemy Update Things or Whatever" << std::endl; 
  }

protected:
  Vector2D Position;
};

class Grunt : public Enemy
{
public:
  Grunt() { ID = 0; }

  Grunt(const Vector2D& InitPosition, int InitID) : Enemy(InitPosition)
  {
    ID = InitID;
  }

  virtual void Update() override
  {
    Enemy::Update();
    std::cout << "Grunt Updated Things and Whatever Else" << std::endl;
  }

protected:
  int ID;
};

class Heavy : public Enemy
{
public:
  Heavy() { ID = 0; }

  Heavy(const Vector2D& InitPosition, int InitID) : Enemy(InitPosition)
  {
    ID = InitID;
  }

  virtual void Update() override
  {
    Enemy::Update();
    std::cout << "Heavy Updated Things and Whatever Else" << std::endl;
  }

protected:
  int ID;

};

int main()
{
  //Enemy ValueEnemy;
  //
  //ValueEnemy = Grunt();
  //ValueEnemy.Update();

  Enemy* CurrentEnemy = nullptr;

  CurrentEnemy = new Heavy();
  CurrentEnemy->Update();
  
  delete CurrentEnemy;
}