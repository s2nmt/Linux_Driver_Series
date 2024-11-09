#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/m_cdev"
#define IOCTL_MAGIC 'k'
#define IOCTL_FUNC1 _IO(IOCTL_MAGIC, 1)
#define IOCTL_FUNC2 _IO(IOCTL_MAGIC, 2)

int main() {
    int fd;
    int choice;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return EXIT_FAILURE;
    }

    // Get user input
    printf("Enter 1 to call function1, 2 to call function2: ");
    scanf("%d", &choice);

    // Use ioctl to call the desired function in the kernel module
    if (choice == 1) {
        if (ioctl(fd, IOCTL_FUNC1) < 0) {
            perror("Failed to call ioctl for function1");
        } else {
            printf("Function 1 called successfully.\n");
        }
    } else if (choice == 2) {
        if (ioctl(fd, IOCTL_FUNC2) < 0) {
            perror("Failed to call ioctl for function2");
        } else {
            printf("Function 2 called successfully.\n");
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    // Close the device
    close(fd);
    return EXIT_SUCCESS;
}
