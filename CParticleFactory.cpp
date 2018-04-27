#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include <algorithm>

#include "CCollider.h"
#include "CParticleFactory.h"
#include "CParticle.h"

namespace ColliderModel
{


    CParticleFactory::~CParticleFactory()
    {
	close_tree();
    }

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
        
    CParticle* CParticleFactory::createParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity, Int_t _ParentID)
    {
        // here we need to check, if the particle with this name exists (may be better in constructor of CParticle)
        // if not, make some exception
        CParticle* pParticle = new CParticle(_name, _pos, _velocity, _ParentID);
        pParticle->m_ID = getNextID();
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

    void CParticleFactory::create_tree(const char * const _filename) {
	close_tree();

	m_pFile = new TFile (_filename, "recreate");
	if (m_pFile == 0)
	{
		std::cout << "Can't create file " << _filename << "!" << std::endl;
		return;
	}

	m_pTree = new TTree("t2", "Example Tree");

        Float_t t, x, y, z;
        Int_t id, parent_id;
        m_pTree->Branch("id", &id);	
        m_pTree->Branch("parent_id", &parent_id);
        m_pTree->Branch("t", &t);
        m_pTree->Branch("x", &x);
	m_pTree->Branch("y", &y);	
	m_pTree->Branch("z", &z);
	
    }

    
    void CParticleFactory::save_to_tree() {
	if (m_pTree == 0)
	{
		std::cout << "m_pTree is null!" << std::endl;
		return;
	}

    	//TFile f("Event.root", "UPDATE");
        //TTree *tree = new TTree("tree", "exp");
        //TTree *t2 = (TTree*)f.Get("t2");
	Float_t t, x, y, z;	
        Int_t id, parent_id;
        m_pTree->SetBranchAddress("id", &id);
        m_pTree->SetBranchAddress("parent_id", &parent_id);
        m_pTree->SetBranchAddress("t", &t);
        m_pTree->SetBranchAddress("x", &x);
	m_pTree->SetBranchAddress("y", &y);	
	m_pTree->SetBranchAddress("z", &z);
	for (partPointerListIter iter = m_pParticles.begin(); iter != m_pParticles.end(); iter++)
        {
            if (*iter != 0)
            {
		id = (*iter)->iD();   
		parent_id = (*iter)->parentID();
		t = CCollider::collider().time();
		x = (*iter)->pos().x();
		y = (*iter)->pos().y();
		z = (*iter)->pos().z();
                m_pTree->Fill();
            }
        }
	m_pTree->Write();
	//f.Close();
        
    }

    void CParticleFactory::close_tree()
    {
	if (m_pTree != 0)
	{
	    delete m_pTree;
	    m_pTree = 0;
	}

        if (m_pFile != 0)
	{
	    m_pFile->Close();
	    delete m_pFile;
	    m_pFile = 0;
	}
    }
} // namespace ColliderModel
