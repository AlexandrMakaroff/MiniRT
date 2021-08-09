.PHONY = all clean fclean re bonus
NAME = miniRT
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = change_cam.c \
check_elems.c \
check_figures.c \
inter_cylinder.c \
inter_pl_sq.c \
inter_sphere.c \
inter_triangle.c \
minirt.c \
new_elements1.c \
new_elements2.c \
parser.c \
ray_tracing.c \
set.c \
to_bmp.c \
trace_ray.c \
utils1.c \
utils2.c \
vec_operations1.c \
vec_operations2.c \
wrapper.c \
ft_error.c \
chec_elems2.c

all:	$(NAME)
$(NAME): $(OBJS)
	make -C ./libft
	make -C ./mlx
	${CC} ${FLAGS} libft/libft.a mlx/libmlx.a mlx/libmlx.a -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	@$(RM) $(OBJS)

fclean:	clean
	make fclean -C ./libft
	@$(RM) $(NAME)

re:	fclean all