#include <iostream>
#include <vector>

using namespace std;
//Программа реализует паттерн Composite на примере работы с цветными кубиками
//Класс Component, является общим для всех (и простых, и сложных) объектов
class Unit
{
  public:
    virtual void info() {}
    virtual void addUnit(Unit* p) {}
    virtual ~Unit() {}
};
//Классы простых объектов
class Red: public Unit
{
  public:
    void info() {
      cout << "Red" << endl;
    }
};

class Blue: public Unit
{
  public:
    void info() {
      cout << "Blue" << endl;
    }
};

class Green: public Unit
{
  public:
    void info() {
      cout << "Green" << endl;
    }
};
//Класс сложного объекта
class Set: public Unit
{
   private:
    vector<Unit*> c;

   public:
    void info() {
      for(int i=0; i<c.size(); ++i)
        c[i]->info();
    }
    void addUnit(Unit* p) {
        c.push_back( p);
    }
    ~Set() {
      for(int i=0; i<c.size(); ++i)
        delete c[i];
    }
};
//Создается набор RGB, в который входят 10 красных, 5 синих, и 6 зеленных кубиков.
Set* createRGB(){
    Set* RGB = new Set;
    for (int i=0; i<10; ++i)
        RGB->addUnit(new Red);
    for (int i=0; i<5; ++i)
        RGB->addUnit(new Blue);
    for (int i=0; i<6; ++i)
        RGB->addUnit(new Green);
    return RGB;
}


int main()
{
    Set* RGB = new Set;
    RGB = createRGB();
    cout << "RGB set is " << endl;
    RGB->info();
    return 0;
}

