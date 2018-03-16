#ifndef __CBOOK_H__
#define __CBOOK_H__

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include "TString.h"

namespace ColliderModel{

  class CBook {
  private:
    virtual std::vector<TString> databaseUnfold(std::string) = 0;
  public:
    virtual Int_t updateData(TString) = 0;
    virtual Char_t getSeparator() const = 0;
    virtual Int_t setSeparator(Char_t) = 0;
    virtual Int_t defaultSeparator() = 0;
  };


}

#endif // CBOOK_H
