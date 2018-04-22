#include "TVector3.h"
#include <iostream>
#include <algorithm>

#include "CParticleFactory.h"
#include "CParticle.h"

namespace ColliderModel
{
    void CParticleFactory::addParticle(CParticle* _pParticle)
    {
        if (_pParticle != 0)
        {
	    std::cout << _pParticle << " was born" << std::endl;
            m_pParticles.push_back(_pParticle);
        }
    }
    
    bool CParticleFactory::removeParticle(CParticle* _pParticle)
    {
        if (_pParticle != 0)
        {
            partPointerListIter foundIter = std::find(m_pParticles.begin(), m_pParticles.end(), _pParticle);
            if (foundIter != m_pParticles.end())
            {
                m_pParticles.erase(foundIter);
	    	std::cout << _pParticle << " was erased" << std::endl;
                return true;
            }
        }
        return false;
    }

    CParticleFactory& CParticleFactory::particleFactory() {
            static CParticleFactory factory;
            return factory;
        }
        
    CParticle* CParticleFactory::createParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity) const
    {
        // here we need to check, if the particle with this name exists (may be better in constructor of CParticle)
        // if not, make some exception
        CParticle* pParticle = new CParticle(_name, _pos, _velocity);
        CParticleFactory::particleFactory().addParticle(pParticle);
        return pParticle;
    }

    void CParticleFactory::clean() {
	for (partPointerListIter iter = m_pParticles.begin(); iter != m_pParticles.end(); iter++)
        {
            if (*iter != 0)
            {
                delete *iter;
		iter--;
            }
        }
    }

    void CParticleFactory::show() {
	for (partPointerListIter iter = m_pParticles.begin(); iter != m_pParticles.end(); iter++)
        {
            if (*iter != 0)
            {
                std::cout << "coordinate of " << *iter << " is " << (*iter)->pos().x() << " " << (*iter)->pos().y() << " " << (*iter)->pos().z() << std::endl;
            }
        }
    }
} // namespace ColliderModel
