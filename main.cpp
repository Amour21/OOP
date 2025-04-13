#include <iostream>
#include "Animal.h"
#include "Zoo.h""

int main() {

    Animal* dog = new Dog("Buddy");
    Animal* cat = new Cat("Whiskers");
    Animal* parrot = new Parrot("Polly");
    Animal* animalArr[] = { dog, cat, parrot };
    int arrSize = sizeof(animalArr) / sizeof(animalArr[0]);
    Zoo zoo(animalArr, arrSize);
    zoo.ask_for_eating();
    
    return 0;
}
