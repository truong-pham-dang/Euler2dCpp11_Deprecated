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
#include "Vector2D.h"

class face {
public:
	MyPoint p1, p2;
	int bc_typ;
	unsigned idface;
	double area = 0.0;
	MyPoint centroid;
	void calcul_area_face();
	void calcul_mid_point();
};

class Cell2D {
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

class ListCell2D {
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
	void calcul_area_cent_faces();
};

class FvmFace2D: public face{
	Vector2d normal_vector;
	Vector2d tangent_vector;
	Cell2D *left_cell  = nullptr;
	Cell2D *right_cell = nullptr;
	double   len_nor;
	double   len_tan;
};

class ListFvmFace2D {
public:
	vector<FvmFace2D> face_2D;
	ListCell2D *short_cut;
};

