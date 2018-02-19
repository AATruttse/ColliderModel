#include "cparticlebook.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

int CParticleBook::DatabaseSetLogfile(const char *_filename)
{
    databaseLogfile.open(_filename);
    if (!databaseLogfile.is_open())
    {
        std::cerr << "Log file cannot be opened for some reason." << std::endl;
        return LOGFILE_OPENING_ERROR;
    }
    return 0;
}


int CParticleBook::DatabaseLoad(const char *_filename)
{
    std::ifstream data_source;
    std::string line_buffer;
    std::string divided_str;
    std::string temp_name;
    CParticleData temp_particle;
    data_source.open(_filename);
    if (!data_source.is_open())
      return DATABASE_FILE_OPENING_ERROR;
    while (!std::getline(data_source, line_buffer))
    {
        divided_str = (line_buffer.substr(0, line_buffer.find_first_of("#")));
        temp_name = divided_str;
        temp_particle.pName = divided_str;
        divided_str = (line_buffer.substr(line_buffer.find_first_of("#")+1, line_buffer.find_first_of("#")));
        temp_particle.pMass = (std::stold(divided_str));
        divided_str = (line_buffer.substr(line_buffer.find_first_of("#")+1, line_buffer.find_first_of("#")));
        temp_particle.pCharge = (std::stof(divided_str));
        std::pair<std::string, CParticleData> key_value(temp_name, temp_particle);
        dataMap.emplace(key_value);
    }
    std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
    std::time_t formatted_time = std::chrono::system_clock::to_time_t(time_now);
    databaseLogfile << std::ctime(&formatted_time) << " " << "Database was updated successfully!"<< std::endl;
    data_source.close();
    return 0;
}

CParticleBook::CParticleBook()
{
    logfileDefaultName = "LOG_DEFAULT.txt";
}

 CParticleData& CParticleBook::getData (std::string _particleName) try
 {
     int particle_entries = dataMap.count(_particleName);
     if (particle_entries == 0) throw std::invalid_argument("No such particle in the dataset.");
     else if(particle_entries > 1) throw std::invalid_argument("The particle is multiply defined!");
     std::map<std::string, CParticleData>::iterator map_iter = dataMap.find(_particleName);
     if (map_iter != dataMap.end())
         return (map_iter->second);
     else throw std::invalid_argument("Unknown error!");
 }
 catch(const std::invalid_argument& e)
 {
     std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
     std::time_t formatted_time = std::chrono::system_clock::to_time_t(time_now);
     databaseLogfile << std::ctime(&formatted_time) << " " << (e.what())<< std::endl;
 }

 int CParticleBook::dataToScreen(std::string _particleName)
 {
     int particle_entries = dataMap.count(_particleName);
     if (particle_entries == 0)
     {
         std::cerr << "No such particle in the dataset." << std::endl;
         return -1;
     }
     else if(particle_entries > 1)
     {
         std::cerr << "The particle is mutiply defined!" << std::endl;
         return -1;
     }
     std::map<std::string, CParticleData>::iterator map_iter = dataMap.find(_particleName);
     if (map_iter != dataMap.end())
     {
        std::cout << "Particle has been found!" << std::endl;
        std::cout << "It is called: " << (map_iter->second.pName) << std::endl;
        std::cout << "Its mass is: " << (map_iter->second.pMass) << std::endl;
        std::cout << "Its charge is: " << (map_iter->second.pCharge) << std::endl;
     }
     else
     {
         std::cerr << "Unknown error!" << std::endl;
         return -1;
     }
     return 0;
 }

 int CParticleBook::dataToFile(std::string _extractionFile, std::string _particleName)
 {
     std::ofstream file_output;
     file_output.open(_extractionFile);
     if (!file_output.is_open())
     {
         std::cerr << "File opening error!" << std::endl;
         return -1;
     }
     int particle_entries = dataMap.count(_particleName);
     if (particle_entries == 0)
     {
         std::cerr << "No such particle in the dataset." << std::endl;
         file_output.close();
         return -1;
     }
     else if(particle_entries > 1)
     {
         std::cerr << "The particle is mutiply defined!" << std::endl;
         file_output.close();
         return -1;
     }
     std::map<std::string, CParticleData>::iterator map_iter = dataMap.find(_particleName);
     if (map_iter != dataMap.end())
     {
        file_output << "Particle has been found!" << std::endl;
        file_output << "It is called: " << (map_iter->second.pName) << std::endl;
        file_output << "Its mass is: " << (map_iter->second.pMass) << std::endl;
        file_output << "Its charge is: " << (map_iter->second.pCharge) << std::endl;
     }
     else
     {
         std::cerr << "Unknown error!" << std::endl;
         file_output.close();
         return -1;
     }
     file_output.close();
     return 0;
 }

CParticleBook& CParticleBook::getInstance()
{
    static CParticleBook instance;
    return instance;
}

