/*
            SAKARYA ÜNİVERSİTESİ
     BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ 
     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
     PROGRAMLAMAYA GİRİŞ DERSİ

     ÖDEV NUMARASI      : 1
     ÖĞRENCİ ADI        : SENA KUZĞU
     ÖĞRENCİ NUMARASI   : G235210385
     DERS GRUBU         : A

*/ 






#include <iostream>
#include <locale.h>   
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

struct ogrenciBilgileri
{
    string isim;
    string soyisim;
    float vizeNotu;
    float odev1;
    float odev2;
    float kisaSinav1;
    float kisaSinav2;
    float yilSonuNotu;
    string harfNotu;
};

int main()
{
    std::vector<ogrenciBilgileri> ogrencitablosu;
    setlocale(LC_ALL, "Turkish");

    unsigned seed = time(0);
    srand(seed);

    string isimler[50] = { "Sena", "Sıla", "Ebrar", "Tahsin", "Bertan", "Hüseyin", "Merve", "Betül", "Eren", "Batu", "Elif", "Salih", "Akgün", "Yağmur","Canan",
        "Ali", "Soner", "Naz", "Cemre", "Gökçe", "Kemal", "Hande", "Aleyna", "Oğuz", "Hilal", "Yıldız", "Zeynep", "Erdem", "Melih", "Şevval","Deniz", "Hazal",
        "Baran", "Ozan", "Enes", "Eda", "Tuğba", "Buğra", "Can", "Cevdet", "Emir", "Esma", "Öykü", "Murat", "Azra", "Fatih", "Sude", "Görkem", "İrem", "Serkan" };
    
    string soyisimler[50] = { "Kandemir", "Çevik", "Öztürk", "Vural", "Sönmez", "Ertekin", "Dede", "Uyanık", "Aslan", "Kaya", "Selvi", "Akpınar", "Çay", "Işık", "Özer",
        "Özdemir", "Tahtacı", "Kulaksız", "Aksel", "Eroğlu", "Dal", "Öcal", "Ayhan", "Yılmaz", "Sezer", "Doğan", "Demir", "Kayayurt", "Sürüm", "Turgut", "Tekin", "Yaman", 
        "Giray", "Şentürk", "Bakar", "Tokatlı", "Özcan", "Ay", "Kara", "Akyüz", "Şener", "Dinçer", "Kılıçsoy", "Özer", "Bora", "Arat", "Üstün", "Aydın", "Güneş", "Ünlü" };
    
    int notlar;

    int kisisayi;
    cout << "Kişi sayısını giriniz: ";
    cin >> kisisayi;
    cout << endl;

    int odev1Etkisi;
    int odev2Etkisi;
    int kisaSinav1Etkisi;
    int kisaSinav2Etkisi;
    int vizeNotuEtkisi;

    cout << "1. Ödevin yıl sonu puanına yüzde etkisini giriniz:  ";
    cin >> odev1Etkisi;
    cout << endl;
    cout << "2. Ödevin yıl sonu puanına yüzde etkisini giriniz:  ";
    cin >> odev2Etkisi;
    cout << endl;
    cout << "1. kısa sınavın yıl sonu puanına yüzde etkisini giriniz:  ";
    cin >> kisaSinav1Etkisi;
    cout << endl;
    cout << "2. kısa sınavın yıl sonu puanına yüzde etkisini giriniz:  ";
    cin >> kisaSinav2Etkisi;
    cout << endl;
    cout << "Vizenin yıl sonu puanına yüzde etkisini giriniz:  ";
    cin >> vizeNotuEtkisi;
    cout << endl;

    for (int i = 0; i < kisisayi; i++) // Rastgele Öğrenci isim ve soyisimleri belirleme
    {
        ogrenciBilgileri ogrenci;
        int isimIndex = rand() % 50;
        int soyisimIndex = rand() % 50;
        ogrenci.isim = isimler[isimIndex];
        ogrenci.soyisim = soyisimler[soyisimIndex];

        if (kisisayi * 0.8 < i)
        {
            // 80-100 arası rastgele not belirleme
            ogrenci.vizeNotu = (rand() % 21 + 80);
            ogrenci.odev1 = (rand() % 21 + 80);
            ogrenci.odev2 = (rand() % 21 + 80);
            ogrenci.kisaSinav1 = (rand() % 21 + 80);
            ogrenci.kisaSinav2 = (rand() % 21 + 80);
        }
        else if (kisisayi * 0.3 < i)
        {
            // 50-80 arası rastgele not belirleme
            ogrenci.vizeNotu = (rand() % 31 + 50);
            ogrenci.odev1 = (rand() % 31 + 50);
            ogrenci.odev2 = (rand() % 31 + 50);
            ogrenci.kisaSinav1 = (rand() % 31 + 50);
            ogrenci.kisaSinav2 = (rand() % 31 + 50);
        }
        else
        {
            // 0-50 arası rastgele not belirleme 
            ogrenci.vizeNotu = (rand() % 51);
            ogrenci.odev1 = (rand() % 51);
            ogrenci.odev2 = (rand() % 51);
            ogrenci.kisaSinav1 = (rand() % 51);
            ogrenci.kisaSinav2 = (rand() % 51);
        }

        ogrenci.yilSonuNotu = (ogrenci.vizeNotu * vizeNotuEtkisi / 100) + (ogrenci.odev1 * odev1Etkisi / 100) + (ogrenci.odev2 * odev2Etkisi / 100) + 
            (ogrenci.kisaSinav1 * kisaSinav1Etkisi / 100) + (ogrenci.kisaSinav2 * kisaSinav2Etkisi / 100);

        // Öğrencilerin notlarına göre harflendirme
        if (ogrenci.yilSonuNotu >= 90) {
            ogrenci.harfNotu = "AA";
        }
        else if (ogrenci.yilSonuNotu >= 85) {
            ogrenci.harfNotu = "BA";
        }
        else if (ogrenci.yilSonuNotu >= 80) {
            ogrenci.harfNotu = "BB";
        }
        else if (ogrenci.yilSonuNotu >= 75) {
            ogrenci.harfNotu = "CB";
        }
        else if (ogrenci.yilSonuNotu >= 65) {
            ogrenci.harfNotu = "CC";
        }
        else if (ogrenci.yilSonuNotu >= 58) {
            ogrenci.harfNotu = "DC";
        }
        else if (ogrenci.yilSonuNotu >= 50) {
            ogrenci.harfNotu = "DD";
        }
        else if (ogrenci.yilSonuNotu >= 40) {
            ogrenci.harfNotu = "FD";
        }

        else {
            ogrenci.harfNotu = "FF";
        }

        ogrencitablosu.push_back(ogrenci);
    }

    // Tablo başlıklarını yazdırma
    cout << setw(15) << "İsim" << setw(15) << "Soyisim" << setw(10) << "Vize Notu" << setw(10) << "Ödev 1" << setw(10) << "Ödev 2" << setw(15) << "Kısa Sınav 1"
        << setw(15) << "Kısa Sınav 2" <<
        setw(15) << "Yıl Sonu Notu" << setw(15) << "Harf Notu" << endl << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
       

    //Öğrenci bilgilerini tabloya yazdırma
    for (const ogrenciBilgileri& ogrenci : ogrencitablosu) {
        cout << setw(15) << ogrenci.isim << setw(15) << ogrenci.soyisim << setw(10) << ogrenci.vizeNotu << setw(10) << ogrenci.odev1 << setw(10) << ogrenci.odev2 <<setw(15)
            << ogrenci.kisaSinav1 << setw(15) << ogrenci.kisaSinav2 << setw(15) << ogrenci.yilSonuNotu << setw(15) << ogrenci.harfNotu << endl << endl << endl;
    }

    

    // En yüksek yıl sonu notunu ve bu Öğrencinin indeksini tutacak değişkenleri tanımlama
    float enYuksekNot = 0;
    int enYuksekNotIndeks = -1;


    // Vektörü dolaşarak en yüksek notu ve indeksi bulma
    for (int i = 0; i < ogrencitablosu.size(); i++) 
    {
        if (ogrencitablosu[i].yilSonuNotu > enYuksekNot)
        {
            enYuksekNot = ogrencitablosu[i].yilSonuNotu;
            enYuksekNotIndeks = i;
        }
    }

    // En yüksek notu ve bu Öğrencinin bilgilerini yazdırma
    if (enYuksekNotIndeks != -1)
    {
        ogrenciBilgileri enYuksekNotAlanOgrenci = ogrencitablosu[enYuksekNotIndeks];
        cout << "En yüksek yıl sonu notunu alan Öğrenci: " << enYuksekNotAlanOgrenci.isim << " " << enYuksekNotAlanOgrenci.soyisim << endl << endl;
        cout << "Yıl Sonu Notu: " << enYuksekNot << endl << endl;
    }

    else
    {
        cout << "Hiç öğrenci yok veya yıl sonu notu pozitif bir değer içermiyor." << endl;
    }

    // En düşük yıl sonu notunu ve bu Öğrencinin indeksini tutacak değişkenleri tanımlama
    float enDusukNot = 100; // Y�ksek bir başlangıç değeri kullanma 
    int enDusukNotIndeks = -1;


    // Vektörü dolaşarak en düşük notu ve indeksi bulma
    for (int i = 0; i < ogrencitablosu.size(); i++)
    {
        if (ogrencitablosu[i].yilSonuNotu < enDusukNot)
        {
            enDusukNot = ogrencitablosu[i].yilSonuNotu;
            enDusukNotIndeks = i;
        }
    }

    // En düşük notu ve bu Öğrencinin bilgilerini yazdırma
    if (enDusukNotIndeks != -1)
    {
        ogrenciBilgileri enDusukNotAlanOgrenci = ogrencitablosu[enDusukNotIndeks];
        cout << "En düşük yıl sonu notunu alan öğrenci: " << enDusukNotAlanOgrenci.isim << " " << enDusukNotAlanOgrenci.soyisim << endl << endl;
        cout << "Yıl Sonu Notu: " << enDusukNot << endl << endl;
    }

    else
    {
        cout << "Hiç öğrenci yok veya yıl sonu notu pozitif bir değer içermiyor." << endl << endl;
    }

    // Sınıftan yıl sonu notlarının toplamını ve öğrenci sayısını hesaplama
    float toplamYilSonuNotu = 0;
    int ogrenciSayisi = ogrencitablosu.size();


    for (int i = 0; i < ogrenciSayisi; i++)
    {
        toplamYilSonuNotu += ogrencitablosu[i].yilSonuNotu;
    }

    // Sınıfın yıl sonu notlarının ortalamasını hesaplama
    float sinifOrtalamasi = toplamYilSonuNotu / ogrenciSayisi;

    // Sınınftan yıl sonu notlarının ortalamasını hesaplama
    sinifOrtalamasi = toplamYilSonuNotu / ogrenciSayisi;

    // Standart sapma hesaplama
    float toplamKareFark = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        float fark = ogrencitablosu[i].yilSonuNotu - sinifOrtalamasi;
        toplamKareFark += fark * fark;
    }

    float standartSapma =sqrt(sqrt(toplamKareFark / ogrenciSayisi));

    // Ortalamayı ve standart sapmayı ekrana yazdırma
    cout << "Sınıfın Yıl Sonu Not Ortalaması: " << fixed << setprecision(2) << sinifOrtalamasi << endl << endl;
    cout << "Sınıfın Yıl Sonu Not Standart Sapması: " << fixed << setprecision(2) << standartSapma << endl << endl;

    // Öğrenci bilgilerini tabloya yazdırma ve harf notları için sayıları hesaplama
    int AA_sayisi = 0;
    int BA_sayisi = 0;
    int BB_sayisi = 0;
    int BC_sayisi = 0;
    int CC_sayisi = 0;
    int CD_sayisi = 0;
    int DD_sayisi = 0;
    int DF_sayisi = 0;
    int FF_sayisi = 0;

    // Her bir harf notundan kaç öğrenci olduğunu hesaplama
    for (const ogrenciBilgileri& ogrenci : ogrencitablosu) {
       
        if (ogrenci.harfNotu == "AA") {
            AA_sayisi++;
        }
        else if (ogrenci.harfNotu == "BA") {
            BA_sayisi++;
        }
        else if (ogrenci.harfNotu == "BB") {
            BB_sayisi++;
        }
        else if (ogrenci.harfNotu == "BC") {
            BC_sayisi++;
        }
        else if (ogrenci.harfNotu == "CC") {
            CC_sayisi++;
        }
        else if (ogrenci.harfNotu == "CD") {
            CD_sayisi++;
        }
        else if (ogrenci.harfNotu == "DD") {
            DD_sayisi++;
        }
        else if (ogrenci.harfNotu == "DF") {
            DF_sayisi++;
        }
        else if (ogrenci.harfNotu == "FF") {
            FF_sayisi++;
        }
    }

    // Her harf notu için sınıf yüzdesini hesaplama
    int toplamOgrenciSayisi = ogrencitablosu.size();
    float AA_yuzdesi = (static_cast<float>(AA_sayisi) / toplamOgrenciSayisi) * 100; //Tür dönüşümü gerçekleştirme: Static_cast
    float BA_yuzdesi = (static_cast<float>(BA_sayisi) / toplamOgrenciSayisi) * 100;
    float BB_yuzdesi = (static_cast<float>(BB_sayisi) / toplamOgrenciSayisi) * 100;
    float BC_yuzdesi = (static_cast<float>(BC_sayisi) / toplamOgrenciSayisi) * 100;
    float CC_yuzdesi = (static_cast<float>(CC_sayisi) / toplamOgrenciSayisi) * 100;
    float CD_yuzdesi = (static_cast<float>(CD_sayisi) / toplamOgrenciSayisi) * 100;
    float DD_yuzdesi = (static_cast<float>(DD_sayisi) / toplamOgrenciSayisi) * 100;
    float DF_yuzdesi = (static_cast<float>(DF_sayisi) / toplamOgrenciSayisi) * 100;
    float FF_yuzdesi = (static_cast<float>(FF_sayisi) / toplamOgrenciSayisi) * 100;

    // Harf notu istatistiklerini yazdısrma
    cout << "AA Notu Alan Öğrenci Sayısı: " << AA_sayisi << " (%" << AA_yuzdesi << ")" << endl;
    cout << "BA Notu Alan Öğrenci Sayısı: " << BA_sayisi << " (%" << BA_yuzdesi << ")" << endl;
    cout << "BB Notu Alan Öğrenci Sayısı: " << BB_sayisi << " (%" << BB_yuzdesi << ")" << endl;
    cout << "BC Notu Alan Öğrenci Sayısı: " << BC_sayisi << " (%" << BC_yuzdesi << ")" << endl;
    cout << "CC Notu Alan Öğrenci Sayısı: " << CC_sayisi << " (%" << CC_yuzdesi << ")" << endl;
    cout << "CD Notu Alan Öğrenci Sayısı: " << CD_sayisi << " (%" << CD_yuzdesi << ")" << endl;
    cout << "DD Notu Alan Öğrenci Sayısı: " << DD_sayisi << " (%" << DD_yuzdesi << ")" << endl;
    cout << "DF Notu Alan Öğrenci Sayısı: " << DF_sayisi << " (%" << DF_yuzdesi << ")" << endl;
    cout << "FF Notu Alan Öğrenci Sayısı: " << FF_sayisi << " (%" << FF_yuzdesi << ")" << endl;




    return 0;
}
