#include <vector>
#include <iostream>
#include <sstream>
#include "MyPoint.h"
#include "streamIO.h"

using namespace std;

struct node_ident
{
    vector<unsigned> id_node;
};

struct node_ident_msh: public node_ident
{
    unsigned ident;
    unsigned elem_typ;
    unsigned nb_tags;
    unsigned tag1;
    unsigned tag2;
};

class GmshReader : public MyPoint{

public:
    unsigned nbnode;
    unsigned nbel_msh;
    unsigned nbelm;
    string fname;

    GmshReader();
	void GmshLoadMesh();
    vector<MyPoint> coord_nodes;
    vector<node_ident> id_nodes;
    vector<node_ident_msh> id_nodes_msh;

private:
	void read_mesh();
	void construct_id_nodes();
	GmshReader(const GmshReader &gmshReader);             // override default copy constructor
	GmshReader & operator = (const GmshReader &gmshReader); // and assignment operator

};

