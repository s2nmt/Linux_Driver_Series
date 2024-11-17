# Đường dẫn đến cross-compiler
CC = /home/s2nmt/work/beagle_bone_black/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc

# Tên tệp thực thi
TARGET = app

# Các tệp nguồn
SRC = app.c led_sys.c

# Cờ biên dịch
CFLAGS = -Wall
.PHONY: all
# Quy tắc mặc định
all: $(TARGET)

# Quy tắc để tạo tệp thực thi
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Quy tắc dọn dẹp
clean:
	rm -f $(TARGET)

