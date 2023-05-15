#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-w -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(OBJ): $(SRC)
	@echo "Compilando minilibX..."
	@$(CC) $(CFLAGS) -c $(SRC)

$(NOM):	$(OBJ)
	@echo "Generando libreria minilibX..."
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "Borrando archivos de la libreria minilibX..."
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
