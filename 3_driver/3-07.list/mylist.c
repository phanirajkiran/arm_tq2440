#include <linux/init.h>
#include <linux/module.h>

struct score
{
    int num;
    int english;
    int math;
    struct list_head list;
};

struct list_head score_head;
struct score stu1, stu2,stu3;
struct list_head *pos;
struct score *tmp;

static int mylist_init()
{
    INIT_LIST_HEAD(&score_head);

    stu1.num = 1;
    stu1.english = 60;
    stu1.math = 98;
    list_add_tail(&(stu1.list), &score_head);

    stu2.num = 2;
    stu2.english = 70;
    stu2.math = 89;
    list_add_tail(&(stu2.list),&score_head);

    stu3.num = 3;
    stu3.english = 88;
    stu3.math = 82;
    list_add_tail(&(stu3.list),&score_head);

    list_for_each(pos,&score_head)
    {
        tmp = list_entry(pos, struct score, list);
        printk("No.%d student, English is %d, Math is %d\n",tmp->num, tmp->english, tmp->math);
    }

    return 0;
}

static void mylist_exit()
{
    list_del(&(stu1.list));
    list_for_each(pos,&score_head)
    {
        tmp = list_entry(pos, struct score, list);
        printk("No.%d student, English is %d, Math is %d\n",tmp->num, tmp->english, tmp->math);
    }
}

module_init(mylist_init);
module_exit(mylist_exit);