DEPS= stack

compile: main2.cpp 
	 g++ main2.cpp -o $(DEPS)

run: $(DEPS)
	 ./$(DEPS)

clean: $(DEPS)
	 rm $(DEPS)
