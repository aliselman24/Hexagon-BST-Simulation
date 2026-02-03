/**
* @file FileReader.cpp
* @description /*
 * FileReader sınıfı, veri dosyasını okuyarak
 * satırları altıgenlere ve BST'lere yerleştirir.
 * Veri yükleme sürecinde kullanıcıya görsel geri bildirim sağlar.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <windows.h> 

FileReader::FileReader() {}


// Dosyadaki verileri okuyarak her 6 satırı bir altıgene,
// her satırı bir BST'ye karşılık gelecek şekilde yükler.

void FileReader::loadData(const std::string& filename, Hexagon* hex, int hexCount, System* sys)
{
    // ---------------------------------------------------------
    // 1. ADIM: Toplam satır sayısını bul
    // ---------------------------------------------------------
    std::ifstream countFile(filename);
    int totalLines = 0;
    std::string tempLine;
    while (std::getline(countFile, tempLine))
    {
        if (!Utils::trim(tempLine).empty())
            totalLines++;
    }
    countFile.close();

    // ---------------------------------------------------------
    // 2. ADIM: İLK DURUM - EKRANI BOŞ GÖSTERİR
    // ---------------------------------------------------------
    // Önce boş şablonu basıyoruz.
    sys->printScreen(0, 0, 0, totalLines);

    
    // Şablonun görülebilmesi için 1 saniye bekletip siliyor.
    Sleep(1000); 
    system("cls");
    
    
    // ---------------------------------------------------------
    // 3. ADIM: VERİYİ SESSİZCE OKU
    // ---------------------------------------------------------
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Dosya acilamadi: " << filename << "\n";
        return;
    }

    int currentLine = 0;
    int hexIndex = 0;
    int bstCounter = 0; 
    std::string line;

    while (std::getline(file, line))
    {
        if (Utils::trim(line).empty()) continue;

        currentLine++;

        if (hexIndex < hexCount)
        {
            QueueBST& q = hex[hexIndex].getQueue();
            q.ensureSixTrees();

            BST* tree = q.at(bstCounter);
            std::stringstream ss(line);
            int val;
            while (ss >> val)
            {
                tree->insert(val);
            }

            bstCounter++;
            
            if (bstCounter == 6)
            {
                hexIndex++;
                bstCounter = 0;
            }
        }
        
        
    }

    file.close();

    // ---------------------------------------------------------
    // 4. ADIM: SON DURUMU GÖSTER
    // ---------------------------------------------------------
    // İşlem bitti, son halini temiz ekrana bas.
    
    sys->printScreen(0, 0, totalLines, totalLines);
}