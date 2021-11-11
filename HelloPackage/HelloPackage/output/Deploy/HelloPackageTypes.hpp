#ifndef BIPMODEL_HelloPackage
#define BIPMODEL_HelloPackage 1
/*
 * This file contains all types that are specific to the BIP model from which it is generated
 */

// User include given in @cpp annotation
#include <stdio.h>

// #include <BipError.hpp>
// #include <UnexpectedEventError.hpp>
// #include <AtomInvariantViolationError.hpp>
// #include <CompoundInvariantViolationError.hpp>
#include <AtomExternalPort.hpp>
#include <BIPEngine.hpp>

#include <signal.h>
#include <unistd.h>
#include <bits/stdc++.h> 

#include <assert.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <stack>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>

using namespace bipscheduler;

namespace HelloPackage {

	/*
	 * Atomic Components
	 */

	
	
	class AT__HELLO : public AtomType {
	 public:
		static unsigned int icounter;
		unsigned int sid;
		unsigned int icount;
	
	  // bitvector encoding state
	  unsigned int _state[2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0)];
	
	  // component parameters
	  int _param__id;
	
	
	  // transitions of ports
	  unsigned int _transition__p;
	;
	
		AT__HELLO( int   _param__id ) {
			this->_param__id = _param__id;
		
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
		ErrorType initialize() override {
			// update state of c1
			for (unsigned int i = 0 ; i < 2/(8*sizeof(unsigned int))+((2%(8*sizeof(unsigned int))) > 0 ? 1 : 0) ; ++i) {
			  _state[i] = 0;
			}
			// check for non 1-safety
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  return NON_ONE_SAFE_PETRI_NET;
			}
			
			_state[0/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
			
			
			
			this->_transition__p = 0;
			
			if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
			  assert(this->_transition__p == 0);
			
			  this->_transition__p = 1;
			}
	
			return NO_ERROR;
		}
	
	//internal port 
		ErrorType port_p() {
		  ErrorType error = NO_ERROR;
		
		  switch (this->_transition__p) {
		    case 1:
		      // execute transition of line TO BE DONE
		      assert((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0);
		      
		      // update state
		      // check for non 1-safety
		      if ((_state[1/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 1%(8*sizeof(unsigned int)))) != 0) {
		        return NON_ONE_SAFE_PETRI_NET;
		      }
		      _state[0/(8*sizeof(unsigned int))] &= ~(((unsigned int) 1) << 0%(8*sizeof(unsigned int)));
		      _state[1/(8*sizeof(unsigned int))] |= (((unsigned int) 1) << 1%(8*sizeof(unsigned int)));
		      
		      // execute transition actions
		      printf("Hello from %d\n", this->_param__id);
		  
		  
		      break;
		  
		    default:
		      assert(false);
		  }
		  
		  this->_transition__p = 0;
		  
		  if ((_state[0/(8*sizeof(unsigned int))] & (((unsigned int) 1) << 0%(8*sizeof(unsigned int)))) != 0) {
		    assert(this->_transition__p == 0);
		  
		    this->_transition__p = 1;
		  }
		
		  return error;
		}
	
		
	
	
	
		void tracename(ostream & out) override {
			out  << "HELLO_" << sid << "_" << icount;
		}
	
		void dumpState(ostream & out) override {
		
		}
	
	 };
	unsigned int AT__HELLO::icounter = 0;
	
	// --- Begin Parametric Data Objects
	
	// Forward Declarations
	
	class SetAT__HELLO;
	
	// Field Accessors
	
	// DATA
	
	// External Ports
	class AT__HELLO__transition__p {
		public:
			SetAT__HELLO* set;
			AT__HELLO__transition__p(SetAT__HELLO* par) { set = par; }
			AT__HELLO__transition__p & operator=(const unsigned int value);
			bool operator==(const unsigned int value);
			bool operator!=(const unsigned int value);
			bool operator<=(const unsigned int value);
			bool operator>=(const unsigned int value);
			bool operator>(const unsigned int value);
			bool operator<(const unsigned int value);
	};
	;
	
	// Parametric Containers
	
	class SetAT__HELLO {
		public:
			set<AT__HELLO*>* elems;
			int size() { assert(elems != NULL); return elems->size(); }
		AT__HELLO__transition__p _transition__p = AT__HELLO__transition__p(this);
	
	//internal ports 
	ErrorType port_p() {
	 	ErrorType error = NO_ERROR;
	
		for(auto iter = elems->begin(); iter != elems->end(); iter++) {
			error = (*iter)->port_p();
			if(error != NO_ERROR) return error;
		}
	
		return error;
	}
	};
	
	// Operator Implementation for basic operations
	
	
	AT__HELLO__transition__p & AT__HELLO__transition__p::operator=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			(*iter)->_transition__p = value;
		return *this;
	}
	bool AT__HELLO__transition__p::operator==(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p != value)
				return false;
		return true;
	}
	bool AT__HELLO__transition__p::operator!=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p == value)
				return false;
		return true;
	}
	bool AT__HELLO__transition__p::operator<=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p > value)
				return false;
		return true;
	}
	bool AT__HELLO__transition__p::operator>=(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p < value)
				return false;
		return true;
	}
	bool AT__HELLO__transition__p::operator>(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p <= value)
				return false;
		return true;
	}
	bool AT__HELLO__transition__p::operator<(const unsigned int value) {
		for(auto iter = set->elems->begin(); iter != set->elems->end(); iter++)
			if((*iter)->_transition__p >= value)
				return false;
		return true;
	}
	// --- End Parametric Data Objects
	




	/*
	 * BIP System
	 */

  class CT__HelloCompound : public BIPSystem {
   public:


    mutable unsigned int interactions;
    mutable unsigned int internals;
    mutable unsigned int externals;
    mutable unsigned int waiting;

	void initialize() override {
		for (auto it= components.begin(); it!=components.end(); ++it)
		    (*it)->initialize();
	}

  };

	/*
	 * Glue
	 */






  // Type encoding for connectors
	class Alone : public Interaction {
	
	
		public:
		static unsigned int icounter;
		unsigned int icount = 0;
		unsigned int sid = 0;
		
		
		bool enabled = false;
		
		
	
		AT__HELLO* _atom_1;
	
		Alone(AT__HELLO* _atom_1) {
			assert(_atom_1 != NULL);
			this->_atom_1 = _atom_1;
			icount = (icounter++) % INT_MAX;
			sid    = bipscheduler::TRACE_SID;
		}
	
		void tracename(ostream & out) override {
			out  << "Alone_" << sid << "_" << icount;
		}
	
		bool isEnabled() override {
			return enabled;
		}
	
		bool checkSetEnabled() override {
		
	
	
			enabled = (_atom_1->_transition__p != 0);
	
	
			return enabled;
		}
		ErrorType execute() {
			ErrorType error = NO_ERROR;
			
			bool _action_1 = (_atom_1->_transition__p != 0);
			
			  if (_action_1) {
			    // execute ports 'c1.p'
			    error = _atom_1->port_p();
			    
			    if (error != NO_ERROR) {
			      return error;
			    }
			  }
	
			return error;
		}
		void print() override {
			if(enabled)
				cout << "(Enabled) ";
	
			cout << this;
	
			cout << " Alone: ";
	
			cout << _atom_1;
			cout << ".";
			cout << "HelloPort_t";
			cout << "(";
			cout << ")";
		}
	};
	unsigned int Alone::icounter = 0;



	CT__HelloCompound modelroot;

	void initializeModel() {
		// Set the root pointer to the correct system
		root = (BIPSystem*) &modelroot;

		// Call the initialization of the reconfiguration layer
		reconfigure::init();
	
		// Model imported initialization
		// Uncomment these to execute the initial provided BIP model
		/*
		modelroot.components.push_back(new AT__HELLO(1));
		modelroot.components.push_back(new AT__HELLO(2));
		modelroot.components.push_back(new AT__HELLO(3));

		IPool * connectors = poolCreate();

		connectors->insert(
			  	new Alone(
					(AT__HELLO*) modelroot.components.at(0)
				)
			);
		*/
	}

}

#endif
