#pragma once

template <class T, class U>
class Conversion
{
  typedef char Small;
  class Big { char dummy[2]; };
  static Small Test(U);
  static Big Test(...);
  static T MakeT();
public:
  static constexpr int exists = sizeof(Test(MakeT())) == sizeof(Small) ;
  static constexpr int sameType = false ;
};

template <class T>
class Conversion<T, T>
{
 public:
  static constexpr int exists = 1;
  static constexpr int sameType = 1;
};

#define SUPERSUBCLASS(T, U) (Conversion<const U*, const T*>::exists && !Conversion<const T*, const void*>::sameType)

template <typename T>
struct Type2Type {
  typedef T type;
};