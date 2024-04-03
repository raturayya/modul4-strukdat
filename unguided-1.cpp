#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Menambahkan data mahasiswa di depan
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
        cout << "Data telah ditambahkan\n";
    }

    // Menambahkan data mahasiswa di belakang
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Mahasiswa* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Data telah ditambahkan\n";
    }

    // Menambahkan data mahasiswa di tengah berdasarkan posisi
    void tambahTengah(string nama, string nim, int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid\n";
            return;
        }
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        if (posisi == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Mahasiswa* temp = head;
            for (int i = 1; i < posisi - 1; i++) {
                if (temp == nullptr) {
                    cout << "Posisi tidak valid\n";
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Data telah ditambahkan\n";
    }

    // Mengubah data mahasiswa di depan
    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data di depan telah diubah\n";
    }

    // Mengubah data mahasiswa di belakang
    void ubahBelakang(string nama, string nim) {
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data di belakang telah diubah\n";
    }

    // Mengubah data mahasiswa di tengah berdasarkan posisi
    void ubahTengah(string nama, string nim, int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid\n";
            return;
        }
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi; i++) {
            if (temp == nullptr) {
                cout << "Posisi tidak valid\n";
                return;
            }
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data di posisi " << posisi << " telah diubah\n";
    }

    // Menghapus data mahasiswa di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
        cout << "Data di depan telah dihapus\n";
    }

    // Menghapus data mahasiswa di belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Data di belakang telah dihapus\n";
            return;
        }
        Mahasiswa* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Data di belakang telah dihapus\n";
    }

    // Menghapus data mahasiswa di tengah berdasarkan posisi
    void hapusTengah(int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid\n";
            return;
        }
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        Mahasiswa* temp = head;
        if (posisi == 1) {
            head = head->next;
            delete temp;
            cout << "Data di posisi " << posisi << " telah dihapus\n";
            return;
        }
        for (int i = 1; i < posisi - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Posisi tidak valid\n";
                return;
            }
            temp = temp->next;
        }
        Mahasiswa* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
        cout << "Data di posisi " << posisi << " telah dihapus\n";
    }

    void tampilkanData() {
        if (head == nullptr) {
            cout << "Linked List kosong\n";
            return;
        }
        cout << "DATA MAHASISWA\n";
        cout << setw(20) << left << "NAMA" << setw(20) << left << "NIM" << endl;
        Mahasiswa* temp = head;
        while (temp != nullptr) {
            cout << setw(20) << left << temp->nama << setw(20) << left << temp->nim << endl;
            temp = temp->next;
        }
    }

    // Menghapus semua data mahasiswa
    void hapusList() {
        while (head != nullptr) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Semua data mahasiswa telah dihapus\n";
    }
};

int main() {
    LinkedList linkedList;
    int pilihan;
    string nama, nim;
    int posisi;
    while (true) {
        cout << "\n  PROGRAM DATA MAHASISWA\n";
        cout << "---------------------------" << endl;
        cout << endl ;
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. TAMPILKAN\n";
        cout << "0. KELUAR\n";

        cout << endl;

        cout << "Pilih Operasi: ";
        cin >> pilihan;

        cout << endl;

        switch (pilihan) {
            case 1:
                cout << "-Tambah Depan\n";
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "-Tambah Belakang\n";
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "-Tambah Tengah\n";
                cout << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "-Ubah Depan\n";
                cout << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "-Ubah Belakang\n";
                cout << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "-Ubah Tengah\n";
                cout << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "-Hapus Depan\n";
                cout << endl;
                linkedList.hapusDepan();
                break;
            case 8:
                cout << "-Hapus Belakang\n";
                cout << endl;
                linkedList.hapusBelakang();
                break;
            case 9:
                cout << "-Hapus Tengah\n";
                cout << endl;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.hapusTengah(posisi);
                break;
            case 10:
                cout << "-Hapus List\n";
                cout << endl;
                linkedList.hapusList();
                break;
            case 11:
                cout << "-Tampilkan\n";
                cout << endl;
                linkedList.tampilkanData();
                break;
            case 0:
                exit(0);
            default:
                cout << "Pilihan tidak valid\n";
        }
    }

    return 0;
}
