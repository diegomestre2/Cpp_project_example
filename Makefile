.PHONY: all release debug
all: release

GENERATOR=
FORCE_COLOR=
ifeq ($(GEN),ninja)
	GENERATOR=-G "Ninja"
	FORCE_COLOR=-DFORCE_COLORED_OUTPUT=1
endif

clean:
	@rm -drf build

release:
	@mkdir -p build/release && \
	cd build/release && \
	cmake  $(GENERATOR) $(FORCE_COLOR) -DCMAKE_BUILD_TYPE=Release ../.. && \
	cmake --build .

debug:
	@mkdir -p build/debug && \
	cd build/debug && \
	cmake $(GENERATOR) $(FORCE_COLOR) -DCMAKE_BUILD_TYPE=Debug ../.. && \
	cmake --build .