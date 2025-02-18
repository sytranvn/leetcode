# TODO: this is not completed
# make it dynamically build subdirectory
# make it run test
# create template for new problem
# ignore built files
#
OBJ=build/obj/
BIN=build/bin/
TEST=build/test/
LIBS=cmocka
CFLAGS:=$(shell pkg-config --cflags --libs $(LIBS))

EXCLUDE_DIRS=$(subst /$,, include template build)

PROBLEMS = $(filter-out $(EXCLUDE_DIRS), $(subst /$,,$(wildcard */)))

all: build

build: $(OBJ) $(BIN) $(TEST) $(addprefix $(BIN), $(PROBLEMS)) $(addprefix $(TEST), $(PROBLEMS))

$(OBJ):
	mkdir -p $@

$(BIN):
	mkdir -p $@

$(TEST):
	mkdir -p $@

$(OBJ)%.o: %/%.c | $(OBJ)
	$(CC) -c $< -o $@

$(BIN)%: %/solution.o %/main.o | $(BIN)
	$(CC) $^ -o $@

$(TEST)%: %/solution.o %/test.o | $(TEST)
	$(CC) $(CFLAGS) $^ -o $@

new:
ifdef PID
	mkdir -p ${PID}
	cp template/* ${PID}/
else
	@echo missing PID
endif

clean:
	$(RM) -rf $(BIN) $(OBJ) $(TEST)

test: $(addsuffix _test_run, $(addprefix $(TEST), $(PROBLEMS)))

%_test_run: %
	./$<

