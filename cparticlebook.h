#ifndef CPARTICLEBOOK_H
#define CPARTICLEBOOK_H
#include <fstream>
#include <map>
#include <string>
#include <tuple>

struct CParticleData
{
  std::string pName;
  long double pMass;
  float pCharge;

};

class CParticleBook
{
private:
    std::map <std::string, CParticleData> dataMap;
    std::ofstream databaseLogfile;
    std::string logfileDefaultName; //state in the constructor

    int DatabaseSetLogfile(const char* _filename);
    int DatabaseLoad(const char* _filename);
    int DatabaseReset(); //Not now, reset the database to original state;
    CParticleBook();
    CParticleBook(const CParticleBook&) = delete;
    CParticleBook& operator= (const CParticleBook&) = delete;

public:
    CParticleData& getData (std::string _particleName);
    int dataToFile(std::string _extractionFile, std::string _particleName);
    int dataToScreen(std::string _particleName);
    static CParticleBook& getInstance();

};
enum Errors {DATABASE_FILE_OPENING_ERROR = 1, LOGFILE_OPENING_ERROR, UNKNOWN_ERROR};
#endif // CPARTICLEBOOK_H
