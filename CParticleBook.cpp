#include "CParticleBook.h"
#include <iostream>

namespace ColliderModel {

static CParticleData __error__particle = {-1.0, 0, 0.0};
static CParticleData __null__particle = {0.0, 0, 0.0};

Char_t CParticleBook::getSeparator() const
{
  return separator;
}

Int_t CParticleBook::setSeparator(Char_t _ch)
{
  separator = _ch;
  return 0;
}

Int_t CParticleBook::defaultSeparator()
{
  separator = '#';
  return 0;
}

CParticleBook& CParticleBook::getInstance()
{
  static CParticleBook instance;
  return instance;
}

CParticleBook::CParticleBook()
{
  separator = '#';
}

std::vector<TString> CParticleBook::databaseUnfold (std::string input_str)
{
  std::vector<TString> UnfoldedDatabaseParts;
  std::string::iterator input_str_iter_fast = input_str.begin();
  std::string::iterator input_str_iter_slow = input_str.begin();
  while (input_str_iter_slow != input_str.end())
  {
    while ((input_str_iter_fast != input_str.end())&&(*input_str_iter_fast != separator))
    {
      ++input_str_iter_fast;
    }
    std::string substring(input_str_iter_slow, input_str_iter_fast);
    TString vec_member = substring.c_str();
    UnfoldedDatabaseParts.push_back(vec_member);
    while ((input_str_iter_fast != input_str.end())&&(*input_str_iter_fast == separator))
    {
      ++input_str_iter_fast;
    }
    input_str_iter_slow = input_str_iter_fast;
  }
  return UnfoldedDatabaseParts;
}

Int_t CParticleBook::updateData(TString _filename)
{
  std::ifstream data_file;
  std::string line_buffer;
  data_file.open(_filename.Data());
  if (!data_file.is_open())
  {
    std::cout << "Cannot open the file " << _filename << std::endl;
    return -1; //Cannot open the file
  }
  while(std::getline(data_file, line_buffer))
  {
    std::vector<TString> temp_unfolded = databaseUnfold(line_buffer);
    if (temp_unfolded.size() < 4)
    {
      data_file.close();
      std::cout << "Damaged database entries" << std::endl;
      return -2; //Damaged database entries
    }
    CParticleData temp_particle = { temp_unfolded[1].Atof(),
                                    temp_unfolded[2].Atoi(),
                                    temp_unfolded[3].Atof() };
    particleMap[ temp_unfolded[0] ] = temp_particle;
  }
  std::cout << "Update data sucesfully, read " << particleMap.size() << "entries" << std::endl;
  return 0;
}

const CParticleData& CParticleBook::getData(TString _particleName)
{
  std::map<TString, CParticleData>::const_iterator search_iter;
  std::cout << particleMap.size() << std::endl;

  search_iter = particleMap.find(_particleName);
  if (search_iter == particleMap.end())
  {
    return __null__particle;
  }
  return (search_iter -> second);
}

Int_t CParticleBook::checkValidity()
{
  for (std::map<TString, CParticleData>::iterator check_iter = particleMap.begin();
       check_iter != particleMap.end();
       check_iter++)
  {
    if (((check_iter -> second).pMass) < 0) particleMap.erase(check_iter);
  }
  return 0;
}

} // For namespace
