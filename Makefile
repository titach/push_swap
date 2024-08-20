CC=cc
CFLAGS=-Wall -Wextra -Werror


# ชื่อของโปรแกรม
NAME=push_swap

# ไฟล์ทั้งหมดที่เกี่ยวข้อง
SRCS=check_int.c main.c push_swap.c pushint_free.c rotate_reverse.c sort_four.c sort_four2.c sorting_stack.c tool_extend.c utils.c radix_sort.c
OBJS=$(SRCS:.c=.o)
HEADER=push_swap.h
# กฎสำหรับการคอมไพล์ .c เป็น .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# กฎสำหรับการสร้างโปรแกรมหลัก
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# กฎสำหรับสร้างทุกอย่าง
all: $(NAME)
# $(NAME): $(OBJS)
# 	@if [ ! -f $(NAME) ]; then \
# 		$(CC) $(CFLAGS) $(OBJS) -o $(NAME); \
# 	fi

# กฎสำหรับการลบไฟล์ที่สร้างจากการคอมไพล์
clean:
	rm -f $(OBJS)

# กฎสำหรับการลบไฟล์ทั้งหมด
fclean: clean
	rm -f $(NAME)

# กฎสำหรับการสร้างทุกอย่างใหม่
re: fclean all

# กฎสำหรับไม่ต้องพิจารณาไฟล์ชั่วคราวหรือโปรแกรมที่มีชื่อเหมือนกัน
.PHONY: all clean fclean re