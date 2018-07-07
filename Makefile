CC         = g++
CXXFLAGS   = -O3 -std=c++11
LD         = g++
LDFLAGS    = -std=c++11
PREPROC    = 

OBJS =  main.o  \
	Mesh2D.o  \
	GmshReader.o  \
	MyPoint.o  \
	Vector2D.o  \


.SUFFIXES: .o .cpp
.cpp.o:
	$(LD) -c $(CXXFLAGS) $<

Euler2dCpp11.exe :$(OBJS) 
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

clean :
	rm -f Euler2dCpp11.exe *.o