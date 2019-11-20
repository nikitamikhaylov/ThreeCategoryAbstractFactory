#pragma once
#include "NullType.h"
#include "TypeUtils.h"

template <typename... Ts>
struct Typelist {};

namespace TL {

/// TypeAt

template <typename TList, unsigned int index>
struct TypeAt;

template <typename Head, typename... Tail>
struct TypeAt<Typelist<Head, Tail...>, 0>
{
  typedef Head result;
};

template <typename Head, typename... Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail...>, i>
{
  typedef typename TypeAt<Typelist<Tail...>, i - 1>::result result;
};

/// TypeExists

template <typename TList, typename T> struct TypeExists;

template <typename T>
struct TypeExists<Typelist<>, T> {
  static constexpr bool result = false;
};

template <typename T, typename... Tail>
struct TypeExists<Typelist<T, Tail...>, T>
{
  static constexpr bool result = true;
};

template <typename Head, typename... Tail, typename T>
struct TypeExists<Typelist<Head, Tail...>, T>
{
  static constexpr int result = TypeExists<Typelist<Tail...>, T>::result;
};

/// ListWithType

template <typename TList, typename T>
struct ListWithType;

template <typename Head, typename... Tail, typename T>
struct ListWithType<Typelist<Head, Tail...>, T>
{
  typedef typename std::conditional<TypeExists<Head, T>::result, Head, typename ListWithType<Typelist<Tail...>, T>::result>::type result;
};

template <typename T>
struct ListWithType<Typelist<>, T>
{
  typedef NullType result;
};

/// Append

template <typename TList, typename T>
struct Append;

template <typename... Ts, typename T>
struct Append<Typelist<Ts...>, T>
{
  typedef Typelist<Ts..., T> result;
};

/// Reverse

template <typename TList> struct Reverse;

template <typename Head, typename... Tail>
struct Reverse<Typelist<Head, Tail...> >
{
  typedef typename Reverse<Typelist<Tail...> >::result ReversedTail ;
  typedef typename Append<ReversedTail, Head>::result result;
};

template <>
struct Reverse<Typelist<> >
{
  typedef Typelist<> result;
};

/// GetTail

template <typename TList>
struct GetTail;

template <typename Head, typename... Tail>
struct GetTail<Typelist<Head, Tail...> >
{
  typedef Typelist<Tail...> result;
};

/// GetSupers

template <typename... TLists>
struct GetSupers;

template <typename Head, typename... Tail, typename TList, typename... OthersTLists>
struct GetSupers<Typelist<Head, Tail...>, TList, OthersTLists...>
{
  typedef typename GetSupers<TList, OthersTLists...>::result OthersRes;
  typedef typename TypeAt<OthersRes, 0>::result OthersResHead;
  typedef typename std::conditional<SUPERSUBCLASS(Head, OthersResHead), Typelist<Head, Tail...>, OthersRes>::type result;
};

template <typename TList>
struct GetSupers<TList>
{
  typedef TList result;
};

}  // namespace TL