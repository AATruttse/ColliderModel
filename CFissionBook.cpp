#include <algorithm>
#include <list>

#include "CFissionBook.h"

namespace ColliderModel {

std::vector<TString> __null_shatters;
static CFissionData __null_fission = {-1, __null_shatters};
std::vector<CFissionData> __null_data;
/*
class myCrippledFunctor {
  std::vector<TString>* p_to_arr;
  myCrippledFunctor(std::vector<TString>* _data_ref )
  {
    p_to_arr = _data_ref;
  }
  void operator()(TString _param_str)
  {
    p_to_arr -> push_back(_param_str);
  }
};
*/
/*
CFissionData::CFissionData()
{
  fProbability = 0;
}
CFissionData::CFissionData(Double_t _param)
{
  fProbability = _param;
}

CFissionData::CFissionData(Double_t _param, std::vector<TString> _vec)
{
  fProbability = _param;
  fShatters = _vec;
}
*/
Char_t CFissionBook::getSeparator() const
{
  return separator;
}

Int_t CFissionBook::setSeparator(Char_t _symbol)
{
  separator = _symbol;
  return 0;
}

Int_t CFissionBook::defaultSeparator()
{
  separator = '#';
  return 0;
}

CFissionBook& CFissionBook::getInstance()
{
  static CFissionBook instance;
  return instance;
}

CFissionBook::CFissionBook()
{
  separator = '#';
}

std::vector<TString> CFissionBook::databaseUnfold (std::string input_str)
{
  std::vector<TString> UnfoldedDatabaseParts;
  std::string::iterator input_str_iter_fast = input_str.begin();
  std::string::iterator input_str_iter_slow = input_str.begin();
  while (input_str_iter_slow == input_str.end())
  {
    while ((input_str_iter_fast != input_str.end())&&(*input_str_iter_fast != separator))
    {
      ++input_str_iter_fast;
    }
    std::string substring(input_str_iter_slow, input_str_iter_fast);
    TString vec_member = substring;
    UnfoldedDatabaseParts.push_back(vec_member);
    while ((input_str_iter_fast != input_str.end())&&(*input_str_iter_fast == separator))
    {
      ++input_str_iter_fast;
    }
    input_str_iter_slow = input_str_iter_fast;
  }
  return UnfoldedDatabaseParts;
}

const std::vector<CFissionData>& CFissionBook::getData(TString _particle)
{
std::map<TString, std::vector <CFissionData> >::const_iterator search_iter;
search_iter = fissionMap.find(_particle);
if (search_iter == fissionMap.end())
{
  return __null_data; //Empty!
}
else return (search_iter -> second);
}

Int_t CFissionBook::updateData(TString _filename)
{
  std::ifstream data_file;
  std::string line_buffer;
  data_file.open(_filename.Data());
  if (!data_file.is_open())
  {
    return -1; //Cannot open the file
  }
  while(!std::getline(data_file, line_buffer))
  {
    std::vector<TString> temp_unfolded = databaseUnfold(line_buffer);
    if (temp_unfolded.size() < 3)
    {
      data_file.close();
      return -2; //Damaged database entries
    }
    CFissionData temp_scenario;
    temp_scenario.fProbability = temp_unfolded[1].Atof();
    std::vector<TString>::iterator point = (temp_unfolded.begin() + 2);
    std::copy(point,
              temp_unfolded.end(),
              (fissionMap[ temp_unfolded[0]])[0].fShatters.begin()
              );

  /*  std::for_each(point,
                  temp_unfolded.end(),
                  myCrippledFunctor fct( &(temp_scenario.fShatters) );
 CFissionData temp_fission = { temp_unfolded[1].Atof(),
                                  temp_unfolded[2].Atoi(),
                                  temp_unfolded[3].Atof() }; */
  //  (fissionMap[ temp_unfolded[0] ]).push_back(temp_scenario);
  }
  return 0;
}



Int_t CFissionBook::checkValidity()
{
  std::list < std::map < TString, std::vector < CFissionData > >::iterator > /*BRUTAL!*/ blacklist;
  Int_t counter = 0;
  for ( std::map<TString, std::vector<CFissionData> >::iterator map_iter = fissionMap.begin();
        map_iter != fissionMap.end();
        map_iter++ )
        {
          if (
               (((map_iter -> second)[counter]).fProbability > 1) ||
               (((map_iter -> second)[counter]).fProbability < 0) ||
               (((map_iter -> second)[counter]).fShatters.empty() )
             )
          {
            blacklist.push_front(map_iter);

          }
        }


  std::list<std::map <TString, std::vector < CFissionData > >::iterator >::iterator  blacklist_iter;
  for (blacklist_iter == blacklist.begin(); blacklist_iter != blacklist.end(); blacklist_iter++)
  {
    fissionMap.erase(*blacklist_iter);
  }
  return 0;
}


} //For namespace
