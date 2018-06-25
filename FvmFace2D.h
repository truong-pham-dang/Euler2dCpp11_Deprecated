#include <vector>
#include "Vector2D.h"
#include "Cell2D.h"

class FvmFace2D, public: face{
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
