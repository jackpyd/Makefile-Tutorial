.PHONY:v1 v2

DIR = v1 v2

all:$(DIR)

$(DIR):
	make -C $@

clean:
	echo $(shell for dir in $(DIR); do make -C $$dir clean; done)