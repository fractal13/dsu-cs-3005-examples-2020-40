#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

class Fraction {
public:
  Fraction( );
  Fraction( int n, int d );
  Fraction( int n ); // converts ints to Fractions

  int getNumerator( ) const;
  int getDenominator( ) const;
  
  void setValue( int n, int d );

  Fraction& operator+=( const Fraction& rhs );
  Fraction& operator-=( const Fraction& rhs );
  Fraction& operator*=( const Fraction& rhs );
  Fraction& operator/=( const Fraction& rhs );

  Fraction& operator+=( const int& rhs );
  Fraction& operator-=( const int& rhs );
  Fraction& operator*=( const int& rhs );
  Fraction& operator/=( const int& rhs );

  Fraction& operator++( );
  Fraction& operator++( int x );

  Fraction operator+( const Fraction& rhs ) const;
  Fraction operator-( const Fraction& rhs ) const;
  Fraction operator*( const Fraction& rhs ) const;
  Fraction operator/( const Fraction& rhs ) const;

  Fraction operator+( const int& rhs ) const;
  Fraction operator-( const int& rhs ) const;
  Fraction operator*( const int& rhs ) const;
  Fraction operator/( const int& rhs ) const;

  bool operator==( const Fraction& rhs ) const;
  bool operator!=( const Fraction& rhs ) const;
  bool operator<( const Fraction& rhs ) const;
  bool operator<=( const Fraction& rhs ) const;
  bool operator>( const Fraction& rhs ) const;
  bool operator>=( const Fraction& rhs ) const;

protected:
  void reduce( );

  int mNumerator;
  int mDenominator;

};

Fraction operator+( const int& lhs, const Fraction& rhs );
Fraction operator-( const int& lhs, const Fraction& rhs );
Fraction operator*( const int& lhs, const Fraction& rhs );
Fraction operator/( const int& lhs, const Fraction& rhs );

std::ostream& operator<<( std::ostream& lhs, const Fraction& rhs );
std::istream& operator>>( std::istream& lhs, Fraction& rhs );

#endif /* _FRACTION_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
