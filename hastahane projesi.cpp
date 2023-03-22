#include <iostream>
#include <vector>
#include <fstream>
using  namespace std;

class human {

 protected:

    string tc;
    string name;
    string surname;


public:

    human() {}

    human(string tc, string name, string surname) {

        this->tc = tc;
        this->name = name;
        this->surname = surname;

    }

    string gettc() { return tc; }

    string getname() { return name; }

    string getsurname() { return surname; }


    void settc(string tc) {

        this->tc = tc;
    }

    void setname(string name) {

        this->name = name;
    }

    void setsurname(string surname) {

        this->surname = surname;
    }


    void setall(string tc, string name, string surname) {

        this->tc = tc;
        this->name = name;
        this->surname = surname;


    }


    virtual void print() {


        cout << "tc: " << tc << endl;

        cout << "name: " << name << endl;

        cout << "surname: " << surname << endl;


    }


};

class hasta :public human {

protected:
    string hastaID;

public:

    hasta() {}

    hasta(string tc, string name, string surname, string hastaID) :human(tc, name, surname) {

        this->hastaID = hastaID;

    }

    string gettc() { return tc; }

    string getname() { return name; }

    string getsurname() { return surname; }

    string gethastaID() { return hastaID; }

    void settc(string tc) {

        this->tc = tc;
    }

    void setname(string name) {

        this->name = name;
    }

    void setsurname(string surname) {

        this->surname = surname;
    }

    void sethastaID(string hastaID) {

        this->hastaID = hastaID;
    }

    void setall(string tc, string name, string surname, string hastaID) {

        this->tc = tc;
        this->name = name;
        this->surname = surname;
        this->hastaID = hastaID;

    }


    void print() {

        human::print();
        cout << "hastaID : " << hastaID << endl;

    }



};

class doktor :public human {

protected:

    string brans;
    string doktorID;

public:

    doktor() {}

    doktor(string tc, string name, string surname, string brans, string doktorID) :

        human(tc, name, surname) {

        this->doktorID = doktorID;
        this->brans = brans;
    }

    string getbrans() { return brans; }

    string getdoktorID() { return doktorID; }

    void setbrans(string brans) {

        this->brans = brans;
    }

    void setdoktorID(string doktorID) {

        this->doktorID = doktorID;
    }

    void setall(string tc, string name, string surname, string brans, string doktorID) {

        this->tc = tc;
        this->name = name;
        this->surname = surname;
        this->brans = brans;
        this->doktorID = doktorID;

    }

    void print() {

        human::print();

        cout << "brans: " << brans << endl;

        cout << "doktorID : " << doktorID << endl;
    }


};

class poliklinik {

protected:

    string name;
    string ID;

public:

    poliklinik() {}

    poliklinik(string name, string ID) {

        this->name = name;
        this->ID = ID;
    }

    string getname() { return name; }

    string getID() { return ID; }


    void setname(string name) {

        this->name = name;

    }

    void setID(string ID) {

        this->ID = ID;
    }

    void setall(string name, string ID) {

        this->name = name;

        this->ID = ID;

    }

    void print() {

        cout << "name: " << name << endl;

        cout << "ID: " << ID << endl;

    }


};

class randevu {

private:

    string poliklinik;
    string hastaID;
    string doktorID;
    string tarih;
    string saat;

public:

    randevu() {}

    randevu(string poliklinik, string hastaID, string doktorID, string tarih, string saat) {

        this->poliklinik = poliklinik;
        this->hastaID = hastaID;
        this->doktorID = doktorID;
        this->tarih = tarih;
        this->saat = saat;

    }

    string getpoliklinik() { return poliklinik; }

    string gethastaID() { return hastaID; }

    string getdoktorID() { return doktorID; }

    string gettarih() { return tarih; }

    string getsaat() { return saat; }


    void setpoliklinik(string poliklinik) {

        this->poliklinik = poliklinik;
    }

    void sethastaID(string hastaID) {

        this->hastaID = hastaID;

    }

    void setdoktorID(string doktorID) {

        this->doktorID = doktorID;
    }

    void settarih(string tarih) {

        this->tarih = tarih;
    }

    void setsaat(string saat) {

        this->saat = saat;
    }

    void setall(string poliklinik, string hastaID, string doktorID, string tarih, string saat) {

        this->poliklinik = poliklinik;
        this->hastaID = hastaID;
        this->doktorID = doktorID;
        this->tarih = tarih;
        this->saat = saat;

    }


    void print() {

        cout << "poliklinik: " << poliklinik << endl;

        cout << "hastaID: " << hastaID << endl;

        cout << "doktorID: " << doktorID << endl;

        cout << "tarih: " << tarih << endl;

        cout << "saat: " << saat << endl;


    }


};

void doktorDosyayaYazdir(vector <doktor> d) {

    ofstream dosyayaYaz("C:\\Users\\erdem\\Desktop\\doktorlar.txt");

    for (int i = 0;i < d.size();i++) {
        dosyayaYaz << d[i].getname() << ":" << d[i].getsurname() << ":" << d[i].getbrans()  << ":" << d[i].getdoktorID() << endl;
    }

    dosyayaYaz.close();

}

void hastaDosyayaYazdir(vector <hasta> h) {

    ofstream dosyayaYaz("C:\\Users\\erdem\\Desktop\\hastalar.txt");

    for (int i = 0;i < h.size();i++) {
        dosyayaYaz << h[i].gettc() << ":" << h[i].getname() << ":" << h[i].getsurname() << ":" << h[i].gethastaID() << endl;
    }

    dosyayaYaz.close();

}

void doktorArama(vector <doktor> d, string klavyeGirisi) {

    int flag=0;
    
    for (int i = 0;i < d.size();i++){
    
        if (klavyeGirisi == d[i].getname() || klavyeGirisi == d[i].getsurname() || klavyeGirisi == d[i].getbrans()) {
        
            ofstream dosyayaYaz("C:\\Users\\erdem\\Desktop\\doktorlar.txt");

            dosyayaYaz << d[i].getname() << ":" << d[i].getsurname() << ":" << d[i].getbrans() << ":" << d[i].getdoktorID() << endl;
           
            dosyayaYaz.close();

            cout << "doktor basariyla bulunup dosyaya yazdirilmistir" << endl;

            flag = 1;
        }
    

    }

    if (flag == 0) {

        cout << "Aradiginiz doktor bulunamamistir" << endl;
    }
}

void hastaArama(vector <hasta> h, string klavyeGirisi) {

    int flag = 0;

    for (int i = 0;i < h.size();i++) {

        if (h[i].getname() == klavyeGirisi || h[i].getsurname() == klavyeGirisi || h[i].gethastaID() == klavyeGirisi) {

            ofstream dosyayaYaz("C:\\Users\\erdem\\Desktop\\hastalar.txt");

            dosyayaYaz << h[i].gettc() << ":" << h[i].getname() << ":" << h[i].getsurname() << ":" << h[i].gethastaID() << endl;
            
            dosyayaYaz.close();

            cout << "hasta basariyla bulunup dosyaya yazdirilmistir" << endl;
            flag = 1;
        }

    }

    if (flag==0) {

    cout << "Aradiginiz hasta bulunamamistir" << endl;
        }
}

void randevuyuDosyayaYazdir(vector <randevu> r,vector <hasta> h) {

    for (int i = 0;i < r.size();i++) {

        for(int j = 0;j < h.size();j++) {

            if (r[i].gethastaID() == h[j].gethastaID()) {

                ofstream dosyayaYaz("C:\\Users\\erdem\\Desktop\\randevu.txt");

                dosyayaYaz << h[j].gettc() << ":" << h[j].getname() << ":" << h[j].getsurname() << ":" << h[j].gethastaID() << ":" << r[i].getpoliklinik() << ":" << r[i].getdoktorID() << ":" << r[i].gettarih() << ":" << r[i].getsaat() << endl;;

                dosyayaYaz.close();
            }
        }
    }

}



int main()
{

    vector <doktor> d;
    vector <hasta> h;
    vector <randevu> r;

    doktor ben;
    ben.setall("1234567890", "resul", "ozdemir", "urolog", "69");
    d.push_back(ben);

    doktor asistan;
    asistan.setall("1234567890", "baran", "sivrikaya", "urolog", "14");
    d.push_back(asistan);
    
    hasta bir;
    bir.setall("55555555", "ahmet", "yilmaz", "12");
    h.push_back(bir);

    hasta iki;
    iki.setall("4865264", "mehmet", "koparan", "2");
    h.push_back(iki);

    randevu randevu1;
    randevu1.setall("uroloji", "12", "69", "24/06/2022", "16.00");
    r.push_back(randevu1);

    randevu randevu2;
    randevu2.setall("uroloji", "14", "14", "25/06/2022", "12.00");
    r.push_back(randevu2);


    int secim;

    cout << "** hastahane sistemine hosgeldiniz **" << endl;
    cout << endl;
    cout << "1-Doktorlari listele" << endl;
    cout << "2-Hastalari listele" << endl;
    cout << "3-Doktor bul" << endl;
    cout << "4-Hasta bul" << endl;
    cout << "5-Randevulari listele" << endl;
    cout << "6-Randevu ver" << endl;
    cout << endl;
    cout << "Yapmak istediginiz islemi seciniz : " << endl;
    cin >> secim;

    string klavyeGirisi;
    
    switch (secim) {

    case 1: //doktorlarý dosyaya yazdýracak sekilde kodlar yazýlacak

        doktorDosyayaYazdir(d);
        cout << "doktorlar dosyaya yazdirilmistir" << endl;

        break;

    case 2: //hastalarý dosyaya yazdýracak sekilde kodlar yazýlacak

        hastaDosyayaYazdir(h);
        cout << "hastalar dosyaya yazdirilmistir" << endl;

        break;

    case 3: //istenilen doktorlarý dosyaya yazdýracak sekilde kodlar yazýlacak

        cout << "Doktorun adini,soyadini veya bransini giriniz : " << endl;
        cin >> klavyeGirisi;

        doktorArama(d, klavyeGirisi);

        break;

    case 4: //istenilen hastalarý dosyaya yazdýracak sekilde kodlar yazýlacak

        cout << "Hastanin adini,soyadini veya ID sini giriniz : " << endl;
        cin >> klavyeGirisi;

        hastaArama(h, klavyeGirisi);


        break;

    case 5: //randevularý dosyaya yazdýracak sekilde kodlar yazýlacak

        randevuyuDosyayaYazdir(r, h);
        cout << "Randevular dosyaya yazdirilmistir." << endl;

        break;

    case 6: //once randevu verecek sonra randevu listesini guncelleyip dosyaya yazdýracak kolar yazýlacak

        int flagg = 0;
        while (flagg == 0) {

            string adGirisi, randevuSaati, randevuGunu;
            int flag = 0;
            cout << "Randevu almak icin Adinizi giriniz : " << endl;
            cin >> adGirisi;

            for (int i = 0;i < h.size();i++) {

                if (h[i].getname() == adGirisi) {

                    cout << "Doktor listeleniyor" << endl;

                    for (int j = 0;j < d.size();j++) {

                        cout << d[j].getdoktorID() << " " << d[j].getname() << " " << d[j].getsurname() << "-" << d[j].getbrans() << endl;

                    }

                    cout << "Randevu almak istediginiz doktorun adini veya soyadini giriniz : " << endl;
                    cin >> klavyeGirisi;
                    int denemeFlag = 0;

                    for (int k = 0;k < d.size();k++) {

                        
                        if (d[k].getname() == klavyeGirisi || d[k].getsurname() == klavyeGirisi) {

                            cout << "doktorun musait oldugu gunler listeleniyor..." << endl;
                            denemeFlag = 1;
                            cout << "24/06/2022" << endl;
                            cout << "25/06/2022" << endl;
                            cout << "26/06/2022" << endl;

                            cout << "Randevu almak istediginiz gunu yaziniz : " << endl;
                            cin >> randevuGunu;

                            if (randevuGunu == "24/06/2022" || randevuGunu == "25/06/2022" || randevuGunu == "26/06/2022") {


                                cout << "Doktorun musait oldugu saatler listeleniyor..." << endl;

                                for (int i = 9;i < 12;i++) {

                                    for (int j = 0;j < 60; j += 15) {

                                        cout << i << ":" << j << endl;
                                    }

                                }

                                for (int i = 13;i < 17;i++) {

                                    for (int j = 0;j < 60; j += 15) {

                                        cout << i << ":" << j << endl;
                                    }

                                }


                                cout << "randevu almak istediginiz saati yaziniz : " << endl;
                                cin >> randevuSaati;

                                for (int l = 0;l < r.size();l++) {

                                    if (randevuSaati == r[l].getsaat()) {

                                        cout << "maalesef doktorumuzun o saatte randevusu vardýr baska bir randevu saati secin" << endl;

                                    }

                                    else {

                                        randevu temp;
                                        temp.setall(d[l].getbrans(), h[i].gethastaID(), d[l].getdoktorID(), randevuGunu, randevuSaati);
                                        r.push_back(temp);
                                        cout << "randevunuz basariyla olusturulmustur." << endl;
                                        randevuyuDosyayaYazdir(r, h);
                                    }

                                }

                            }

                            else {

                                cout << "Tarihi duzgun girin" << endl;

                            }
                        }

                        

                    }

                    if(denemeFlag==0)
                    {

                        cout << "boyle bir doktor bulunamadi." << endl;
                    }


                }

                int aFlag = 0;

                for (int i = 0;i < h.size();i++) {

                    if (h[i].getname() != adGirisi) {

                        aFlag += 1;


                    }
                }

                if (aFlag == h.size()) {
                    int secim;
                    cout << "Bu isimde bir hasta bulunamadi kayit olmak istermisiniz ?" << endl;
                    cout << "Evet icin 1 ,hayir icin 2 yazin : " << endl;
                    cin >> secim;

                    if (secim == 1) {

                        string yeniHastaAd, yeniHastaSoyad, yeniHastaTC, yeniHastaID;
                        hasta temp;

                        cout << "Adinizi giriniz : ";
                        cin >> yeniHastaAd;
                        temp.setname(yeniHastaAd);

                        cout << "Soyadinizi giriniz : ";
                        cin >> yeniHastaSoyad;
                        temp.setsurname(yeniHastaSoyad);

                        cout << "TC giriniz : ";
                        cin >> yeniHastaTC;
                        temp.settc(yeniHastaTC);

                        cout << "ID giriniz : ";
                        cin >> yeniHastaID;
                        temp.sethastaID(yeniHastaID);

                        h.push_back(temp);
                        hastaDosyayaYazdir(h);

                        cout << "kayit basariyla olusturulmustur" << endl;



                    }

                    else {

                        cout << "kayit olmak istemediginiz icin sisteminden cikis yapildi" << endl;

                    }

                }


                break;
            }

        }

    }

    return 0;
}
