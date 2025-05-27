
#include "class.h"

//параметры
GameParameters::GameParameters() : day(1), money(10000), eat(100), popular(0), animal(0), aviary(0), workers(1), visitors(0) {}

    void GameParameters::displayParameters() {
    //внешка
        wcout << L"Параметры игры   " << endl;
        wcout << L"День: " << day << endl;
        wcout << L"Деньги: " << money << L"$" << endl;
        wcout << L"Еда: " << eat << endl;
        wcout << L"Популярность: " << popular << endl;
        wcout << L"Животные: " << animal << endl;
        wcout << L"Вольеров: " << aviary << endl;
        wcout << L"Работников: " << workers << endl;
        wcout << L"Посетители: " << visitors << endl;
    }
    //взаимодействия с параметрами
    void GameParameters::increaseDay() { day++; }
    void GameParameters::setVisitors(int count) { visitors = count; }
    void GameParameters::spendMoney(int amount) { money -= amount; if (money < 0) money = 0; }
    void GameParameters::earnMoney(int amount) { money += amount; }
    void GameParameters::addAnimal() { animal++; }
    void GameParameters::removeAnimal() { animal--; }
    void GameParameters::addAviary() { aviary++; }
    void GameParameters::addWorker() { workers++; }
    void GameParameters::addVisitor() { visitors++; }
    void GameParameters::setPopularity(int value) { popular = value; }
    void GameParameters::spendpopular(int amount) { money -= amount; }
    void GameParameters::setEat(int value) { eat = value; }
    void GameParameters::reduceEat(int amount) { eat -= amount; if (eat < 0) eat = 0; }
//покупка еды
    void GameParameters::buyFood(int amount) {
        const int foodPrice = 5;
        int totalCost = amount * foodPrice;
        if (money >= totalCost) {
            eat += amount;
            spendMoney(totalCost);
            wcout << L"Куплено " << amount << L" единиц еды за " << totalCost << L"$." << endl;
        }
        else {
            wcout << L"Не хватает денег для покупки " << amount << L" единиц еды! Необходимая сумма: " << totalCost << L"$." << endl;
        }
    }
// популярность рандом каждый день
    void GameParameters::randomizePopularity() {
        int change = rand() % 21 - 10;
        popular += change;
        if (popular < 0) popular = 0;
    }
// кол во поситителей
    void GameParameters::calculateVisitors() {
        visitors = 2 * popular;
        if (visitors < 0) visitors = 0;
    }
// Геттеры для параметров игры
    int GameParameters::getDay() const { return day; }
    int GameParameters::getMoney() const { return money; }
    int GameParameters::getEat() const { return eat; }
    int GameParameters::getPopularity() const { return popular; }
    int GameParameters::getAnimals() const { return animal; }
    int GameParameters::getAviary() const { return aviary; }
    int GameParameters::getWorkers() const { return workers; }
    int GameParameters::getVisitors() const { return visitors; }

// Конструктор Animal - создание животного с заданными параметрами
Animal::Animal(const wstring& name, int age, int weight, int price, int id, const wstring& climate, bool isPredator, int vid_, bool zabolel_)
        : name(name), age(age), weight(weight), price(price), id(id), climate(climate), isAlive(true), isPredator(isPredator), vid(vid_), volier_id(-1), zabolel(zabolel_) {
        pol = (rand() % 2 == 0) ? B : G;
    }

    
// Перечисление типов животных
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
// Вывод информации о животном
    void Animal::printInfo() const {
        wcout << L"Имя: " << name << L", Возраст: " << age << L", Вес: " << weight
            << L" кг, Цена: " << price << L" руб., ID: " << id << L", Вольер: "
            << (volier_id == -1 ? L"Нет" : to_wstring(volier_id + 1)) << L", Климат: "
            << climate << L", Тип: " << (isPredator ? L"Хищник" : L"Травоядное")
            << L", Состояние: " << (isAlive ? L"Живое " : L"Мертвое ") << (pol == B ? L"мужик" : L"женщина") << (zabolel == true ? L" ЕБЛО ЗАБОЛЕЛО" : L" SPEED НЕ ОБНАРУЖЕН") << endl;
    }

// Геттеры сетеры Animal
    int Animal::getId() const { return id; }
    int  Animal::getVolierId() const { return volier_id; }
    void  Animal::setVolierId(int id) { volier_id = id; }
    wstring  Animal::getClimate() const { return climate; }
    int  Animal::getPrice() const { return price; }
    bool  Animal::isAliveStatus() const { return isAlive; }
    void  Animal::die() { isAlive = false; }
    bool  Animal::getIsPredator() const { return isPredator; }
    bool  Animal::getpol() const { return pol; }
    int  Animal::getvid() const { return vid; }
    wstring  Animal::getName() const { return name; }




// Конструкторы конкретных типов животных (наследники Animal)

    TropicalCat::TropicalCat(int id) : Animal(L"Тропический кот", 3, 4, 1000, id, L"Тропический", true, tropcat, 0) {}



    TropicalDog::TropicalDog(int id) : Animal(L"Тропическая собака", 5, 20, 5000, id, L"Тропический", false, tropdog, 0) {}



    SeaLion::SeaLion(int id) : Animal(L"Морской котик", 4, 100, 8000, id, L"Тропический", false, aquacat, 0) {}



    Shark::Shark(int id) : Animal(L"Акула", 10, 200, 15000, id, L"Арктический", true, shark, 0) {}



    ArcticCat::ArcticCat(int id) : Animal(L"Арктический кот", 3, 4, 1000, id, L"Арктический", true, arccat, 0) {}


    ArcticDog::ArcticDog(int id) : Animal(L"Арктическая собака", 5, 20, 5000, id, L"Арктический", false, arcdog, 0) {}


// Новый класс для гибридных животных

    HybridAnimal::HybridAnimal(const wstring& name, int age, int weight, int price, int id, int vid, bool zabolel, const wstring& climate, const wstring& parent1, const wstring& parent2)
        : Animal(name, age, weight, price, id, climate, false, vid, zabolel), parent1(parent1), parent2(parent2) {}

    void HybridAnimal::printInfo() const  {
        Animal::printInfo();
        wcout << L"Родители: " << parent1 << L" и " << parent2 << endl;
    }


// Класс Worker (работник)
Worker::Worker(int id, const wstring& name) : id(id), name(name), volier_id(-1) {}
// Методы Worker
    bool Worker::isBusy() const { return volier_id != -1; }
    void Worker::assignVolier(int id) { volier_id = id; }
    void Worker::removeVolier() { volier_id = -1; }
    wstring Worker::getName() const { return name; }
    int Worker::getId() const { return id; }
    int Worker::getVolierID() const { return volier_id; }


// Класс VolierClass (вольер)
    VolierClass::VolierClass(int capacity, const wstring& climateType, int price, bool isPredator)
        : capacity(capacity), climateType(climateType), price(price), isPredator(isPredator) {}
// Методы VolierClass
    void VolierClass::printInfo() const {
        wcout << L"Вольер: Вместимость " << capacity << L", Климат: " << climateType
            << L", Цена: " << price << L" руб., Тип: " << (isPredator ? L"Хищники" : L"Травоядные") << endl;
    }
    int VolierClass::getcapacity() const { return capacity + 5; }
    int VolierClass::getPrice() const { return price; }
    wstring VolierClass::getClimateType() const { return climateType; }
    bool VolierClass::getIsPredator() const { return isPredator; }




// Класс ZooManager (управление зоопарком)
    ZooManager::ZooManager() : next_animal_id(1), next_worker_id(1) {
        workers.push_back(new Worker(next_worker_id++, L"Игорь"));
        srand(static_cast<unsigned int>(time(0)));
    }
// Деструктор ZooManager - освобождение памят
    ZooManager::~ZooManager() {
        for (auto animal : animals) delete animal;
        for (auto worker : workers) delete worker;
    }

    void ZooManager::buyWorker() {
        wcout << L"Цена за работника: 3000 руб.\n";
        wcout << L"Введите имя работника: ";
        wstring workerName;
        wcin >> workerName;

        for (auto& worker : workers) {
            if (worker->getName() == workerName) {
                wcout << L"Работник с таким именем уже существует." << endl;
                return;
            }
        }

        int workerPrice = 3000;
        if (parameters.getMoney() < workerPrice) {
            wcout << L"Не хватает денег для покупки работника. Необходимая сумма: " << workerPrice << L" руб.\n";
            return;
        }

        parameters.spendMoney(workerPrice);
        workers.push_back(new Worker(next_worker_id++, workerName));
        parameters.addWorker();
        wcout << L"Работник " << workerName << L" успешно куплен!" << endl;
    }

    void ZooManager::feedAnimals() {
        int totalFoodRequired = parameters.getAnimals() * 10;
        parameters.reduceEat(totalFoodRequired);

        if (parameters.getEat() < 0) {
            for (auto& animal : animals) {
                if (animal->isAliveStatus() && (static_cast<double>(rand()) / RAND_MAX > 0.5)) {
                    animal->die();
                    wcout << L"Животное " << animal->getId() << L" умерло от голода!" << endl;
                }
            }
        }
    }

    void ZooManager::buyFood() {
        wcout << L"Сколько единиц еды хотите купить? ";
        int amount;
        wcin >> amount;
        parameters.buyFood(amount);
    }

    void ZooManager::sellAnimal() {
        wcout << L"Введите ID животного, которое хотите продать: ";
        int animal_id;
        wcin >> animal_id;

        auto it = find_if(animals.begin(), animals.end(), [animal_id](Animal* animal) {
            return animal->getId() == animal_id;
            });

        if (it != animals.end()) {
            Animal* animalToSell = *it;
            parameters.earnMoney(animalToSell->getPrice());
            parameters.removeAnimal();
            wcout << L"Животное " << animal_id << L" продано за " << animalToSell->getPrice() << L"$." << endl;
            delete animalToSell;
            animals.erase(it);
        }
        else {
            wcout << L"Животное с таким ID не найдено." << endl;
        }
    }

    void ZooManager::randomEvents() {
        int event = rand() % 4;
        switch (event) {
        case 0: wcout << L"Случайное событие: Местные СМИ опубликовали положительный обзор, популярность увеличивается на 10!" << endl;
            parameters.setPopularity(parameters.getPopularity() + 10); break;
        case 1: wcout << L"Случайное событие: У вас одни из животных игрось попытался утопить -5 популярности." << endl;
            parameters.setPopularity(parameters.getPopularity() - 5); break;
        case 2: wcout << L"Случайное событие: Проведена благотворительная акция, популярность увеличивается на 20!" << endl;
            parameters.setPopularity(parameters.getPopularity() + 20); break;
        case 3: wcout << L"Случайное событие: Возникли проблемы с одним из работником, популярность снизилась на 5!" << endl;
            parameters.setPopularity(parameters.getPopularity() - 5); break;
        }
    }

    void ZooManager::buyPopularity() {
        wcout << L"Выберите, сколько популярности хотите купить:\n";
        wcout << L"1. За 100$ ( +10 )\n";
        wcout << L"2. За 1000$ ( +10 до +100 случайно )\n";
        wcout << L"3. За 10000$ ( +100 )\n";
        wcout << L"Ваш выбор: ";
        int choice;
        wcin >> choice;

        switch (choice) {
        case 1: if (parameters.getMoney() >= 100) {
            parameters.spendMoney(100);
            parameters.setPopularity(parameters.getPopularity() + 10);
            wcout << L"Популярность увеличена на 10." << endl;
        }
              else wcout << L"Не хватает денег для покупки популярности." << endl; break;
        case 2: if (parameters.getMoney() >= 1000) {
            parameters.spendMoney(1000);
            int increase = 10 + rand() % 91;
            parameters.setPopularity(parameters.getPopularity() + increase);
            wcout << L"Популярность увеличена на " << increase << L"." << endl;
        }
              else wcout << L"Не хватает денег для покупки популярности." << endl; break;
        case 3: if (parameters.getMoney() >= 10000) {
            parameters.spendMoney(10000);
            parameters.setPopularity(parameters.getPopularity() + 100);
            wcout << L"Популярность увеличена на 100." << endl;
        }
              else wcout << L"Не хватает денег для покупки популярности." << endl; break;
        default: wcout << L"Некорректный выбор." << endl;
        }
    }

    void ZooManager::zabolelspeed() {
        int i = 1;//rand() % 2;
        if (i == 1) {

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
            wcout << L"гандон заболел\n";


        }
        else {}
    }

    void ZooManager::zabolelspeed100PORZ() {
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
        wcout << L"гандон заболел\n";

    }

    void ZooManager::AIBOLIT() {

        showAnimals();
        wcout << L"введте животное которое хотите вылечить:\n";

        int idanimal;
        wcin >> idanimal;

        for (auto& animal : animals) {
            for (int i = 0; i == idanimal; i++) {
                if (i == idanimal) {}
            }

        }

    }



    void ZooManager::nextDay() {
        zabolelspeed();
        feedAnimals();
        int dailyIncome = parameters.getVisitors() * parameters.getAnimals();
        parameters.earnMoney(dailyIncome);
        wcout << L"Заработок за день: " << dailyIncome << L"$" << endl;
        parameters.randomizePopularity();
        parameters.calculateVisitors();
        randomEvents();
        parameters.increaseDay();

        if (parameters.getMoney() < 0) {
            wcout << L"Вы проиграли! У вас не осталось денег." << endl;
            exit(0);
        }

        wcout << L"=== Конец дня ===" << endl;
        parameters.displayParameters();

        int parent1 = 0, parent2 = 0, parent3 = 0, schetzabol = 0, parent4 = 0, parent5 = 0;

        if (animals.empty()) { return; }
        for (auto& animal : animals) {

            parent1 = animal->getId();
            if (animal->zabolel == true) {
                schetzabol += 1;
            }



        }



        if (schetzabol >= (parent1 / 2))
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


                    if ((it != animals.end()) && randomer == 1) {
                        Animal* animalToSell = *it;

                        parameters.removeAnimal();
                        wcout << L"Животное " << animal_id << L" погибло в борьбе со скоростью " << endl;
                        delete animalToSell;
                        animals.erase(it);
                    }
                    else {

                    }

                }


            }
        schetzabol = 0;

    }

    void ZooManager::buyAnimal() {
        if (workers.empty() || (workers.size() == 1 && workers[0]->getName() == L"Игорь" && workers[0]->isBusy())) {
            wcout << L"Нет доступных работников для обслуживания вольеров. Нельзя купить животное." << endl;
            return;
        }

        wcout << L"Выберите животное для покупки:\n";
        wcout << L"1. Тропический кот (1000 руб.)\n";
        wcout << L"2. Тропическая собака (5000 руб.)\n";
        wcout << L"3. Арктический кот (1000 руб.)\n";
        wcout << L"4. Арктическая собака (5000 руб.)\n";
        wcout << L"5. Морской котик (8000 руб.)\n";
        wcout << L"6. Акула (15000 руб.)\n";
        wcout << L"Ваш выбор: ";

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
        default: wcout << L"Некорректный выбор!" << endl; return;
        }

        if (parameters.getMoney() < newAnimal->getPrice()) {
            wcout << L"Не хватает денег для покупки " << newAnimal->getId() << L". Необходимая сумма: "
                << newAnimal->getPrice() << L" руб.\n";
            delete newAnimal;
            return;
        }

        animals.push_back(newAnimal);
        parameters.addAnimal();
        parameters.spendMoney(newAnimal->getPrice());
        wcout << L"Животное успешно куплено." << endl;
    }

    void ZooManager::assignWorkerToVolier() {
        wcout << L"Введите имя работника: ";
        wstring workerName;
        wcin >> workerName;

        for (auto& worker : workers) {
            if (worker->getName() == workerName) {
                if (worker->isBusy()) {
                    wcout << L"Этот работник уже занят." << endl;
                    return;
                }

                wcout << L"Выберите вольер для назначения: " << endl;
                for (size_t i = 0; i < voliers.size(); ++i) {
                    wcout << L"ID: " << (i + 1) << L" ";
                    voliers[i].printInfo();
                }

                wcout << L"Введите номер вольера: ";
                int volier_index;
                wcin >> volier_index;

                if (volier_index < 1 || volier_index > voliers.size()) {
                    wcout << L"Некорректный номер вольера." << endl;
                    return;
                }

                worker->assignVolier(volier_index - 1);
                wcout << worker->getName() << L" успешно назначен на вольер " << volier_index << endl;
                return;
            }
        }

        wcout << L"Работник с именем " << workerName << L" не найден." << endl;
    }

    void ZooManager::placeAnimalInVolier() {
        wcout << L"Введите ID животного, которое хотите разместить: ";
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
            wcout << L"Животное с таким ID не найдено." << endl;
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
            wcout << L"Нет доступного работника для размещения животного." << endl;
            return;
        }

        wcout << L"Выберите вольер для размещения животного: " << endl;
        for (size_t i = 0; i < voliers.size(); ++i) {
            wcout << L"ID: " << (i + 1) << L" ";
            voliers[i].printInfo();
        }

        wcout << L"Введите номер вольера: ";
        int volier_index;
        wcin >> volier_index;

        if (volier_index < 1 || volier_index > voliers.size()) {
            wcout << L"Некорректный номер вольера." << endl;
            return;
        }

        if (animalToPlace->getClimate() != voliers[volier_index - 1].getClimateType()) {
            wcout << L"Неверный климат для размещения животного в вольере." << endl;
            return;
        }

        if (animalToPlace->getIsPredator() != voliers[volier_index - 1].getIsPredator()) {
            wstring animalType = animalToPlace->getIsPredator() ? L"хищник" : L"травоядное";
            wstring volierType = voliers[volier_index - 1].getIsPredator() ? L"хищников" : L"травоядных";
            wcout << L"Ошибка! Это животное - " << animalType
                << L", а вольер предназначен для " << volierType << L"." << endl;
            return;
        }

        animalToPlace->setVolierId(volier_index - 1);
        wcout << L"Животное успешно размещено в вольер!" << endl;
    }

    void ZooManager::showAnimals() const {
        wcout << L"\n=== Животные ===" << endl;
        for (const auto& animal : animals) {
            animal->printInfo();
        }
    }

    void ZooManager::showVoliers() const {
        wcout << L"\n=== Вольеры ===" << endl;
        for (size_t i = 0; i < voliers.size(); ++i) {
            wcout << L"ID: " << (i + 1) << L" ";
            voliers[i].printInfo();
        }
    }

    void ZooManager::showWorkers() const {
        wcout << L"\n=== Работники ===" << endl;
        for (const auto& worker : workers) {
            wcout << L"ID: " << worker->getId()
                << L", Имя: " << worker->getName()
                << L", ID вольера: "
                << (worker->isBusy() ? to_wstring(worker->getVolierID() + 1) : L"Нет") << endl;
        }
    }

    void ZooManager::breedAnimals() {
        showAnimals();
        wcout << L"Введите ID первого животного: ";
        int id1;
        wcin >> id1;

        wcout << L"Введите ID второго животного: ";
        int id2;
        wcin >> id2;

        Animal* parent1 = nullptr;
        Animal* parent2 = nullptr;

        // Найти родителей по ID
        for (auto& animal : animals) {
            if (animal->getId() == id1) {
                parent1 = animal;
            }
            else if (animal->getId() == id2) {
                parent2 = animal;
            }
        }

        if (!parent1 || !parent2) {
            wcout << L"Одно или оба из указанных животных не найдены." << endl;
            return;
        }

        if (parent1->getId() == parent2->getId()) {
            wcout << L"Нельзя размножать одно и то же животное." << endl;
            return;
        }

        if (parent1->getvid() != parent2->getvid()) {
            wcout << L"нельзя скрещивать разных животных";
            return;
        }
        /*
        if (parent1->getpol() == parent2->getpol()){
            if(parent1->getpol() == 0) wcout << L"фу пидорасня идите отсюда!";
            if (parent1->getpol() == 1) wcout << L"Девки ну вы шо лучше уж эскорт";
            return;
        }
        */


        wstring hybridName = parent1->getName() + L"_" + parent2->getName() + L" Гибрид";
        int hybridPrice = (parent1->getPrice() + parent2->getPrice()) / 2;
        hybridPrice = max(1000, hybridPrice);

        Animal* newAnimal = new HybridAnimal(hybridName, 0, 5, hybridPrice, next_animal_id++, parent1->getvid(), 0, L"Гибридный", parent1->getName(), parent2->getName());
        animals.push_back(newAnimal);
        parameters.addAnimal();

        wcout << L"Гибридное животное " << hybridName << L" успешно создано!" << endl;
    }

    void ZooManager::buyVolier() {
        int type, capacity;

        wcout << L"Выберите тип вольера:\n";
        wcout << L"1. Для арктических животных\n";
        wcout << L"2. Для тропических животных\n";
        wcout << L"Ваш выбор: ";
        wcin >> type;

        wcout << L"Введите количество мест в вольере (1-100): ";
        wcin >> capacity;

        int pricePerPlace = (type == 1) ? 200 : 250;
        int totalPrice = pricePerPlace * capacity;

        if (parameters.getMoney() < totalPrice) {
            wcout << L"Не хватает денег! Необходимая сумма: " << totalPrice << L" руб.\n";
            return;
        }

        parameters.spendMoney(totalPrice);
        wstring climateType = (type == 1) ? L"Арктический" : L"Тропический";

        wcout << L"Выберите тип животных для вольера:\n";
        wcout << L"1. Хищники\n";
        wcout << L"2. Травоядные\n";
        int animalType;
        wcin >> animalType;

        bool isPredator = (animalType == 1);
        voliers.emplace_back(capacity, climateType, totalPrice, isPredator);
        parameters.addAviary();
        wcout << L"Вольер успешно куплен!\n";
    }

    void ZooManager::upVolier() {
        if (voliers.empty() != true) {

            showVoliers();
            wcout << L"какой хотите улучшить все вольеры\n";

            wcout << L"Введите ID: ";
            int id1;
            wcin >> id1;
            if (parameters.getMoney() > 200) {
                parameters.spendMoney(200);
            }
            else {
                wcout << L"у вас нет вольеров\n";
                return;
            }
            for (auto& voler : voliers) {


                voler.capacity = voler.getcapacity();


            }
        }
        else {
            wcout << L"у вас нет вольеров\n";
            return;
        }


    }

