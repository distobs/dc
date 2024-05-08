all: dc

dc:
	cd src && make

test:
	cd test && sh test_dc.sh

clean:
	rm ./src/dc

.PHONY: test clean
