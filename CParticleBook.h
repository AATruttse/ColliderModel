#ifndef __CPARTICLEBOOK_H__
#define __CPARTICLEBOOK_H__

#include "CBook.h"

namespace ColliderModel {

struct CParticleData
{
  Double_t pMass;
  Int_t pCharge;
  Double_t pHalfLife;
};

class CParticleBook : public CBook
{
public:
  CParticleData& getData(TString _particle);
  Int_t updateData(TString _filename);
  Int_t checkValidity();
  static CParticleBook& getInstance();
  Char_t getSeparator() const;
  Int_t setSeparator(Char_t _ch);
  Int_t defaultSeparator();
  virtual ~CParticleBook();

private:
  CParticleBook();
  CParticleBook(const CParticleBook&);
  CParticleBook& operator= (const CParticleBook);
  std::vector<TString> databaseUnfold(std::string input_str);
  std::map<TString, CParticleData> particleMap;
  Char_t separator;

};


} //For namespace

#endif // CPARTICLEBOOK_H
