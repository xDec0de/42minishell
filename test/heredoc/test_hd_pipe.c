#include "ms_assertions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *read_file(const char *path)
{
    FILE *f = fopen(path, "r");
    if (!f)
        return NULL;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = malloc(size + 1);
    fread(buf, 1, size, f);
    buf[size] = '\0';
    fclose(f);
    return buf;
}

static int str_contains(const char *haystack, const char *needle)
{
    return strstr(haystack, needle) != NULL;
}

int main(void)
{
    const char *script = "cat <<EOF | grep hi\nhi there\nEOF\nexit\n";
    FILE *f = fopen("tmp_pipe.sh", "w");
    fputs(script, f);
    fclose(f);
    int ms_status = system("./minishell < tmp_pipe.sh > ms_pipe.txt 2>&1");
    int bash_status = system("bash --noprofile --norc < tmp_pipe.sh > bash_pipe.txt 2>&1");
    char *ms = read_file("ms_pipe.txt");
    char *bash = read_file("bash_pipe.txt");
    ASSERT_TRUE(str_contains(bash, "hi there"));
    ASSERT_TRUE(str_contains(ms, "hi there"));
    ASSERT_TRUE(ms_status == 0);
    ASSERT_TRUE(bash_status == 0);
    free(ms);
    free(bash);
    remove("tmp_pipe.sh");
}
