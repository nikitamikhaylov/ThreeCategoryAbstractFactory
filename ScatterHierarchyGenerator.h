#pragma once

#include "Typelist.h"
#include "EmptyType.h"

/// GenScatterHierarchy

template <typename TList, template <class> class Unit>
class GenScatterHierarchy;

template <typename Head, typename... Tail, template <class> class Unit>
class GenScatterHierarchy<Typelist<Head, Tail...>, Unit> : public GenScatterHierarchy<Head, Unit>, public GenScatterHierarchy<Typelist<Tail...>, Unit> {
 public:
  typedef Typelist<Head, Tail...> TList;
  typedef GenScatterHierarchy<Head, Unit> LeftBase;
  typedef GenScatterHierarchy<Typelist<Tail...>, Unit> RightBase;
};

template <typename AtomicType, template <class> class Unit>
class GenScatterHierarchy : public Unit<AtomicType> {
 public:
  typedef Unit<AtomicType> LeftBase;
};

template <template <class> class Unit>
class GenScatterHierarchy<Typelist<>, Unit> {};