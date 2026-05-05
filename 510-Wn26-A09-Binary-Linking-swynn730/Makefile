all:
	for d in LoadTimeLinking; \
	do \
		$(MAKE) -j --directory=$$d all; \
	done

clean:
	for d in LoadTimeLinking; \
	do \
		$(MAKE) --directory=$$d clean; \
	done
