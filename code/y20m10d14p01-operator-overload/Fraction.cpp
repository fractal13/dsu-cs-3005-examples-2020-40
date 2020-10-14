#include "Fraction.h"

Fraction::Fraction( ) 
  : mNumerator( 0 ), mDenominator( 1 ) {
  this->reduce( );
}
Fraction::Fraction( int n, int d )
  : mNumerator( n ), mDenominator( d ) {
  this->reduce( );
}
Fraction::Fraction( int n ) 
  : mNumerator( n ), mDenominator( 1 ) {
  this->reduce( );
}

int Fraction::getNumerator( ) const {
  return this->mNumerator;
}

int Fraction::getDenominator( ) const {
  return this->mDenominator;
}

void Fraction::setValue( int n, int d ) {
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );
}

Fraction& Fraction::operator+=( const Fraction& rhs ) {
  int n = mNumerator * rhs.mDenominator + rhs.mNumerator * mDenominator;
  int d = mDenominator * rhs.mDenominator;
  mNumerator = n;
  mDenominator = d;
  reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator-=( const Fraction& rhs ) {
  int n = this->mNumerator * rhs.mDenominator - rhs.mNumerator * this->mDenominator;
  int d = this->mDenominator * rhs.mDenominator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator*=( const Fraction& rhs ) {
  int n = this->mNumerator * rhs.mNumerator;
  int d = this->mDenominator * rhs.mDenominator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator/=( const Fraction& rhs ) {
  int n = this->mNumerator * rhs.mDenominator;
  int d = this->mDenominator * rhs.mNumerator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator+=( const int& rhs ) {
  int n = this->mNumerator + rhs * this->mDenominator;
  int d = this->mDenominator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator-=( const int& rhs ) {
  int n = this->mNumerator - rhs * this->mDenominator;
  int d = this->mDenominator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator*=( const int& rhs ) {
  int n = this->mNumerator * rhs;
  int d = this->mDenominator;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator/=( const int& rhs ) {
  int n = this->mNumerator;
  int d = this->mDenominator * rhs;
  this->mNumerator = n;
  this->mDenominator = d;
  this->reduce( );

  return *this; // return the Fraction pointed to by this -- dereferencing
}

Fraction& Fraction::operator++( ) {
  this->mNumerator += this->mDenominator;
  this->reduce( );
  return *this;
}

Fraction& Fraction::operator++( int x ) {
  (void)x;
  this->mNumerator += this->mDenominator;
  this->reduce( );
  return *this;
}


Fraction Fraction::operator+( const Fraction& rhs ) const {
  Fraction result( mNumerator, mDenominator );
  // Fraction += Fraction
  result += rhs;
  return result;
}

Fraction Fraction::operator-( const Fraction& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result -= rhs;
  return result;
}

Fraction Fraction::operator*( const Fraction& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result *= rhs;
  return result;
}

Fraction Fraction::operator/( const Fraction& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result /= rhs;
  return result;
}

Fraction Fraction::operator+( const int& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result += rhs;
  return result;
}

Fraction Fraction::operator-( const int& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result -= rhs;
  return result;
}

Fraction Fraction::operator*( const int& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result *= rhs;
  return result;
}

Fraction Fraction::operator/( const int& rhs ) const {
  Fraction result( this->mNumerator, this->mDenominator );
  result /= rhs;
  return result;
}


bool Fraction::operator==( const Fraction& rhs ) const {
  return this->mNumerator * rhs.mDenominator == this->mDenominator * rhs.mNumerator;
}

bool Fraction::operator!=( const Fraction& rhs ) const {
  return this->mNumerator * rhs.mDenominator != this->mDenominator * rhs.mNumerator;
}


bool Fraction::operator<( const Fraction& rhs ) const {
  return this->mNumerator * rhs.mDenominator < this->mDenominator * rhs.mNumerator;
}


bool Fraction::operator<=( const Fraction& rhs ) const {
  return this->mNumerator * rhs.mDenominator <= this->mDenominator * rhs.mNumerator;
}


bool Fraction::operator>( const Fraction& rhs ) const {
  return rhs < *this;
  //return this->mNumerator * rhs.mDenominator > this->mDenominator * rhs.mNumerator;
}


bool Fraction::operator>=( const Fraction& rhs ) const {
  return this->mNumerator * rhs.mDenominator >= this->mDenominator * rhs.mNumerator;
}

static int gcd( int a, int b ) {
  if( b > a ) {
    return gcd( b, a );
  }
  if( b == 0 ) {
    return a;
  }
  return gcd( b, a % b );
}


void Fraction::reduce( ) {
  int g = gcd( abs( this->mNumerator ), abs( this->mDenominator ) );
  this->mNumerator /= g;
  this->mDenominator /= g;
  if( this->mDenominator < 0 ) {
    this->mNumerator *= -1;
    this->mDenominator *= -1;
  }
}

Fraction operator+( const int& lhs, const Fraction& rhs ) {
  Fraction result( lhs, 1 );
  result += rhs;
  return result;
}

Fraction operator-( const int& lhs, const Fraction& rhs ) {
  Fraction result( lhs, 1 );
  result -= rhs;
  return result;
}

Fraction operator*( const int& lhs, const Fraction& rhs ) {
  Fraction result( lhs, 1 );
  result *= rhs;
  return result;
}

Fraction operator/( const int& lhs, const Fraction& rhs ) {
  Fraction result( lhs, 1 );
  result /= rhs;
  return result;
}


std::ostream& operator<<( std::ostream& lhs, const Fraction& rhs ) {
  lhs << rhs.getNumerator( );
  lhs << "/";
  lhs << rhs.getDenominator( );
  return lhs;
}

std::istream& operator>>( std::istream& lhs, Fraction& rhs ) {
  int n, d;
  char slash;

  lhs >> n >> slash >> d;
  rhs.setValue( n, d );

  return lhs;
}
