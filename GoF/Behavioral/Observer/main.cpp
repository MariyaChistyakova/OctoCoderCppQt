
#include <iostream>
#include <vector>
using namespace std;

//Реализация патерна Observer - отношение один-ко многим на примере находжения суммы и произведения значения субьекта со значениями обьекта.
//Соответвено при изменении значения сбьекта меняются результаты.

//Субьект
class Subject {
    vector < class Observer * > views;//Список наблюдателей над субьектом - несколько наблюдателей дл одного субьекта
    int value;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

//Обьект, наблюдатель
class Observer {
    Subject *model;
    int denom;
  public:
    Observer(Subject *mod, int div) {
        model = mod;
        denom = div;
        //Добавляем наблюдателя к субьекту
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

void Subject::notify() {
  //Извещение наблюдателей об изменении субьекта
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

class ProObserver: public Observer {
  public:
    ProObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        // Получение информации от субьекта
        int v = getSubject()->getVal(), d = getDivisor();
         cout << v << " product " << d << " is " << v*d << '\n';
    }
};

class AmoObserver: public Observer {
  public:
    AmoObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " amount " << d << " is " << v+d << '\n';
    }
};

int main() {
  Subject subj;
  ProObserver divObs1(&subj, 4);
  ProObserver divObs2(&subj, 3);
  AmoObserver modObs3(&subj, 3);
  subj.setVal(14);
  subj.setVal(25);
  ProObserver divObs4(&subj, 4); // 7. Клиент настраивает число
  ProObserver divObs5(&subj, 3); //    и типы наблюдателей
  AmoObserver modObs6(&subj, 3);

}
