/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1
**				ÖĞRENCİ ADI...............:Ali Sait Şahiner
**				ÖĞRENCİ NUMARASI.:b201210011
**				DERS GRUBU…………:A
****************************************************************************/

#include<conio.h>
#include <iostream>
#include<locale.h>
#include<stdio.h>
#include<string>
#include<math.h>
#include <vector>

using namespace std;


int main()
{
	setlocale(LC_ALL, ("Turkish"));
	int islem;
	do
	{
		cout << "MENÜ (Yapılacak işlemin numarasını girin) " << endl;
		cout << "*********************************************************************" << endl;
		cout << "1-Matris Toplama" << endl;
		cout << "2-Matris Çarpma" << endl;
		cout << "3-Matris Farkı" << endl;                                          //menü
		cout << "4-Matris İzi" << endl;
		cout << "5-Matrisin Transpozesi" << endl;
		cout << "6-Matris Tersi Alma" << endl;
		cout << "7-Çıkış" << endl;
		cin >> islem;

		switch (islem)                                                             //işlemlere switch case ile karar veriliyor
		{
			//*********************************************************************************Toplama
		case 1:
		{
			int satır, sütun;
			int değer;
			char rastgeleDeğer;

			cout << "MATRİS TOPLAMA" << endl;
			cout << "***********************************************" << endl; 
			cout << "Satır sayısını giriniz...";
			cin >> satır;                                                          //kullanıcıdan satır ve sütun sayısını alıyor
			cout << "Sütun sayısını giriniz...";
			cin >> sütun;

			if (satır <= 0 || sütun <= 0)                                         //satır sütun değer kontrolü
			{
				cout << "Satır veya sütun değeri 0 ve 0 dan az olamaz" << endl;
				exit(0);
			}


			int matris1[10][10] = {};
			int matris2[10][10] = {};                                              //matris tanımlamaları
			int sonuc[10][10] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";                      //değerlerin rastgele olup olmama seçimi yapılıyor
			cin >> rastgeleDeğer;


			cout << "\n Matris 1\n" << endl;
			for (int i = 0; i < satır; i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;                              //eğer 'e' tuşlanırsa rastgele bir matris
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun : " << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :";       //eğer h tuşlanırsa kullanıcı eğerleri girer
						cin >> değer;
						matris1[i][j] = değer;
					}
				}
			}
			cout << "\n Matris 2\n" << endl;
			for (int i = 0; i < satır; i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris2[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun : " << matris2[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :";
						cin >> değer;
						matris2[i][j] = değer;
					}
				}
			}

			for (int k = 0;k < satır;k++)
			{
				for (int l = 0;l < sütun;l++)
				{
					sonuc[k][l] = matris1[k][l] + matris2[k][l];                      //matrislerde toplama işlemi
				}
			}
			cout << "\n Sonuç Matrisi\n" << endl;
			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					cout << i + 1 << " . Satır " << j + 1 << " . Sütun : " << sonuc[i][j] << endl;    //sonuç matrisi yazdırılıyor
				}
			}
			cout << endl << endl;
		}break;
		//******************************************************************************ÇARPMA
		case 2:
		{
			cout << "MATRİS ÇARPMA " << endl;
			cout << "*******************************************" << endl;
			int m1, n1, m2, n2;
			int değer;                                                                      //değişken tanımlamaları yapılıyor
			char rastgeleDeğer;
			do
			{
				cout << "!Birinci matrisin sütun sayısı ile ikinci matrisin satır sayısı eşit olmalı" << endl;

				cout << "1. MATİRİSİN SATIR VE SÜTUN SAYISINI GİRİNİZ(mxn)..." << endl;
				cin >> m1;
				cin >> n1;
				cout << "2. MATİRİSİN SATIR VE SÜTUN SAYISINI GİRİNİZ(mxn)..." << endl;
				cin >> m2;
				cin >> n2;
				if (m1 <= 0 || n1 <= 0||m2<=0||n2<=0)                                         //satır sütun değer kontrolü
				{
					cout << "Satır veya sütun değeri 0 ve 0 dan az olamaz" << endl;
					exit(0);
				}
			} while (n1 != m2);                                                           //matrislerde çarpma için ilk matris sütunu ile ikinci
																						  //matrisin satırının eşit olma kontrolü

			float matris1[10][10] = {};
			float matris2[10][10] = {};
			float sonuc[10][10] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";
			cin >> rastgeleDeğer;

			cout << "\n Matris 1 \n";
			for (int i = 0;i < m1;i++)
			{
				for (int j = 0;j < n1;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << " . Sütun :" << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << " . Sütun :";
						cin >> değer;
						matris1[i][j] = değer;
					}
				}
			}
			cout << "\n Matris 2 \n";
			for (int i = 0;i < m2;i++)
			{
				for (int j = 0;j < n2;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris2[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << " . Sütun :" << matris2[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << " . Sütun :";
						cin >> değer;
						matris2[i][j] = değer;
					}
				}
			}

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < n2; j++)
				{
					sonuc[i][j] = 0;

					for (int s = 0; s < m2; s++)
					{
						sonuc[i][j] += matris1[i][s] * matris2[s][j];                              //matrislerde çarpma işlemi
					}
				}
			}
			cout << "\n Sonuç Matrisi" << endl;
			for (int i = 0;i < m1;i++)
			{
				for (int j = 0;j < n2;j++)
				{
					cout << i + 1 << ". Satır " << j + 1 << " . Sütun : " << sonuc[i][j] << endl;
				}
			}
			cout << endl << endl;
		}break;
		//***********************************************************************************FARK
		case 3:
		{
			int satır, sütun;
			int değer;
			char rastgeleDeğer;
			cout << "MATRİS FARKI" << endl;
			cout << "***********************************************" << endl;
			cout << "Satır sayısını giriniz...";
			cin >> satır;
			cout << "Sütun sayısını giriniz...";
			cin >> sütun;

			if (satır <= 0 || sütun <= 0)                                         //satır sütun değer kontrolü
			{
				cout << "Satır veya sütun değeri 0 ve 0 dan az olamaz" << endl;
				exit(0);
			}

			int matris1[10][10] = {};
			int matris2[10][10] = {};
			int sonuc[10][10] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";
			cin >> rastgeleDeğer;

			cout << "\n Matris 1\n" << endl;
			for (int i = 0; i < satır; i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :" << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :";
						cin >> değer;
						matris1[i][j] = değer;
					}
				}
			}
			cout << "\n Matris 2\n" << endl;
			for (int i = 0; i < satır; i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris2[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :" << matris2[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :";
						cin >> değer;
						matris2[i][j] = değer;
					}
				}
			}

			for (int k = 0;k < satır;k++)
			{
				for (int l = 0;l < sütun;l++)
				{
					sonuc[k][l] = matris1[k][l] - matris2[k][l];
				}
			}
			cout << "\n Sonuç Matrisi\n" << endl;
			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					cout << i + 1 << " . Satır " << j + 1 << " . Sütun : " << sonuc[i][j] << endl;
				}
			}
			cout << endl << endl;
		}break;
		//**********************************************************************************MATRİS İZİ
		case 4:
		{
			cout << "MATRİS İZİ " << endl;
			cout << "*******************************************" << endl;
			int satır, sütun;
			int değer;
			char rastgeleDeğer;

			do
			{
				cout << "!Matris izinin bulunabilmesi için satırı ve sütunu eşit (karesel matris olmalıdır.)" << endl;

				cout << "Satır sayısını giriniz..." << endl;                            //karesel matris olma kontrolü
				cin >> satır;
				cout << "Sütun sayısını giriniz..." << endl;
				cin >> sütun;

				if (satır <= 0 || sütun <= 0)                                         //satır sütun değer kontrolü
				{
					cout << "Satır veya sütun değeri 0 ve 0 dan az olamaz" << endl;
					exit(0);
				}

			} while (satır != sütun);

			float matris1[10][10] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";
			cin >> rastgeleDeğer;


			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :" << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << ". Satır " << j + 1 << " . Sütun : ";
						cin >> değer;
					}
				}
			}
			cout << endl;
			float iz = 0;
			for (int i = 0;i < satır;i++)
			{
				iz += matris1[i][i];                             //matris izi bulma işlemi
			}
			cout << "Matrisin izi : " << iz << endl;
		}break;
		//*************************************************************************************TRANSPOZESİ
		case 5:
		{
			int satır, sütun;
			int değer;
			char rastgeleDeğer;
			cout << "MATRİS TRANSPOZU" << endl;

			cout << "Satır sayısını giriniz...";
			cin >> satır;
			cout << "Sütun sayısını giriniz...";
			cin >> sütun;

			if (satır <= 0 || sütun <= 0)                                         //satır sütun değer kontrolü
			{
				cout << "Satır veya sütun değeri 0 ve 0 dan az olamaz" << endl;
				exit(0);
			}

			int matris1[10][10] = {};
			int transpozMatris[10][10] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";
			cin >> rastgeleDeğer;


			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :" << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << " . Satır " << j + 1 << ". Sütun : ";
						cin >> değer;
						matris1[i][j] = değer;
					}
				}
			}
			cout << "\n Matris\n" << endl;

			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					cout << " " << matris1[i][j];
					if (j == sütun - 1)
						cout << endl;
				}
			}

			for (int i = 0;i < satır;i++)
			{
				for (int j = 0;j < sütun;j++)
				{
					transpozMatris[j][i] = matris1[i][j];                        //matrisin transpozunu alma
				}
			}
			cout << "\n Matrisin Transpozu \n" << endl;
			for (int i = 0;i < sütun;i++)
			{
				for (int j = 0;j < satır;j++)
				{
					cout << " " << transpozMatris[i][j];                         //transpoz matrisi yazdırma
					if (j == satır - 1)
						cout << endl;
				}
			}
			cout << endl << endl;
		}break;
		//*********************************************************************************************MATRİS TERSİ
		case 6:
		{
			cout << "MATRİS TERSİ ALMA (3X3 MATRİSLER)" << endl;
			int değer;
			float determinant = 0;
			char rastgeleDeğer;

			int matris1[3][3] = {};
			float tersMatris[3][3] = {};

			cout << "Değerler rastgele olsun mu ? (e/h)... ";
			cin >> rastgeleDeğer;

			for (int i = 0;i < 3;i++)
			{
				for (int j = 0;j < 3;j++)
				{
					if (rastgeleDeğer == 'e')
					{
						matris1[i][j] = rand() % 100;
						cout << i + 1 << ". Satır " << j + 1 << ". Sütun :" << matris1[i][j] << endl;
					}
					else if (rastgeleDeğer == 'h')
					{
						cout << i + 1 << " . Satır " << j + 1 << ". Sütun : ";
						cin >> değer;
						matris1[i][j] = değer;
					}
				}
			}

			for (int i = 0;i < 3;i++)                                  //tersini hesaplamak içim determinant hesaplanıyor
			{
				determinant = determinant + (matris1[0][i] * (matris1[1][(i + 1) % 3] * matris1[2][(i + 2) % 3] - matris1[1][(i + 2) % 3] * matris1[2][(i + 1) % 3]));
			}
			if (determinant == 0)
			{
				cout << "Determinant = 0 tanımsızlığı" << endl;
			}
			cout << "Determinant : " << determinant << endl;

			for (int i = 0;i < 3;i++)
			{
				for (int j = 0;j < 3;j++)                           //ters matris hesaplanıyor
				{
					tersMatris[i][j] = ((matris1[(j + 1) % 3][(i + 1) % 3] * matris1[(j + 2) % 3][(i + 2) % 3]) - (matris1[(j + 1) % 3][(i + 2) % 3] * matris1[(j + 2) % 3][(i + 1) % 3])) / determinant;
				}
			}

			cout << "\n Ters Matris \n" << endl;

			for (int i = 0;i < 3;i++)
			{
				for (int j = 0;j < 3;j++)                           //ters matris yazdırılıyor
				{
					cout << i + 1 << " . Satır " << j + 1 << " . Sütun : " << tersMatris[i][j] << endl;
				}
			}
		}break;

		default:
		{
			
			return 0;
		}
		break;
		}
		cout << endl << endl;

	} while (islem != 7);                                           //çıkış tuşuna basana kadar uygulama çalışıyor
	
	return 0;

}


