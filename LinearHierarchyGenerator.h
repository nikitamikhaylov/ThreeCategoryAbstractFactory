#pragma once

#include "Typelist.h"
#include "EmptyType.h"

// GenLinearHierarchy

template <typename TList, template <class AtomicType, class Base> class Unit, typename Root = EmptyType>
class GenLinearHierarchy;

template <typename Head, typename Head2, typename... Tail, template <class, class> class Unit, typename Root>
class GenLinearHierarchy<Typelist<Head, Head2, Tail...>, Unit, Root>
    : public Unit<Head, GenLinearHierarchy<Typelist<Head2, Tail...>, Unit, Root> > {};

template <typename T, template <class, class> class Unit, typename Root>
class GenLinearHierarchy<Typelist<T>, Unit, Root> : public Unit<T, Root> {};