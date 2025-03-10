CC = mpicc
CFLAGS = -g -Wall -I$(IDIR)
BDIR=exercise$(EX)/build
SDIR=exercise$(EX)/src
IDIR=exercise$(EX)/include

SRCS = $(wildcard $(SDIR)/*.c)
OBJ = $(SRCS:$(SDIR)/%.c=$(BDIR)/%.o)

default: $(BDIR)/ex$(EX)

$(BDIR):
	@mkdir -p $(BDIR)

$(BDIR)/ex$(EX): $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(BDIR)/%.o: $(SDIR)/%.c $(IDIR)/*.h | $(BDIR)
	@$(CC) -c $< -o $@ $(CFLAGS)

run:
	@mpiexec -n (PROCS)./$(BDIR)/ex$(EX) $(ARGS)
	
clean: 
	@rm -f $(BDIR)/*.o $(BDIR)/ex$(EX)
# // make EX=..
# // make clean EX=..
# // make run EX=.. ARGS=".."