#include <iostream>
#include <vector>
#include <string>

class Hayvan {
public:
    Hayvan(std::string ad, int yas) : ad(ad), yas(yas) {}

    void sahiplendirildi() const {
        std::cout << ad << " adli hayvan sahiplendirildi!" << std::endl;
    }

    std::string getAd() const {
        return ad;
    }

    int getYas() const {
        return yas;
    }

private:
    std::string ad;
    int yas;
};

class Barinak {
public:
    void hayvanlariGoster() const {
        std::cout << "Barinak İçindeki Hayvanlar:" << std::endl;
        for (int i = 0; i < hayvanlar.size(); ++i) {
            std::cout << i + 1 << ". " << hayvanlar[i].getAd() << " - " << hayvanlar[i].getYas() << " years old" << std::endl;
        }
    }

    void hayvanEkle(const Hayvan& hayvan) {
        hayvanlar.push_back(hayvan);
    }

    void hayvanSahiplen(int indeks) {
        if (indeks >= 0 && indeks < hayvanlar.size()) {
            hayvanlar[indeks].sahiplendirildi();
            hayvanlar.erase(hayvanlar.begin() + indeks); 
        } else {
            std::cout << "Gecersiz indeks!" << std::endl;
        }
    }

    int getHayvanSayisi() const {
        return hayvanlar.size();
    }

private:
    std::vector<Hayvan> hayvanlar;
};

void hosgeldinizMesaji() {
    std::cout << "welcome to animal shelter system!" << std::endl;
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

                Hayvan yeniHayvan(ad, yas);
                barinak.hayvanEkle(yeniHayvan);
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
