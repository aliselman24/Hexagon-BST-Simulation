/**
* @file FileReader.hpp
* @description /*
 * FileReader sınıfı, veri dosyasını okuyarak
 * satırları altıgenlere ve BST'lere yerleştirir.
 * Veri yükleme sürecinde kullanıcıya görsel geri bildirim sağlar.
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>
#include "Hexagon.hpp"
#include "System.hpp" // System* parametresi için gerekli

class FileReader
{
public:
    FileReader();

    // System* parametresi 
    void loadData(const std::string& filename, Hexagon* hex, int hexCount, System* sys);
};

#endif