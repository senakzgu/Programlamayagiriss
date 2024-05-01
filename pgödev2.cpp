/*
            SAKARYA ÜNİVERSİTESİ
     BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ 
     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
     PROGRAMLAMAYA GİRİŞ DERSİ

     ÖDEV NUMARASI      : 2
     ÖĞRENCİ ADI        : SENA KUZĞU
     ÖĞRENCİ NUMARASI   : G231210385
     DERS GRUBU         : A

*/ 


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;


int gecenSureGenel = 0; 
int gecenSureOzel = 0; 

 struct HesapNo
{
    int genelHesapNo;
    int ozelHesapNo;
    double kriptoParaMiktarı = 0.0;
  
};
   
    HesapNo h[20];
    int i = 0;
    int j = 10;
   



class ozelHesap 
{
    
    public:
    
    void kriptoParaAl() // Para alma fonksiyonu
    {
         
        
        int miktar;
        cout << "Hesaba yatırmak istediğiniz para miktarını giriniz." << endl;
        cin >> miktar;
        h[i].kriptoParaMiktarı = miktar + h[i].kriptoParaMiktarı;
        cout << "Para yükleme işleminiz gerçekleşmiştir." << endl;
    }


    void kriptoParaSat() // Para satma fonksiyonu
    {
        
      
        int miktar;
        cout << "Hesaptan satmak istediğiniz para miktarını giriniz." << endl;
        cin >> miktar;
        if(miktar<= h[i].kriptoParaMiktarı) // Yeterli bakiye bulunup bulunmadığını kontrol eder.
        {
            h[i].kriptoParaMiktarı = h[i].kriptoParaMiktarı - miktar ;

            cout << "Para satma işleminiz gerçekleşmiştir." << endl;
        }
        else
        {
            cout << "Yetersiz bakiye!!" << endl;
        }
    }


    void tarih() // güncel tarihi gösteren fonksiyon
     {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Sistem Tarihi: " << ltm->tm_mday << "-" << ltm->tm_mon + 1 << "-" << ltm->tm_year + 1900 << endl;
    }
    

    double karhesabı()  // Kar hesabı yapar.
    {


        if(gecenSureGenel != 0) // ilk gün artış yok.
        {
             h[i].kriptoParaMiktarı =  h[i].kriptoParaMiktarı * (1.05); // her gün %5 artış yaşanır.
        }
         if (gecenSureOzel / 30 ==0 ) // 1. ayda random 3 gün seçer.
        {
            int secilenguns;
            secilenguns = rand() % 30;
            secilenguns = rand() % 30;
            secilenguns = rand() % 30;
          

            if(secilenguns == gecenSureOzel) // Seçilen 3 gün geldiğinde %10 düşüş yaşanır.
            {
                 h[i].kriptoParaMiktarı =  h[i].kriptoParaMiktarı * 0.9;
             }

        }
   
    

    
    }

    
};




class genelHesap 
{
    
    public:
    

    void kriptoParaAl() // Para alma fonksiyonu
    {
         
        int miktar;
        cout << "Hesaba yatırmak istediğiniz para miktarını giriniz." << endl;
        cin >> miktar;
        h[j].kriptoParaMiktarı = miktar + h[j].kriptoParaMiktarı;
        cout << "Para yükleme işleminiz gerçekleşmiştir." << endl;
    }

    void kriptoParaSat() // Para satma fonksiyonu
    {
        int miktar;
        cout << "Hesaptan satmak istediğiniz para miktarını giriniz." << endl;
        cin >> miktar;
        
        if(miktar<= h[j].kriptoParaMiktarı) // Yeterli bakiye bulunup bulunmadığını hesaplayan fonksiyon
        {
            h[j].kriptoParaMiktarı = h[j].kriptoParaMiktarı -miktar;

            cout << "Para satma işleminiz gerçekleşmiştir." << endl;
        }
        else
        {
            cout << "Yetersiz bakiye!!" << endl;
        }
    }

    void tarih() // Güncel tarihi gösterir.
     
    {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Sistem Tarihi: " << ltm->tm_mday << "-" << ltm->tm_mon + 1 << "-" << ltm->tm_year + 1900 << endl;
    }


    
    double karhesabı()  // Kar hesabı yapar.
    {

     
         if(gecenSureGenel != 0) // ilk gün artış yok.
         {
            h[j].kriptoParaMiktarı =  h[j].kriptoParaMiktarı * (1.01); // her gün %1 artış yaşanır.
         }
        

        int  a =  gecenSureGenel % 15;
        if( a == 0 && gecenSureGenel != 0) // 15 günde bir %5 düşüş yaşanır.
         {
         h[j].kriptoParaMiktarı = h[j].kriptoParaMiktarı * 0.95;
         }

      
    }

};







int main()
{
    
    int cevap;
    ozelHesap öHesap[10];
    genelHesap gHesap[10];


    unsigned seed = time(0);
    srand(seed); 
    
  

    int secim;
    do // Menüye dönüşü sağlar.
    {
    cout << "Lütfen istediğiniz işlemi seçiniz(1-7)" << endl;
    cout << "1 : Genel hesap aç" << endl;
    cout << "2 : Özel hesap aç" << endl;
    cout << "3 : Hesaba para ekle" << endl;
    cout << "4 : Hesaptan para çek"<< endl;
    cout << "5 : Sistem tarihini göster"<< endl;
    cout << "6 : Hesabı listele"<< endl;

    cin >> secim;

    
    

    switch (secim)
    {
    case 1:
    {
       // genel hesap oluşturma.
         
        h[j].genelHesapNo = rand () % 9999999 + 10000000;
        cout << "Genel hesap oluşturuldu." << endl;
        cout << "Hesap No: " << h[j].genelHesapNo << endl;
        j++;
        cout<<"Menüye dönmek için 9'a basınız!" << endl;
        cin >> cevap;

    }
        break;

    case 2:
    {
        // özel hesap oluşturma
        
        h[i].ozelHesapNo = rand () % 9999999 + 10000000;
        cout << "Özel hesap oluşturuldu." << endl;
        cout << "Hesap No: " << h[i].ozelHesapNo << endl;
        i++;
        cout<<"Menüye dönmek için 9'a basınız!" << endl;
        cin >> cevap;

    }
    
        break;

    case 3:
    {
        int girilenHesapNo;
        cout << "Lütfen hesap numaranızı giriniz." << endl;
        cin >> girilenHesapNo;
        for(int i = 0, j = 10; i < 10 && j < 20; i++, j++) // Girilen hesap numarasını kontrol eder.
        {
            
            if(girilenHesapNo == h[i].ozelHesapNo) // özel hesaba eşitse özel hesap fonksiyonunu çağırır.
            {
             
              öHesap[i].kriptoParaAl();
              break;
            }
            else if (girilenHesapNo == h[j].genelHesapNo) // genel hesaba eşitese genel hesap fonksiyonunu çağırır.
            {
              gHesap[j].kriptoParaAl();
              break;
            }
           
            
             
        }
        
        
    }
    cout<<"Menüye dönmek için 9'a basınız!" << endl;
        cin >> cevap;
        break;

     case 4:
      {
        int girilenHesapNo;
        cout << "Lütfen hesap numaranızı giriniz." << endl;
        cin >> girilenHesapNo;
        
        for(int i = 0, j = 10; i < 10 && j < 20; i++, j++) // Girilen hesap numarasını kontrol eder.
        {
        
            if(girilenHesapNo == h[i].ozelHesapNo) // özel hesaba eşitse özel hesap fonksiyonunu çağırır.
            {
             
              öHesap[i].kriptoParaSat();
              break;
            }
            else if (girilenHesapNo == h[j].genelHesapNo) // genel hesaba eşitese genel hesap fonksiyonunu çağırır.
            {
              gHesap[j].kriptoParaSat();
              break;
            }
            
             
        }
         cout<<"Menüye dönmek için 9'a basınız!" << endl;
         cin >> cevap;
      }
        break;

    case 5:
    {

         öHesap[i].tarih();

    }
        cout<<"Menüye dönmek için 9'a basınız!" << endl;
        cin >> cevap;
    
        break;

    case 6:
    {
        for(int j = 10 ; j < 20; j++)
        {
        
            gHesap[j].karhesabı();
            cout << "Hesap Türü: Genel Hesap" << endl;
            cout << "Hesap No: " << h[j].genelHesapNo << endl;
            cout << " Hesap bakiyesi: " << h[j].kriptoParaMiktarı << endl << endl;

        }
    
     for(int i = 0 ; i < 10 ; i++)
        {

             öHesap[i].karhesabı();
            cout << "Hesap Türü: Özel Hesap" << endl;
            cout << "Hesap No: " << h[i].ozelHesapNo << endl;
            cout << " Hesap bakiyesi: " << h[i].kriptoParaMiktarı <<  endl << endl;

        }
              
    }
        
    
    
         gecenSureGenel++;
         gecenSureOzel++;
    
        cout<<"Menüye dönmek için 9'a basınız!" << endl;
        cin >> cevap;
    
        break;

   
    
         default:
         break;
    
    }
    
    }
    
    
    while(cevap == 9);

    
    


}
