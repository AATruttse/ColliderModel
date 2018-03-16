#ifndef __CFISSIONBOOK_H__
#define __CFISSIONBOOK_H__

#include "CBook.h"

namespace ColliderModel{


struct CFissionData
{
  Double_t fProbability;
  std::vector<TString> fShatters;
};

class CFissionBook : public CBook
{
public:
  CFissionData& getData(TString _particle);
  Int_t updateData(TString _filename);
  Int_t checkValidity();
  static CFissionBook& getInstance();
  Char_t getSeparator() const;
  Int_t setSeparator(Char_t _ch);
  Int_t defaultSeparator();
  virtual ~CFissionBook();
  
private:
  CFissionBook();
  CFissionBook(const CParticleBook&);
  CFissionBook& operator= (const CFissionBook);
  std::vector<TString> databaseUnfold(std::string input_str);
  std::map<TString, CFissionData> fissionMap;
  Char_t separator;
};






} //For namespace

#endif
