#include <bits/stdc++.h>
#include <string>
using namespace std;

class contact{
public:
    string nama;
    string tempat_tinggal;
    string alamat;
    string kekuatan;
    int umur;
        
    void namakontak(string p, string q, string r, string s, int t){
        nama = p;
        tempat_tinggal = q;
        alamat = r;
        kekuatan = s; 
        umur = t;
    }
    void displaycontact(){
        cout<<"Nama: "<< nama <<endl;
        cout<<"tempat_tinggal: "<< tempat_tinggal <<endl;
        cout<<"alamat: "<<endl;
        cout<<"kekuatan: "<< kekuatan <<endl;
        cout<<"umur: "<< umur <<endl;
    }
    
};

class PhoneBook{
    private:
        contact orang[8];
        int count = 0;
    public:
        void addkontak(string nama, string tempat_tinggal, string alamat,string kekuatan, int umur){
            if (count<8){
                orang[count].namakontak(nama,tempat_tinggal,alamat,kekuatan,umur);
                count++;
            }
            else{
                for(int i = 1; i<8; i++){
                    orang[i-1] = orang[i];
                }
                orang[7].namakontak(nama,tempat_tinggal,alamat,kekuatan,umur);
            }
            cout<<"Kontak telah ditambahkan"<<endl;
        }
        
        void displayallcontact(){
            if (count == 0){
                cout<<"Kontak tidak ditemukan"<<endl;
            }
            else{
                cout<<"Kontak yang anda miliki: "<<endl;
                for (int i = 0; i<count; i++){
              cout<< i+1 <<". "<<orang[i].nama<<endl;
              }  
            }
        }
        
        void carikontak(string nama){
            for (int i = 0; i<count; i++){
                if (orang[i].nama == nama){
                    cout<<"Kontak ditemukan"<<endl;
                    orang[i].displaycontact();
                }
                else{
                    cout<<"Kontak tidak ditemukan"<<endl;
                }
            }
        }
        void hapuskontak() {
        count = 0;
        cout << "Kontak telah dihapus\n";
    }
};

int main(){
    int choice;
    PhoneBook kontak;
    string nama, tempat_tinggal ,alamat, kekuatan;
    int umur;
    
    do {
        cout << "Menu:"<<endl;
        cout << "1. ADD"<<endl;
        cout << "2. SEARCH"<<endl;
        cout << "3. EXIT"<<endl;
        cout << "Masukkan pilihanmu: "<<endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukkan tempat_tinggal: ";
            cin>>tempat_tinggal;
            cout << "Masukan Alamat: ";
            cin >> alamat;
            cout << "Masukkan Kekuatan: ";
            cin >> kekuatan;
            cout<< "Masukkan umur: ";
            cin>>umur;
            kontak.addkontak(nama, tempat_tinggal, alamat, kekuatan, umur);
        } else if (choice == 2) {
            kontak.displayallcontact();
            cout << "Masukkan Nama yang ingin dicari: ";
            cin >> nama;
            kontak.carikontak(nama);
        } else if (choice == 3) {
            kontak.hapuskontak();
            cout << "Terima kasih\n";
        } else {
            cout << "Silahkan coba lagi\n";
        }
    } while (choice != 3);
    
    return 0;
}