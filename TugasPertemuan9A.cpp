#include <iostream>
#include <string>

class Mahasiswa {
private:
    std::string nama;
    std::string NIM;
    float nilai;

public:
    Mahasiswa(std::string n, std::string nim) : nama(n), NIM(nim), nilai(0) {}

    friend void beriNilai(Mahasiswa* m, float n);
};

void beriNilai(Mahasiswa* m, float n) {
    m->nilai = n;
}

class Dosen {
private:
    std::string nama;
    std::string NIDN;
    std::string pangkat;
    float gaji;

public:
    Dosen(std::string n, std::string nidn, std::string p, float g) : nama(n), NIDN(nidn), pangkat(p), gaji(g) {}

    friend void ubahPangkat(Dosen* d, std::string pangkatBaru);
    friend class Universitas; // Class Universitas sebagai friend
};

void ubahPangkat(Dosen* d, std::string pangkatBaru) {
    d->pangkat = pangkatBaru;
}

class Staff {
private:
    std::string nama;
    std::string IDstaff;
    float gaji;

public:
    Staff(std::string n, std::string id, float g) : nama(n), IDstaff(id), gaji(g) {}

    friend void lihatGajiStaff(Staff* s);
};

void lihatGajiStaff(Staff* s) {
    std::cout << "Gaji Staff " << s->nama << ": " << s->gaji << std::endl;
}

class Universitas {
public:
    void aksesGajiDosen(Dosen* d) {
        std::cout << "Gaji Dosen " << d->nama << ": " << d->gaji << std::endl;
    }
};

int main() {
    Mahasiswa mhs("Intan", "123456");
    beriNilai(&mhs, 85.0);

    Dosen dosen("Dr. Budiono siregar", "7891011", "Lektor", 900000);
    ubahPangkat(&dosen, "Profesor");

    Staff staff("Nazar", "STF123", 700000);

    Universitas univ;
    univ.aksesGajiDosen(&dosen);
    lihatGajiStaff(&staff);

    return 0;
}
