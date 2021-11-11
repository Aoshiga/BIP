#include<../drbip>
#include<HelloPackageTypes.hpp>
#include<map>
#include<list>
#include<set>
using namespace HelloPackage;

namespace reconfigure {

    class HelloPackageMap {
        public:
            list<Node*> nodes;

            Node * create() {
                return new Node();
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

            void insert(Node * node) {
                nodes.push_front(node);
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


            AT_HELLO * findFirstHello(HelloPackageMap & map) {
                Node * first = map.getFirstHello();
                assert(first != NULL);

                for(auto elem = nodeMap.begin(); elem != nodeMap.end(); ++elem)
                    if(elem->second == first)
                        return (AT_HELLO*) elem->first;

                assert(false);
                return NULL;
            }

            AT_HELLO * findLastHello(PlatoonMap & map) {
                Node * last = map.getLastHello();
                assert(last != NULL);

                for(auto elem = nodeMap.end(); elem != nodeMap.begin(); --elem)
                    if(elem->second == last)
                        return (AT_HELLO*) elem->first;

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

            set<AT_HELLO*>* getAllHello() {
                set<AT_HELLO*>* hello = new set<AT_HELLO*>();

                for(auto elem = nodeMap.begin(); elem != nodeMap.end(); ++elem)
                    hello->insert((AT_HELLO*) elem->first);

                return hello;
            }

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
    }
}