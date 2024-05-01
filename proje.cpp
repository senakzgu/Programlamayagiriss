/*
            SAKARYA ÜNİVERSİTESİ
     BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ 
     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
     PROGRAMLAMAYA GİRİŞ DERSİ

     ÖDEV NUMARASI      : PROJE
     ÖĞRENCİ ADI        : SENA KUZĞU
     ÖĞRENCİ NUMARASI   : G231210385
     DERS GRUBU         : A

*/ 






#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <random>

using namespace std;


struct bilgi //  Takım ve futbolcu bilgilerini içerir
{
	
    string takimAdi;
    string takimAdresi;
    long takimTelefonNo;
    int takimOyuncuSayisi=0;
    string takimYöneticiİsmi;
	string takimYöneticiSoyismi;
    long futbolcuTCNo;
    string futbolcuAdi;
    string futbolcuSoyadi;
    string futbolcuKonumu;
    double futbolcuMaaşı;
	int gol;
	int puan;
    
};
// Global değişkenler
bilgi b[300]; 
int i = 1;
int j = 1;


	





class futboltakimi // futbol takımı sınıfı
{
	
   

    public:
	

    void takimİşlemi() 
	{
		int secim = 0;
	
		
		
			// Takım işlemleri
			cout << "TAKIM İŞLEMİ" << endl;
			cout << "----------------------" << endl;
			cout << "1- Takım Ekle" << endl;
			cout << "2- Takım Sil" << endl;
			cout << "3- Takımları listele" << endl;
			cout << "Seçiminiz:";
			cin >> secim;

			switch (secim)
			{
			case 1: 
            {
                takimEkle();
				i++;
            }
				break;
			case 2:
            {
				
                takimSil();
				
			 }
				break;
			case 3: 
            {
               takimlariListele();
            }

				break;
		
			}

		
	}



// Takım ekleme
void takimEkle()
	{
        
				ofstream tdosyayaz;
	            tdosyayaz.open("takim.txt",ios::app); // takım dosyasına yazdırma işlemi
		
				
                cout << "Takım adı giriniz: ";
                cin >> b[i].takimAdi;
                cout << endl;

                cout << "Takım adresi giriniz: ";
                cin >> b[i].takimAdresi;
                cout << endl;

                cout << "Takım telefon numarası giriniz: ";
                cin >> b[i].takimTelefonNo;
                cout << endl;

                cout << "Takım yöneticisi ismi giriniz: ";
                cin >> b[i].takimYöneticiİsmi;
                cout << endl;

				cout << "Takım yöneticisi soyismi giriniz: ";
                cin >> b[i].takimYöneticiSoyismi;
                cout << endl;

				// dosyaya yazdırma işlemi
		            tdosyayaz << i << setw(20) << b[i].takimAdi << setw(20) << b[i].takimAdresi << setw(20) << b[i].takimTelefonNo << setw(10) << 
				  b[i].takimOyuncuSayisi <<
              	  setw(20) << b[i].takimYöneticiİsmi << setw(20) << b[i].takimYöneticiSoyismi << endl << endl;
				 


					tdosyayaz.close();
					cout << endl;
					cout << "TAKIM KAYDEDİLDİ!!";
					cout << endl; 
                    


		
	}

 	// Takım silme
	void takimSil()
	{
		
		int girilenTakımNumarası; 
		cout << "Takım numarasini giriniz:";
		cin >> girilenTakımNumarası;
		
		ifstream tdosyaoku("takim.txt");
    	ofstream gtdosyayaz("takimgecici.txt"); // geçici takım dosyasına yazdırma işlemi
		
		
		
		
			 for (int k = 1; k <= i; k++) // i'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
        tdosyaoku >> k >> setw(20) >> b[k].takimAdi >> setw(20) >> b[k].takimAdresi >> setw(20) >> b[k].takimTelefonNo >> setw(10) >>
            b[k].takimOyuncuSayisi >> setw(20) >> b[k].takimYöneticiİsmi >> setw(20) >> b[k].takimYöneticiSoyismi;

        if (girilenTakımNumarası == k)
        {
            cout << "Takım silindi" << endl;
			continue;
        }
        
        
            gtdosyayaz << k << setw(20) << b[k].takimAdi << setw(20) << b[k].takimAdresi << setw(20) << b[k].takimTelefonNo << setw(10) <<
                b[k].takimOyuncuSayisi << setw(20) << b[k].takimYöneticiİsmi << setw(20) << b[k].takimYöneticiSoyismi << endl << endl;
        
   		 }
	
    tdosyaoku.close(); // dosyalar kapatılır
    gtdosyayaz.close();
    remove("takim.txt"); // takım dosyası silinir
    rename("takimgecici.txt", "takim.txt"); // geçici takım dosyasının adı değiştirilir.
	
			

	}

	// Takımları listeleme
	void takimlariListele()
	{
        ifstream gtdosyaoku("takim.txt");
		string satır;

		while (getline(gtdosyaoku,satır))
		{
				cout << satır << endl;
		}

		gtdosyaoku.close();
		
	}



	void skorİşlemi() 
	{
		int secim = 0;
	
		
		
			// skor işlemleri
			cout << "SKOR İŞLEMİ" << endl;
			cout << "----------------------" << endl;
			cout << "1- Karşılaşmaları gir" << endl;
			cout << "2- Haftalık oynayan takımları göster" << endl;
			cout << "3- Haftalık puan durumunu göster" << endl;
			cout << "4- Oyuncu durumlarını göster" << endl;
			cout << "Seçiminiz:";
			cin >> secim;

			switch (secim)
			{
			case 1: 
            {
               karsilasmakaydı();
            }
				break;
			case 2:
            {
				haftalikOynayanTakimlar();
              
			 }
				break;
			case 3: 
            {
               haftalıkpuandurumu();
            }
				break;
			case 4:
			{
				oyuncudurumu();
			}
			break;
		
			}

		
	}


			
		
	void karsilasmakaydı()
	{
		int girilenTakımNo;
		cout << "Ev sahibi takımın numarasını giriniz." << endl;
		cin >> girilenTakımNo;
		
		ifstream tdosyaoku("takim.txt");
		ofstream dosyayaz("skor.txt",ios::app);
    	
			 for (int k = 1; k <= i; k++) // i'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
        tdosyaoku >> k >> setw(20) >> b[k].takimAdi >> setw(20) >> b[k].takimAdresi >> setw(20) >> b[k].takimTelefonNo >> setw(10) >>
            b[k].takimOyuncuSayisi >> setw(20) >> b[k].takimYöneticiİsmi >> setw(20) >> b[k].takimYöneticiSoyismi;

        if (girilenTakımNo == k)
        {
            cout << "Takım adı: " << b[k].takimAdi  << endl;
			cout << "Attığı gol sayısı: " ;
			cin >> b[k].gol;
			
        }
		else{cout<<"Böyle bir takım bulunmamaktadır"<<endl;}
		 


		dosyayaz <<"1. takım: " << b[k].takimAdi << " - " << b[k].gol << " gol    ";
		 };
		


		int girilenTakimno;
		cout << "Deplasman takımın numarasını giriniz" << endl;
		cin >> girilenTakimno;


		 for (int k = 1; k <= i; k++) // i'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
        tdosyaoku >> k >> setw(20) >> b[k].takimAdi >> setw(20) >> b[k].takimAdresi >> setw(20) >> b[k].takimTelefonNo >> setw(10) >>
            b[k].takimOyuncuSayisi >> setw(20) >> b[k].takimYöneticiİsmi >> setw(20) >> b[k].takimYöneticiSoyismi;

		if (girilenTakimno == k)
        {
            cout << "Takım adı: " << b[k].takimAdi  << endl;
			cout << "Attığı gol sayısı: " ;
			cin >> b[k].gol;
        }
		else{cout<<"Böyle bir takım bulunmamaktadır"<<endl;}


		dosyayaz <<"2. takım: " << b[k].takimAdi << " - " << b[k].gol << " gol ";

        
   		 }
	if(b[girilenTakımNo].gol > b[girilenTakimno].gol) // hangi takımın kaç puan aldığını belirleme
	{
		b[girilenTakımNo].puan=+3;
	}
	else if(b[girilenTakımNo].gol < b[girilenTakimno].gol)
	{
		b[girilenTakimno].puan=+3;
	}
	else
	{
		b[girilenTakımNo].puan=+1;
		b[girilenTakimno].puan=+1;
	}

		


        tdosyaoku.close(); 
		dosyayaz.close();
   		 }
		
		
		void haftalikOynayanTakimlar()
		{
   			ifstream skorDosyaoku("skor.txt");
    		string satir;

   		 	cout << "Haftalık Oynayan Takımlar ve Skorları" << endl;
    		cout << "-------------------------------------" << endl;

   			 while (getline(skorDosyaoku, satir))
    			{
        			cout << satir << endl;
    			}

    		skorDosyaoku.close();
		}
	
		void haftalıkpuandurumu()
		{

			cout << "  Haftalık Puan Durumu" << endl;
			cout << "-------------------------" << endl;

			for(int w = 1; w <= i; w++)
			{
				cout << b[w].takimAdi << " : " << b[w].puan << " puan"	<< endl;
			}


			
		}


		void oyuncudurumu() // oynayan oyuncular ve gol atan oyuncular
		{
			for(int x = 1; x <= i ; x++)
			{
				cout << b[x].takimAdi << " takımı oynayan oyuncular: " << endl;
					for(int y = 1; y <=11; y++)
					{
						cout << b[y].futbolcuAdi << " " << b[y].futbolcuSoyadi << " : " << b[y].futbolcuKonumu << endl;
					}
				cout << endl;

				cout << b[x].takimAdi << " takımında gol atan oyuncular: " << endl;
					
					int a = b[i].gol;
					for(int d = 0; d <= a; d++)
					{
						for(int s = 0; a <= d; a++ )
						{
							int rastgeleindex = rand() % s;
							cout << b[rastgeleindex].futbolcuAdi << b[rastgeleindex].futbolcuSoyadi << endl;
							
						}
					}


			}

		}


	};



	












class futbolcular // Futbolcu sınıfı
{
	public:
	
	// futbolcu işlemleri
	void futbolcuİslemleri() 
	{
		int secim = 0;
		
			
			cout << "   FUTBOLCU İŞLEMLERİ" << endl;
			cout << "------------------------" << endl;
			cout << "1-	Oyuncu ekleme" << endl;
			cout << "2-	Oyuncu silme" << endl;
            cout << "3-	Oyuncu güncelleme" << endl;
            cout << "4-	Oyuncular listeleme" << endl;
			cout << "Seciminiz:";
			cin >> secim;

			switch (secim)
			{
			case 1: 
            {
                futbolcuEkle();
				j++;

            }
				break;
			case 2: 
            {
				
                futbolcusil();
				
            }
				break;
            case 3: 
            {
                futbolcuguncelle();
            }
				break;
            case 4: 
            {
				futbolcularıListele();
                
            }
				break;

			
			

			}
		

	}   


	// Futbolcu ekleme
	 void futbolcuEkle()
	{
		ofstream fdosyayaz;
		fdosyayaz.open ("futbolcu.txt",ios::app); // futbolcu dosyası açılır
		
		char cevap;

			
			cout << "  FUTBOLCU BILGISI" << endl;
			cout << "-----------------------" << endl;
			cout << "Futbolcu adi: ";
			cin >> b[j].futbolcuAdi;
			cout << "Futbolcu soyadi: ";
			cin >> b[j].futbolcuSoyadi;
			cout << "Futbolcu TC no: ";
			cin >> b[j].futbolcuTCNo;
            cout << "Futbolcunun oyundaki konumu: ";
            cin >> b[j].futbolcuKonumu;
            cout << "Futbolcu maaşı: ";
            cin >> b[j].futbolcuMaaşı;


			fdosyayaz << j  << setw(20) << b[j].futbolcuAdi  << setw(20) <<b[j].futbolcuSoyadi << setw(20) << b[j].futbolcuTCNo << setw(20)<<  b[j].futbolcuKonumu 
            << setw(20) <<  b[j].futbolcuMaaşı << endl << endl;


		fdosyayaz.close();
		cout << endl;
		cout << "KAYIT YAPILDI!!";
		cout << endl;
	
	
	}



	// Futbolcu silme
	void futbolcusil()
	{
		
		int girilenlisansno; 
		cout << "Futbolcunun lisans numarasini giriniz:";
		cin >> girilenlisansno;
		char ch;
		ifstream fdosyaoku("futbolcu.txt");
    	ofstream fgdosyayaz("futbolcugecici.txt"); // geçici futbolcu dosyası açılır
		string satir ;
	
				
			 for (int m = 1; m <= j; m++) // j'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
       		fdosyaoku >> m >> b[m].futbolcuAdi >> b[m].futbolcuSoyadi >> b[m].futbolcuTCNo >> b[m].futbolcuKonumu >>  b[m].futbolcuMaaşı;

        if (girilenlisansno == m)
        {
            cout << "Futbolcu silindi" << endl;
			continue;
        }
        
        
            fgdosyayaz << m << setw(20) << b[m].takimAdi << setw(20) << b[m].takimAdresi << setw(20) << b[m].takimTelefonNo << setw(10) <<
                b[m].takimOyuncuSayisi << setw(20) << b[m].takimYöneticiİsmi << setw(20) << b[m].takimYöneticiSoyismi << endl << endl;
        
   		 }

		
		

				
             
				fdosyaoku.close(); // dosyalar kapatılır
        		fgdosyayaz.close();
        		remove("futbolcu.txt"); // futbolcu dosyası silinir
        		rename("futbolcugecici.txt", "futbolcu.txt"); // geçici futbolcu dosyasının adı değiştirilir

	}


	// Futbolcu güncelleme
	void futbolcuguncelle()
	{
		
		int girilenlisansno; 
		cout << "Futbolcunun lisans numarasini giriniz:" << endl;
		cin >> girilenlisansno;
	
		char ch;

		ifstream fdosyaoku("futbolcu.txt");
    	ofstream fgdosyayaz("futbolcugecici.txt"); // geçici futbolcu dosyası açılır
		
	
    	
			 for (int m = 1; m <= j; m++) // j'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
       		fdosyaoku >> m >> b[m].futbolcuAdi >> b[m].futbolcuSoyadi >> b[m].futbolcuTCNo >> b[m].futbolcuKonumu >>  b[m].futbolcuMaaşı;

        if (girilenlisansno == m)
        {
			cout << "Futbolcu adi: ";
			cin >> b[j].futbolcuAdi;
			cout << "Futbolcu soyadi: ";
			cin >> b[j].futbolcuSoyadi;
			cout << "Futbolcu TC no: ";
			cin >> b[j].futbolcuTCNo;
            cout << "Futbolcunun oyundaki konumu: ";
            cin >> b[j].futbolcuKonumu;
            cout << "Futbolcu maaşı: ";
            cin >> b[j].futbolcuMaaşı;
           
        }
        
        
            fgdosyayaz << m << setw(20) << b[m].futbolcuAdi  << setw(20) << b[m].futbolcuSoyadi << setw(20) << b[m].futbolcuTCNo << setw(20)<<  b[m].futbolcuKonumu 
           			 << setw(20) <<  b[m].futbolcuMaaşı << endl << endl;
   		 }

		
		

				
             
				fdosyaoku.close();// dosyalar kapatılır
        		fgdosyayaz.close();
        		remove("futbolcu.txt"); // futbolcu dosyası silinir
        		rename("futbolcugecici.txt", "futbolcu.txt");  // geçici futbolcu dosyasının adı değiştirilir


	
	}


	 // Futbolcuları listeleme
	void futbolcularıListele()
	{
        ifstream fgdosyaoku("futbolcu.txt");
		string satır;

		while (getline(fgdosyaoku,satır))
		{
				cout << satır << endl;
		}

		fgdosyaoku.close();
		
	}



	 // Futbolcuyu takıma ekleme
	void futbolcuyuTakimaEkle()
    {
        
        // Takım dosyasını açın
        ifstream takimDosyaOku("takim.txt");
        ofstream geciciDosyaYaz("takimgecici.txt");

		int girilenTakımNo;
		int girilenLisansNo;

		cout<< "Takım numarasını giriniz" << endl;
		cin >> girilenTakımNo;
		cout << endl;
		
		


		 for (int k = 1; k <= i; k++) // i'yi kontrol etmek için kullanılan döngü sınırı değiştirildi
   		 {
        takimDosyaOku >> k >> setw(20) >> b[k].takimAdi >> setw(20) >> b[k].takimAdresi >> setw(20) >> b[k].takimTelefonNo >> setw(10) >>
            b[k].takimOyuncuSayisi >> setw(20) >> b[k].takimYöneticiİsmi >> setw(20) >> b[k].takimYöneticiSoyismi;

        if (girilenTakımNo == k)
        {
			cout << "Takım ismi: " << b[k].takimAdi << endl;

			ifstream futboldosyaoku("futbolcu.txt");

			futboldosyaoku >> j >> b[j].futbolcuAdi >> b[j].futbolcuSoyadi;


           	cout << "Futbolcu lisans numarasını giriniz" << endl;
			cin >> girilenLisansNo;

			if(girilenLisansNo == j)
			{
				b[k].takimOyuncuSayisi++;
				geciciDosyaYaz <<  k << setw(20) << b[k].takimAdi << setw(20) << b[k].takimAdresi << setw(20) << b[k].takimTelefonNo << setw(10) <<
                b[k].takimOyuncuSayisi << setw(20) << b[k].takimYöneticiİsmi << setw(20) << b[k].takimYöneticiSoyismi << endl << "Futbolcu:    " << j << setw(10) << 
				b[j].futbolcuAdi << setw(10) << b[j].futbolcuSoyadi << endl;
				cout << b[j].futbolcuAdi << " " << b[j].futbolcuSoyadi << " isimli futbolcu " <<  b[k].takimAdi << " takımına kayıt edildi." << endl;
				
				
			}
			else{cout << "Futbolcu bulunmamaktadır" << endl;}
        }
		else{
			geciciDosyaYaz <<  k << setw(20) << b[k].takimAdi << setw(20) << b[k].takimAdresi << setw(20) << b[k].takimTelefonNo << setw(10) <<
                b[k].takimOyuncuSayisi << setw(20) << b[k].takimYöneticiİsmi << setw(20) << b[k].takimYöneticiSoyismi << endl;

		}
         
   		 }
	
			 
        takimDosyaOku.close();
        geciciDosyaYaz.close();

        // Eski takım dosyasını silin ve yeni dosyayı yeniden adlandırın
        remove("takim.txt");
        rename("takimgecici.txt", "takim.txt");
    }

};



	





    int main()
    {

		futboltakimi t[20];
		futbolcular f[300];
		

	
		int secim = 0; 
		int cevap = 0;

		do
		{
			cout << "      İŞLEMLER" << endl;
			cout << "--------------------------" << endl;
			cout << "1- Takım İşlemleri" << endl;
			cout << "2- Oyuncu İşlemleri" << endl;
			cout << "3- Oyuncu Kayıt İşlemleri" << endl;
			cout << "4- Skor kayıtları" << endl;
			cout << "Seçiminiz: ";
			cin >> secim;

			switch (secim) 
			{
			case 1: 
            {
                t[i].takimİşlemi();
				cout<<"Menüye dönmek için 9'a basınız!" << endl;
        		cin >> cevap;
            }
				break;
				
			case 2:
			{
				f[j].futbolcuİslemleri();
				cout<<"Menüye dönmek için 9'a basınız!" << endl;
        		cin >> cevap;
			}
				break;

			case 3:
			{

				f[j].futbolcuyuTakimaEkle();
				cout<<"Menüye dönmek için 9'a basınız!" << endl;
        		cin >> cevap;
			}
			break;

			case 4:
			{
				t[i].skorİşlemi();
				cout<<"Menüye dönmek için 9'a basınız!" << endl;
        		cin >> cevap;

			}
			break;

			}
		 } while (cevap==9);

	}




		
        
    



		



	