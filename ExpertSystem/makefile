SRC=ExpertSystem.java\
MegaNode.java\
Node.java\
NpiConverter.java\
Operations.java\
State.java
OBJ=ExpertSystem.class\
MegaNode.class\
Node.class\
NpiConverter.class\
Operations.class\
State.class
NAME="ExpertSystem"

$(NAME) :
	@javac -d bin src/MainPackage/*.java
	@echo "Building done !"

all : $(NAME)

clean :
	@/bin/rm -f $(OBJ)
	@echo "Cleaning done !"

fclean : clean

re : fclean all

ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

run :
	@java -cp "./bin/" MainPackage.ExpertSystem $(RUN_ARGS)


