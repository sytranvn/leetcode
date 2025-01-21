# TODO: this is not completed
# make it dynamically build subdirectory
# make it run test
# create template for new problem
# ignore built files
#
OBJ=build/obj/
BIN=build/bin/
PID:=problem_id

EXCLUDE_DIRS=$(subst /$,, include template build)

PROBLEMS = $(filter-out $(EXCLUDE_DIRS), $(subst /$,,$(wildcard */)))

all: build test

build: $(OBJ) $(BIN) $(addprefix $(BIN), $(PROBLEMS))

$(OBJ):
	mkdir -p $@

$(BIN):
	mkdir -p $@

$(OBJ)%.o: %/main.c | $(OBJ)
	$(CC) -c $< -o $@

$(BIN)%: $(OBJ)%.o | $(BIN)
	$(CC) $< -o $@

test:
	for P in $(PROBLEMS); do \
		for f in $$P/in*; do \
			"$(BIN)/$$P" < "$$f" | diff $${f/in/out} -; \
			if [ "$$?" -ne 0 ]; then \
				echo $$f Failed; \
				exit 1; \
			else \
				echo $$f Passed; \
			fi; \
		done; \
	done

new:
	mkdir -p ${PID}
	touch ${PID}/${PID}.{c}
	touch ${PID}/{in,out}

clean:
	rm -rf $(BIN) $(OBJ)
