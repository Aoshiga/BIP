#include<drbip.h>
#include<HelloPackage.cpp>
#include<HelloPackageTypes.hpp>
#include <bits/stdc++.h>

using namespace HelloPackage;

namespace reconfigure {

    set<Motif*> motifs;
    set<ExecutableRule*> globalrules;
    const char * const PACK_NAME = "HelloPackage";
    #ifdef PERFMODE
    unsigned int nrules_imr = 0;
    unsigned int nrules_ir  = 0;
    unsigned int nrules_rr  = 0;
    unsigned int nobj_create_atoms = 0;
    unsigned int nobj_destroy_atoms = 0;
    unsigned int nobj_create_motifs = 0;
    unsigned int nobj_destroy_motifs = 0;
    #endif

    class MotifSet {
    public:
        set<AT__HELLO*> S_HELLO;
        int size() {
            int sz = 0;
            sz += S_HELLO.size();
            return sz;
        }
        void tracestate(ostream & out) {
            for(auto iter_0 = S_HELLO.begin(); iter_0 != S_HELLO.end(); iter_0++){
                cout << " ";
                (*iter_0)->tracename(out);
            }
        }
    };
    
    MotifSet global;

    //Spawn functions

    AT__HELLO* spawnHELLO(int arg0) {
        AT__HELLO* obj = new AT__HELLO(arg0);
        global.S_HELLO.insert(obj);
        root->components.insert((AtomType*) obj);
        obj->initialize();
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> spawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_create_atoms++;
            #endif
        return obj;
    }
    void despawnHELLO(AT__HELLO* obj) {
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> despawn component ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_destroy_atoms++;
            #endif
        root->components.erase((AtomType*) obj);
        global.S_HELLO.erase(obj);
        delete obj;
    }


    class HelloPackage : public Motif {
    public:
        MotifSet comps;
        static unsigned int icounter;
        int sid;
        int icount;
        HelloPackageMap structure;
        HelloPackageAddressing address;
        HelloPackage();
        void tracename (ostream & out) override;
        void tracestate(ostream & out) override;
    };
    class firstSayHello : public Rule {
    public:
        HelloPackage* motif;
        IPool * connectors;
        static unsigned int icounter;
        int sid;
        int icount;
        firstSayHello() {
            connectors = poolCreate();
            icount = (icounter++) % INT_MAX;
            sid    = bipscheduler::TRACE_SID;
        }
        virtual Motif* getMotif() { return (Motif*) motif; }
    
        ~firstSayHello() {
            cleanup(connectors);
            poolDelete(connectors);
        }
    
        bool execute() {
            return applyAll();
        }
        bool applyAll() {
            bool applied = false;
            cleanup(connectors);
            SetAT__HELLO* v_all;
            for(auto i_arg_h = motif->comps.S_HELLO.begin(); i_arg_h != motif->comps.S_HELLO.end(); ++i_arg_h ){
                auto v_h = *i_arg_h;
                if(!((motif->comps.size()>1)&&motif->structure.isFirst(motif->address((AtomType*)v_h)))) continue;
                v_all = new SetAT__HELLO();
                v_all->elems = new set<AT__HELLO*>();
                for(auto i_arg_all = motif->comps.S_HELLO.begin(); i_arg_all != motif->comps.S_HELLO.end(); ++i_arg_all ){
                    if(!((*i_arg_all)!=v_h)) continue;
                    v_all->elems->insert(*i_arg_all);
                }
                apply(v_h,v_all);
                applied = true;
            }
            return applied;
        }
        void apply(AT__HELLO* h, SetAT__HELLO* all){
            Interaction * myConnector = new Alone(h);
            connectors->insert(myConnector);
            #ifndef PERFMODE
            cout << "<TRACE> <DRBIP> apply ";
            tracename(cout);
            cout << " with";
            cout << " ";
            h->tracename(cout);
            cout << " ";
            cout << "[ ";
            for(auto piter = all->elems->begin(); piter != all->elems->end(); ++piter) {
                (*piter)->tracename(cout);
                cout << " ";
            }
            cout << "]";
            cout << endl;
            cout << "<TRACE> <DRBIP> spawn interaction ";
            myConnector->tracename(cout);
            cout << " ";
            h->tracename(cout);
            cout << endl;
            #endif
            #ifdef PERFMODE
            nrules_ir++;
            #endif
        }
        bool addTriggers() {
            return false;
        }
    void tracename(ostream & out) {
        out << "IR firstSayHello_" << sid << "_" << icount;
        out << " in ";
        motif->tracename(out);
    }
    };
    unsigned int firstSayHello::icounter = 0;
    
    HelloPackage::HelloPackage(){
        firstSayHello* rule0 = new firstSayHello();
        rule0->motif = this;
        ir.push_back(rule0);
        icount = (icounter++) % INT_MAX;
        sid    = bipscheduler::TRACE_SID;
    }
    void HelloPackage::tracename(ostream & out) {
        out << "HelloPackage_" << sid << "_" << icount;
    }
    void HelloPackage::tracestate(ostream & out) {
        comps.tracestate(out);
    }
    unsigned int HelloPackage::icounter = 0;


    set<HelloPackage*> S_HelloPackage;

    HelloPackage* spawnHelloPackage() {
        HelloPackage* obj = new HelloPackage();
        S_HelloPackage.insert(obj);
        motifs.insert((Motif*) obj);
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> spawn motif ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_create_motifs++;
            #endif
        return obj;
    }
    void despawnHelloPackage(HelloPackage* obj) {
        #ifndef PERFMODE
        cout << "<TRACE> <DRBIP> despawn motif ";
        obj->tracename(cout);
        cout << endl;
        #endif
            #ifdef PERFMODE
            nobj_destroy_motifs++;
            #endif
        S_HelloPackage.erase(obj);
        motifs.erase((Motif*) obj);
        delete obj;
    }


    void initializer() {
        HelloPackage* hi=spawnHelloPackage();
        set<int >* v_i = seq(0, 100);
        auto i = v_i->begin();
        while(i != v_i->end()) {
            AT__HELLO* newHello=spawnHELLO((*i));
            Node* node=hi->structure.create();
            hi->address.bind(newHello, node);
            hi->structure.insert(node);
            (hi->comps.S_HELLO).insert(newHello);
            ++i;
        }
        if(v_i != NULL) delete v_i;
    }
}
