OS ?= $(shell uname -s)

ifeq ($(OS), Darwin)
	CC=clang
	# on darwin, the linker complains about missing fns such as _main
	# even when building a shared object
	LINKER_FLAGS=-Wl,-undefined -Wl,dynamic_lookup
else ifeq($(OS), Linux)
	CC=gcc
	LINKER_FLAGS=
else
	CC=
	LINKER_FLAGS=
endif

NODE_VERSION=$(shell node -v | cut -c2-)

INCLUDES=-I./ -I./lib/$(NODE_VERSION)/include/node

# generate a shared lib with debug symbols and debug safe
# optimizations cuz this is an example
CFLAGS=-fPIC -shared -g -Og $(LINKER_FLAGS) $(INCLUDES)

SOURCES=addon.c

BUILD_DIR=./.build

build: clean ensure
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)/addon.node

ensure:
	mkdir -p $(BUILD_DIR)
	npm run prep-node-headers # we invoke node-gyp via npm so that node-gyp that ships with npm is used

clean:
	rm -fr $(BUILD_DIR)

dump: $(BUILD_DIR)/addon.node
	objdump -Sds $(BUILD_DIR)/addon.node

.PHONY: all build ensure clean dump
