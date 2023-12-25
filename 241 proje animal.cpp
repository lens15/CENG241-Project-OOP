#include <iostream>
#include <vector>
#include <string>

class Hayvan {
public:
    Hayvan(std::string ad, int yas) : ad(ad), yas(yas) {}

    virtual void sahiplendirildi() const {
        std::cout << ad << " adli hayvan sahiplendirildi!" << std::endl;
    }

    virtual void tanit() const {
        std::cout << ad << " - " << yas << " years old" << std::endl;
    }

    virtual ~Hayvan() {}

protected:
    std::string ad;
    int yas;
};

class Kedi : public Hayvan {
public:
    Kedi(std::string ad, int yas, std::string tuyRengi) : Hayvan(ad, yas), tuyRengi(tuyRengi) {}

    void tanit() const override {
        std::cout << ad << " - " << yas << " years old - Fur Color: " << tuyRengi << std::endl;
    }

private:
    std::string tuyRengi;
};

class Kopek : public Hayvan {
public:
    Kopek(std::string ad, int yas, std::string tur) : Hayvan(ad, yas), tur(tur) {}

    void tanit() const override {
        std::cout << ad << " - " << yas << " years old - Breed: " << tur << std::endl;
    }

private:
    std::string tur;
};

class Barinak {
public:
    void hayvanlariGoster() const {
        std::cout << "Barinak İçindeki Hayvanlar:" << std::endl;
        for (const auto& hayvan : hayvanlar) {
            hayvan->tanit();
        }
    }

    void hayvanEkle(Hayvan* hayvan) {
        hayvanlar.push_back(hayvan);
    }

    void hayvanSahiplen(int indeks) {
        if (indeks >= 0 && indeks < hayvanlar.size()) {
            hayvanlar[indeks]->sahiplendirildi();
            delete hayvanlar[indeks];
            hayvanlar.erase(hayvanlar.begin() + indeks);
        } else {
            std::cout << "Gecersiz indeks!" << std::endl;
        }
    }

    int getHayvanSayisi() const {
        return hayvanlar.size();
    }

    ~Barinak() {
        for (const auto& hayvan : hayvanlar) {
            delete hayvan;
        }
    }

private:
    std::vector<Hayvan*> hayvanlar;
};

void hosgeldinizMesaji() {
    std::cout << "Welcome to the animal shelter system!" << std::endl;
}

int main() {
    hosgeldinizMesaji();

    Barinak barinak;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Animals\n";
        std::cout << "2. Adopt Pet\n";
        std::cout << "3. Add New Animal\n";
        std::cout << "4. Exit\n";
        std::cout << "Make your selection: ";

        int secim;
        std::cin >> secim;

        switch (secim) {
            case 1:
                barinak.hayvanlariGoster();
                break;
            case 2: {
                barinak.hayvanlariGoster();
                std::cout << "Enter the number of the animal you want to adopt:";
                int indeks;
                std::cin >> indeks;
                barinak.hayvanSahiplen(indeks - 1);
                break;
            }
            case 3: {
                std::string ad;
                int yas;
                std::cout << "Enter the name of the new animal: ";
                std::cin >> ad;
                std::cout << "Enter the age of the new animal: ";
                std::cin >> yas;

                int secimTur;
                std::cout << "Select the type of the new animal (1. Cat, 2. Dog): ";
                std::cin >> secimTur;

                if (secimTur == 1) {
                    std::string tuyRengi;
                    std::cout << "Enter the fur color of the cat: ";
                    std::cin >> tuyRengi;
                    barinak.hayvanEkle(new Kedi(ad, yas, tuyRengi));
                } else if (secimTur == 2) {
                    std::string tur;
                    std::cout << "Enter the breed of the dog: ";
                    std::cin >> tur;
                    barinak.hayvanEkle(new Kopek(ad, yas, tur));
                } else {
                    std::cout << "Invalid choice!" << std::endl;
                }

                std::cout << "Yeni hayvan eklendi!" << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Geçersiz seçim!" << std::endl;
                break;
        }

        std::cout << "Total number of animals in the shelter: " << barinak.getHayvanSayisi() << std::endl;
    }

    return 0;
}


