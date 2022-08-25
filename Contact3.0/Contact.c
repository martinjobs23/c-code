//
//  Contact.c
//  Contact
//
//  Created by DFH on 2022/8/24.
//

#include "Contact.h"
static int search_by_name(const struct Contact* ps,char name[MAX_NAME]) {
    int i = 0;
    int ret = -1;
    for (i = 0; i < ps->size; i++)
    {
        if (strcmp(name, ps->data[i].name) == 0) {
            ret = i;
            break;
        }
    }
    return ret;
}
static int cmp_by_age(const void* e1, const void* e2) {
    return (((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age);
}
static int cmp_by_name(const void* e1, const void* e2) {
    return strcmp(((struct PeoInfo*)e1)->name , ((struct PeoInfo*)e2)->name);
}
void CheckCapacity(struct Contact *ps){
    //如果满了就会增加空间，没有满的话直接写数据即可
    if(ps->size == ps->capacity){
        struct PeoInfo *ptr = realloc(ps->data, (ps->capacity+2)*sizeof(struct PeoInfo));
        if(ptr != NULL){
            ps->data = ptr;
            ps->capacity += 2;
            printf("增容成功。\n");
        }
        else
            printf("增容失败。\n");
    }
}
void LoadContact(struct Contact* ps){
    FILE*pfread = fopen("/Users/dfh/Desktop/test_code/C-code/Contact3.0/Contact.txt", "rb");
    if (pfread == NULL) {
        printf("LoadContact::%s",strerror(errno));
        return;
    }
    //读取文件
    
    struct PeoInfo tmp = {0};
    while (fread(&tmp, sizeof(struct PeoInfo), 1, pfread)) {
        CheckCapacity(ps);
        ps->data[ps->size] = tmp;
        ps->size ++;
    }
    
    
    fclose(pfread);
    pfread = NULL;
}

void InitContact(struct Contact* ps) {
    ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
    if (ps->data == NULL) {
        printf("%s",strerror(errno));
        return;
    }
    ps->capacity = DEFINE_SZ;
    ps->size = 0;
    //如果是文件格式的话，我需要将已经有的信息，加载到通讯录中，这样保留的信息也能够被读取
    LoadContact(ps);
}
void AddContact(struct Contact* ps) {
    //在使用添加通讯录前首先要检查容量是否够用，能不能继续增加
    //设计使用CheckCapacity函数
    CheckCapacity(ps);
    
//    if (ps->size == MAX-1) {
//        printf("通讯录已满，无法继续增加。\n");
//    }
//    else {
        printf("请输入姓名:");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄:");
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入性别:");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入住址:");
        scanf("%s", ps->data[ps->size].addr);
        //ps中的size++
        ps->size++;
        printf("增加成功。\n");
    //}
}
void DelContact(struct Contact* ps) {
    printf("请输入要删除的人的姓名：");
    char name[MAX_NAME];
    scanf("%s", name);
    int ret = search_by_name(ps,name);
    if (ret == -1) {
        printf("未找到需要删除的人。\n");
    }
    else {
        int j = 0;
        for ( j = ret; j < ps->size-1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功。\n");
    }
}
void SearchContact(const struct Contact* ps) {
    char name[MAX_NAME];
    printf("请输入要查找人的姓名：");
    scanf("%s", name);
    int ret = search_by_name(ps, name);
    if (ret == -1) {
        printf("未找到需要查找的人。\n");
    }
    else {
        printf("%-20s\t%-4s\t%-10s\t%-15s\t%-30s\n","name","age","sex","tele","addr");
        printf("%-20s\t%-4d\t%-10s\t%-15s\t%-30s\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
    }
}
void ModifyContact(struct Contact* ps) {
    char name[MAX_NAME];
    printf("请输入要查找人的姓名：");
    scanf("%s", name);
    int ret = search_by_name(ps, name);
    if (ret == -1) {
        printf("未找到需要修改的人。\n");
    }
    else {
        printf("请输入姓名:");
        scanf("%s", ps->data[ret].name);
        printf("请输入年龄:");
        scanf("%d", &(ps->data[ret].age));
        printf("请输入性别:");
        scanf("%s", ps->data[ret].sex);
        printf("请输入电话:");
        scanf("%s", ps->data[ret].tele);
        printf("请输入住址:");
        scanf("%s", ps->data[ret].addr);
        printf("修改成功。\n");
    }
}
void ShowContact(const struct Contact* ps) {
    if (ps->size == 0) {
        printf("通讯录为空。\n");
    }
    else {
        int i = 0;
        printf("%-20s\t%-4s\t%-10s\t%-15s\t%-30s\n","name","age","sex","tele","addr");
        for ( i = 0; i < ps->size; i++)
        {
        //printf("姓名        性别    电话        住址        年龄");
            printf("%-20s\t%-4d\t%-10s\t%-15s\t%-30s\n", ps->data[i].name, ps->data[i].age,ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
        }
    }
}
void SortContact(struct Contact* ps) {
    printf("请输入按照何种方式排序，选择1用姓名排序，选择2用年龄排序：");
    int input;
    scanf("%d",&input );
    if (input == 1) {
        qsort(ps->data,ps->size,sizeof(struct PeoInfo),cmp_by_name);
        printf("按照姓名排序成功。\n");
        ShowContact(ps);
    }
    else if (input == 2) {
        qsort(ps->data,ps->size,sizeof(struct PeoInfo), cmp_by_age);
        printf("按照年龄排序成功。\n");
        ShowContact(ps);
    }
    else {
        printf("输入错误，排序失败。\n");
        ShowContact(ps);
    }
}
void DestoryContact(struct Contact* ps){
    free(ps->data);
    ps->data = NULL;
}
void SaveContact(struct Contact* ps){
    FILE*pfwrite = fopen("/Users/dfh/Desktop/test_code/C-code/Contact3.0/Contact.txt", "wr");
    if (pfwrite == NULL) {
        printf("SaveContact::%s",strerror(errno));
        return;
    }
    int i = 0;
    for (i = 0; i<ps->size; i++) {
        fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfwrite);
    }
    fclose(pfwrite);
    pfwrite = NULL;
    printf("保存成功。\n");
}
