#ifndef __CPARTICLEFACTORY_H__
#define __CPARTICLEFACTORY_H__

namespace ColliderModel
{
    class CParticle;
    class CParticleFactory {
    
        private:
            CParticleFactory() {}
            CParticleFactory(const CParticleFactory &_copy) {}
            CParticleFactory &operator=(CParticleFactory &_copy) {}
        
        public:
            static CParticleFactory& particleFactory();
            CParticle* createParticle(const TVector3 &_pos, const TVector3 &_velocity) const;
    }; // class CParticleFactory
    
} // namespace ColliderModel

#endif // __CPARTICLEFACTORY_H__
