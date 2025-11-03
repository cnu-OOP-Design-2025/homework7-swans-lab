[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/AFORVcxa)
  # C++ 클래스 상속 실습 프로젝트

이 프로젝트는 C++의 전략 패턴(Strategy Pattern)을 활용하여 다양한 오리(Duck) 객체의 행동을 동적으로 설정하고 변경하는 실습입니다.

---

## 실습 목적

- 인터페이스 기반의 행동 클래스 구현
- 동적 행동 변경을 위한 전략 패턴 이해
- 가상 소멸자(virtual destructor)의 역할 이해

---


## 아래 클래스 다이어그램을 참고하여 Class를 구현

```       
        +----------------+
        | <<interface>>  |
        |  FlyBehavior   |
        +----------------+
        | +fly()         |
        | +~FlyBehavior()|
        +----------------+
               ▲
               |
        +--------------+
        |              |
+--------------+  +----------+
| FlyWithWings |  | FlyNoWay |
+--------------+  +----------+
| +fly()       |  | +fly()   |
+--------------+  +----------+

        +------------------+
        |  <<interface>>   |
        |   QuackBehavior  |
        +------------------+
        | +quack()         |
        | +~QuackBehavior()|
        +------------------+
                 ▲
                 |
     +--------------------------+
     |           |              |
+---------+  +---------+  +----------+
| Quack   |  | Squeak  |  | MuteQuack|
+---------+  +---------+  +----------+
| +quack()|  | +quack()|  | +quack() |
+---------+  +---------+  +----------+


        +------------------------------+
        |      Duck (abstract)         |
        +------------------------------+
        | flyBehavior: FlyBehavior     |
        | quackBehavior: QuackBehavior |
        +------------------------------+
        | +swim(): void                |
        | +display(): void             |
        | +performQuack(): void        |
        | +performFly(): void          |
        | +setFlyBehavior(): void      |
        | +setQuackBehavior(): void    |
        | +Duck():                     |
        | +~Duck():                    |
        +------------------------------+
                   ▲
                   |
      --------------------------------------------------------------------------
      |                   |                  |                |                |
+--------------+  +---------------+  +--------------+  +-------------+  +-------------+
| MallarDuck   |  | RedheadDuck   |  | RubberDuck   |  | DecoyDuck   |  | ModelDuck   |
+--------------+  +---------------+  +--------------+  +-------------+  +-------------+
| +display()   |  | +display()    |  | +display()   |  | +display()  |  | +display()  |
| MallarDuck() |  | +RedheadDuck()|  | +RubberDuck()|  | +DecoyDuck()|  | +ModelDuck()|
+--------------+  +---------------+  +--------------+  +-------------+  +-------------+


```
### FlyBehavior (인터페이스 클래스)
- `fly()`: 순수 가상 함수. 하위 클래스에서 비행 행동을 정의해야 함.

### FlyWithWings
- `fly()`: "I can Fly!" 출력

### FlyNoWay
- `fly()`: "I can't fly..." 출력


### QuackBehavior (인터페이스 클래스)
- `quack()`: 순수 가상 함수. 하위 클래스에서 울음소리 행동을 정의해야 함.

### Quack
- `quack()`: "Quack!" 출력

### Squeak
- `quack()`: "Squeak!" 출력

### MuteQuack
- `quack()`: "<\<Silent\>>" 출력


### Duck (추상 클래스)
- `display()`: 순수 가상 함수. 하위 클래스에서 오리 종류 출력
- `performFly()`: 현재 설정된 flyBehavior의 fly() 호출
- `performQuack()`: 현재 설정된 quackBehavior의 quack() 호출
- `setFlyBehavior(FlyBehavior*)`: flyBehavior를 동적으로 변경
- `setQuackBehavior(QuackBehavior*)`: quackBehavior를 동적으로 변경
- `~Duck()`: flyBehavior와 quackBehavior 메모리 해제

### MallardDuck
- `display()`: "I'm a Mallar Duck." 출력
- 기본 행동: FlyWithWings, Quack

### RedheadDuck
- `display()`: "I'm a Redhead Duck." 출력
- 기본 행동: FlyWithWings, Quack

### RubberDuck
- `display()`: "I'm a Rubber Duck." 출력
- 기본 행동: FlyNoWay, Squeak

### DecoyDuck
- `display()`: "I'm a Decoy Duck." 출력
- 기본 행동: FlyNoWay, MuteQuack

### ModelDuck
- `display()`: "I'm a Decoy Duck." 출력
- 기본 행동: FlyNoWay, MuteQuack
- 동적으로 행동 변경 테스트



### 예상 출력
```
----------------------
Duck #1:
I'm a Mallar Duck.
I can Fly!
Quack!
----------------------
Duck #2:
I'm a Redhead Duck.
I can Fly!
Quack!
----------------------
Duck #3:
I'm a Rubber Duck.
I can't fly...
Squeak!
----------------------
Duck #4:
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 1)
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 2)
I'm a Decoy Duck.
I can't fly...
Squeak!
----------------------
ModelDuck (version 3)
I'm a Decoy Duck.
----------------------
Duck #1:
I'm a Mallar Duck.
I can Fly!
Quack!
----------------------
Duck #2:
I'm a Redhead Duck.
I can Fly!
Quack!
----------------------
Duck #3:
I'm a Rubber Duck.
I can't fly...
Squeak!
----------------------
Duck #4:
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 1)
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 2)
I'm a Decoy Duck.
I can't fly...
Squeak!
----------------------
ModelDuck (version 3)
I'm a Decoy Duck.
I can Fly!
Squeak!
--------------------------------------------
Duck #1:
I'm a Mallar Duck.
I can Fly!
Quack!
----------------------
Duck #2:
I'm a Redhead Duck.
I can Fly!
Quack!
----------------------
Duck #3:
I'm a Rubber Duck.
I can't fly...
Squeak!
----------------------
Duck #4:
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 1)
I'm a Decoy Duck.
I can't fly...
<<Silent>>
----------------------
ModelDuck (version 2)
I'm a Decoy Duck.
I can't fly...
Squeak!
----------------------
ModelDuck (version 3)
I'm a Decoy Duck.
I can Fly!
Squeak!
----------------------
```

## 테스트 방법

모든 함수 구현 후, 아래 명령어를 통해 테스트를 실행하세요:

### Windows 사용자
```
.\test7.bat
```

### MacOS/Linux 사용자
```bash
/bin/bash test7.sh
```
