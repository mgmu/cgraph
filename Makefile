GPP=g++ -std=c++11 -Wall

all: test_1 test_2 test_3 test_4 test_5

Vertex.o: Vertex.cpp Vertex.hpp
	$(GPP) -c $^

Edge.o: Edge.cpp Edge.hpp
	$(GPP) -c $^

Graph.o: Graph.cpp Graph.hpp Vertex.hpp Edge.hpp GarbageCollector.hpp
	$(GPP) -c $^

GarbageCollector.o: GarbageCollector.cpp GarbageCollector.hpp Vertex.hpp Edge.hpp
	$(GPP) -c $^

Test_1.o: Test_1.cpp Vertex.hpp GarbageCollector.hpp
	$(GPP) -c $^

Test_2.o: Test_2.cpp Vertex.hpp Edge.hpp GarbageCollector.hpp
	$(GPP) -c $^

Test_3.o: Test_3.cpp Vertex.hpp Edge.hpp GarbageCollector.hpp
	$(GPP) -c $^

Test_4.o: Test_4.cpp Vertex.hpp Edge.hpp GarbageCollector.hpp
	$(GPP) -c $^

Test_5.o: Test_5.cpp Vertex.hpp Edge.hpp GarbageCollector.hpp Graph.hpp
	$(GPP) -c $^

clean:
	rm -rf *.o *~ *.gch test_*

test_1: Test_1.o Vertex.o GarbageCollector.o
	$(GPP) -o $@ $^

test_2: Test_2.o Vertex.o Edge.o GarbageCollector.o
	$(GPP) -o $@ $^

test_3: Test_3.o Vertex.o Edge.o Graph.o GarbageCollector.o
	$(GPP) -o $@ $^

test_4: Test_4.o Vertex.o Edge.o Graph.o GarbageCollector.o
	$(GPP) -o $@ $^

test_5: Test_5.o Vertex.o Edge.o Graph.o GarbageCollector.o
	$(GPP) -o $@ $^

test_1_memcheck: test_1
	valgrind --leak-check=full ./$<

test_2_memcheck: test_2
	valgrind --leak-check=full ./$<

test_3_memcheck: test_3
	valgrind --leak-check=full ./$<

test_4_memcheck: test_4
	valgrind --leak-check=full ./$<

test_5_memcheck: test_5
	valgrind --leak-check=full ./$<
