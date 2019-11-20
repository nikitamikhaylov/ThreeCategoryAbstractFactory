#pragma once

#include <iostream>

class Product
{
  virtual void identify() = 0;
};

class Chair : public Product {
 public:
  void identify() override {
    std::cout << "I am Chair" << std::endl;
  }
};

class WoodenChair: public Chair {
 public:
  void identify() override {
    std::cout << "I am Wooden Chair" << std::endl;
  }
};

class MetalChair: public Chair {
 public:
  void identify() override {
    std::cout << "I am Metal Chair" << std::endl;
  }
};

class MetalRichChair: public MetalChair {
 public:
  void identify() override {
    std::cout << "I am Metal Rich Chair" << std::endl;
  }
};

class MetalPoorChair: public MetalChair {
 public:
  void identify() override {
    std::cout << "I am Metal Poor Chair" << std::endl;
  }
};

class WoodenPoorChair: public WoodenChair {
 public:
  void identify() override {
    std::cout << "I am Wooden Poor Chair" << std::endl;
  }
};

class Table: public Product {
 public:
  void identify() override {
    std::cout << "I am Table" << std::endl;
  }
};

class WoodenTable: public Table {
 public:
  void identify() override {
    std::cout << "I am Wooden Table" << std::endl;
  }
};

class MetalTable: public Table {
 public:
  void identify() override {
    std::cout << "I am Metal Table" << std::endl;
  }
};

class MetalRichTable: public MetalTable {
 public:
  void identify() override {
    std::cout << "I am Metal Rich Table" << std::endl;
  }
};

class MetalPoorTable: public MetalTable {
 public:
  void identify() override {
    std::cout << "I am Metal Poor Table" << std::endl;
  }
};

class Sofa : public Product {
 public:
  virtual void identify() override {
    std::cout << "I am Sofa" << std::endl;
  }
};

class WoodenSofa: public Sofa {
 public:
  void identify() override {
    std::cout << "I am Wooden Sofa" << std::endl;
  }
};

class MetalSofa: public Sofa {
 public:
  void identify() override {
    std::cout << "I am Metal Sofa" << std::endl;
  }
};

class MetalRichSofa: public MetalSofa {
 public:
  void identify() override {
    std::cout << "I am Metal Rich Sofa" << std::endl;
  }
};

class MetalPoorSofa: public MetalSofa {
 public:
  void identify() override {
    std::cout << "I am Metal Poor Sofa" << std::endl;
  }
};