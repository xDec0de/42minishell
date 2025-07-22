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
    int ms_status = system("printf 'cat <<EOF\\nhello\\nEOF\\nexit\\n' | ./minishell > ms_out.txt 2>&1");
    int bash_status = system("printf 'cat <<EOF\\nhello\\nEOF\\n' | bash --noprofile --norc > bash_out.txt 2>&1");
    char *ms = read_file("ms_out.txt");
    char *bash = read_file("bash_out.txt");
    ASSERT_TRUE(str_contains(ms, "hello"));
    ASSERT_TRUE(str_contains(bash, "hello"));
    ASSERT_TRUE(ms_status == 0);
    ASSERT_TRUE(bash_status == 0);
    free(ms);
    free(bash);
}
