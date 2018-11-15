#ifndef MAIN_INCLUDE
#define MAIN_INCLUDE

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Bos {
private:
    string username = "", password = "";
public:
    Bos(){
    }
    bool login(string user, string pass){
        ifstream file("data.dt");
        while (!file.eof()){
            file >> username;
            file >> password;
            if (username == user && password == pass){
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    void inputKaryawan(){
        string nama, nik;
        char c;
        cout << "Masukkan nama karyawan: "; cin >> nama;
        cout << "Masukkan nik karyawan: "; cin >> nik;
        cout << "Yakin? "; cin >> c;
        if (c == 'y' || c == 'Y'){
            fstream file("karyawan.dt");
            file.seekp(0, ios::end);
            file << "\n" << nama << ":" << nik;
            file.close();
        }
        return;
    }
    void cetakKaryawan(){
        system("cls");
        string line, nama, nik;
        cout << "Daftar Karyawan:" << endl;
        fstream file("karyawan.dt");
        while (getline(file, line)){
            stringstream iss(line);
            getline(iss, nama, ':');
            getline(iss, nik, '\n');
            cout << nama << " " << nik << endl;
        }
        file.close();
    }
    void hasilKerja(){
        // Kode Pegawai - Nama - Tugas - Kode Ruang - Deadline
		cout << "1. Urut Berdasarkan Kode Pegawai \n";
		cout << "2. Urut Berdasarkan Nama \n";
		cout << "3. Urut Berdasarkan Tugas \n";
		cout << "4. Urut Berdasarkan Kode Ruang \n";
		cout << "5. Urut Berdasarkan Deadline \n";
		cout << "0. Kembali \n";
    }
    void tambahTugas(){
        cout << "Masukkan Tugas 	: "; cin >> tugas;
		cout << "Masukkan Deadline	: "; cin >> dl;
		cout << "Masukkan Target	: "; cin >> kodeP;
    }
    void kesimpulanKerja(){
    }
};

class Init {
private:
    int i;
    char c;
    string usr, pass;
    bool is_bos;
    Bos bos;
public:
    Init(){
    }
    void awal(){
        system("cls");
        cout << "====== SOFTWARE PERUSAHAAN PT TUNGGAL IKA ======" << endl;
        cout << "1. Login sebagai karyawan" << endl;
        cout << "2. Login sebagai atasan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: "; cin >> i;
        switch(i){
        case 0: return; break;
        case 1: is_bos = false; break;
        case 2: login(); break;
        }
    }
    void login(){
        system("cls");
        cout << "====== LOGIN SESSION ======" << endl;
        cout << "Masukkan username: "; cin >> usr;
        cout << "Masukkan password: "; cin >> pass;
        if (bos.login(usr, pass)){
            is_bos = true;
        }
        else {
            cout << "Username/ password salah" << endl;
            cout << "Coba lagi? "; cin >> c;
            if (c == 'y' || c == 'Y') login();
            else {
                cout << "Kembali ke menu utama? "; cin >> c;
                if (c == 'y' || c == 'Y') awal();
            }
        }
    }
    bool isBos(){
        return is_bos;
    }
};

class Menu {
private:
    Bos atasan;
    int i;
public:
    Menu() {}
    void bos() {
        system("cls");
        cout << "====== MENU ATASAN ======" << endl;
        cout << "1. Tambah Karyawan \n";
        cout << "2. Tampilkan Karyawan \n";
        cout << "3. Hasil Kerja Karyawan \n";
        cout << "4. Tambah Tugas Karyawan \n";
        cout << "5. Laporan Akhir Hasil Kerja \n";
        cout << "0. Keluar \n";
        cout << "Pilih menu: "; cin >> i;
        switch(i){
        case 0: return; break;
        case 1: atasan.inputKaryawan(); bos(); break;
        case 2: atasan.cetakKaryawan(); break;
        case 3: atasan.hasilKerja(); break;
        case 4: atasan.tambahTugas(); break;
        case 5: atasan.kesimpulanKerja(); break;
        }
    }
    void karyawan() {
        system("cls");
        cout << "====== MENU KARYAWAN ======" << endl;
    }
};

#endif
