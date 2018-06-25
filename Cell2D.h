#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include "MyPoint.h"
#include "GmshReader.h"

class face {
public:
	MyPoint p1, p2;
	int bc_typ;
	unsigned idface;
	double area = 0.0;
	MyPoint centroid;
};

class Cell2D : public MyPoint {
public: 
	unsigned ident = 0;
	MyPoint vertex[4];
	face faces[4];
	Cell2D *neighbor1 = nullptr;
	Cell2D *neighbor2 = nullptr;
	Cell2D *neighbor3 = nullptr;
	Cell2D *neighbor4 = nullptr;
	double vol = 0.0;
	void calcul_vol();
};

class ListCell2D : public Cell2D {
public:
	unsigned nbfaces;
	GmshReader msh_reader;
	vector<Cell2D> cells;
	void assign_vextex();
	void assign_faces();
	void assign_boundary_condition();
	void detect_nearest_neighbor();
	void calcul_vol_cells();
	void write_vtk();
};


