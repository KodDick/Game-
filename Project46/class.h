
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GameParameters{
private:
    int day;
    int money;
    int eat;
    int popular;
    int animal;
    int aviary;
    int workers;
    int visitors;

public:
    GameParameters();
    void displayParameters();
    void increaseDay();
    void setVisitors(int count);
    void spendMoney(int amount);
    void earnMoney(int amount);
    void addAnimal();
    void removeAnimal();
    void addAviary();
    void addWorker();
    void addVisitor();
    void setPopularity(int value);
    void spendpopular(int amount);
    void setEat(int value);
    void reduceEat(int amount);
    void buyFood(int amount);
    void randomizePopularity();
    void calculateVisitors();
    int getDay() const;
    int getMoney() const;
    int getEat() const;
    int getPopularity() const;
    int getAnimals() const;
    int getAviary() const;
    int getWorkers() const;
    int getVisitors() const;
};

class Animal {
protected:
    wstring name;
    int age;
    int weight;
    int price;
    int id;
    int volier_id;
    wstring climate;
    bool isAlive;
    bool isPredator;
    bool pol;
    int vid;

public:
    bool zabolel;
    bool getzaboell() const;

    enum animalpenetration {
        tropcat,
        tropdog,
        aquacat,
        shark,
        arccat,
        arcdog
    };

    enum poll {
        B,
        G
    };

    Animal(const wstring& name, int age, int weight, int price, int id,
        const wstring& climate, bool isPredator, int vid_, bool zabolel_);
    //virtual ~Animal();
    virtual void printInfo() const;
    int getId() const;
    int getVolierId() const;
    void setVolierId(int id);
    wstring getClimate() const;
    int getPrice() const;
    bool isAliveStatus() const;
    void die();
    bool getIsPredator() const;
    bool getpol() const;
    int getvid() const;
    wstring getName() const;
};

class TropicalCat : public Animal {
public:
    TropicalCat(int id);
};

class TropicalDog : public Animal {
public:
    TropicalDog(int id);
};

class SeaLion : public Animal {
public:
    SeaLion(int id);
};

class Shark : public Animal {
public:
    Shark(int id);
};

class ArcticCat : public Animal {
public:
    ArcticCat(int id);
};

class ArcticDog : public Animal {
public:
    ArcticDog(int id);
};

class HybridAnimal : public Animal {
private:
    wstring parent1;
    wstring parent2;

public:
    HybridAnimal(const wstring& name, int age, int weight, int price,
        int id, int vid, bool zabolel, const wstring& climate,
        const wstring& parent1, const wstring& parent2);
    void printInfo() const override;
};

class Worker {
private:
    wstring name;
    int id;
    int volier_id;

public:
    Worker(int id, const wstring& name);
    bool isBusy() const;
    void assignVolier(int id);
    void removeVolier();
    wstring getName() const;
    int getId() const;
    int getVolierID() const;
};

class VolierClass {
private:
    wstring climateType;
    int price;
    bool isPredator;

public:
    int capacity;
    VolierClass(int capacity, const wstring& climateType, int price, bool isPredator);
    void printInfo() const;
    int getcapacity() const;
    int getPrice() const;
    wstring getClimateType() const;
    bool getIsPredator() const;
};

class ZooManager {
private:
    vector<Animal*> animals;
    vector<Worker*> workers;
    int next_animal_id;
    int next_worker_id;

public:
    vector<VolierClass> voliers;
    GameParameters parameters;

    ZooManager();
    ~ZooManager();
    void buyWorker();
    void feedAnimals();
    void buyFood();
    void sellAnimal();
    void randomEvents();
    void buyPopularity();
    void zabolelspeed();
    void zabolelspeed100PORZ();
    void AIBOLIT();
    void nextDay();
    void buyAnimal();
    void assignWorkerToVolier();
    void placeAnimalInVolier();
    void showAnimals() const;
    void showVoliers() const;
    void showWorkers() const;
    void breedAnimals();
    void buyVolier();
    void upVolier();
};
