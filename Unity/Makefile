ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean
.PHONY: test

TEST_PREFIX = Test
RUNNER_SUFFIX = _Runner

# Folder Structure
PATHU = Unity/
PATHS = Source/
PATHT = Test/
PATHB = Build/Test/
PATHD = Build/Test/Depends/
PATHO = Build/Test/Objs/
PATHR = Build/Test/Results/
PATHTR = Test/TestRunners/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

# Source test files
SRCT = $(wildcard $(PATHT)*.c)

# Test results
RESULTS = $(patsubst $(PATHT)$(TEST_PREFIX)%.c,$(PATHR)$(TEST_PREFIX)%.txt,$(SRCT))

# Targets for the test files
TARGETS = $(patsubst $(PATHT)$(TEST_PREFIX)%.c,$(PATHO)%.o,$(SRCT))

# Compiler options
# Compile, but do not link.
COMPILE=gcc -c
# Linking
LINK=gcc
DEPEND=gcc -MM -MG -MF

# Optimization
OPT=-O0
# Defines
DEFINES= -DTARGET_HOST
# Build flags
CFLAGS= -Wall -g $(OPT) $(DEFINES)

INC_DIRS=-I$(PATHS) -I$(PATHU)
SYMBOLS=

# Process report files
PASSED = `grep -s PASS $(PATHR)*.txt`
TPASSED = `grep -s PASS $(PATHR)*.txt | wc -l`

FAIL = `grep -s FAIL $(PATHR)*.txt`
TFAIL = $(shell expr `grep -s FAIL $(PATHR)*.txt | wc -l` - 1)

IGNORE = `grep -s IGNORE $(PATHR)*.txt`
TIGNORE = `grep -s IGNORE $(PATHR)*.txt | wc -l`

all: test

test: $(BUILD_PATHS) $(RESULTS)
	@echo "Results file -> $(RESULTS)"
	@echo "Target files -> $(TARGETS)"
	@echo "(TARGETS)"
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "-----------------------\nSUMMARY:\n-----------------------"
	@echo "Ignore tests: \t$(TIGNORE)"
	@echo "Fail tests: \t$(TFAIL)"
	@echo "Passed tests: \t$(TPASSED)"
	@echo "\nREPORT DONE"

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	@echo "Create report -> $@"
	-./$< > $@ 2>&1

$(PATHB)%.$(TARGET_EXTENSION): $(PATHO)unity.o $(PATHO)%.o $(PATHO)%$(RUNNER_SUFFIX).o $(TARGETS) #$(PATHD)%.d
	@echo "Linking -> $@"
	$(LINK) -o $@ $^

$(PATHO)%.o:: $(PATHTR)%.c
	@echo "Compile test runners -> $@"
	$(COMPILE) $(CFLAGS) $(INC_DIRS) $< -o $@

$(PATHO)%.o:: $(PATHT)%.c
	@echo "Compile tests -> $@"
	$(COMPILE) $(CFLAGS) $(INC_DIRS) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c
	@echo "Compile source -> $@"
	$(COMPILE) $(CFLAGS) $(INC_DIRS) $< -o $@

$(PATHO)%.o:: $(PATHU)%.c $(PATHU)%.h
	@echo "Compile unity -> $@"
	$(COMPILE) $(CFLAGS) $(INC_DIRS) $< -o $@

$(PATHD)%.d:: $(PATHTR)%.c
	@echo "Compile dependency"
	$(DEPEND) $@ $<

# Build direcotory
$(PATHD)%.d:: $(PATHT)%.c
	@echo "Compile dependency"
	$(DEPEND) $@ $<

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	@echo "Clean objects, binary files and test results"
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt


.PRECIOUS: $(PATHB)Test%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
