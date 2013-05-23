
compile:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir || exit $?; \
	done

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done
	rm -rf *.o *.i *.s $(TARGET)
	
