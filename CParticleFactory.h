#ifndef __CPARTICLEFACTORY_H__
#define __CPARTICLEFACTORY_H__

#include <list>


#include "TVector3.h"

class TFile;
class TTree;

namespace ColliderModel
{

    
    class CParticle;

    typedef std::list<CParticle*> partPointerList;
    typedef partPointerList::iterator partPointerListIter;

    class CParticleFactory {
    
        private:
	    TTree *m_pTree;
	    TFile *m_pFile;

            Int_t m_NextID;

	    partPointerList m_pParticles;

            CParticleFactory() : m_pTree(0), m_pFile(0), m_NextID(1) {}
            CParticleFactory(const CParticleFactory &_copy) : m_pTree(0), m_pFile(0), m_NextID(1) {}
            CParticleFactory &operator=(CParticleFactory &_copy) {close_tree();}

            void addParticle(CParticle* _pParticle);
            bool removeParticle(CParticle* _pParticle);
        
        public:
            static CParticleFactory& particleFactory();
            CParticle* createParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity, Int_t _ParentID = 0);
	    void clean();
	    void show();	
            void create_tree(const char * const _filename);
            void save_to_tree();
            void close_tree();
	    friend class CParticle;

            Int_t getNextID() {return m_NextID++;}

	    ~CParticleFactory();
    }; // class CParticleFactory
    
} // namespace ColliderModel

#endif // __CPARTICLEFACTORY_H__
