
using namespace std;

class GameParameters {
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
    GameParameters() : day(1), money(10000), eat(100), popular(0), animal(0), aviary(0), workers(1), visitors(0) {}

    void displayParameters()  {

        wcout << L"��������� ����   " << endl;
        wcout << L"����: " << day << endl;
        wcout << L"������: " << money << L"$" << endl;
        wcout << L"���: " << eat << endl;
        wcout << L"������������: " << popular << endl;
        wcout << L"��������: " << animal << endl;
        wcout << L"��������: " << aviary << endl;
        wcout << L"����������: " << workers << endl;
        wcout << L"����������: " << visitors << endl;
    }

    void increaseDay() { day++; }
    void setVisitors(int count) { visitors = count; }
    void spendMoney(int amount) { money -= amount; if (money < 0) money = 0; }
    void earnMoney(int amount) { money += amount; }
    void addAnimal() { animal++; }
    void removeAnimal() { animal--; }
    void addAviary() { aviary++; }
    void addWorker() { workers++; }
    void addVisitor() { visitors++; }
    void setPopularity(int value) { popular = value; }
    void spendpopular(int amount) { money -= amount; }
    void setEat(int value) { eat = value; }
    void reduceEat(int amount) { eat -= amount; if (eat < 0) eat = 0; }

    void buyFood(int amount) {
        const int foodPrice = 5;
        int totalCost = amount * foodPrice;
        if (money >= totalCost) {
            eat += amount;
            spendMoney(totalCost);
            wcout << L"������� " << amount << L" ������ ��� �� " << totalCost << L"$." << endl;
        }
        else {
            wcout << L"�� ������� ����� ��� ������� " << amount << L" ������ ���! ����������� �����: " << totalCost << L"$." << endl;
        }
    }

    void randomizePopularity() {
        int change = rand() % 21 - 10;
        popular += change;
        if (popular < 0) popular = 0;
    }

    void calculateVisitors() {
        visitors = 2 * popular;
        if (visitors < 0) visitors = 0;
    }

    int getDay() const { return day; }
    int getMoney() const { return money; }
    int getEat() const { return eat; }
    int getPopularity() const { return popular; }
    int getAnimals() const { return animal; }
    int getAviary() const { return aviary; }
    int getWorkers() const { return workers; }
    int getVisitors() const { return visitors; }
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
    bool getzaboell() const { return zabolel; }

    Animal(const wstring& name, int age, int weight, int price, int id, const wstring& climate, bool isPredator, int vid_,bool zabolel_)
        : name(name), age(age), weight(weight), price(price), id(id), climate(climate), isAlive(true), isPredator(isPredator),vid(vid_), volier_id(-1),zabolel(zabolel_) {
        pol = (rand() % 2 == 0) ? B : G;
    }

    virtual ~Animal() {}

    enum animalpenetration{
        tropcat,
        tropdog,
        aquacat,
        shark,
        arccat,
        arcdog
        
    };

    enum poll{
        B,
        G
    };

    virtual void printInfo() const {
        wcout << L"���: " << name << L", �������: " << age << L", ���: " << weight
            << L" ��, ����: " << price << L" ���., ID: " << id << L", ������: "
            << (volier_id == -1 ? L"���" : to_wstring(volier_id + 1)) << L", ������: "
            << climate << L", ���: " << (isPredator ? L"������" : L"����������")
            << L", ���������: " << (isAlive ? L"����� " : L"������� ") << (pol == B ? L"�����" : L"�������")  << (zabolel == true ? L" ���� ��������" : L" SPEED �� ���������") << endl;
    }

    
    int getId() const { return id; }
    int getVolierId() const { return volier_id; }
    void setVolierId(int id) { volier_id = id; }
    wstring getClimate() const { return climate; }
    int getPrice() const { return price; }
    bool isAliveStatus() const { return isAlive; }
    void die() { isAlive = false; }
    bool getIsPredator() const { return isPredator; }
    bool getpol() const { return pol; }
    int getvid() const { return vid; }
    
    wstring getName() const { return name; }
};

class TropicalCat : public Animal {
public:

    TropicalCat(int id) : Animal(L"����������� ���", 3, 4, 1000, id, L"�����������", true, tropcat, 0) {}
};

class TropicalDog : public Animal {
public:
    TropicalDog(int id) : Animal(L"����������� ������", 5, 20, 5000, id, L"�����������", false, tropdog, 0) {}
};

class SeaLion : public Animal {
public:
    SeaLion(int id) : Animal(L"������� �����", 4, 100, 8000, id, L"�����������", false, aquacat,0) {}
};

class Shark : public Animal {
public:
    Shark(int id) : Animal(L"�����", 10, 200, 15000, id, L"�����������", true, shark, 0) {}
};

class ArcticCat : public Animal {
public:
    ArcticCat(int id) : Animal(L"����������� ���", 3, 4, 1000, id, L"�����������", true, arccat, 0) {}
};

class ArcticDog : public Animal {
public:
    ArcticDog(int id) : Animal(L"����������� ������", 5, 20, 5000, id, L"�����������", false, arcdog, 0) {}
};

// ����� ����� ��� ��������� ��������
class HybridAnimal : public Animal {
private:
    wstring parent1;
    wstring parent2;

public:
    HybridAnimal(const wstring& name, int age, int weight, int price, int id,int vid, bool zabolel, const wstring& climate, const wstring& parent1, const wstring& parent2)
        : Animal(name, age, weight, price, id, climate, false, vid , zabolel), parent1(parent1), parent2(parent2) {}

    void printInfo() const override {
        Animal::printInfo();
        wcout << L"��������: " << parent1 << L" � " << parent2 << endl;
    }
};

class Worker {
private:
    wstring name;
    int id;
    int volier_id;

public:
    Worker(int id, const wstring& name) : id(id), name(name), volier_id(-1) {}

    bool isBusy() const { return volier_id != -1; }
    void assignVolier(int id) { volier_id = id; }
    void removeVolier() { volier_id = -1; }
    wstring getName() const { return name; }
    int getId() const { return id; }
    int getVolierID() const { return volier_id; }
};

class VolierClass {
private:
    
    wstring climateType;
    int price;
    bool isPredator;

public:
    int capacity;
    VolierClass(int capacity, const wstring& climateType, int price, bool isPredator)
        : capacity(capacity), climateType(climateType), price(price), isPredator(isPredator) {}

    void printInfo() const {
        wcout << L"������: ����������� " << capacity << L", ������: " << climateType
            << L", ����: " << price << L" ���., ���: " << (isPredator ? L"�������" : L"����������") << endl;
    }
    int getcapacity() const { return capacity + 5; }
    int getPrice() const { return price; }
    wstring getClimateType() const { return climateType; }
    bool getIsPredator() const { return isPredator; }
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

    ZooManager() : next_animal_id(1), next_worker_id(1) {
        workers.push_back(new Worker(next_worker_id++, L"�����"));
        srand(static_cast<unsigned int>(time(0)));
    }

    ~ZooManager() {
        for (auto animal : animals) delete animal;
        for (auto worker : workers) delete worker;
    }

    void buyWorker() {
        wcout << L"���� �� ���������: 3000 ���.\n";
        wcout << L"������� ��� ���������: ";
        wstring workerName;
        wcin >> workerName;

        for (auto& worker : workers) {
            if (worker->getName() == workerName) {
                wcout << L"�������� � ����� ������ ��� ����������." << endl;
                return;
            }
        }

        int workerPrice = 3000;
        if (parameters.getMoney() < workerPrice) {
            wcout << L"�� ������� ����� ��� ������� ���������. ����������� �����: " << workerPrice << L" ���.\n";
            return;
        }

        parameters.spendMoney(workerPrice);
        workers.push_back(new Worker(next_worker_id++, workerName));
        parameters.addWorker();
        wcout << L"�������� " << workerName << L" ������� ������!" << endl;
    }

    void feedAnimals() {
        int totalFoodRequired = parameters.getAnimals() * 10;
        parameters.reduceEat(totalFoodRequired);

        if (parameters.getEat() < 0) {
            for (auto& animal : animals) {
                if (animal->isAliveStatus() && (static_cast<double>(rand()) / RAND_MAX > 0.5)) {
                    animal->die();
                    wcout << L"�������� " << animal->getId() << L" ������ �� ������!" << endl;
                }
            }
        }
    }

    void buyFood() {
        wcout << L"������� ������ ��� ������ ������? ";
        int amount;
        wcin >> amount;
        parameters.buyFood(amount);
    }

    void sellAnimal() {
        wcout << L"������� ID ���������, ������� ������ �������: ";
        int animal_id;
        wcin >> animal_id;

        auto it = find_if(animals.begin(), animals.end(), [animal_id](Animal* animal) {
            return animal->getId() == animal_id;
            });

        if (it != animals.end()) {
            Animal* animalToSell = *it;
            parameters.earnMoney(animalToSell->getPrice());
            parameters.removeAnimal();
            wcout << L"�������� " << animal_id << L" ������� �� " << animalToSell->getPrice() << L"$." << endl;
            delete animalToSell;
            animals.erase(it);
        }
        else {
            wcout << L"�������� � ����� ID �� �������." << endl;
        }
    }

    void randomEvents() {
        int event = rand() % 4;
        switch (event) {
        case 0: wcout << L"��������� �������: ������� ��� ������������ ������������� �����, ������������ ������������� �� 10!" << endl;
            parameters.setPopularity(parameters.getPopularity() + 10); break;
        case 1: wcout << L"��������� �������: � ��� ���� �� �������� ������ ��������� ������� -5 ������������." << endl;
            parameters.setPopularity(parameters.getPopularity() - 5); break;
        case 2: wcout << L"��������� �������: ��������� ����������������� �����, ������������ ������������� �� 20!" << endl;
            parameters.setPopularity(parameters.getPopularity() + 20); break;
        case 3: wcout << L"��������� �������: �������� �������� � ����� �� ����������, ������������ ��������� �� 5!" << endl;
            parameters.setPopularity(parameters.getPopularity() - 5); break;
        }
    }

    void buyPopularity() {
        wcout << L"��������, ������� ������������ ������ ������:\n";
        wcout << L"1. �� 100$ ( +10 )\n";
        wcout << L"2. �� 1000$ ( +10 �� +100 �������� )\n";
        wcout << L"3. �� 10000$ ( +100 )\n";
        wcout << L"��� �����: ";
        int choice;
        wcin >> choice;

        switch (choice) {
        case 1: if (parameters.getMoney() >= 100) {
            parameters.spendMoney(100);
            parameters.setPopularity(parameters.getPopularity() + 10);
            wcout << L"������������ ��������� �� 10." << endl;
        }
              else wcout << L"�� ������� ����� ��� ������� ������������." << endl; break;
        case 2: if (parameters.getMoney() >= 1000) {
            parameters.spendMoney(1000);
            int increase = 10 + rand() % 91;
            parameters.setPopularity(parameters.getPopularity() + increase);
            wcout << L"������������ ��������� �� " << increase << L"." << endl;
        }
              else wcout << L"�� ������� ����� ��� ������� ������������." << endl; break;
        case 3: if (parameters.getMoney() >= 10000) {
            parameters.spendMoney(10000);
            parameters.setPopularity(parameters.getPopularity() + 100);
            wcout << L"������������ ��������� �� 100." << endl;
        }
              else wcout << L"�� ������� ����� ��� ������� ������������." << endl; break;
        default: wcout << L"������������ �����." << endl;
        }
    }

    void zabolelspeed() {
        int i = 1;//rand() % 2;
        if (i == 1) {

            int parent1= 0, parent2 = 0, parent3 = 0;
           
            if (animals.empty()) { return; }
            for (auto& animal : animals) {
                
                    parent1 = animal->getId();

                    parent2 = rand() % parent1;
                
                
            }
            int id = 0;
           
            
            for (auto& animal : animals) {
                parent3 = animal->getId();
                animal->zabolel = true;
               

            }
            wcout << L"������ �������\n";
            

        }
        else{}
    }

    void zabolelspeed100PORZ() {
        int parent1 = 0, parent2 = 0, parent3 = 0;

        if (animals.empty()) { return; }
        for (auto& animal : animals) {

            parent1 = animal->getId();

            parent2 = rand() % parent1;


        }
        int id = 0;


        for (auto& animal : animals) {
            parent3 = animal->getId();
            animal->zabolel = true;


        }
        wcout << L"������ �������\n";
        
    }

    void AIBOLIT() {

        showAnimals();
        wcout << L"������ �������� ������� ������ ��������:\n";

        int idanimal;
        wcin >> idanimal;

        for (auto& animal : animals) {
            for (int i = 0; i == idanimal; i++) {
                if(i == idanimal){}
            }

        }

    }



    void nextDay() {
        zabolelspeed();
        feedAnimals();
        int dailyIncome = parameters.getVisitors() * parameters.getAnimals();
        parameters.earnMoney(dailyIncome);
        wcout << L"��������� �� ����: " << dailyIncome << L"$" << endl;
        parameters.randomizePopularity();
        parameters.calculateVisitors();
        randomEvents();
        parameters.increaseDay();
        
        if (parameters.getMoney() < 0) {
            wcout << L"�� ���������! � ��� �� �������� �����." << endl;
            exit(0);
        }

        wcout << L"=== ����� ��� ===" << endl;
        parameters.displayParameters();

        int parent1 = 0, parent2 = 0, parent3 = 0 , schetzabol = 0, parent4 = 0 , parent5 = 0;

        if (animals.empty()) { return; }
        for (auto& animal : animals) {

            parent1 = animal->getId();
            if (animal->zabolel == true) {
                schetzabol += 1;
            }
            


        }
        

        
        if(schetzabol >= (parent1/2))
        for (auto& animal : animals) {
            parent3 = animal->getId();
            if (animal->zabolel == true) {
                int random_index = rand() % animals.size();
                parent4 = animals[random_index]->getId();
                
                
                int animal_id, randomer = rand() % 5;
                animal_id = parent4;
                
                auto it = find_if(animals.begin(), animals.end(), [animal_id](Animal* animal) {
                    return animal->getId() == animal_id;
                    });
                
                
                if ((it != animals.end())&& randomer == 1) {
                    Animal* animalToSell = *it;
                    
                    parameters.removeAnimal();
                    wcout << L"�������� " << animal_id << L" ������� � ������ �� ��������� " << endl;
                    delete animalToSell;
                    animals.erase(it);
                }
                else {
                   
                }

            }


        }
        schetzabol = 0;

    }

    void buyAnimal() {
        if (workers.empty() || (workers.size() == 1 && workers[0]->getName() == L"�����" && workers[0]->isBusy())) {
            wcout << L"��� ��������� ���������� ��� ������������ ��������. ������ ������ ��������." << endl;
            return;
        }

        wcout << L"�������� �������� ��� �������:\n";
        wcout << L"1. ����������� ��� (1000 ���.)\n";
        wcout << L"2. ����������� ������ (5000 ���.)\n";
        wcout << L"3. ����������� ��� (1000 ���.)\n";
        wcout << L"4. ����������� ������ (5000 ���.)\n";
        wcout << L"5. ������� ����� (8000 ���.)\n";
        wcout << L"6. ����� (15000 ���.)\n";
        wcout << L"��� �����: ";

        int animalType;
        wcin >> animalType;

        Animal* newAnimal = nullptr;

        switch (animalType) {
        case 1: newAnimal = new TropicalCat(next_animal_id++); break;
        case 2: newAnimal = new TropicalDog(next_animal_id++); break;
        case 3: newAnimal = new ArcticCat(next_animal_id++); break;
        case 4: newAnimal = new ArcticDog(next_animal_id++); break;
        case 5: newAnimal = new SeaLion(next_animal_id++); break;
        case 6: newAnimal = new Shark(next_animal_id++); break;
        default: wcout << L"������������ �����!" << endl; return;
        }

        if (parameters.getMoney() < newAnimal->getPrice()) {
            wcout << L"�� ������� ����� ��� ������� " << newAnimal->getId() << L". ����������� �����: "
                << newAnimal->getPrice() << L" ���.\n";
            delete newAnimal;
            return;
        }

        animals.push_back(newAnimal);
        parameters.addAnimal();
        parameters.spendMoney(newAnimal->getPrice());
        wcout << L"�������� ������� �������." << endl;
    }

    void assignWorkerToVolier() {
        wcout << L"������� ��� ���������: ";
        wstring workerName;
        wcin >> workerName;

        for (auto& worker : workers) {
            if (worker->getName() == workerName) {
                if (worker->isBusy()) {
                    wcout << L"���� �������� ��� �����." << endl;
                    return;
                }

                wcout << L"�������� ������ ��� ����������: " << endl;
                for (size_t i = 0; i < voliers.size(); ++i) {
                    wcout << L"ID: " << (i + 1) << L" ";
                    voliers[i].printInfo();
                }

                wcout << L"������� ����� �������: ";
                int volier_index;
                wcin >> volier_index;

                if (volier_index < 1 || volier_index > voliers.size()) {
                    wcout << L"������������ ����� �������." << endl;
                    return;
                }

                worker->assignVolier(volier_index - 1);
                wcout << worker->getName() << L" ������� �������� �� ������ " << volier_index << endl;
                return;
            }
        }

        wcout << L"�������� � ������ " << workerName << L" �� ������." << endl;
    }

    void placeAnimalInVolier() {
        wcout << L"������� ID ���������, ������� ������ ����������: ";
        int animal_id;
        wcin >> animal_id;

        Animal* animalToPlace = nullptr;
        for (auto& animal : animals) {
            if (animal->getId() == animal_id) {
                animalToPlace = animal;
                break;
            }
        }

        if (animalToPlace == nullptr) {
            wcout << L"�������� � ����� ID �� �������." << endl;
            return;
        }

        bool hasWorker = false;
        for (auto& worker : workers) {
            if (worker->isBusy()) {
                hasWorker = true;
                break;
            }
        }

        if (!hasWorker) {
            wcout << L"��� ���������� ��������� ��� ���������� ���������." << endl;
            return;
        }

        wcout << L"�������� ������ ��� ���������� ���������: " << endl;
        for (size_t i = 0; i < voliers.size(); ++i) {
            wcout << L"ID: " << (i + 1) << L" ";
            voliers[i].printInfo();
        }

        wcout << L"������� ����� �������: ";
        int volier_index;
        wcin >> volier_index;

        if (volier_index < 1 || volier_index > voliers.size()) {
            wcout << L"������������ ����� �������." << endl;
            return;
        }

        if (animalToPlace->getClimate() != voliers[volier_index - 1].getClimateType()) {
            wcout << L"�������� ������ ��� ���������� ��������� � �������." << endl;
            return;
        }

        if (animalToPlace->getIsPredator() != voliers[volier_index - 1].getIsPredator()) {
            wstring animalType = animalToPlace->getIsPredator() ? L"������" : L"����������";
            wstring volierType = voliers[volier_index - 1].getIsPredator() ? L"��������" : L"����������";
            wcout << L"������! ��� �������� - " << animalType
                << L", � ������ ������������ ��� " << volierType << L"." << endl;
            return;
        }

        animalToPlace->setVolierId(volier_index - 1);
        wcout << L"�������� ������� ��������� � ������!" << endl;
    }

    void showAnimals() const {
        wcout << L"\n=== �������� ===" << endl;
        for (const auto& animal : animals) {
            animal->printInfo();
        }
    }

    void showVoliers() const {
        wcout << L"\n=== ������� ===" << endl;
        for (size_t i = 0; i < voliers.size(); ++i) {
            wcout << L"ID: " << (i + 1) << L" ";
            voliers[i].printInfo();
        }
    }

    void showWorkers() const {
        wcout << L"\n=== ��������� ===" << endl;
        for (const auto& worker : workers) {
            wcout << L"ID: " << worker->getId()
                << L", ���: " << worker->getName()
                << L", ID �������: "
                << (worker->isBusy() ? to_wstring(worker->getVolierID() + 1) : L"���") << endl;
        }
    }

    void breedAnimals() {
        showAnimals();
        wcout << L"������� ID ������� ���������: ";
        int id1;
        wcin >> id1;

        wcout << L"������� ID ������� ���������: ";
        int id2;
        wcin >> id2;

        Animal* parent1 = nullptr;
        Animal* parent2 = nullptr;

        // ����� ��������� �� ID
        for (auto& animal : animals) {
            if (animal->getId() == id1) {
                parent1 = animal;
            }
            else if (animal->getId() == id2) {
                parent2 = animal;
            }
        }

        if (!parent1 || !parent2) {
            wcout << L"���� ��� ��� �� ��������� �������� �� �������." << endl;
            return;
        }

        if (parent1->getId() == parent2->getId()) {
            wcout << L"������ ���������� ���� � �� �� ��������." << endl;
            return;
        }

        if (parent1->getvid() != parent2->getvid()) {
            wcout << L"������ ���������� ������ ��������";
            return;
        }
        /*
        if (parent1->getpol() == parent2->getpol()){
            if(parent1->getpol() == 0) wcout << L"�� ��������� ����� ������!";
            if (parent1->getpol() == 1) wcout << L"����� �� �� �� ����� �� ������";
            return;
        }
        */
        

        wstring hybridName = parent1->getName() + L"_" + parent2->getName() + L" ������";
        int hybridPrice = (parent1->getPrice() + parent2->getPrice()) / 2;
        hybridPrice = max(1000, hybridPrice);

        Animal* newAnimal = new HybridAnimal(hybridName, 0, 5, hybridPrice, next_animal_id++, parent1->getvid() , 0 , L"���������", parent1->getName(), parent2->getName());
        animals.push_back(newAnimal);
        parameters.addAnimal();

        wcout << L"��������� �������� " << hybridName << L" ������� �������!" << endl;
    }

    void buyVolier() {
        int type, capacity;

        wcout << L"�������� ��� �������:\n";
        wcout << L"1. ��� ����������� ��������\n";
        wcout << L"2. ��� ����������� ��������\n";
        wcout << L"��� �����: ";
        wcin >> type;

        wcout << L"������� ���������� ���� � ������� (1-100): ";
        wcin >> capacity;

        int pricePerPlace = (type == 1) ? 200 : 250;
        int totalPrice = pricePerPlace * capacity;

        if (parameters.getMoney() < totalPrice) {
            wcout << L"�� ������� �����! ����������� �����: " << totalPrice << L" ���.\n";
            return;
        }

        parameters.spendMoney(totalPrice);
        wstring climateType = (type == 1) ? L"�����������" : L"�����������";

        wcout << L"�������� ��� �������� ��� �������:\n";
        wcout << L"1. �������\n";
        wcout << L"2. ����������\n";
        int animalType;
        wcin >> animalType;

        bool isPredator = (animalType == 1);
        voliers.emplace_back(capacity, climateType, totalPrice, isPredator);
        parameters.addAviary();
        wcout << L"������ ������� ������!\n";
    }

    void upVolier() {
        if (voliers.empty() != true) {
            
            showVoliers();
            wcout << L"����� ������ �������� ��� �������\n";

            wcout << L"������� ID: ";
            int id1;
            wcin >> id1;
            if(parameters.getMoney() > 200){
                parameters.spendMoney(200);
            }
            else{
                wcout << L"� ��� ��� ��������\n";
                return;
            }
            for (auto& voler : voliers) {
                
                    
                  voler.capacity = voler.getcapacity(); 
                    
                
            }
        }
        else { wcout << L"� ��� ��� ��������\n";
        return;
        }


    }
};
