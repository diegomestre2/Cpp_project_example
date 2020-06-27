# Defines special targets or phony files
.PHONY: clean all
all: main debug

# Ninja is build system that speeds up compilation, more in: https://ninja-build.org/
GENERATOR=
FORCE_COLOR=
ifeq ($(GEN),ninja)
	GENERATOR=-G "Ninja"
	FORCE_COLOR=-DFORCE_COLORED_OUTPUT=1
endif

clean:
	@rm -drf build

main:
	@mkdir -p build/release && \
	cd build/release && \
	cmake  $(GENERATOR) $(FORCE_COLOR) -DCMAKE_BUILD_TYPE=Release ../.. && \
	cmake --build .

debug:
	@mkdir -p build/debug && \
	cd build/debug && \
	cmake $(GENERATOR) $(FORCE_COLOR) -DCMAKE_BUILD_TYPE=Debug ../.. && \
	cmake --build .

format: