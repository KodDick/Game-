
#include "library.h"
#include "class.h"
#include "def.h"
using namespace std;

// Класс для управления параметрами игры



int wmain() {
    setlocale(LC_ALL, "Russian");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    ZooManager zooManager;
    wstring zooname;
    wcout << L"введите название своего зоопарка:\n";  wcin >> zooname; 

    while (true) {

        wcout << L"\nЗоопарк " << zooname << endl;
        zooManager.parameters.displayParameters();
        menu();

        int choice;
        wcin >> choice;

        switch (choice) {
        case 1: zooManager.buyAnimal(); break;
        case 2: zooManager.buyWorker(); break;
        case 3: zooManager.assignWorkerToVolier(); break;
        case 4: zooManager.placeAnimalInVolier(); break;
        case 5: zooManager.buyVolier(); break;
        case 6: zooManager.buyFood(); break;
        case 7: zooManager.sellAnimal(); break;
        case 8: zooManager.buyPopularity(); break;
        case 9: zooManager.showAnimals(); break;
        case 10: zooManager.showVoliers(); break;
        case 11: zooManager.showWorkers(); break;
        case 12: zooManager.nextDay(); break;
        case 13: zooManager.breedAnimals(); break;
        case 14: zooManager.upVolier(); break;
        case 15: zooManager.AIBOLIT(); break;
        default: wcout << L"все хуйня давай по новой" << endl;
        }
    }
    return 0;
}