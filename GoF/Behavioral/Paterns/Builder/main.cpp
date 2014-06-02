#include <iostream>
#include <vector>

using namespace std;
//Программа реализует потерн Builder на примере создания разных наборов цветных кубиков
//Классы всех возможных видов кубиков
class Red
{
  public:
    void info() {
      cout << "Red" << endl;
    }
};

class Blue
{
  public:
    void info() {
      cout << "Blue" << endl;
    }
};

class Green
{
  public:
    void info() {
      cout << "Green" << endl;
    }
};

class Yellow
{
  public:
    void info() {
      cout << "Yellow " << endl;
    }
};

class Purple
{
  public:
    void info() {
      cout << "Purple" << endl;
    }
};

class Black
{
  public:
    void info() {
      cout << "Black" << endl;
    }
};

//Клас содержащий все типы кубиков
class Set
{
    public:
        vector<Red>     vr;
        vector<Green>   vg;
        vector<Blue>    vb;
        vector<Yellow>  vy;
        vector<Purple>  vp;
        vector<Black>   vbk;
        void info() {
          int i;
          for(i=0; i<vr.size(); ++i)  vr[i].info();
          for(i=0; i<vg.size(); ++i)  vg[i].info();
          for(i=0; i<vb.size(); ++i)  vb[i].info();
          for(i=0; i<vy.size(); ++i)  vy[i].info();
          for(i=0; i<vp.size(); ++i)  vp[i].info();
          for(i=0; i<vbk.size(); ++i) vbk[i].info();
        }


};
//Класс строитель объявляет интерфейс для построения наборов
class SetBuilder
{
    protected:
        Set *s;
    public:
        virtual ~SetBuilder() {}
        virtual void createSet() {}
        virtual void buildRed() {}
        virtual void buildGreen() {}
        virtual void buildBlue() {}
        virtual void buildYellow() {}
        virtual void buildPurple() {}
        virtual void buildBlack() {}
        virtual Set* getSet() { return s; }

};
//Два различных набора RGB и YPB
class RGB: public SetBuilder
{
    public:
    void createSet(){ s = new Set;}
    void buildRed() {s->vr.push_back(Red());
                    s->vr.push_back(Red());}
    void buildGreen() {s->vg.push_back(Green());}
    void buildBlue() {s->vb.push_back(Blue());}

};
class YPB: public SetBuilder
{
    public:
    void createSet(){ s = new Set;}
    void buildYellow() {s->vy.push_back(Yellow());}
    void buildPurple() {s->vp.push_back(Purple());}
    void buildBlack() {s->vbk.push_back(Black());}

};

//Класс распорядитель, конструирует наборы кубиков используя интерфейс строителя
class Director
{
  public:
    Set* createSet( SetBuilder &builder )
    {
        builder.createSet();
        builder.buildRed();
        builder.buildGreen();
        builder.buildBlue();
        builder.buildYellow();
        builder.buildPurple();
        builder.buildBlack();
        return( builder.getSet());
    }
};
int main()
{
        Director dir;
        RGB rgb_builder;
        YPB ypb_builder;

        Set * rgb = dir.createSet(rgb_builder);
        Set * ypb = dir.createSet(ypb_builder);
        cout << "Set RGB:" << endl;
        rgb->info();
        cout << "\nSet YPB:" << endl;
        ypb->info();
        return 0;
}

