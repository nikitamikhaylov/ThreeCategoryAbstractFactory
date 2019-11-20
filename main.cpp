#include <iostream>
#include "Typelist.h"
#include "AbstractFactoryGenerator.h"
#include "Product.h"

typedef GetAbstractFactory<
    3, 5,
    Typelist<Chair, Table, Sofa>,
    Typelist<WoodenChair, WoodenTable, WoodenSofa>,
    Typelist<MetalChair, MetalTable, MetalSofa>,
    Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
    Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>
> MyFactoryHierarchy;

void MetalRich()
{
  auto MyFactory = std::make_unique<MyFactoryHierarchy::GetConcreteFactory<MetalRichChair>::result>();
  auto sofa = std::unique_ptr<Sofa>(MyFactory->Get<Sofa>());
  auto table = std::unique_ptr<Table>(MyFactory->Get<Table>());
  auto chair = std::unique_ptr<Chair>(MyFactory->Get<Chair>());

  std::cout << "MetalRichSofa = ";
  sofa->identify();
  std::cout << "MetalRichTable = ";
  table->identify();
  std::cout << "MetalRichChair = ";
  chair->identify();
}

void Default()
{
  auto MyFactory = std::make_unique<MyFactoryHierarchy::GetConcreteFactory<Table>::result>();
  auto sofa = std::unique_ptr<Sofa>(MyFactory->Get<Sofa>());
  auto table = std::unique_ptr<Table>(MyFactory->Get<Table>());
  auto chair = std::unique_ptr<Chair>(MyFactory->Get<Chair>());

  std::cout << "Sofa = ";
  sofa->identify();
  std::cout << "Table = ";
  table->identify();
  std::cout << "Chair = ";
  chair->identify();
}

void Wooden()
{
  auto MyFactory = std::make_unique<MyFactoryHierarchy::GetConcreteFactory<WoodenSofa>::result>();
  auto sofa = std::unique_ptr<Sofa>(MyFactory->Get<Sofa>());
  auto table = std::unique_ptr<Table>(MyFactory->Get<Table>());
  auto chair = std::unique_ptr<Chair>(MyFactory->Get<Chair>());

  std::cout << "WoodenSofa = ";
  sofa->identify();
  std::cout << "WoodenTable = ";
  table->identify();
  std::cout << "WoodenChair = ";
  chair->identify();
}

void MetalPoor()
{
  auto MyFactory = std::make_unique<MyFactoryHierarchy::GetConcreteFactory<MetalPoorChair>::result>();
  auto sofa = std::unique_ptr<Sofa>(MyFactory->Get<Sofa>());
  auto table = std::unique_ptr<Table>(MyFactory->Get<Table>());
  auto chair = std::unique_ptr<Chair>(MyFactory->Get<Chair>());

  std::cout << "MetalPoorSofa = ";
  sofa->identify();
  std::cout << "MetalPoorTable = ";
  table->identify();
  std::cout << "MetalPoorChair = ";
  chair->identify();
}

int main() {

  MetalRich();
  Default();
  Wooden();
  MetalPoor();
  return 0;
}