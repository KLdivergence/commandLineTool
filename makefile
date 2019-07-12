CFLAGS=-I
test: prebuild_test_main.o hello.o
# 	echo "good"
	g++ -o $@ $^ -lstdc++ -L/home/user/ysun/bin/boost/include/ -lboost_program_options 
	# g++ -o test prebuild_test_main.o -lstdc++ -L/home/user/ysun/bin/boost/include/ -lboost_program_options 


prebuild_test_main.o: prebuild_test_main.cxx hello.h
	g++ $< -c -o $@ 
	# g++ prebuild_test_main.cxx -c -o prebuild_test_main.o

hello.o: hello.cxx hello.h
	g++ $< -c -o $@ 

clean:
	rm -rf *.o

