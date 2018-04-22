#ifndef __CPARTICLEFACTORY_H__
#define __CPARTICLEFACTORY_H__

#include <list>

#include "TVector3.h"

namespace ColliderModel
{
    
    class CParticle;

    typedef std::list<CParticle*> partPointerList;
    typedef partPointerList::iterator partPointerListIter;

    class CParticleFactory {
    
        private:
	    partPointerList m_pParticles;

            CParticleFactory() {}
            CParticleFactory(const CParticleFactory &_copy) {}
            CParticleFactory &operator=(CParticleFactory &_copy) {}

            void addParticle(CParticle* _pParticle);
            bool removeParticle(CParticle* _pParticle);
        
        public:
            static CParticleFactory& particleFactory();
            CParticle* createParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity) const;
	    void clean();
	    void show();

	    friend class CParticle;
    }; // class CParticleFactory
    
} // namespace ColliderModel

#endif // __CPARTICLEFACTORY_H__
