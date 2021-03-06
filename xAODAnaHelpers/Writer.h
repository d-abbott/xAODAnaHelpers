#ifndef xAODAnaHelpers_Writer_H
#define xAODAnaHelpers_Writer_H

// algorithm wrapper
#include "xAODAnaHelpers/Algorithm.h"

class Writer : public xAH::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  TString m_outputLabel = "";

  TString m_jetContainerNamesStr = "";
  TString m_electronContainerNamesStr = "";
  TString m_muonContainerNamesStr = "";

private:
  int m_numEvent;         //!

  std::vector<TString> m_jetContainerNames;
  std::vector<TString> m_electronContainerNames;
  std::vector<TString> m_muonContainerNames;

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!

  // this is a standard constructor
  Writer ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(Writer, 1);
};

#endif
