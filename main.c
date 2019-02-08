

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_element
{
    char *key;
    char *val;
    struct hash_element *next;
};

struct hash_element **inittable(int size);
int simple_hash(char *seed);
void insert(struct hash_element **table, char *key, char *val);
char *get(struct hash_element **table, char *key);

int main(int argc, char *argv[])
{
    // int table_size = 10;
    // int *table = inittable(table_size);

    // for (int i = 0; i < table_size; i++)
    // {
    //     printf("%d\n", table[i]);
    // }

    // char *sample_str = "sample string";
    // char *sample_str1 = "seeample string";
    // char *sample_str2 = "sample string33";
    // char *sample_str3 = "sample string33few";

    // int hash_value = simple_hash(sample_str);
    // int hash_value1 = simple_hash(sample_str1);
    // int hash_value2 = simple_hash(sample_str2);
    // int hash_value3 = simple_hash(sample_str3);

    // printf("%d\n", hash_value);
    // printf("%d\n", hash_value1);
    // printf("%d\n", hash_value2);
    // printf("%d\n", hash_value3);
    struct hash_element **table = inittable(701);

    // char *sample_str = "sample string";
    // char *sample_val = "sample val";
    // int hash_value = simple_hash(sample_str);
    // struct hash_element ele = {sample_str, sample_val, NULL};

    // table[hash_value] = ele;
    // printf("%s\n", table[hash_value].val);

    insert(table, "sample_key", "sample_val");
    char *sample = get(table, "sample_key");
    printf("%s\n", sample);
}

struct hash_element **inittable(int size)
{
    struct hash_element **table = calloc(size, sizeof(struct hash_element *));
    return table;
}

int simple_hash(char *seed)
{
    int len = strlen(seed);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (int)seed[i] * (i + 1) * 128;
    }
    int remain = sum % 701;
    return remain;
}

char *get(struct hash_element **table, char *key)
{

    int hash_value = simple_hash(key);
    struct hash_element *ele = table[hash_value];
    return ele->val;
}

void insert(struct hash_element **table, char *key, char *val)
{

    int hash_value = simple_hash(key);
    struct hash_element *ele = (struct hash_element *)malloc(sizeof(struct hash_element *));
    ele->key = key;
    ele->val = val;
    ele->next = NULL;
    struct hash_element *head;
    if (table[hash_value] == 0)
    {
        table[hash_value] = ele;
    }
    else
    {
        while (1)
        {
            head = table[hash_value];
            if (head->next == NULL)
            {
                break;
            }
        }
        head->next = ele;
    }
}