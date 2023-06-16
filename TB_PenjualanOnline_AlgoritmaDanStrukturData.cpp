#include <iostream>
#include <string>
#include <conio.h> //header untuk memanggil fungsi getch 
#include <stdlib.h> //header untuk memanggil fungsi operasi pembanding dan operasi konversi
#include <windows.h>
#define MAX 100
#define MAX_SIZE 100
#define max 100

using namespace std;//deklarasi namespace std untuk menggunakan semua fungsi yang ada di dalam class atau file pada namespace std 
string barang[MAX_SIZE];
int nomer[MAX];//deklarasi array nomor dengan tipedata integer dengan panjang elemen bernilai 100
int head=-1, tail=-1;//assign variabel integer head dengan value -1 , tail = -1
int top = -1;
int batas = max;

void tampilan(){
    cout << "  ______   __    __   ______    ______   _______   ________        __    __  ________  __    __  __    __ " << endl;
    cout << " /      \\ |  \\  |  \\ /      \\  /      \\ |       \\ |        \\      |  \\  /  \\|        \\|  \\  |  \\|  \\  |  \\" << endl;
    cout << "|  $$$$$$\\| $$  | $$|  $$$$$$\\|  $$$$$$\\| $$$$$$$\\| $$$$$$$$      | $$ /  $$| $$$$$$$$| $$  | $$| $$\\ | $$" << endl;
    cout << "| $$___\\$$| $$__| $$| $$  | $$| $$  | $$| $$__/ $$| $$__          | $$/  $$ | $$__    | $$  | $$| $$$\\| $$" << endl;
    cout << " \\$$    \\ | $$    $$| $$  | $$| $$  | $$| $$    $$| $$  \\         | $$  $$  | $$  \\   | $$  | $$| $$$\\$ $$" << endl;
    cout << " _\\$$$$$$\\| $$$$$$$$| $$  | $$| $$  | $$| $$$$$$$ | $$$$$         | $$$$$\\  | $$$$$   | $$  | $$| $$\\$$\\$$\\" << endl;
    cout << "|  \\__| $$| $$  | $$| $$__/ $$| $$__/ $$| $$      | $$_____       | $$ \\$$\\ | $$_____ | $$__/ $$| $$ \\$$$$" << endl;
    cout << " \\$$    $$| $$  | $$ \\$$    $$ \\$$    $$| $$      | $$     \\      | $$  \\$$\\| $$     \\ \\$$    $$| $$  \\$$$" << endl;
    cout << "  \\$$$$$$  \\$$   \\$$  \\$$$$$$   \\$$$$$$  \\$$       \\$$$$$$$$       \\$$   \\$$ \\$$$$$$$$  \\$$$$$$  \\$$   \\$$" << endl;
    cout << "                                                                                                          " << endl;
    cout << "                                                                                                          " << endl;
}

bool IsEmpty(){ // membuat fungsi IsEmpty() dengan return type boolean 
   if(tail == -1){// klausa if dengan kondisi tail = -1
       return true;// jika benar maka mengembalikan boolean true
   }else{ 
       return false;//jika tail tidak sama dengan -1 maka mengembalikan boolean false
   }
}
bool IsFull(){  // membuat fungsi IsFull() dengan return type boolean 
   if(tail == MAX-1){// klausa if dengan kondisi tail = MAX-1
       return true;//jika benar maka mengembalikan boolean true
   }else{
       return false;//jika benar maka mengembalikan boolean false
   }
}
void AntrianMasuk(int no){// membuat procedure AntrianMasuk() dengan parameeter no type integer
    if (IsEmpty()){//memanggil fungsi IsEmpty() di dalam kondisi if jika true maka
        head=tail=0;//assign variabel head = 0 ,tail = 0
    }else {//jika false maka
        tail++;//post-increment variabel tail
        nomer[tail] = no;
    }
    nomer[tail]=no;//assign array nomor dengan index value dari variabel tail dengan nilai dari parameter (variabel no)
}
void AntrianKeluar(){//membuat procedure AntrianKeluar()
    if(IsEmpty()){ //memanggil fungsi IsEmpty() di dalam kondisi if jika true maka
        cout<<"Antrian sudah kosong ! "; //mencetak di layar output program Antrian sudah kosong !
        getch();//memanggil fungsi get character yang digunakan untuk membaca input dari keyboard (menjeda proses yg berlangsung /press any key)
    } else {//jika false maka
        for(int a=head;a<tail;a++){//perulangan for dengan kondisi a kurang dari tail
            nomer[a]=nomer[a+1];//assign array nomor dengan index value dari variabel a dengan nilai darirray nomor dengan index = (a+1)
        }
        tail--;//post-decrement variabel tail
        if(tail == -1){//if dengan kondisi tail = -1 maka
            head = -1; //assign variabel head dengan nilai -1
        }
    }
}
void Clear(){//membuat procedure Clear()
    head=tail=-1;//assign variabel head dan tail dengan nilai -1
}

///
struct Barang
{
    string nama;
    double harga;
    int stock;
};

struct Stack
{
    Barang data[max];
    int top;
    int batas;
    
} tumpukan;

void initialize() {
    tumpukan.top = -1;
}

bool isFull()
{
    return tumpukan.top == tumpukan.batas - 1;
}

bool isEmpty()
{
    return tumpukan.top == -1;
}

void push()
{
    cout << "==================================================" << endl;
    cout << "               Masukkan Data Barang               " << endl;
    cout << "==================================================" << endl;
    if (isFull())
    {
        cout << "Error: Data Barang sudah penuh!" << endl;
    }
    else
    {
        tumpukan.top++;
        int itemIndex = tumpukan.top + 1;
        cout << "Input Nama Barang: ";
        cin.ignore();
        getline(cin, tumpukan.data[tumpukan.top].nama);
        cout << "Input Harga Barang: ";
        cin >> tumpukan.data[tumpukan.top].harga;
        cout << "Input Stock Barang: ";
        cin >> tumpukan.data[tumpukan.top].stock;
        cout << "Data Barang berhasil dimasukkan!" << endl;
    }
}

void pop()
{
    cout << "==================================================" << endl;
    cout << "               Menghapus Data Barang              " << endl;
    cout << "==================================================" << endl;
    if (isEmpty())
    {
        cout << "==================================================" << endl;
        cout << "NOTIF ! >> Data Barang kosong!" << endl;
        cout << "==================================================" << endl;
    }
    else
    {
        cout << "Data Barang " << tumpukan.data[tumpukan.top].nama << " berhasil dihapus!" << endl;
        tumpukan.top--;
    }
}

void view()
{
    cout << "==================================================" << endl;
    cout << "                  List Data Barang                " << endl;
    cout << "==================================================" << endl;
    if (isEmpty())
    {
        cout << "==================================================" << endl;
        cout << "NOTIF ! >> Data Barang kosong!" << endl;
        cout << "==================================================" << endl;
    }
        cout << "=== Daftar Barang ===" << endl;
        for (int i = tumpukan.top; i >= 0; i--)
        {
            int itemIndex = i + 1;
            cout << "Kode Barang #" << itemIndex << endl;
            cout << "Nama Barang: " << tumpukan.data[i].nama << endl;
            cout << "Harga Barang: Rp. " << tumpukan.data[i].harga << endl;
            cout << "Stock Barang: " << tumpukan.data[i].stock << endl;
            cout << endl;
        }
    }

void peek()
{
    cout << "==================================================" << endl;
    cout << "                Data Barang Teratas               " << endl;
    cout << "==================================================" << endl;
    if (isEmpty())
    {
        cout << "==================================================" << endl;
        cout << "NOTIF ! >> Data Barang kosong!" << endl;
        cout << "==================================================" << endl;
    }
    else
    {
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "Nama Barang: " << tumpukan.data[tumpukan.top].nama << endl;
        cout << "Harga Barang: " << tumpukan.data[tumpukan.top].harga << endl;
        cout << "Stock Barang: " << tumpukan.data[tumpukan.top].stock << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    }
}

void clear()
{
    cout << "==================================================" << endl;
    cout << "                 Clear Data Barang                " << endl;
    cout << "==================================================" << endl;
    if (isEmpty())
    {
        cout << "==================================================" << endl;
        cout << "NOTIF ! >> Data Barang kosong!" << endl;
        cout << "==================================================" << endl;
    }
    else
    {
        tumpukan.top = -1;
        cout << "Semua Data Barang berhasil dihapus." << endl;
    }
}

int quantity;
int index;
void TambahPengiriman() {
    cout << "==================================================" << endl;
    cout << "             Masukkan Data Pengiriman             " << endl;
    cout << "==================================================" << endl;
    if (IsFull()) {
        cout << "Antrian pengiriman sudah penuh, mohon tunggu beberapa saat lagi." << endl;
    } else if (isEmpty()) {
        cout << "Barang lagi kosong :(. \nTidak ada barang yang tersedia di gudang." << endl;
    } else {
        cout << "Daftar Barang yang Tersedia:" << endl;
        view(); // Display the items in the stack

        cout << "Masukkan kode barang yang ingin dikirim: ";
        cin >> index;
        index--;

        if (index < 0 || index > tumpukan.top) {
            cout << "Kode barang tidak valid." << endl;
            return;
        }

        cout << "\nMasukkan jumlah barang yang ingin dikirim:";
        cin >> quantity;

        if (quantity > tumpukan.data[index].stock) {
            cout << "Jumlah barang yang diminta melebihi stok yang tersedia." << endl;
            return;
        }

        double totalHarga = tumpukan.data[index].harga * quantity;
        double ppn = totalHarga * 0.1;
        double jasakirim = 20000;
        double totalHargakirim = totalHarga + ppn + jasakirim;

        cout << "\nJumlah Barang: " << quantity << endl;
        cout << "Total Harga (sebelum PPN): " << totalHarga << endl;
        cout << "PPN (10%): " << ppn << endl;
        cout << "Biaya Kirim: " << jasakirim << endl;
        cout << "\nTotal Harga : " << totalHargakirim << endl;

        // Create a new delivery in the queue
        int deliveryNumber = tail + 1;
        AntrianMasuk(deliveryNumber);
        barang[deliveryNumber] = tumpukan.data[index].nama; // Store the selected item in the barang array

        // Update the stock of the selected item in the stack
        tumpukan.data[index].stock -= quantity;

        cout << "Barang berhasil dimasukkan ke dalam antrian pengiriman.(Enter untuk melanjutkan)" << endl;
    }
}


void PanggilPengiriman() {
    if (IsEmpty()) {
        cout << "Tidak ada pengiriman dalam antrian." << endl;
    } else {
        int queueNumber = nomer[head];
        string itemName = barang[queueNumber];
        double totalHarga = tumpukan.data[index].harga * quantity;
        double ppn = totalHarga * 0.1;
        double jasakirim = 20000;
        double totalHargakirim = totalHarga + ppn + jasakirim;

        cout << "\nNo. Pengiriman : [" << queueNumber << "]" << endl;
        cout << "\nNama Barang: " << itemName << endl;
        cout << "Jumlah Barang: " << quantity << endl;
        cout << "Total Harga (sebelum PPN): " << totalHarga << endl;
        cout << "PPN (10%): " << ppn << endl;
        cout << "Biaya Kirim: " << jasakirim << endl;
        cout << "\nTotal Harga : " << totalHargakirim << endl;

        AntrianKeluar();
        cout << "\nBarang Berhasil Dikirim !!" << endl;
    }
}


void LihatDaftarPengiriman() {
    if (IsEmpty()) {
        cout << "Tidak ada pengiriman saat ini ." << endl;
    } else {
        system("cls");
        cout << "=== Daftar Pengiriman ===" << endl;
        for (int i = head; i <= tail; i++) {
            int queueNumber = nomer[i];
            string itemName = barang[queueNumber];
            double totalHarga = tumpukan.data[index].harga * quantity;
            double ppn = totalHarga * 0.1;
            double jasakirim = 20000;
            double totalHargakirim = totalHarga + ppn + jasakirim;

            cout << "\nNo. Pengiriman : [" << queueNumber << "]" << endl;
            cout << "Nama Barang: " << itemName << endl;
            cout << "Jumlah Barang: " << quantity << endl;
            cout << "Total Harga (sebelum PPN): " << totalHarga << endl;
            cout << "PPN (10%): " << ppn << endl;
            cout << "Biaya Kirim: " << jasakirim << endl;
            cout << "\nTotal Harga : " << totalHargakirim << endl;
            cout << "===================================" << endl;
        }
    }
}




///

struct User {
    string username;
    string password;
    string role;
};

const int MAX_USERS = 100;
User users[MAX_USERS];
int numUsers = 0;


void displayUsers() {
    cout << "\nList User:\n";
    for (int i = 0; i < numUsers; ++i) {
    cout << "Username > " << users[i].username << " ==|== Role > " << users[i].role << "\n";
    }
    cout << endl;
}

void addUser() {
    if (numUsers >= MAX_USERS) {
        cout << "User Penuh Brayyyy!\n";
        return;
    }

    User newUser;
    cout << "==================================================" << endl;
    cout << "==================================================" << endl;
    cout << "~List Role~ \n";
    cout << "|>-- admin/superadmin \n";
    cout << "|>-- toko (stack): \n";
    cout << "|>-- jnt (queue): \n";
    cout << "==================================================" << endl;
    cout << "                Masukkan Data Akun                " << endl;
    cout << "==================================================" << endl;
    cout << "\nMasukin username: ";
    cin >> newUser.username;
    cout << "Masukin password: ";
    cin >> newUser.password;
    cout << "Masukin nama role: ";
    cin >> newUser.role;
    users[numUsers++] = newUser;
    system("cls");
    cout << "User udah dibuat braayyy!\n";
}

void updateUser() {
    displayUsers();
    string username;
    cout << "==================================================" << endl;
    cout << "                 Update Data Akun                 " << endl;
    cout << "==================================================" << endl;
    cout << "Masukin username yang mau di ubah: ";
    cin >> username;

    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username) {
            cout << "Masukin username baru: ";
            cin >> users[i].username;
            cout << "Masukin password baru: ";
            cin >> users[i].password;
            cout << "Masukin Role baru: ";
            cin >> users[i].role;
            return;
        }
    }
    system("cls");
    cout << "User yang kamu cari gak ada :( !!!\n";
}

void deleteUser() {
    displayUsers();
    string username;
    cout << "==================================================" << endl;
    cout << "                  Hapus Data Akun                 " << endl;
    cout << "==================================================" << endl;
    cout << "Masukin username yang mau dihapus: ";
    cin >> username;

    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username) {
            for (int j = i; j < numUsers - 1; ++j) {
                users[j] = users[j + 1];
            }
            --numUsers;
            system("cls");
            cout << "User udah di hapus!\n";
            return;
        }
    }
    cout << "User yang kamu cari gak ada :( !!!\n";
}

bool login(string& role) {
    tampilan();
    string username, password;
    cout << "==================================================" << endl;
    cout << "               Login Dulu Brayy                   " << endl;
    cout << "==================================================" << endl;
    cout << "\nMasukin username: ";
    cin >> username;
    cout << "\nMasukin password: ";
    cin >> password;
    system("cls");
    
    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username && users[i].password == password) {
            role = users[i].role;
            return true;
        }
    }
    return false;
}
//========================================================
int main() {
    system("color 38");
    // Menambahkan user default
    User defaultUser;
    defaultUser.username = "egha";
    defaultUser.password = "123";
    defaultUser.role = "admin";
    users[numUsers++] = defaultUser;
    tumpukan.top = top;
    tumpukan.batas = batas;
    initialize();

    int choice;
    system("cls");


    while (true) {
    tampilan();
    cout << "==================================================" << endl;
    cout << "                  ____________                    " << endl;
    cout << "                 | Kelompok 6 |                   " << endl;
    cout << "                 |____________|                   " << endl;
    cout << ">> Egha Satria Bagaskara {2106058}                " << endl;
    cout << ">> Arvin Muhamad Ajif {2106100}                   " << endl;
    cout << "==================================================" << endl;
    cout << "            Toko Online Shoope Keun               " << endl;
    cout << "==================================================" << endl;
    cout << "==================================================\n";
    cout << "----------------->PILIH MENU<---------------------" << endl;
    cout << "|>>- 1. User Manager                 " << endl;
    cout << "|>>- 2. Pengelola Toko Barang (stack)" << endl;
    cout << "|>>- 3. Pengiriman Barang (queue)    " << endl;
    cout << "|>>- 4. Selesai                      " << endl;
    cout << "\n==================================================\n";
    cout << endl;
    cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        system("cls");

        if (choice == 1) {
            string role;
            
            if (!login(role)) {
                cout << "Gagal Login bro!\n";
                continue;
            }

            if (role != "admin" && role != "superadmin") {
                cout << "Kamu gak bisa akses ke User Manager :( \n";
                continue;
            }

            while (true) {
                tampilan();
                cout << "==================================================" << endl;
                cout << "                 Menu User Manager                " << endl;
                cout << "==================================================" << endl;
                displayUsers();
                cout << "==================================================" << endl;
                cout << "==================================================" << endl;
                cout << "|>-- 1. Tambah User\n";
                cout << "|>-- 2. Update User\n";
                cout << "|>-- 3. Hapus User\n";
                cout << "|>-- 4. Kembali\n";
                cout << "==================================================" << endl;
                cout << "Pilih menu: ";
                cin >> choice;
                system("cls");

                switch (choice) {
                    case 1:
                        addUser();
                        break;
                    case 2:
                        updateUser();
                        break;
                    case 3:
                        deleteUser();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Menu gak ada braayyy!\n";
                }

                if (choice == 4) {
                    break;
                }
            }
        } else if (choice == 2) {
            //code
            string role;
            if (!login(role)) {
                cout << "Login Gagal bro!\n";
                continue;
            }

            if (role != "admin" && role != "toko") {
                cout << "Kamu ga bisa akses ke menu Toko :(\n";
                continue;
            }
    while (true) {
        tampilan();
        cout << "==================================================" << endl;
        cout << "                 Menu Pengelola Toko              " << endl;
        cout << "==================================================" << endl;
        cout << "|>-- 1. Masukkan data barang ke gudang (Push)\n";
        cout << "|>-- 2. Keluarkan data barang ke gudang (Pop)\n";
        cout << "|>-- 3. Lihat Data Barang di gudang\n";
        cout << "|>-- 4. Lihat barang teratas di gudang\n";
        cout << "|>-- 5. Hilangkan semua barang di gudang\n";
        cout << "|>-- 6. Kembali\n";
        cout << "==================================================" << endl;
        cout << "\nPilih Menu : ";
        cin >> choice;
                system("cls");

                switch (choice) {
                    case 1:
                        push();
                        break;
                    case 2:
                        pop();
                        break;
                    case 3:
                        view();
                        break;
                    case 4:
                        peek();
                        break;
                    case 5:
                        clear();
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Menu gak ada braayyy!\n";
                }
                if (choice == 6) {
                    break;
                    system("pause");
                    system("cls");
                }
            }

        } else if (choice == 3) {
            string role;
            if (!login(role)) {
                std::cout << "Login Gagagl baryy!\n";
                continue;
            }

            if (role != "admin" && role != "jnt") {
                cout << "Kamu gak bisa akses ke menu pengiriman :(\n";
                continue;
            }
    int choose, p=1, urut;
    double totalHarga = 0;//deklarasi variabel choose,urut ,assign variabel p dengan nilai 1
    do{// membuat perulangan do while sampai choose bernilai 5
    system("cls");//membersihkan layar output program
    tampilan();
        cout << "==================================================" << endl;
        cout << "                  Menu Jasa Kirim                 " << endl;
        cout << "==================================================" << endl;
        cout << "==================================================" << endl;
        cout<< "|>-- 1. Tambah Pengiriman (enqueue)\n" 
            << "|>-- 2. Panggil Pengiriman (dequeue)\n"
            << "|>-- 3. Lihat daftar Pengiriman\n"
            << "|>-- 4. Kosongkan Pengiriman\n"
            << "|>-- 5. Kembali\n";
        cout << "==================================================" << endl;
        cout << "\nPilih menu : "; cin >> choose; //keyword cin untuk membaca inputan pada keyboard
        cout << "\n\n";
        switch (choose) {
            case 1:
                TambahPengiriman();
                break;
            case 2:
                PanggilPengiriman();
                break;
            case 3:
                LihatDaftarPengiriman();
                break;
            case 4:
                Clear();
                cout << "Pengiriman sudah dikosongkan untuk saat ini!" << endl;
                break;
            case 5:
            cout << "Enter ngab untuk masuk menu utama !" << endl;
                break;
            default:
                cout << "Manu yang kamu pilih gak adaaaa ! \n" << endl;
                break;
        }

        getch();
    } while (choose != 5);
}else if (choice == 4) {
            cout << "  ________  _______  __   ___   __          __      _____  ___   " << endl;
            cout << " /\"       )/\"     \"||/\"| /  \") |\" \\        /\"\"\\    (\\\"   \\|\"  \\  " << endl;
            cout << "(:   \\___/(: ______)(: |/   /  ||  |      /    \\   |.\\\\   \\    | " << endl;
            cout << " \\___  \\   \\/    |  |    __/   |:  |     /' /\\  \\  |: \\.   \\\\  | " << endl;
            cout << "  __/  \\\\  // ___)_ (// _  \\   |.  |    //  __'  \\ |.  \\    \\. | " << endl;
            cout << " /\" \\   :)(:      \"||: | \\  \\  /\\  |\\  /   /  \\\\  \\|    \\    \\ | " << endl;
            cout << "(_______/  \\_______)(__|  \\__)(__\\_|_)(___/    \\___)\\___|\\____\\)" << endl;
            cout << "================================================================" << endl;
            cout << "-------------------------Terima kasih!--------------------------" << endl;
            cout << "================================================================" << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            break;
        } else {
            cout << "Menu gak ada braayyy!\n";
        }
    }
}