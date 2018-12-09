

/*
  Movie.cpp

  Definition file for Movie class
*/

#include "Movie.hpp"

class Price{

public:
  virtual int getPriceCode() const=0;
  
  virtual double getCharge(int daysRented)=0;
  int getFrequentRenterPoints(int daysRented) const{
    return 1;
  }

};

class ChildrensPrice: public Price{
  public:
    double getCharge(int daysRented){
    double result = 1.5;
    if(daysRented > 3)
      result+= (daysRented-3)*1.5;
    return result;
  }

  int getPriceCode() const{return Movie::CHILDRENS;  }
};

class NewReleasePrice: public Price{
 public:
    double getCharge(int daysRented){
      return daysRented*3;
  }
  int getFrequentRenterPoints(int daysRented) const{
    return (daysRented>1)?2:1;
  }

  int getPriceCode() const{return Movie::NEW_RELEASE;  }
};

class RegularPrice: public Price{

 public:
  double getCharge(int daysRented){
    double result = 2;
    if(daysRented > 2)
      result+= (daysRented-2)*1.5;
    return result;
  }

   int getPriceCode() const{return Movie::REGULAR;  }
};



// constructor
Movie::Movie(const std::string& title, int price_code)
  : title(title)
{
  setPriceCode(price_code);
}

Movie::Movie(const Movie& movie){
  title = movie.title;

  setPriceCode(movie.price_code);}

// movie price code
int Movie::getPriceCode() const {

  return price->getPriceCode();
  // return price_code;
}

// set movie price code
void Movie::setPriceCode(int new_price_code) {

  switch(new_price_code){                                                                           
  case REGULAR:
    price = new RegularPrice();
    price_code = price->getPriceCode();
    break;
  case CHILDRENS:
    price = new ChildrensPrice();
    price_code = price->getPriceCode();
    break;
  case NEW_RELEASE:
     price = new NewReleasePrice();
    price_code = price->getPriceCode();
    break;                                                                                         
  default:                                                                                          
    throw "Incorrect Price";                                                                        
  }
}

// movie title
const std::string& Movie::getTitle() const {

    return title;
}

double Movie::getCharge(int  daysRented) const{

  return price->getCharge(daysRented);
} 

int Movie::getFrequentRenterPoints(int daysRented) const{
  return price->getFrequentRenterPoints(daysRented);
}
