#B3WW

CC = gcc
C_FLAGS = -fsanitize=address -g
C_OBJECTS_FLAGS = -g -fsanitize=address -lncurses
HEADERS = -I./includes
OBJECTS = objects

NAME = test

vpath %.c sources
vpath %.c sources/controls
vpath %.c sources/gets
vpath %.c sources/sprites
vpath %.c sources/samples
vpath %.c sources/clocks
vpath %.c sources/ELEMENTS_LISTS
vpath %.c sources/tools

SRC = 	main.c \
\
		init.c \
		end.c \
		display.c \
\
		get_shell_size.c \
\
		sprite_create.c \
		sprite_display.c \
		sprite_set_position.c \
\
		sample_create.c \
\
		clock_create.c \
		clock_update.c \
\
		elist_create.c \
		elist_add.c \
\
		get_file_content.c \
		wstr_to_word_array.c \

OBJ = $(patsubst %.c, $(OBJECTS)/%.o, $(SRC))

all : create_dir $(NAME)

create_dir :| $(OBJECTS)

$(OBJECTS):
	@mkdir -p $@

$(OBJECTS)/%.o: %.c
	@$(CC) -c -o $@ $< $(HEADERS) $(C_FLAGS)
	@echo "-[DONE] $@-"

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(HEADERS) $(C_OBJECTS_FLAGS)
	@echo "-[SUCCESS]-"

re:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"
	@make

clean:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"

fclean:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"
	@rm -f $(NAME)
	@echo "-[RM] $(NAME)-"
