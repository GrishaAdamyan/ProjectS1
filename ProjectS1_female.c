#include <fcntl.h>

#include <stdio.h>

#include <unistd.h>

#include <errno.h>

#include <stdlib.h>

#include <string.h>

#define N 1000

struct For_Female
{
    struct For_Female *next;
    float hemoglobinLevel;
    float erythrocytes;
    float leukocytes;
    float thrombocytes;
    int id;
    char sex;
};

void add_female(struct For_Female **head, char sex[], float hemoglobinLevel, float erythrocytes, float leukocytes, float thrombocytes, int id)
{
    if (0 == *head)
    {
        *head = malloc(sizeof(struct For_Female));
        strcpy(&(*head)->sex, sex);
        (*head)->hemoglobinLevel = hemoglobinLevel;
        (*head)->erythrocytes = erythrocytes;
        (*head)->leukocytes = leukocytes;
        (*head)->thrombocytes = thrombocytes;
        (*head)->id = id;

        printf("Check result in result_female.txt\n");

        FILE *res = fopen("result_female.txt", "a");

        fprintf(res, "Added element id: %d\n", id);
        fprintf(res, "Hemoglobin Level: %f\n", hemoglobinLevel);
        fprintf(res, "Erythrocytes: %f\n", erythrocytes);
        fprintf(res, "Leukocytes: %f\n", leukocytes);
        fprintf(res, "Thrombocytes: %f\n\n\n", thrombocytes);
        fclose(res);

        return;
    }
    else
    {
        struct For_Female *copy = *head;
        struct For_Female **new_head = head;
        while (copy->next != 0 && copy->id != id)
        {
            copy = copy->next;
        }
        
        if (copy->id == id)
        {
            printf("You can't add, id has been already used!\n");
            return;
        }
        else
        {
            struct For_Female *new = malloc(sizeof(struct For_Female));
            strcpy(&new->sex, sex);
            new->hemoglobinLevel = hemoglobinLevel;
            new->erythrocytes = erythrocytes;
            new->leukocytes = leukocytes;
            new->thrombocytes = thrombocytes;
            new->id = id;
            new->next = 0;
            copy->next = new;
            head = new_head;

            printf("Check result in result_female.txt\n");

            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "Added element id: %d\n", id);
            fprintf(res, "Hemoglobin Level: %f\n", hemoglobinLevel);
            fprintf(res, "Erythrocytes: %f\n", erythrocytes);
            fprintf(res, "Leukocytes: %f\n", leukocytes);
            fprintf(res, "Thrombocytes: %f\n\n\n", thrombocytes);
            fclose(res);
        }
        return;
    }
}

void get_female(struct For_Female **head, int id)
{
    struct For_Female *copy = *head;
    struct For_Female *t = 0;
    int i = 1;
    while (copy != NULL && id != copy->id)
    {
        copy = copy->next;
        i++;
    }
    if (copy != NULL)
    {
        printf("Check result in result_female.txt\n");

        FILE *res = fopen("result_female.txt", "a");

        fprintf(res, "The position of id %d in the female list is: %d\n\n", id, i);
        fclose(res);
    }
    else
    {
        printf("You can't get that data, invalid id!\n");
    }
    return;
}

void analize_female(struct For_Female **head, int id)
{
    struct For_Female *copy = *head;
    struct For_Female *t = 0;
    int i = 0;
    while (copy != NULL && id != copy->id)
    {
        copy = copy->next;
        i++;
    }
    if (copy != NULL)
    {
        printf("Check result in result_female.txt\n");

        FILE *res = fopen("result_female.txt", "a");

        fprintf(res, "Analize for id: %d\n", id);
        fclose(res);
        if (copy->hemoglobinLevel < 12)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "Hemoglobin level is low\n");
            fclose(res);
        }
        else if (copy->hemoglobinLevel <= 16)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "Hemoglobin level is normal\n");
            fclose(res);
        }
        else
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "Hemoglobin level is high\n");
            fclose(res);
        }

        if (copy->erythrocytes < 3.8)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of erythrocytes is low\n");
            fclose(res);
        }
        else if (copy->erythrocytes <= 5.2)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of erythrocytes is normal\n");
            fclose(res);
        }
        else
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of erythrocytes is high\n");
            fclose(res);
        }

        if (copy->leukocytes < 4500)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of leukocytes is low\n");
            fclose(res);
        }
        else if (copy->leukocytes <= 11000)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of leukocytes is normal\n");
            fclose(res);
        }
        else
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of leukocytes is high\n");
            fclose(res);
        }

        if (copy->thrombocytes < 157000)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of thrombocytes is low\n\n");
            fclose(res);
        }
        else if (copy->thrombocytes <= 371000)
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of thrombocytes is normal\n\n");
            fclose(res);
        }
        else
        {
            FILE *res = fopen("result_female.txt", "a");

            fprintf(res, "The number of thrombocytes is high\n\n");
            fclose(res);
        }
    }
    else
    {
        printf("You can't analize that data, invalid id\n");
    }
    return;
}

int main()
{
    struct For_Female *listHead = 0;
    char buf[N];
    int fd = open("data_for_ProjectS1(female).txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Cannot open file");
        return errno;
    }
    ssize_t bytes = read(fd, buf, N);
    if (bytes == -1)
    {
        perror("Cannot open file");
        return errno;
    }
    buf[bytes] = ' ';
    buf[bytes + 1] = '\0';
    close(fd);

    int i = 0;
    char str[50];
    int count = 0;
    float hemoglobinLevel, erythrocytes, leukocytes, thrombocytes;
    int id;
    int j = 0;
    while (buf[i] != '\0')
    {
        while (buf[i] != '\n' && buf[i] != ' ')
        {
            str[j] = buf[i];
            i += 1;
            j += 1;
        }
        str[j] = '\0';
        count += 1;
        if (count == 1)
        {
            hemoglobinLevel = atof(str);
        }
        else if (count == 2)
        {
            erythrocytes = atof(str);
        }
        else if (count == 3)
        {
            leukocytes = atof(str);
        }
        else if (count == 4)
        {
            thrombocytes = atof(str);
        }
        else if (count == 5)
        {
            id = atoi(str);
            count = 0;
        }
        i += 1;
        memset(str, '\0', sizeof(str));
        j = 0;
        if (count == 0)
        {
            add_female(&listHead, "f", hemoglobinLevel, erythrocytes, leukocytes, thrombocytes, id);
        }
    }

    int f = 1;
    do
    {
        char action[10];
        printf("Choose action(add, get or analize): ");
        scanf("%s", &action[10]);
        if (strcmp(&action[10], "add") == 0)
        {
            float hemoglobinLevel;
            printf("Enter hemoglobin level: ");
            scanf("%f", &hemoglobinLevel);
            float erythrocytes;
            printf("Enter the number of erythrocytes(red blood cells): ");
            scanf("%f", &erythrocytes);
            float leukocytes;
            printf("Enter the number of leukocytes(white blood cells): ");
            scanf("%f", &leukocytes);
            float thrombocytes;
            printf("Enter the number of thrombocytes(platelets): ");
            scanf("%f", &thrombocytes);
            int id;
            printf("Enter id: ");
            scanf("%d", &id);

            add_female(&listHead, "f", hemoglobinLevel, erythrocytes, leukocytes, thrombocytes, id);
        }
        else if (strcmp(&action[10], "get") == 0)
        {
            int id;
            printf("Enter id: ");
            scanf("%d", &id);

            get_female(&listHead, id);
        }
        else if (strcmp(&action[10], "analize") == 0)
        {
            int id;
            printf("Enter id: ");
            scanf("%d", &id);

            analize_female(&listHead, id);
        }
        else
        {
            printf("Invalid action");
            break;
        }
        char answer[10];
        printf("Do you want to continue(yes or no)? ");
        scanf("%s", &answer[10]);
        if (strcmp(&answer[10], "no") == 0)
        {
            f = 0;
        }
        else if (strcmp(&answer[10], "yes") == 0)
        {
            f = 1;
        }
        else
        {
            printf("Invalid answer. Exitting...\n");
            f = 0;
        }
    } while (f == 1);

    struct For_Female *ptr = listHead;
    struct For_Female *del = listHead;
    while (ptr != 0)
    {
        del = ptr;
        ptr = ptr->next;
        free(del);
    }
    return 0;
}
