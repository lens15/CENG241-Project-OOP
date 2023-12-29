#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
enum class Animal_Type { Domestic, Wild };
enum class Pet_Type { Cat, Dog,Bird,Fish,Rabbit,Turtle,Hamster,Wild_Cat,Spider,Other_Insect,Monkey };
enum class Gender { Male, Female };
enum class CharacterTrait { Playfull, NotPlayfull,Endangered,Dangerous,Sensitive};

class Animal {
protected:
    string name;
    int age;
    Animal_Type animalType;
    Pet_Type evcilHayvanTuru;
    Gender gender;
    CharacterTrait character;
    string feather_color;

public:
    Animal(const string& name, int age, Animal_Type type, Pet_Type evcilTuru, Gender gender, CharacterTrait character)
        : name(name), age(age), animalType(type), evcilHayvanTuru(evcilTuru), gender(gender), character(character) {}
    virtual ~Animal() {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << (gender == Gender::Male ? "Male" : "Female")<< endl;//**********************************
        cout<<"Character: " << (character == CharacterTrait::Playfull ? "Playfull" :"Not Playfull")<< endl;
    }
    Animal_Type getType() const { 
        return animalType;
    }
    Pet_Type getEvcilHayvanTuru() const { 
        return evcilHayvanTuru;
    }
};
class Dog : public Animal {
private:
    float weight;
    string featherColor;
    bool vaccinated;
    bool vicious;
    string species;/****wtf*****/
 
public:
    bool isVaccinated()const {
        return vaccinated;
    }
    bool visious()const {
        return vicious;
    }
    string getName()const {
        return name;
    }
    Dog(const string&name,int age,float weight,const string&featherColor,bool vaccinated,bool vicious,const string& species,Gender gender, CharacterTrait character)
    :Animal(name,age,Animal_Type::Domestic,Pet_Type::Dog,gender,character),weight(weight),featherColor(featherColor),vaccinated(vaccinated),vicious(vicious),species(species) {};

    void displayInfo() const override {//////**************************************************************************
        cout << "Dog: ";


    }

};


class Cat : public Animal {
private:
    float weight;
    string featherColor;
    bool vaccinated;
    bool vicious;
    string species;

public:
    bool isVaccinated() const { 
        return vaccinated;
    }
    bool vicious()const {
        return vicious;
    }
    string getName() const { 
        return name;
    }
    // Yapýcý metodu species parametresini de alacak þekilde güncelle
    Cat(const string& name, int age, float weight, const string& featherColor, bool vaccinated, bool vicious, const string& species, Gender gender, CharacterTrait character)
        : Animal(name, age, Animal_Type::Domestic, Pet_Type::Cat, gender, character), weight(weight), featherColor(featherColor), vaccinated(vaccinated), vicious(vicious), species(species) {}

    void displayInfo() const override {
        cout << left << setw(15) << species << setw(15) << name << setw(5) << age << setw(10) << weight
            << setw(15) << featherColor << setw(15) << (vaccinated ? "Yes" : "No") << setw(15) << (vicious ? "Yes" : "No")
            << setw(10) << (gender == Gender::Male ? "Male" : "Female")
            << setw(15) << (character == CharacterTrait::Playfull ? "Playfull" : "Not Playfull") << endl;
    }


    void displayAnimals(const vector<Animal*>& animals, Pet_Type tur) {
        cout << left << setw(15) << "SPECIES" << setw(15) << "NAME" << setw(5) << "AGE" << setw(10) << "WEIGHT"
            << setw(15) << "FEATHERCOLOR" << setw(15) << "VACCINATED" << setw(15) << "VICIOUS"
            << setw(10) << "GENDER" << setw(15) << "CHARACTER" << endl;
        cout << string(110, '-') << endl; // Çizgi uzunluðunu sütun geniþliklerine göre ayarla

        for (const auto& animal : animals) {
            if (animal->getType() == Animal_Type::Domestic && animal->getEvcilHayvanTuru() == tur) {
                animal->displayInfo();
            }
        }
    }

};

class Bird {
private:



public:




};
class Fish{
private:




public:



};
class Rabbit{
private:


public:



};
class Turtle{
private:


public:


};
class Hamster{
private:

public:


};
class Wild_Cat{
private:



public:



};
class Spider{
private:


public:


};
class Other_Insect{
private:

public:


};
class Monkey{



private:



public:



};
class Volunteering {
public:
    string name;
    string surname;
    int id;
    
   
    Volunteering(const string& othname, const string& othsurname, const int& othid) {
        name= othname;
        surname = othsurname;
        id = othid;
    }
    ~Volunteering() {
    };
   
};

/*class Feedback {
public:
    string e_mail;
    string phone_number;
    string user_feedback;
    char choose;
    void Feedbackfunc () {
        cout << "Enter your feedback: ";
        getline(cin, user_feedback);
        cout << "If you want us to contact with you please provide contact info?" << endl;
        cout << "If you want press 'y' ýf no press 'n' : ";
        cin >> choose;
        if (choose == 'y' || choose == 'Y') {
            cout << "Your Email Adress: " << endl;
            cin >> e_mail;
            cout << "Your Phone Number: " << endl;
            cin >> phone_number;
        }
        else if (choose = 'n' || choose == 'N') {
            cout << "Our contact infos: " << endl;
            cout << "Email: sheltercutie@gmail.com" << endl;
            cout << "Phone Number: +905442224455" << endl;
        }
      
    }
    void disp()const{
        cout << "Feedback: " << user_feedback << endl;
        cout << "Contact Email: " << e_mail;
        cout << "Contact Phone: " << phone_number;
        cout << endl;
    }
};*/// feedback sýnýfý tam olmadý;
class LostAndFoundAnimal {
public:
    string species;
    string name;
    string description;
    bool isLost;

};
void loadAnimalsFromFile(const string& filePath, vector<Animal*>& animals) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    string line, type, name, featherColor, species, genderStr, characterStr;
    string ageStr, weightStr, vaccinatedStr, viciousStr;
    int age;
    float weight;
    bool vaccinated, vicious;
    Gender gender;
    CharacterTrait character;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, weightStr, ',');
        getline(ss, featherColor, ',');
        getline(ss, vaccinatedStr, ',');
        getline(ss, viciousStr, ',');
        getline(ss, species, ',');
        getline(ss, genderStr, ',');
        getline(ss, characterStr);

        characterStr.erase(remove(characterStr.begin(), characterStr.end(), ' '), characterStr.end());

        try {
            age = stoi(ageStr);
            weight = weightStr.empty() ? 0 : stof(weightStr);
        }
        catch (const std::invalid_argument& e) {
            cerr << "Invalid number format in line: " << line << endl;
            continue;
        }

        vaccinated = (vaccinatedStr == "Yes");
        vicious = (viciousStr == "Yes");
        gender = (genderStr == "Male" ? Gender::Male : Gender::Female);
        character = (characterStr == "Oynar" ? CharacterTrait::Playfull : CharacterTrait::NotPlayfull);

        if (type == "Cat") {
            animals.push_back(new Cat(name, age, weight, featherColor, vaccinated, vicious, species, gender, character));
        }
        else if (type == "Dog") {
            //animals.push_back(new Dog(name, age, gender, character));
        }
        // Diðer hayvan türleri için benzer iþlemler...
    }
    file.close();
}
void displayUnvaccinatedAnimals(const vector<Animal*>& animals) {
    bool foundUnvaccinatedAnimals = false;

    for (const auto& animal : animals) {
        if (animal->getType() == Animal_Type::Domestic) {
            const Cat* cat = dynamic_cast<const Cat*>(animal);
            if (cat != nullptr) {
                if (!cat->isVaccinated()) {
                    if (!foundUnvaccinatedAnimals) {
                        cout << "Unvaccinated animals:\n";
                        foundUnvaccinatedAnimals = true;
                    }
                    cout << "Species: Cat, Name " << cat->getName() << endl;
                }
            }
            // Burada, diðer hayvan türleri için de benzer kontrol ve yazdýrma iþlemleri ekleyebilirsiniz.
        }
    }

    if (!foundUnvaccinatedAnimals) {
        cout << "All animals have been vaccinated.\n";
    }
}
void displayAnimals(const vector<Animal*>& animals, Pet_Type tur) {
    int totalCats = 0;

    cout << left << setw(15) << "SPECIES" << setw(15) << "NAME" << setw(5) << "AGE" << setw(10) << "WEIGHT"
        << setw(15) << "FEATHERCOLOR" << setw(15) << "VACCINATED" << setw(15) << "VICIOUS"
        << setw(10) << "GENDER" << setw(15) << "CHARACTER" << endl;
    cout << string(110, '-') << endl;

    for (const auto& animal : animals) {
        if (animal->getType() == Animal_Type::Domestic && animal->getEvcilHayvanTuru() == tur) {
            animal->displayInfo();
            totalCats++;
        }
    }

    cout << "\n** There is a " << totalCats << " cat total in this shelter**\n\n" << endl;
}

int donationBox = 0;
void manageCostsAndDonations() {
    int choice;
    cout << "1.Make a Donation. " << endl;
    cout << "2.See the Total Amount. " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        int donation;
        cout << "How much would you like to donate? (TL): ";
        cin >> donation;

        if (donation > 0) {
            donationBox += donation;
            cout << "Thank you for your donation! The current donation box balance is: " << donationBox << " TL.\n";
        }
        else {
            cout << "Invalid donation amount. Please try again.\n";
        }
        break;
    case 2:
        cout << "The current amount of donations: " << donationBox << " TL" << endl;
        break;
    default:
        cout << "Invalid choice.Please try again..." << endl;
        break;
    }
}


int main() {
    vector<Animal*> animals;
    string filePath = "C:\\Users\\selin\\Desktop\\animalls.txt.txt";
    vector<Volunteering*>volunteers;
    loadAnimalsFromFile(filePath, animals);

    int mainChoice;
    int animalTypeChoice;
    int VolunteerChoice;
    string ID, name, surname, concept, date, hour, duration,place;


    while (mainChoice == !11) {
        cout << "**Welcome to the Virtual Animal Shelter!**\n";
        cout << "---------- Shelter SelUmAlÖz ----------\n";
        cout << "1. Animal Information\n";
        cout << "2. Health Records Management\n";
        cout << "3. Adoption Status Tracking\n";
        cout << "4. Volunteer Management\n";
        cout << "5. Donation Management\n";
        cout << "6. Event Planning\n";
        cout << "7. Lost and Found Animals\n";
        cout << "8. Training and Behavior Management\n";
        cout << "9. Feedback and Contact Forms\n";
        cout << "10. Exit\n";
        cout << "Make your choice: ";
        cin >> mainChoice;
        switch (mainChoice) {
        case 1:
            cout << "Select Animal Type:" << endl;
            cout << "1.Pets" << endl;
            cout << "2.Wild Animals" << endl;
            cin >> animalTypeChoice;
            switch (animalTypeChoice) {
            case 1:
                int pet_Choice;
                cout << "Current Domestic Animal species: " << endl;
                cout << "1.Cats" << endl;
                cout << "2.Dogs" << endl;
                cout << "3.Birds" << endl;
                cout << "4.Fishes" << endl;
                cout << "5.Rabbits" << endl;
                cout << "6.Turtles" << endl;
                cout << "7.Hamsters" << endl;
                cout << "Choose a Pet:";
                cin >> pet_Choice;
                switch (pet_Choice) {
                case1:
                    displayAnimals(animals, Pet_Type::Cat);
                    break;
                case2:
                    displayAnimals(animals, Pet_Type::Dog);
                    break;
                case 3:
                    
                    break;
                case 4:
                    //fishes
                    break;
                case 5:
                    //Rabbits
                    break;
                case 6:
                    //Turtles
                    break;
                case 7:
                    //Hamster
                    break;
                default:
                    cout << "Invalid choice.!" << endl;
                    break;
                }
                break;
            case 2:
                int wild_Choice;
                cout << "Current Wild Animal species: " << endl;
                cout << "1.Wild Cats" << endl;
                cout << "2.Snakes" << endl;
                cout << "3.Spider" << endl;
                cout << "4.Insects" << endl;
                cout << "5.Monkeys" << endl;
                cin >> wild_Choice;
                switch(wild_Choice) {
                case 1:
                    //Wild cats
                    break;
                case 2:
                    //Snakes
                    break;
                case 3:
                    //Spider
                    break;
                case 4:
                    //Insects
                    break;
                case 5:
                    //Monkeys
                    break;
                default:
                    cout << "Invalid Choice.!"<<endl;
                    break;
                }
                    break;
            }
            break;
        case 2:
            //Health records management;
            break;
        case 3:

            //Adoption Status Tracking
            break;
        case 4:
            cout << "**Volunteering**" << endl;
            cout << "1.See all Volunteers" << endl;
            cout << "2.Become a Volunteer" << endl;
            cout << "Your choice: ";
            cin >> VolunteerChoice;
            cout << endl;
            switch (VolunteerChoice) {
            case 1:
               
                break;
            case 2:
                cout << "Enter Name: ";
                string VolunteerName;
                getline(cin, VolunteerName);
                cout << endl;
                cout << "Enter Surname: ";
                string VolunteerSurname;
                getline(cin, VolunteerSurname);
                cout << endl;
                cout << "Enter ID: ";
                string VolunteerId;
                getline(cin, VolunteerId);
                cout << endl;
               // volunteers.push_back(new Volunteering(VolunteerName, VolunteerSurname, VolunteerId));//olmadý bura

                break;
            }

            break;
        case 5:
            manageCostsAndDonations();
            break;
        case 6:
  
            cout << "**Welcome To Event Planning Section**" << endl;
            cout << "Please Enter Your Name and Surname" << endl;
            cout << "Your name: ";
            getline(cin, name);
            cout << endl;
            cout << "Your surname: ";
            getline(cin, surname);
            cout << endl;
            cout << "Concept Of Your Event";
            getline(cin, concept);
            cout << endl;
            cout << "Date: " << endl;
            getline(cin, date);
            cout << endl;
            cout << "Starting hour: ";
            getline(cin, hour);
            cout << endl;
            cout << "How many hours will it take: ";
            getline(cin, duration);
            cout << "Lastly where do you think is more suitable for you? Options: " << endl;
            cout << "1.Garden" << endl;
            cout << "2.Auditorium" << endl;
            cout << "3.Training Area(The ground may be muddy depending on the weather)" << endl;
            getline(cin, place);
            cout << endl;
            cout << "Thank You..!! " << name << " " << surname << " We will inform you about your event plan within 2 days wia e-mail or phone " << endl;
            break;
        case 7:
            //Lost and Found Animals
            break;
        case 8:
            //Training and Behaivour Management
            break;
        case 9:
            //Feedback and Contact Forms
            break;
        case 10:
            cout << "Exiting the sheltiring system..." << endl;
                break;
        default:
            cout << "Invalid selection..!" << endl;
            break;
        }
    }

    for (auto* animal : animals) {
        delete animal;
    }

    return 0;
}