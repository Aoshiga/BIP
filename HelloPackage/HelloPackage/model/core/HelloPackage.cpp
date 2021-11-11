#include<drbip.h>
#include<HelloPackageTypes.hpp>
#include<map>
#include<list>
#include<set>
using namespace HelloPackage;

namespace reconfigure {

    class FirstHello : public CondState<AT__HELLO, 1, 1> {
        FirstHello(AT__HELLO * hello) : CondState(atom) {}
    };

    class MiddleHello : public CondState<AT__HELLO, 2, 1> {
        MiddleHello(AT__HELLO * hello) : CondState(atom) {}
    };

    class LastHello : public CondState<AT__HELLO, 3, 1> {
        LastHello(AT__HELLO * hello) : CondState(atom) {}
    };

    class HelloPackageMap {
        public:
            list<Node*> nodes;

            Node * create() {
                return new Node();
            }

            void insert(Node * node) {
                nodes.push_front(node);
            }

            void assign(HelloPackageMap * helloPackage) {
                nodes.clear();
                nodes = helloPackage->nodes;
            }

            bool isFirst(Node * node) {
                return node == nodes.back();
            }

            bool isLast(Node * node) {
                return node == nodes.front();
            }

            Node * getFirstHello() {
                return nodes.back();
            }
        
            Node * getLastHello() {
                return nodes.front();
            }

            void print() {
                cout << "[DEBUG] [HelloPackageMap] [HELLO] #" << this << ":";
                for(auto elem = nodes.begin(); elem != nodes.end(); ++elem) {
                    cout << " " << *elem;
                }
                cout << " | First: " << getFirstHello();
                cout << endl;
            }
    };

    class HelloPackageAddressing {
        public:
            map<AtomType*, Node*> nodeMap;

            void bind(AtomType* atom, Node* node) {
                nodeMap.insert(pair<AtomType*, Node*>(atom, node));
            }


            AT__HELLO * findFirstHello(HelloPackageMap & map) {
                Node * first = map.getFirstHello();
                assert(first != NULL);

                for(auto elem = nodeMap.begin(); elem != nodeMap.end(); ++elem)
                    if(elem->second == first)
                        return (AT__HELLO*) elem->first;

                assert(false);
                return NULL;
            }

            AT__HELLO * findLastHello(HelloPackageMap & map) {
                Node * last = map.getLastHello();
                assert(last != NULL);

                for(auto elem = nodeMap.end(); elem != nodeMap.begin(); --elem)
                    if(elem->second == last)
                        return (AT__HELLO*) elem->first;

                assert(false);
                return NULL;
            }

            Node * operator()(AtomType * atom) {
                auto value = nodeMap.find(atom);
                if(value != nodeMap.end())
                    return value->second;
                else
                    return NULL;
            }

            /*set<AT__HELLO*>* getAllHello() {
                set<AT__HELLO*>* hello = new set<AT__HELLO*>();

                for(auto elem = nodeMap.begin(); elem != nodeMap.end(); ++elem)
                    hello->insert((AT__HELLO*) elem->first);

                return hello;
            }*/

            HelloPackageAddressing* slice(HelloPackageMap* list) {

                HelloPackageAddressing * res = new HelloPackageAddressing();

                for(auto node = list->nodes.begin(); node != list->nodes.end(); ++node) {
                    for(auto map = nodeMap.begin(); map != nodeMap.end(); ++map) {
                        if(map->second == *node)
                            res->bind(map->first, *node);
                    }
                }

                return res;
            }
    };
}