a.out: KNN.o knnClass.o distances.o pair.o
	g++ KNN.o knnClass.o distances.o pair.o -o a.out
	
KNN.o:
	g++ -std=c++11 -c KNN.cpp KNN.h
	
knnClass.o:
	g++ -std=c++11 -c knnClass.cpp knnClass.h
	
distances.o:
	g++ -std=c++11 -c distances.cpp distances.h

pair.o:
	g++ -std=c++11 -c pair.cpp pair.h
	
target: dependencies
	action
	
clean:
	rm *.o *.h.gch a.out