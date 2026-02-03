/**
* @file Node.hpp
* @description data alanına verilen value atanır
 * - left ve right nullptr yapılır (yeni düğüm başlangıçta yapraktır)
* @course 1B
* @assignment 2.ÖDEV
* @date 14.12.2025
* @author ALİ SELMAN ERKAN selman.erkan@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value); // SADECE İMZA
};

#endif
