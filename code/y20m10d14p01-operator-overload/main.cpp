#include "Fraction.h"
#include <iostream>

int main( ) {

  Fraction f1( 2, 3 );  // 2/3
  Fraction f2( 5, 6 );  // 5/6
  Fraction f3, f4;
  int i;

  f3 = f1 + f2;
  // f3 = f1.operator+( f2 );

  i = 7;
  f3 = f1 + i;
  // f3 = f1.operator+( i );

  f3 += f2;
  // f3.operator+=( f2 );

  f4 = f3 += f2;
  //f4 = (f3 += f2);
  // f4 = f3.operator+=( f2 );
  
  ( f3 += f2 ) += f1;
  // (f3.operator+=( f2 )).operator+=( f1 );

  f3 += f2 += f1;
  // (f3.operator+=( f2.operator+=( f1 ) );

  f4 = i + f2;
  // f4 = operator+( i, f2 );

  f4 = f3 = f2 = f1;

  

  if( f4 < i ) {
    // f4.operator<(Fraction(i))
    std::cout << f4 << " < " << i << std::endl;
    // FAIL std::cout.operator<<(f4)
    // operator<<(std::cout, f4)
    // operator<<(operator<<(operator<<(operator<<(std::cout, f4), " < "),  i), std::endl);

  } else {
    std::cout << f4 << " not < " << i << std::endl;
  }

  f4++;
  ++f4;

  if( static_cast<Fraction>(i) > f4 ) {
    std::cout << i << " > " << f4 << std::endl;
  } else {
    std::cout << i << " not > " << f4 << std::endl;
  }

  std::cout << f1 << std::endl;
  //( std::cout << f1 ) << std::endl;

  return 0;
}
