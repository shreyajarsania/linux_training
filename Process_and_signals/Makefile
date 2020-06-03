DIRECTORIES = $(wildcard */)
all:
	for directory in $(DIRECTORIES); do\
                make -C $$directory ;\
        done
clean:
	for directory in $(DIRECTORIES); do\
                make clean -C $$directory ;\
        done                            
