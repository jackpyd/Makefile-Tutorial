A := 123

define FUNC1
	@echo -------func1-------
	echo arg: $(0) $(1) $(2)
	@echo -------------------
endef

define FUNC2
	@echo -------func2-------
	echo return 123
	@echo -------------------
endef

define FUNC3
	@echo -------func3-------
	echo $(shell ls)
	@echo -------------------
endef

all:
	$(call FUNC1, $(A), asd)
	$(call FUNC2)
	$(call FUNC3)
