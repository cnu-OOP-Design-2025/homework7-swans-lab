#pragma once

#include <iostream>
using namespace std;

// 인터페이스 클래스: 날기 행동
class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

// 인터페이스 클래스: 꽥꽥 행동
class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

// 전략 구현 클래스들
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        cout << "I can Fly!" << endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        cout << "I can't fly..." << endl;
    }
};

class Quack : public QuackBehavior {
public:
    void quack() override {
        cout << "Quack!" << endl;
    }
};

class Squeak: public QuackBehavior {
public:
    void quack() override {
        cout << "Squeak!" << endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        cout << "<<Silent>>" << endl;
    }
};

// 오리 클래스
class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavior(fb), quackBehavior(qb) {}

    virtual void display() = 0;

    void performFly() {
        flyBehavior->fly();
    }

    void performQuack() {
        quackBehavior->quack();
    }

    void setFlyBehavior(FlyBehavior* fb) {
        if(flyBehavior) delete flyBehavior;
        flyBehavior = fb;
    }

    void setQuackBehavior(QuackBehavior* qb) {
        if(quackBehavior) delete quackBehavior;
        quackBehavior = qb;
    }

    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }
};

// 구체적인 오리 클래스
class MallardDuck : public Duck {
public:
    MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display() override {
        cout << "I'm a Mallar Duck." << endl;
    }
};

class RedheadDuck: public Duck{
public:
    RedheadDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display() override {
        cout << "I'm a Redhead Duck." << endl;
    }
};

class RubberDuck: public Duck{
public:
    RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {}
    
    void display() override {
        cout << "I'm a Rubber Duck." << endl;
    }
};

class DecoyDuck: public Duck{
public:
    DecoyDuck() : Duck(new FlyNoWay(), new MuteQuack()) {}

    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

class ModelDuck: public Duck{
public:
    ModelDuck() : Duck(new FlyNoWay(), new MuteQuack()) {}

    void display() override {
        cout << "I'm a Decoy Duck." << endl;
    }
};

