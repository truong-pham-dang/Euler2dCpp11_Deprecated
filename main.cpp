#include <iostream>
#include <chrono>
#include "Cell2D.h"

using namespace std;
using namespace std::chrono;

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	ListCell2D list_cell;

	// Mesh reading process

	list_cell.msh_reader.GmshLoadMesh();

	list_cell.assign_vextex();
	list_cell.assign_faces();
	list_cell.assign_boundary_condition();
	list_cell.detect_nearest_neighbor();
	list_cell.write_vtk();

	// Calculate some geometry information
	list_cell.calcul_vol_cells();

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(t2 - t1).count();

	cout << duration << " seconds." << endl;

    return 0;
}
