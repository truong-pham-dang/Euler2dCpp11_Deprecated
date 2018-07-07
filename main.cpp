#include <iostream>
#include <chrono>
#include "Mesh2D.h"

using namespace std;
using namespace std::chrono;

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	ListCell2D list_cell;

	// Mesh reading process

	list_cell.msh_reader.GmshLoadMesh();

	// Preprocessing:

	list_cell.preProcessing();

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(t2 - t1).count();

	cout << duration << " seconds." << endl;

    return 0;
}
