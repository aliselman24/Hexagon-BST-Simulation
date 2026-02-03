/**
* @file Node.cpp
* @description data alanına verilen value atanır
 * - left ve right nullptr yapılır (yeni düğüm başlangıçta yapraktır)
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(int value)
    : data(value), left(nullptr), right(nullptr)
{
}
