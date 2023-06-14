#include <iostream>
#include <string>
#include <conio.h> //header untuk memanggil fungsi getch 
#include <stdlib.h> //header untuk memanggil fungsi operasi pembanding dan operasi konversi
#include <windows.h>
#define MAX 1000
#define MAX_SIZE 1000
#define max 10


using namespace std;//deklarasi namespace std untuk menggunakan semua fungsi yang ada di dalam class atau file pada namespace std 
string barang[MAX_SIZE];
int nomer[MAX];//deklarasi array nomor dengan tipedata integer dengan panjang elemen bernilai 100
int head=-1, tail=-1;//assign variabel integer head dengan value -1 , tail = -1
int top = -1;
int batas = max;
int savedTop = -1;
int savedData[max];
double totalHarga = 0;


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
void View(){//membuat procedure View()
     if(IsEmpty()){//memanggil fungsi IsEmpty() di dalam kondisi if jika true maka
         cout<<"Antrian kosong ! "; //mencetak di layar output program Antrian sudah kosong !

     }else {//jika false maka
         system("cls");//membersihkan layar output program 
         for(int a=head;a<=tail;a++){//perulangan for dengan kondisi a kurang dari tail
         /*mencetak di layar output program 
		 ===============================
 		  >> No. Antri : value dari array nomor index ke a
		 ===============================
		 endl = newline
		 */
              cout << "===============================" 
                   << "\n >> No. Pengiriman : [" << nomer[a] << "]"
                   << ">> Nama Barang: " << barang[nomer[a]] << endl;
                   cout << "\n==============================="<< endl;
         }
     }
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
    if (isFull())
    {
        cout << "Error: Data sudah penuh!" << endl;
    }
    else
    {
        tumpukan.top++;
        cout << "Input Nama Barang: ";
        cin.ignore();
        getline(cin, tumpukan.data[tumpukan.top].nama);
        cout << "Input Harga Barang: ";
        cin >> tumpukan.data[tumpukan.top].harga;
        cout << "Input Stock Barang: ";
        cin >> tumpukan.data[tumpukan.top].stock;
        cout << "Data berhasil dimasukkan!" << endl;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        cout << "Data " << tumpukan.data[tumpukan.top].nama << " berhasil dihapus!" << endl;
        tumpukan.top--;
    }
}

void view()
{
    if (isEmpty())
    {
        cout << "Data kosong!" << endl;
    }
        cout << "=== Daftar Barang ===" << endl;
        for (int i = tumpukan.top; i >= 0; i--)
        {
            cout << "Kode Barang #" << i + 1 << endl;
            cout << "Nama Barang: " << tumpukan.data[i].nama << endl;
            cout << "Harga Barang: Rp. " << tumpukan.data[i].harga << endl;
            cout << "Stock Barang: " << tumpukan.data[i].stock << endl;
            cout << endl;
        }
    }

void peek()
{
    if (isEmpty())
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        cout << "Data Paling Atas:" << endl;
        cout << "Nama Barang: " << tumpukan.data[tumpukan.top].nama << endl;
        cout << "Harga Barang: " << tumpukan.data[tumpukan.top].harga << endl;
        cout << "Stock Barang: " << tumpukan.data[tumpukan.top].stock << endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "Data kosong!" << endl;
    }
    else
    {
        tumpukan.top = -1;
        cout << "Semua Data berhasil dihapus." << endl;
    }
}
void TambahPengiriman() {
    if (IsFull()) {
        cout << "Pengiriman sudah penuh, mohon tunggu beberapa saat lagi." << endl;
    } else if (isEmpty()) {
        cout << "Stack kosong. Tidak ada barang yang tersedia." << endl;
    } else {
        cout << "Daftar Barang yang Tersedia:" << endl;
        view();
        int index;
        cout << "Masukkan kode barang barang yang ingin dikirim: ";
        cin >> index;
        if (index < 0 || index > tumpukan.top) {
            cout << "Kode barang tidak valid." << endl;
            return;
        }
        totalHarga = 0;
                for (int i = tumpukan.top; i >= 0; i--) {
                    totalHarga += tumpukan.data[i].harga * tumpukan.data[i].stock;
                }
        cout << "Total Harga     : " << totalHarga << endl;
        cout << "Barang berhasil masuk pengiriman." << endl;
        int p=1, urut;
                urut=p; //assign variabel urut = p
                AntrianMasuk(urut);//memanggil procedure AntrianMasuk dengan memberikan nilai parameternya = variabel urut
                /*mencetak di layar output program
                ---------------------------------
				|          NO. ANTRIAN          |
				|       value variabel p        ||
				---------------------------------
				|       Silahkan Mengantri      |
				|  Menunggu value variabel tail  Antrian      ||
				---------------------------------
				endl = newline
				*/
                cout << "---------------------------------" << endl;
                cout << "|          NO. RESI         |" << endl;
                cout << "|               " << p << "              ||" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Barang sedang di packing      |" << endl;
                cout << "|      Menunggu " << tail << " pengiriman     ||" << endl;
                cout << "---------------------------------" << endl;
                p++;//post increment variabel p
    }
}

void PanggilPengiriman() {
    if (isEmpty()) {
        cout << "Tidak ada pengiriman dalam antrian." << endl;
    } else {
        cout << "=================================" << endl;
        cout << "No. Antri : [" << nomer[head] << "]";
        cout << "=================================" << endl;
        totalHarga = 0;
                for (int i = tumpukan.top; i >= 0; i--) {
                    totalHarga += tumpukan.data[i].harga * tumpukan.data[i].stock;
                }
        cout << "Total Harga pengiriman    : " << totalHarga << endl;
        AntrianKeluar();
        cout << "Barang Telah Dikirim !" << endl;
    }
}

void LihatDaftarPengiriman() {
    if (isEmpty()) {
        cout << "Tidak ada pengiriman dalam antrian." << endl;
    } else {
        system("cls");
        for(int a=head;a<=tail;a++){
        cout    << "===============================" 
                << "\n >> No. Antri : [" << nomer[a] << "]"
                << "\n==============================="<< endl;
        totalHarga = 0;
                for (int i = tumpukan.top; i >= 0; i--) {
                    totalHarga += tumpukan.data[i].harga * tumpukan.data[i].stock;
                }
        cout << "Total Harga     : " << totalHarga << endl;
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
    cout << "List User:";
    for (int i = 0; i < numUsers; ++i) {
    cout << "Username: " << users[i].username << " | Role: " << users[i].role << "\n";
    }
    cout << endl;
}

void addUser() {
    if (numUsers >= MAX_USERS) {
        cout << "User limit exceeded!\n";
        return;
    }

    User newUser;
  
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;
    cout << "Enter role: ";
    cin >> newUser.role;
    users[numUsers++] = newUser;
    cout << "User added successfully!\n";
}

void updateUser() {
    string username;
    cout << "Enter username to update: ";
    cin >> username;

    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username) {
            cout << "Enter new username: ";
            cin >> users[i].username;
            cout << "Enter new password: ";
            cin >> users[i].password;
            return;
        }
    }
    cout << "User not found!\n";
}

void deleteUser() {
    string username;
    cout << "Enter username to delete: ";
    cin >> username;

    for (int i = 0; i < numUsers; ++i) {
        if (users[i].username == username) {
            for (int j = i; j < numUsers - 1; ++j) {
                users[j] = users[j + 1];
            }
            --numUsers;
            cout << "User deleted successfully!\n";
            return;
        }
    }
    cout << "User not found!\n";
}

bool login(string& role) {
    
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
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
    system("color 37");
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
        cout << "Menu:\n";
        cout << "1. User Manager\n";
        cout << "2. Pengelola barang\n";
        cout << "3. Pengiriman\n";
        cout << "4. Selesai\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 1) {
            string role;
            
            if (!login(role)) {
                cout << "Gagal Login bro!\n";
                continue;
            }

            if (role != "admin" && role != "superadmin") {
                cout << "Kamu gak bisa akses ke sini!\n";
                continue;
            }

            while (true) {
                displayUsers();
                cout << "User Manager Menu:\n";
                cout << "1. Add User\n";
                cout << "2. Update User\n";
                cout << "3. Delete User\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
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
                        cout << "Invalid choice!\n";
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

            if (role != "admin" && role != "jasa") {
                cout << "Kamu ga bisa akses ke sini!\n";
                continue;
            }
    while (true) {
        cout << "===============\n";
        cout << "Pilih Menu :\n";
        cout << "===============\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. View\n";
        cout << "4. Peek\n";
        cout << "5. Clear\n";
        cout << "6. Exit\n";
        cout << "\n>> Input Menu = ";
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
                        cout << "Invalid choice!\n";
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
                std::cout << "Invalid login credentials!\n";
                continue;
            }

            if (role != "admin" && role != "jasa") {
                cout << "Insufficient privileges!\n";
                continue;
            }
    //fungsi untuk memberikan warna pada text dan background c++
    int choose, p=1, urut;
    double totalHarga = 0;//deklarasi variabel choose,urut ,assign variabel p dengan nilai 1
    do{// membuat perulangan do while sampai choose bernilai 5
        system("cls");//membersihkan layar output program 
        /*mencetak di layar output program
        ===== PROGRAM ANTRIAN C++ =====
		===============================
		|1. Tambah Antrian            |
		|2. Panggil Antrian           |
		|3. Lihat daftar antrian      |
		|4. Kosongkan antrian         |
		|5. Exit                      |
		===============================
		Choose !
		\n = newline
		*/
    cout << "\n\n====== PENGIRIMAN BARANG ======="
            << "\n==============================="
            << "\n|1. Tambah Pengiriman            |"
            << "\n|2. Panggil Pengiriman           |"
            << "\n|3. Lihat daftar Pengiriman      |"
            << "\n|4. Kosongkan Pengiriman         |"
            << "\n|5. Kembali                      |"
            << "\n===============================";
        cout << "\nChoose ! "; cin >> choose; //keyword cin untuk membaca inputan pada keyboard
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
                cout << "Antrian dikosongkan !" << endl;
                break;
            case 5:
            cout << "Enter ngab untuk masuk menu utama !" << endl;
                break;
            default:
                cout << "Masukan anda salah ! \n" << endl;
                break;
        }

        getch();
    } while (choose != 5);
}
}
}