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
    const char *script = "cat <<EOF1 <<EOF2\nA\nEOF1\nB\nEOF2\nexit\n";
    FILE *f = fopen("tmp_script.sh", "w");
    fputs(script, f);
    fclose(f);
    int ms_status = system("./minishell < tmp_script.sh > ms_multi.txt 2>&1");
    int bash_status = system("bash --noprofile --norc < tmp_script.sh > bash_multi.txt 2>&1");
    char *ms = read_file("ms_multi.txt");
    char *bash = read_file("bash_multi.txt");
    ASSERT_TRUE(str_contains(bash, "B"));
    ASSERT_TRUE(str_contains(ms, "B"));
    ASSERT_TRUE(ms_status == 0);
    ASSERT_TRUE(bash_status == 0);
    free(ms);
    free(bash);
    remove("tmp_script.sh");
}
