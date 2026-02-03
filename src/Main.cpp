/**
* @file Main.cpp
* @description  * Programın başlangıç noktasıdır.
 * Veri dosyasını okur, sistemi oluşturur,
 * kullanıcıdan tur sayısını alır ve simülasyonu başlatır.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Giris temizligi icin

#include "System.hpp"
#include "FileReader.hpp"
#include "Utils.hpp"

int main()
{
    std::string filename = "data.txt";

    // ---------------------------------------------------------
    // 1. ADIM: DOSYA ANALIZI (Sadece bir kez yapilir)
    // ---------------------------------------------------------
    std::ifstream f(filename);
    if (!f.is_open())
    {
        std::cout << "Data.txt bulunamadi!\n";
        return 1;
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(f, line))
    {
        if (!Utils::trim(line).empty()) ++lineCount;
    }
    f.close();

    if (lineCount == 0)
    {
        std::cout << "Data.txt bos!\n";
        return 1;
    }

    // Altigen sayisi sabittir, degismez.
    int hexCount = (lineCount + 5) / 6;
    
    // Bellek tahsisi (Program boyunca kalir, icerigi temizlenip tekrar kullanilir)
    Hexagon* hexagons = new Hexagon[hexCount];
    System sys(hexagons, hexCount);
    FileReader reader;

    // ---------------------------------------------------------
    // 2. ADIM: ANA PROGRAM DONGUSU
    // ---------------------------------------------------------
    while (true)
    {
        // A) TEMIZLIK: Onceki turdan kalan verileri sil
        for (int i = 0; i < hexCount; ++i)
        {
            hexagons[i].clear(); 
        }

        // B) YUKLEME EKRANI: Verileri tekrar oku ve animasyonu goster
        // Bu islem System::printScreen cagirdigi icin ekrani temizleyip bastan cizecektir.
        reader.loadData(filename, hexagons, hexCount, &sys); 
        
        // C) KULLANICI GIRISI
        int tourCount = 0;
        std::cout << "\nKac tur oynatilsin? (Cikis icin 0): ";
        
        // Hatali giris kontrolu (Harf girilirse sonsuz donguye girmesin)
        if (!(std::cin >> tourCount)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            tourCount = 0;
        }

        if (tourCount <= 0) 
        {
            std::cout << "Cikis yapiliyor...\n";
            break;
        }

        // D) SIMULASYON BASLAT
        sys.run(tourCount); 
        // run() fonksiyonu bitince ekranda son turun goruntusu kalir.

        // E) BASA DONME SECENEGI
        std::cout << "\n--------------------------------------\n";
        std::cout << "Simulasyon Tamamlandi.\n";
        std::cout << "Basa donmek ve tekrar veri yuklemek icin 'e' tusuna basin.\n";
        std::cout << "Cikmak icin baska bir tusa basin: ";
        
        char choice;
        std::cin >> choice;
        
        if (choice != 'e' && choice != 'E') {
            break; // Donguden cik ve programi kapat
        }
        
        // 'e' secildiyse dongu basa doner -> Veriler temizlenir -> Yukleme ekrani gelir.
    }

    // ---------------------------------------------------------
    // 3. ADIM: KAPATMA
    // ---------------------------------------------------------
    delete[] hexagons;

    return 0;
}