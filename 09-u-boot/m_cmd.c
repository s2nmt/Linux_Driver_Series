#include <common.h>
#include <command.h>
#include <linux/compiler.h>

#define CONFIG_MAX_ARGS 	4
#define CONFIG_REPEATABLE	1
#define USAGE			"print hello world"
#define HELP			"u-boot command line"


int do_mcmd(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int i;
	printf("##########################\n");
	printf("\nHello U-boot CMD\n");
	printf("##########################\n");

	for (i = 0; i < argc; i ++)
	{
		printf("%s-%d: argv[%d]: %s\n", __func__, __LINE__, i + 1, argv[i]);
	}

        return 0;
}




U_BOOT_CMD(
        mcmd, CONFIG_MAX_ARGS, CONFIG_REPEATABLE, do_mcmd,
        USAGE,
	HELP
);
