#
# CFG
#

LIBS    = `pkg-config --cflags --libs raylib`
CFLAGS += -std=c99 -Wall -Wextra $(LIBS)

#
# CLI
#

.PHONY: build
build: bin/main;

.PHONY: help
help:
	@echo "make build - build the project"
	@echo "make run   - run the project"
	@echo "make fmt   - format the source code"
	@echo "make deps  - install dependencies"

.PHONY: fmt
fmt:
	find . -name '*.c'  | xargs clang-format -i

.PHONY: deps
deps:
	brew install clang-format pkg-config raylib

.PHONY: clean
clean:
	rm -rf bin

#
# OUT
#

bin/main: src/main.c
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^
